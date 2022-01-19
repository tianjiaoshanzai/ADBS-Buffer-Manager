#pragma once

#include <iostream>
#include <string>
#include"basicUnit.h"


class DSMgr
{
public:
	DSMgr();
	~DSMgr();
	int OpenFile(std::string filename);
	int CloseFile();
	bFrame ReadPage(int page_id);//返回page_id对应的块
	int WritePage(int page_id, bFrame frm);//返回写入字节数
	int Seek(int offset, int pos);//移动文件指针
	FILE* GetFile();
	void IncNumPages();
	int GetNumPages(); 
	void SetUse(int index, int use_bit);
	int GetUse(int index);

	void IncIOCnt();
	int GetIOCnt();
private:
	FILE* currFile;
	int numPages;
	int pages[MAXPAGES];//使用状态bit标记
	
	int IOCount;
};