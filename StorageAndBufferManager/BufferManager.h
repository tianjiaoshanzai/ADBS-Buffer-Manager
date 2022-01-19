#pragma once
#include"basicUnit.h"
#include"DataStorageManager.h"
class BMgr
{
public:
	BMgr();
	BMgr(DSMgr* dsmgr_in);
	~BMgr();
	
	// Interface functions
	int FixPage(int page_id, int prot);
	void NewPage FixNewPage();
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
	int hitCnt;//ÃüÖÐ´ÎÊý
	DSMgr* dsmgr;
};