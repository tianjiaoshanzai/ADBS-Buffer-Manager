#include<iostream>

#include"basicUnit.h"

BCB::BCB() {
    page_id = -1;//-1代表无效
    frame_id = -1;//-1代表无效
    latch = 0;
    count = 0;
    dirty = 0;//0为clean
    next = nullptr;
}

BCB::BCB(int frm_id)
{
    page_id = -1;//-1代表无效
    frame_id = frm_id;//-1代表无效
    latch = 0;
    count = 0;
    dirty = 0;//0为clean
    next = nullptr;
}

void writeLog(std::string log_str)
{
    //出错时可以打印到控制台
    //std::cout << log_str << std::endl;

    //TODO：可以创建log文件写入log
}
