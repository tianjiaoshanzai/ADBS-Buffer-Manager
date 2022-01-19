#include"basicUnit.h"

BCB::BCB() {
    page_id = -1;//-1代表无效
    frame_id = -1;//-1代表无效
    latch = 0;
    count = 0;
    dirty = 0;//0为clean
}

BCB::BCB(int frame_id)
{
    page_id = -1;//-1代表无效
    frame_id = frame_id;//-1代表无效
    latch = 0;
    count = 0;
    dirty = 0;//0为clean
}
