#pragma once
#include <string>

//-----------------��ʼ������ʼ--------------------------------------------------//
#define FRAMESIZE 4096 //frame��С
#define DEFBUFSIZE 1024 //bufferĬ�ϴ�С���û��ɺ����Զ���

#define PAGESIZE 4096 //frame��С����frameһ��

#define MAXPAGES 50000 //�������ݿ�50000��
//-----------------��ʼ��������-------------------------------------------------//

std::string db_file_path = "data.dbf";//��������file name

struct bFrame
{//frame����
    char field[FRAMESIZE];
};

bFrame buf[DEFBUFSIZE];//buffer����

struct BCB
{//������Ƶ�Ԫ��һ��frame��Ӧһ��BCB
    BCB();
    BCB(int frm_id);
    int page_id;
    int frame_id;
    int latch;
    int count;
    int dirty;
    BCB* next;
};

struct Record {//��¼
    int page_id;
    int slot_num;
};

struct Frame {
    int frame_id;
    int offset;
};

/************************************�Զ��幤���࿪ʼ**************************************/
//ȫ��log��ӡ��д��־
void writeLog(std::string);

/************************************�Զ��幤�������**************************************/