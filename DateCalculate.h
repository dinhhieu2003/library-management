#ifndef DATE_CALCULATE_H
#define DATE_CALCULATE_H

#include<bits/stdc++.h>

using namespace std;

class DateCalculate{
	public:
		int d, m, y;
		DateCaculate(int dd, int mm, int yy)
		{
			d = dd;
			m = mm;
			y = yy;
		}
		int tinhSoNgayTrongThang (int m , int y);											
		int tinhSTTNgay(int d, int m, int y);
		bool kiemTraNamNhuan(int y);
		int tinhSoNgayTuNam1(int d, int m, int y);
		int soSanhNgay(int d1, int m1, int y1, int d2, int m2, int y2);
};

int DateCalculate::tinhSoNgayTrongThang(int m, int y)
{
	if(m==2)
	{
		if(kiemTraNamNhuan(y)==true)
			return 29;
		else
			return 28;
	}
	else 
	{
		if (m==4 || m==6 || m==9 || m==11)
			return 30;
		else	
			return 31;
	}
}

int DateCalculate::tinhSTTNgay(int d, int m, int y)
{
	int sTT = 0;
	for (int i = 1 ; i < m ; i++)
	{
		sTT += tinhSoNgayTrongThang (i , y) ;
	}
	sTT += d ;
	return sTT;
}

bool DateCalculate::kiemTraNamNhuan(int y)
{
	if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
	  return true;
	else 
	   return false;
}

int DateCalculate::tinhSoNgayTuNam1(int d, int m, int y)
{
	int soNgay = 0 ;
	for(int i = 1 ; i < y ; i++)
	{
		soNgay += 365 ;
		if(kiemTraNamNhuan(i)==true)
			soNgay++ ;
	}
	soNgay += tinhSTTNgay(d, m, y);
	return soNgay ;
}

int DateCalculate::soSanhNgay(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int ngay1 = tinhSoNgayTuNam1(d1, m1, y1);
	int ngay2 = tinhSoNgayTuNam1(d2, m2, y2);
	if(ngay1 > ngay2)
		return 1;
	if(ngay1 == ngay2)
		return 0;
	if(ngay1 < ngay2)
		return -1;
}

#endif
