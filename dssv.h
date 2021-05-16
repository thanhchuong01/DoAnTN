//*******************DS LK DON*******************
#pragma once
#include"dsdiem.h"
#include<string.h>
using namespace std;

struct sv
{
	//*****DATA********
	string MSSV;
	string HO;	
	string TEN;
	string PHAI;
	string PASSWORD;
	dsdiem DSDIEM;
	
	//********Pointer*********
	sv *pNext;
};
typedef struct sv sv;
struct dssv
{
	int SLSV=0;
	sv *pHead=NULL;
};
typedef struct dssv dssv;