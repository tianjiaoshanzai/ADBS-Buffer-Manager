#include<iostream>

#include"basicUnit.h"

BCB::BCB() {
    page_id = -1;//-1������Ч
    frame_id = -1;//-1������Ч
    latch = 0;
    count = 0;
    dirty = 0;//0Ϊclean
    next = nullptr;
}

BCB::BCB(int frm_id)
{
    page_id = -1;//-1������Ч
    frame_id = frm_id;//-1������Ч
    latch = 0;
    count = 0;
    dirty = 0;//0Ϊclean
    next = nullptr;
}

void writeLog(std::string log_str)
{
    //����ʱ���Դ�ӡ������̨
    //std::cout << log_str << std::endl;

    //TODO�����Դ���log�ļ�д��log
}
