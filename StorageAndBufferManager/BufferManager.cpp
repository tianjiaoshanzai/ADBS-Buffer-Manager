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
	}
	hitCnt = 0;
	dsmgr = new DSMgr();


}

BMgr::BMgr(DSMgr* dsmgr_in)
{
	memset(ftop, -1, DEFBUFSIZE);//初始buffer无对应page
	for (int i = 0; i < DEFBUFSIZE; i++) {
		ptof[i] = new BCB(i);
	}
	hitCnt = 0;
	dsmgr =dsmgr_in;
}

BMgr::~BMgr() {
	WriteDirtys();


	delete ftop;
	delete ptof;
	delete dsmgr;
}

int BMgr::Hash(int page_id)
{
	return page_id%DEFBUFSIZE;
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
