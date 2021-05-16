//***************DS TUYEN TINH**************
#pragma once
#define MAXMH 10
#include<string.h>
using namespace std;

struct mh
{
	string MAMH;
	string TENMH;
};
struct dsmh
{
	int SLMH;
	mh DSMH[MAXMH];
};
typedef struct dsmh dsmh;
