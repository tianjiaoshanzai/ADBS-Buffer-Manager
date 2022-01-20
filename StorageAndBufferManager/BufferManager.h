#pragma once

#include <list> 

#include"basicUnit.h"
#include"DataStorageManager.h"
#include"LRU.h"
class BMgr
{
public:
	BMgr();
	BMgr(DSMgr* dsmgr_in);
	~BMgr();

	struct NewPage {
		int page_id;
		int frame_id;
	};

	/*
	 struct UnUsedPage
	{
		int unused_page_id;
		UnUsedPage* next;
	};
	*/
	
	
	// Interface functions
	int FixPage(int page_id, int prot);
	int FixNewPage();
	int UnfixPage(int page_id);
	int NumFreeFrames();
	// Internal Functions
	int SelectVictim();
	int Hash(int page_id);
	void RemoveBCB(BCB* ptr, int page_id);
	void RemoveLRUEle(int frid);
	void SetDirty(int frame_id);
	void UnsetDirty(int frame_id);
	void WriteDirtys();
	void PrintFrame(int frame_id);
private:
	// Hash Table
	int ftop[DEFBUFSIZE];
	BCB* ptof[DEFBUFSIZE];
	int frame_num;//frame总数
	int used_frame_num;//已使用frame数量
	int hitCnt;//命中次数
	int requestCnt;
	DSMgr* dsmgr;

	LRU* lru;
	
	std::list<int> unused_page_list;
	//UnUsedPage* unused_page_list;


};