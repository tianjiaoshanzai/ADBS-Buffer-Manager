#include"basicUnit.h"

BCB::BCB() {
    page_id = -1;//-1������Ч
    frame_id = -1;//-1������Ч
    latch = 0;
    count = 0;
    dirty = 0;//0Ϊclean
}

BCB::BCB(int frame_id)
{
    page_id = -1;//-1������Ч
    frame_id = frame_id;//-1������Ч
    latch = 0;
    count = 0;
    dirty = 0;//0Ϊclean
}
