#pragma once
#include<iostream>
#include<string.h>
#include"dslop.h"
#include"dssv.h"
#include"dsdiem.h"
#include"dsmh.h"
#include"dscauhoi.h"
#include"mylib.h"
#include<fstream>
#include<stdlib.h>
#include <math.h>
#define bgmenu 9
using namespace std;

void nhaplop(dslop &ds_lop)
{
    cout<<"\t************************************\n";
    lop *p=new lop;
    cout<<"Nhap Ma Lop : \t";
    fflush(stdin);
    getline(cin,p->MALOP);
    cout<<"Nhap Ten Lop : \t";
    fflush(stdin);
    getline(cin,p->TENLOP);
    ds_lop.DSLOP[ds_lop.SLLOP]=p;
    ds_lop.SLLOP+=1;
    cout<<"\t************************************\n";
}
void indslop(dslop ds_lop)
{
    cout<<"\t************************************\n";
    cout<<"\n SL LOP : "<<ds_lop.SLLOP<<endl;
    for(int i=0;i<ds_lop.SLLOP;i++)
    {
        cout<<"\nMALOP : "<<ds_lop.DSLOP[i]->MALOP;
        cout<<"\nTENLOP : "<<ds_lop.DSLOP[i]->TENLOP<<endl;
    }
    cout<<"\t************************************\n";
}
void nhapsv(dslop &ds_lop)
{
    cout<<"\t************************************\n";
    cout<<"\nNhap MALOP cua SV    ";
    string malopsv;
    fflush(stdin);
    getline(cin,malopsv);
    sv *p=new sv;
    cout<<"Sl SV muon nhap     ";
    int slsv;
    cin>>slsv;
    for(int i=0;i<slsv;i++)
    {
        cout<<"nhap MSSV\t";
        fflush(stdin);
        getline(cin,p->MSSV);
        cout<<"nhap HO    ";
        fflush(stdin);
        getline(cin,p->HO);
        cout<<"nhap TEN\t";
        fflush(stdin);
        getline(cin,p->TEN);
        cout<<"nhap PHAI\t";
        fflush(stdin);
        getline(cin,p->PHAI);
        for(int i=0;i<ds_lop.SLLOP;i++)
        {
            if(ds_lop.DSLOP[i]->MALOP==malopsv)
                {
                    p->pNext=ds_lop.DSLOP[i]->DSSV.pHead;
                    ds_lop.DSLOP[i]->DSSV.pHead=p;
                    ds_lop.DSLOP[i]->DSSV.SLSV+=1;
                }
            
        }
    }
    cout<<"\t************************************\n";
}

void indssvcuacaclop(dslop ds_lop)
{
    cout<<"\t************************************\n";
     for(int i=0;i<ds_lop.SLLOP;i++)
    {
    	cout<<"\nLOP "<<i;
    	cout<<"\nMALOP: "<<ds_lop.DSLOP[i]->MALOP;
    	cout<<"\nTENLOP: "<<ds_lop.DSLOP[i]->TENLOP;
        cout<<"\nSL SV cua lop\t: ";
        cout<<ds_lop.DSLOP[i]->DSSV.SLSV;
        if(ds_lop.DSLOP[i]->DSSV.SLSV!=0) 
        {
            sv *p=new sv;
			p=ds_lop.DSLOP[i]->DSSV.pHead;
            while(p!=NULL)
            {
                cout<<"\n"<<p->HO<<" "<<p->TEN<<"("<<p->PHAI<<")"<<endl;
                p=p->pNext;
            }
            cout<<"\n\t************************************\n";

        }
    }
    cout<<"\n\t************************************\n";
}
void themmh(dsmh &ds_mh)
{
    cout<<"\n\t************************************\n";
    cout<<"Nhap MAMH\t: ";
    fflush(stdin);
    getline(cin,ds_mh.DSMH[ds_mh.SLMH].TENMH);
    cout<<"Nhap TENMH\t: ";
    fflush(stdin);
    getline(cin,ds_mh.DSMH[ds_mh.SLMH].TENMH);
    ds_mh.SLMH+=1;
    cout<<"\n\t************************************\n";
}

