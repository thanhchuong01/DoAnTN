//*************CAy NHI PHAN*******************
#pragma once
#include<string.h>
using namespace std;

struct ch
{
	//******DATA********
	int key;
	string MAMH;
	string ND;
	string A,B,C,D;
	string DAPAN;
	//******POINTER******
	ch *pLeft;
	ch *pRight;	
};
typedef struct ch* TREE;
struct dsch
{
	int SLCH=0;
	TREE DSCH=NULL;
};
typedef struct dsch dsch;
