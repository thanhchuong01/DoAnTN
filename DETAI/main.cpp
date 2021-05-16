#include<iostream>
#include<string.h>
#include"dslop.h"
#include"dssv.h"
#include"dsdiem.h"
#include"dsmh.h"
#include"dscauhoi.h"
#include"xuly.h"

using namespace std;

int main()
{
	dslop DS_LOP;
	dsmh DS_MH;
	dsch DS_CH;
	loadfiledssv(DS_LOP);
	nhappass();
//	dangnhap(DS_LOP);
	return 0;
}
