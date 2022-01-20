#include"BufferManager.h"

BMgr::BMgr() {
	/*
	int ftop[DEFBUFSIZE];
	BCB* ptof[DEFBUFSIZE];
	int hitCnt;//命中次数
	DSMgr* dsmgr
	*/
	memset(ftop, -1, DEFBUFSIZE);//初始buffer无对应page
	for (int i = 0; i < DEFBUFSIZE; i++) {
		ptof[i] = new BCB(i);

		unused_page_list.push_back(i);
	}
	hitCnt = 0;
	frame_num = 0;
	used_frame_num = 0;
	requestCnt = 0;
	dsmgr = new DSMgr();
	lru = new LRU(DEFBUFSIZE);

	//for(int i=0)
	//unused_page_list.push_back()


}

BMgr::BMgr(DSMgr* dsmgr_in)
{
	memset(ftop, -1, DEFBUFSIZE);//初始buffer无对应page
	for (int i = 0; i < DEFBUFSIZE; i++) {
		ptof[i] = new BCB(i);

		unused_page_list.push_back(i);
	}
	hitCnt = 0;
	frame_num = 0;
	used_frame_num = 0;
	requestCnt = 0;
	dsmgr =dsmgr_in;
	lru = new LRU(DEFBUFSIZE);
}

BMgr::~BMgr() {
	WriteDirtys();


	delete ftop;
	delete ptof;
	delete dsmgr;
	delete lru;
}

int BMgr::FixPage(int page_id, int prot)
{
	requestCnt++;
	int tar_frame_id=Hash(page_id);
	BCB* tar_frame = ptof[tar_frame_id];
	tar_frame->count++;
	if (tar_frame->page_id == page_id) {
		hitCnt++;//命中次数加一
		return tar_frame_id;
	}
	else {
		if (tar_frame->page_id != -1 && tar_frame->dirty == 1) {
			dsmgr->WritePage(tar_frame->page_id, buf[tar_frame->frame_id]);//写入脏页
		}
		
		buf[tar_frame->frame_id]=dsmgr->ReadPage(page_id);//未命中page读入buffer
	}
	return tar_frame_id;
}

int BMgr::FixNewPage()
{
	int unused_page_id = unused_page_list.front();
	//BCB* tar_frame = ptof[Hash(unused_page_id)];
	FixPage(unused_page_id, 0);

	return unused_page_id;
}

int BMgr::UnfixPage(int page_id)
{
	int tar_frame_id = Hash(page_id);
	BCB* tar_frame = ptof[tar_frame_id];
	tar_frame->count--;
	return 0;
}

int BMgr::NumFreeFrames()
{
	return frame_num-used_frame_num;
}

int BMgr::SelectVictim()
{
	return lru->Victim();
}

int BMgr::Hash(int page_id)
{
	return page_id%DEFBUFSIZE;
}

void BMgr::RemoveBCB(BCB* ptr, int page_id)
{
}

void BMgr::RemoveLRUEle(int frid)
{
	lru->Remove(frid);
}

void BMgr::SetDirty(int frame_id)
{
	BCB* target_BCB = ptof[frame_id];
	target_BCB->dirty = 1;
}

void BMgr::UnsetDirty(int frame_id)
{
	BCB* target_BCB = ptof[frame_id];
	target_BCB->dirty = 0;
}

void BMgr::WriteDirtys()
{
	for (int i = 0; i < DEFBUFSIZE; i++) {
		if (ptof[i]->dirty == 1) {
			dsmgr->WritePage(ptof[i]->page_id, buf[ptof[i]->frame_id]);
			delete ptof[i];
		}
	}
}

void BMgr::PrintFrame(int frame_id)
{
	BCB* target_BCB = ptof[frame_id];
	/*
	int page_id;
    int frame_id;
    int latch;
    int count;
    int dirty;
    BCB* next;
	*/

	std::cout << "frame_id:" << target_BCB->frame_id << std::endl;
	std::cout << "page_id:" << target_BCB->page_id << std::endl;
	std::cout << "latch:" << target_BCB->latch << std::endl; 
	std::cout << "count:" << target_BCB->count << std::endl;
	std::cout << "dirty:" << target_BCB->dirty << std::endl;
	//std::cout << "next" << target_BCB->page_id << std::endl;
}
