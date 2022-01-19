#include"DataStorageManager.h"
#include"basicUnit.h"

DSMgr::DSMgr()
{
	currFile = nullptr;
	numPages = 0;
	IOCount = 0;

	std::string log_str = "DataStorageManager初始化成功";
	writeLog(log_str);
}

DSMgr::~DSMgr() {
	CloseFile();

	std::string log_str = "DataStorageManager销毁成功";
	writeLog(log_str);
}

int DSMgr::OpenFile(std::string filename)
{
	/*FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, filename, "w+");
	if (err == 0) {
		currFile = fp;
	}
	
	return err;*/

	currFile = fopen(filename.c_str(), "r+");//读写打开

	std::string log_str = "";
	if (currFile == nullptr) {

		log_str = filename+"文件不存在," + "打开失败,"+"初始化创建文件"+filename;
		writeLog(log_str);

		currFile = fopen(filename.c_str(), "w");//不存在创建
		currFile = freopen(filename.c_str(), "r+", currFile);
	}
	else {
		fseek(currFile, 0L, SEEK_END);
		long sz = ftell(currFile);
		numPages = sz / PAGESIZE;//重新初始化page数量

		log_str = filename + "文件打开成功";
		writeLog(log_str);
	}
	return currFile != nullptr;
}

int DSMgr::CloseFile()
{
	int errCode=fclose(currFile);

	std::string log_str = "关闭文件";
	writeLog(log_str);
	return errCode;
}

bFrame DSMgr::ReadPage(int page_id)
{
	//todo:后续可选加入首块，索引块
	bFrame* res_ptr = new bFrame;

	std::string log_str = "";
	if (Seek(page_id * PAGESIZE, SEEK_SET != 0)) {
		//fprintf(stderr, "Error: cannot find page: %d\n", page_id);
		log_str = page_id+"该页不存在";
		writeLog(log_str);

		exit(1);
	}
	fread(res_ptr, sizeof(struct bFrame), 1, currFile);

	log_str = "页面："+page_id;
	log_str +="读取成功";
	writeLog(log_str);

	IncIOCnt();
	return *res_ptr;
}

int DSMgr::WritePage(int page_id, bFrame frm)
{//返回写入字节数
	bFrame* frm_ptr = &frm;

	std::string log_str = "";
	if (Seek(page_id * sizeof(bFrame), SEEK_SET) != 0) {
		//fprintf(stderr, "Error: cannot find page: %d\n", page_id);

		log_str = page_id + "该页不存在";
		writeLog(log_str);
		exit(1);
	}
	int frmNum= fwrite(frm_ptr, sizeof(bFrame),1, currFile);

	log_str = "页面：" + page_id;
	log_str += "写入成功";
	writeLog(log_str);

	IncIOCnt();
	return frmNum* sizeof(bFrame);
}

int DSMgr::Seek(int offset, int pos)
{
	std::string log_str = "文件指针移动至";
	log_str += pos;
	log_str += "+";
	log_str += offset;
	writeLog(log_str);

	return fseek(currFile, (long)offset, pos);
}

FILE* DSMgr::GetFile()
{
	return currFile;
}

void DSMgr::IncNumPages()
{
	std::string log_str = "块数加一";
	writeLog(log_str);

	numPages++;
}

int DSMgr::GetNumPages()
{
	return numPages;
}

void DSMgr::SetUse(int index, int use_bit)
{
	std::string log_str = "块"+index;
	log_str += "设置使用位为：" + use_bit;
	writeLog(log_str);

	pages[index] = use_bit;
}

int DSMgr::GetUse(int index)
{
	return pages[index];
}

void DSMgr::IncIOCnt()
{
	IOCount++;
}

int DSMgr::GetIOCnt()
{
	return IOCount;
}