void xoaptumang(mh *arr,int vtri,int slptu)
{
    for(int i=vtri;i<slptu;i++)
    {
        arr[i]=arr[i+1];
    }
}

void xoamh(dsmh &ds_mh)
{
    cout<<"\n\t************************************\n";
    cout<<"Nhap MAMH can xoa\t ";
    string a;
    getline(cin,a);
    for(int i=0;i<ds_mh.SLMH;i++)
    {
        if(ds_mh.DSMH[i].MAMH==a)
            xoaptumang(ds_mh.DSMH,i,ds_mh.SLMH);
    }
    ds_mh.SLMH-=1;
    cout<<"\n\t************************************\n";
}

void hieuchinhmh(dsmh ds_mh)
{
    string mamh;
    string tenmh;
    cout<<"\n\t************************************\n";
    cout<<"Nhap MAMH can xoa\t ";
    string a;
    getline(cin,a);
    for(int i=0;i<ds_mh.SLMH;i++)
    {
        if(ds_mh.DSMH[i].MAMH==a)
            {
                cout<<"\nSua MAMH thanh\t: ";
                fflush(stdin);
                getline(cin,mamh);
                cout<<"\nSua TENMH thanh\t: ";
                fflush(stdin);
                getline(cin,tenmh);
                ds_mh.DSMH[i].MAMH=mamh;
                ds_mh.DSMH[i].TENMH=tenmh;
            }
    }
    cout<<"\n\t************************************\n";
}
int sinhid()
{
    int ID;
    
    return ID;
}

