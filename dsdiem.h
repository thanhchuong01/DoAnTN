//*******************DS LK DON*******************
#pragma once
#include<string.h>
using namespace std;

struct diem
{
	//****DATA******
	string MAMH;
	float DIEM;
	//******p*******
	diem *pNext;
};
typedef struct diem diem;
struct dsdiem
{
	int SLDIEM=0;
	diem *pHead=NULL;
};
typedef struct dsdiem dsdiem;

