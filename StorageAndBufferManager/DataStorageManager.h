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
	bFrame ReadPage(int page_id);//����page_id��Ӧ�Ŀ�
	int WritePage(int page_id, bFrame frm);//����д���ֽ���
	int Seek(int offset, int pos);//�ƶ��ļ�ָ��
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
	int pages[MAXPAGES];//ʹ��״̬bit���
	
	int IOCount;
};