TREE khoitaonode(dsch ds_ch)
{
    cout<<"\n\t************************************\n";
    TREE p;
    p->key=sinhid();

    p->pLeft=NULL;

    p->pRight=NULL;

    cout<<"\nNhap MAMH\t: ";
    fflush(stdin);
    getline(cin,p->MAMH);

    cout<<"\nNhap ND\t: ";
    fflush(stdin);
    getline(cin,p->ND);

    cout<<"\nNhap A\t: ";
    fflush(stdin);
    getline(cin,p->A);

    cout<<"\nNhap B\t: ";
    fflush(stdin);
    getline(cin,p->B);

    cout<<"\nNhap C\t: ";
    fflush(stdin);
    getline(cin,p->C);

    cout<<"\nNhap D\t: ";
    fflush(stdin);
    getline(cin,p->D);

    cout<<"\nNhap DAPAN\t: ";
    fflush(stdin);
    getline(cin,p->DAPAN);
    
    cout<<"\n\t************************************\n";
    return p;
}
int Stoi(string data)
{
	int num = 0;
    for(int i = data.length()- 1; i >= 0; --i){
        num += (int)(data[i] - '0') * pow(10,data.length()- 1);
    }
    return num;
}
void loadfiledsmh(dsmh &ds_mh)
{
    fstream f;
    f.open("dsmh.txt",ios::in);
    string data;
    getline(f,data);
    ds_mh.SLMH=Stoi(data);
    for(int i=0;i<ds_mh.SLMH;i++)
    {
        getline(f,ds_mh.DSMH[i].MAMH);
        getline(f,ds_mh.DSMH[i].TENMH);
    }
    f.close();
}
void savefiledsmh(dsmh ds_mh)
{
    fstream f;
    f.open("dsmh.txt",ios::app);
    f<<ds_mh.SLMH<<endl;
    for(int i=0;i<ds_mh.SLMH;i++ )
    {
        f<<ds_mh.DSMH[i].MAMH<<endl;
        f<<ds_mh.DSMH[i].TENMH<<endl;
    }
    f.close();
}
void xuatsv1lop(lop *a)
{
	int i=0;
	sv *p=a->DSSV.pHead;
	while(p!=NULL)
	{
		cout<<"\n\t"<<p->MSSV;
		cout<<"\t"<<p->HO;
		cout<<" "<<p->TEN;
		cout<<"("<<p->PHAI<<")";
		cout<<"\t"<<p->PASSWORD<<endl;
		p=p->pNext;
		i++;
	}
}
void loadfiledssv(dslop &ds_lop)
{
    fstream f;
    f.open("dssv.txt",ios::in);
    string data;
    getline(f,data);
    ds_lop.SLLOP=Stoi(data);
    if(ds_lop.SLLOP<0) return;
    for(int i=0;i<ds_lop.SLLOP;i++ )
    {
    	lop *a=new lop;
        getline(f,a->MALOP);
        getline(f,a->TENLOP);
        getline(f,data);
        a->DSSV.SLSV=Stoi(data);
        if(a->DSSV.SLSV<0) break; 
        for(int j=0;j<a->DSSV.SLSV;j++)
        {
        	sv *p=new sv;
            getline(f,p->MSSV);
            getline(f,p->HO);
            getline(f,p->TEN);
            getline(f,p->PHAI);
            getline(f,p->PASSWORD);
            getline(f,data);
            p->DSDIEM.SLDIEM=Stoi(data);
            if(p->DSDIEM.SLDIEM<0) break;
            for(int k=0;k<p->DSDIEM.SLDIEM;k++)
            {
				diem *q=new diem;
                getline(f,q->MAMH);
                getline(f,data);
                q->DIEM=atof(data.c_str());
                q->pNext=p->DSDIEM.pHead;
                p->DSDIEM.pHead=q;
            }
            
            p->pNext=a->DSSV.pHead;
            a->DSSV.pHead=p;
        }
     	ds_lop.DSLOP[i]=a;
    }
    f.close();

}
void savefiledssv(dslop ds_lop)
{
    fstream f;
    f.open("dssv.txt",ios::app);
    f<<ds_lop.SLLOP<<endl;
    for(int i=0;i<ds_lop.SLLOP;i++)
    {
        f<<ds_lop.DSLOP[i]->MALOP;
        f<<ds_lop.DSLOP[i]->TENLOP;
        f<<ds_lop.DSLOP[i]->DSSV.SLSV;
        for(sv *p=ds_lop.DSLOP[i]->DSSV.pHead;p!=NULL;p=p->pNext)
        {
            f<<p->MSSV<<endl;
            f<<p->HO<<endl;
            f<<p->TEN<<endl;
            f<<p->PHAI<<endl;
            f<<p->PASSWORD<<endl;
            for(diem *q=p->DSDIEM.pHead;q!= NULL;q=q->pNext)
            {
                f<<q->MAMH<<endl;
                f<<q->DIEM<<endl;
            }
        }
    }
    f.close();
}
void inhoa(string &s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>97&&s[i]<122)
			s[i]-=32;
	}
}
void xoaktdb(string &s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<48||(s[i]>57&&s[i]<65)||(s[i]<97&&s[i]>90)||s[i]>122)
			{
				s.erase(s.begin() + i);
				i--;
			}
	}
}
void xoabangmenu()
{
	for(int i=1;i<23;i++)
		for(int j=28;j<91;j++)           
		{
			gotoxy(j,i);
			cout<<"                            ";
		}
}
void khungmenu()
{
	SetBGColor(1);
	gotoxy(0,0);
	for(int i=0;i<6;i++) cout<<"++++++++++++++++++++";
	gotoxy(0,23);
	for(int i=0;i<6;i++) cout<<"++++++++++++++++++++";
	gotoxy(0,29);
	for(int i=0;i<6;i++) cout<<"++++++++++++++++++++";
	for(int i=0;i<29;i++)
	{
		gotoxy(0,i);
		cout<<"++";
		if(i<23)
		{
			gotoxy(26,i);
			cout<<"++";
		}
		gotoxy(118,i);
		cout<<"++";
	}
	SetBGColor(0);
}
void menusv(dslop ds_lop,sv *p)
{
	khungmenu();
	gotoxy(5,2);
	cout<<"USE: "<<p->MSSV;
	int chon =1;
	int y=0;
	char a[5][50]={"","1: Thi Trac Nghiem","2: Lich Su Thi","3: Bang Diem","4: Thoat"};
	for(int i=1;i<=5;i++)
    {
    	gotoxy(5,4+y);
    	cout<<a[i];
    	y+=2;
	}
	bool b=true;
	while(b)
    {
    	gotoxy(5,4+2*(chon-1));
		SetBGColor(5);
    	cout<<a[chon];
    	SetBGColor(0);
    	switch(getch())
		{
			case 72:
			gotoxy(5,4+2*(chon-1));
    		SetBGColor(0);
    		cout<<a[chon];
			chon--;
			if(chon<1) 
			{
				chon=4;
			}
			break;
    		case 80:
	    	gotoxy(5,4+2*(chon-1));
    		SetBGColor(0);
    		cout<<a[chon];
	    	chon++;
	    	if(chon>4) 
			{
				chon=1;
			}
		    break;
			case 13:
			{
				b=false;
				break;
			}
			case 27: return;
		}
	}
	switch(chon)
    {
    
  	case 1: clrscr(); 
	  		cout<<"Thi tn";  
	  		switch(getch())
	  		{
	  			case 27:
	  				clrscr();
					menusv(ds_lop,p);
					return;
					
			}
	case 2: clrscr(); 
			cout<<"LS thi";  
			switch(getch())
	  		{
	  			case 27:
	  				clrscr();
					menusv(ds_lop,p);
					return;
					
			}
	case 3: clrscr(); 
			cout<<"Diem thi"; 
			switch(getch())
	  		{
	  			case 27:
	  				clrscr();
					menusv(ds_lop,p);
					return;
					
			}
	case 4: return;
	}
}
void menugv(dslop ds_lop)
{
	khungmenu();	
	gotoxy(5,2);
	cout<<"USE: GV";
	bool b=true;
	int chon=1;
	int y=0;
    char a[10][50]={"","1: Nhap Lop        ","2: In DS Lop        ","3: Nhap SV          ","4: Nhap MH          ",
		"5: Nhap Cau Hoi Thi ","6: Thi Trac Nghiem  ","7: LS Thi           ","8: In Bang Diem     ","9:Thoat             "};
    for(int i=1;i<=10;i++)
    {
    	gotoxy(5,4+y);
    	cout<<a[i];
    	y+=2;
	}
    while(b)
    {
    	gotoxy(5,4+2*(chon-1));
		SetBGColor(5);
    	cout<<a[chon];
    	SetBGColor(0);
    	switch(getch())
		{
			case 72:
			gotoxy(5,4+2*(chon-1));
    		SetBGColor(0);
    		cout<<a[chon];
			chon--;
			if(chon<1) 
			{
				chon=9;
			}
			break;
    		case 80:
	    	gotoxy(5,4+2*(chon-1));
    		SetBGColor(0);
    		cout<<a[chon];
	    	chon++;
	    	if(chon>9) 
			{
				chon=1;
			}
		    break;
			case 13:
			{
				b=false;
				break;
			}
			case 27: return;
		}
	}
    switch(chon)
    { 
	case 1: clrscr(); nhaplop(ds_lop); b=false; break;
	case 2: clrscr(); indslop(ds_lop);
		if(getch()==27)
		{
		 	b=false;
			break;
		}
	case 3: clrscr(); nhapsv(ds_lop); b=false; break;
	case 4: clrscr(); /*themmh(ds_mh)*/; b=false; break;
	case 5: clrscr(); /*nhapch(ds_ch);*/ b=false; break;
	case 6: clrscr(); cout<<"chon 7"; b=false; break;
	case 7: clrscr(); cout<<"chon 8"; b=false; break;
	case 8:	clrscr(); cout<<"chon 9"; b=false; break;
	case 9: return;
	}
}
void nhappass()
{
	char a[10];
	int x=0;
	while(strlen(a)<10)
	{
		x=getch();
		a[strlen(a)]=(char)x;
		cout<<x<<endl;
	}
	cout<<endl<<a;
}
void chuanhoa(string &s)
{
	strlwr((char*)s.c_str());
	if(s=="") return;
	while(s[0]==' ')
	{
		s.erase(s.begin() + 0);
	}
	while(s[s.length()-1]==' ')
	{
		s.erase(s.begin() + s.length()-1);
	}
	for(int i=0;i<s.length();i++)
	{
		if((s[i]!=' ')&&(s[i]<97||s[i]>122))
			{
				s.erase(s.begin() + i);
				i--;
			}
	}
	for(int i=0;i<s.length();i++)				
	{
		if((s[i]==' ')&&((s[i+1]==' ')))
		{
			s.erase(s.begin() + i);
			i--;
		}
	}
	s[0]-=32;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==' ') s[i+1]-=32;
	}
}
void khungdn()
{
	SetBGColor(bgmenu);
	for(int i=0;i<14;i++)
	{
		gotoxy(35,7+i);
		cout<<"                                                  ";
	}
	SetColor(15);
	gotoxy(55,8);
	cout<<"L O G I N";
	gotoxy(53,17);
	cout<<"   Dang Nhap   ";
	gotoxy(53,19);
	cout<<"     Thoat     ";
	SetBGColor(15);
	SetColor(0);
	gotoxy(40,11);
	cout<<"                                        ";
	gotoxy(40,12);
	cout<<"MSSV:                                   ";
	gotoxy(40,14);
	cout<<"                                        ";
	gotoxy(40,15);
	cout<<"PASS:                                   ";
	SetBGColor(0);
	SetColor(15);
}
string ktradn(dslop ds_lop,string mssv,string pass,sv* &q)
{
	if(((mssv=="GV")||(mssv=="gv"))&&((pass=="GV")||(pass=="gv"))) 
	{
		return "GV";
	}
	else 
	{
		for(int i=0;i<ds_lop.SLLOP;i++)
		{
			for(sv *p=ds_lop.DSLOP[i]->DSSV.pHead;p!=NULL;p=p->pNext)
			{
				if((p->MSSV==mssv)&&(p->PASSWORD==pass))
				{
					q=p;
					return "SV";	
				}
			}
			return "";
		}
	}
}
void dangnhap(dslop ds_lop)
{
	sv *p=new sv;
	khungdn();
	int chon=1;
	bool b;
	string mssv,password;
	gotoxy(48,12);
	fflush(stdin);
	SetColor(0);
	SetBGColor(15);
	getline(cin,mssv);
	xoaktdb(mssv);
	inhoa(mssv);
	gotoxy(48,12);
	cout<<"                    ";
	gotoxy(48,12);
	cout<<mssv;
	SetColor(15);
	SetBGColor(0);
	gotoxy(48,15);
	fflush(stdin);
	SetColor(0);
	SetBGColor(15);
	getline(cin,password);
	xoaktdb(password);
	gotoxy(48,15);
	cout<<"                    ";
	gotoxy(48,15);
	cout<<password;
	SetColor(15);
	SetBGColor(0);
	while(1)
	{
		switch(chon)
		{
			case 1:
				SetBGColor(10);
				SetColor(15);
				gotoxy(53,17);
				cout<<"   Dang Nhap   ";
				SetBGColor(bgmenu);
				SetColor(15);
				gotoxy(53,19);
				cout<<"     Thoat     ";
				break;
			case 2:
				SetBGColor(bgmenu);
				SetColor(15);
				gotoxy(53,17);
				cout<<"   Dang Nhap   ";
				SetBGColor(10);
				SetColor(15);
				gotoxy(53,19);
				cout<<"     Thoat     ";
				break;
		}
		SetColor(15);
		SetBGColor(0);
		switch(getch())
		{
			case 72:
				if(chon==1) chon=2;
				else chon=1;
				break;
			
			case 80:
				if(chon==2) chon=1;
				else chon=2;
				break;	
			case 13:
				if(chon==2) 
				{
					return;
				}
				
				if(ktradn(ds_lop,mssv,password,p)=="GV")
				{
					clrscr();				
					menugv(ds_lop);
					return;
				}
				else if(ktradn(ds_lop,mssv,password,p)=="SV")
				{
					clrscr();	
					menusv(ds_lop,p);
					return;
				}
				else
				{
					cout<<"LOI";
					clrscr();	
					dangnhap(ds_lop);
					break;
				}
				break;
		}
	}
}




