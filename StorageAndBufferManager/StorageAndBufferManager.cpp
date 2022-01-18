#include <iostream>

//-----------------初始参数开始--------------------------------------------------//
#define FRAMESIZE 4096 //frame大小
#define DEFBUFSIZE 1024 //buffer默认大小，用户可后续自定义
//-----------------初始参数结束-------------------------------------------------//



struct bFrame
{
    char field[FRAMESIZE];
};

bFrame buf[DEFBUFSIZE];


int main()
{
    std::cout << "Hello World!\n";
}


