#pragma once
#include <string>

//-----------------初始参数开始--------------------------------------------------//
#define FRAMESIZE 4096 //frame大小
#define DEFBUFSIZE 1024 //buffer默认大小，用户可后续自定义

#define PAGESIZE 4096 //frame大小，与frame一样

#define MAXPAGES 50000 //测试数据块50000块
//-----------------初始参数结束-------------------------------------------------//

std::string db_file_path = "data.dbf";//本地数据file name

struct bFrame
{//frame定义
    char field[FRAMESIZE];
};

bFrame buf[DEFBUFSIZE];//buffer定义

struct BCB
{//缓存控制单元，一个frame对应一个BCB
    BCB();
    BCB(int frm_id);
    int page_id;
    int frame_id;
    int latch;
    int count;
    int dirty;
    BCB* next;
};

struct Record {//记录
    int page_id;
    int slot_num;
};

struct Frame {
    int frame_id;
    int offset;
};

/************************************自定义工具类开始**************************************/
//全局log打印和写日志
void writeLog(std::string);

/************************************自定义工具类结束**************************************/