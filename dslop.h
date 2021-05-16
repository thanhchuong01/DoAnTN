//*****************MANG CON TRO**************
#pragma once
#include<string>
#define MAXDSLOP 100
#include<string.h>
#include"dssv.h"
using namespace std;

struct lop
{
	string MALOP;
	string TENLOP;
	dssv DSSV; 
};
typedef struct lop lop;
struct dslop
{
	int SLLOP=0;
	lop *DSLOP[MAXDSLOP];
};
typedef struct dslop dslop;
