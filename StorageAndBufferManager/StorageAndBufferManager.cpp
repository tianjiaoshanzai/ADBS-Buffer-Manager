#include <iostream>
#include <cstring>
#include <time.h>

#include"BufferManager.h"



int init_db_file() {
//初始化数据库文件
    FILE* db_file = fopen(db_file_path.c_str(), "r");
    /* create db with certain size */
    if (db_file == NULL) {
        db_file = fopen(db_file_path.c_str(), "w");
        void* buffer = malloc(50000 * sizeof(bFrame));
        fwrite(buffer, PAGE_SIZE, 50000, db_file);
        free(buffer);
    }
    fclose(db_file);
}


int main()
{

    /*
    bFrame* t1 = new bFrame;
    bFrame* t2=new bFrame;
    t1->field[0] = 'C';

    FILE* fp=NULL;
    errno_t err = fopen_s(&fp, "test1.txt", "w+");
    //fp = fopen("test1.txt", "w+");
    fwrite(t1, sizeof(struct bFrame), 1, fp);
    fseek(fp, 0, SEEK_SET);
    fread(t2, sizeof(struct bFrame), 1, fp);

    std::cout << t2->field[0]<<"/n";
    */


}


