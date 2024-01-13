#ifndef LIB_DATA_H
#define LIB_DATA_H

#include<bits/stdc++.h>
#include "LinkedList.h"
#include "Node.h"
#include "AVLTree.h"
using namespace std;

struct Date{
	int dd;
	int mm;
	int yy;
};

struct ViTri{
	int day;
	int hang;
	int ngan;
};

struct CuonSach{
	string maDauSach;
	string maCuon;
	ViTri viTri;
	bool tinhTrang;//1 da muon 0 la con
//	 ngay muon va han tra chi duoc su dung khi cuon sach co nguoi muon
	string maDG;
	Date ngayMuon;
	Date hanTra;
	Date ngayTra;
	int compareMaCS(CuonSach x, CuonSach y)
	{
		int cntx=0,cnty=0;
		for(int i=3; i<x.maCuon.length(); i++)
		{
			cntx = cntx*10 + (x.maCuon[i]-'0');
		}
		for(int j=3; j<y.maCuon.length(); j++)
		{
			cnty = cnty*10 + (y.maCuon[j]-'0');
		}
		
		if(cntx > cnty)
			return 1;
		else if(cntx < cnty)
				return -1;
			else 
				return 0;
	}
	
	int compareMC(string x, string y)
	{
		int cntx=0,cnty=0;
		for(int i=3; i<x.length(); i++)
		{
			cntx = cntx*10 + (x[i]-'0');
		}
		for(int j=3; j<y.length(); j++)
		{
			cnty = cnty*10 + (y[j]-'0');
		}
		
		if(cntx > cnty)
			return 1;
		else if(cntx < cnty)
				return -1;
			else
				return 0;	
	}
};

struct DauSach{
	string maDauSach;
	string tenSach;
	string theLoai;
	string tenTacGia;
	int namXB;
	string NXB;
	int soLuongCuon;
	LinkedList<CuonSach> listCuonSach;
	bool same (DauSach x, DauSach y)
	{
	 	if(x.tenSach.compare(y.tenSach)==0 && x.theLoai.compare(y.theLoai)==0 &&
			x.tenTacGia.compare(y.tenTacGia)==0 && (x.namXB == y.namXB) && x.NXB.compare(y.NXB)==0)
			{
				return true;
			}
		return false;
	}
	int compareTenSach(DauSach x, DauSach y)
	{
		return (x.tenSach.compare(y.tenSach));		
	}
	
	int compareMaDS(DauSach x, DauSach y)
	{
		int cntx=0,cnty=0;
		for(int i=3; i<x.maDauSach.length(); i++)
		{
			cntx = cntx*10 + (x.maDauSach[i]-'0');
		}
		for(int j=3; j<y.maDauSach.length(); j++)
		{
			cnty = cnty*10 + (y.maDauSach[j]-'0');
		}
		
		if(cntx > cnty)
			return 1;
		else if(cntx < cnty)
				return -1;
			else
				return 0;		
	}
	
		
	int compareDS(string x, string y)
	{
		int cntx=0,cnty=0;
		for(int i=3; i<x.length(); i++)
		{
			cntx = cntx*10 + (x[i]-'0');
		}
		for(int j=3; j<y.length(); j++)
		{
			cnty = cnty*10 + (y[j]-'0');
		}
		
		if(cntx > cnty)
			return 1;
		else if(cntx < cnty)
				return -1;
			else
				return 0;		
	}
};

struct DocGia{
	string maDG;
	string tenDG;
	string SDT;
	int soSachDaMuon;
	LinkedList<CuonSach> listMuon;
	int compareMaDG(DocGia x, DocGia y)
	{
		int cntx=0,cnty=0;
		for(int i=2; i<x.maDG.length(); i++)
		{
			cntx = cntx*10 + (x.maDG[i]-'0');
		}
		for(int j=2; j<y.maDG.length(); j++)
		{
			cnty = cnty*10 + (y.maDG[j]-'0');
		}
		
		if(cntx > cnty)
			return 1;
		else if(cntx < cnty)
				return -1;
			else
				return 0;
	}		
	
	int compareStringMaDG(string x, string y)
	{
		int cntx=0,cnty=0;
		for(int i=2; i<x.length(); i++)
		{
			cntx = cntx*10 + (x[i]-'0');
		}
		for(int j=2; j<y.length(); j++)
		{
			cnty = cnty*10 + (y[j]-'0');
		}
		
		if(cntx > cnty)
			return 1;
		else if(cntx < cnty)
				return -1;	
			else 
				return 0;	
	}
	int compareName(DocGia x, DocGia y)
	{
	 	return (x.tenDG.compare(y.tenDG));		
	}
	
	int compareSLSach(DocGia x, DocGia y)
	{
		if(x.soSachDaMuon > y.soSachDaMuon)
			return 1;
		else
			return 0;
	}
};

void docDuLieu1CuonSach(CuonSach &cs, fstream &input);
void docDuLieu1SachMuon(CuonSach &cs, fstream &input);
void docDuLieu1SachDaMuon(CuonSach& cs, fstream& input);

class DuLieuThuVien{
	public:
		void docFileLSMuon(AVLTree<DocGia> *&root);
		void docFileLSMuonLinkedList(LinkedList<DocGia> &lst);
		void docFileDauSach(LinkedList<DauSach>& lst);
		void docFileDocGia(LinkedList<DocGia>& lst);
		void chenVaoCayTheoMaDG(AVLTree<DocGia> *&root);
		void chenVaoCayTheoTen(AVLTree<DocGia> *&root);
		void chenVaoCayTheoSLCuon(AVLTree<DocGia> *&root);
		void chenVaoCayTheoMaCS(AVLTree<DocGia> *&rootdg, AVLTree<CuonSach> *&rootcs);
		void chenDauSachVaoCayTheoMaDS(AVLTree<DauSach> *&root);
		void chenVaoCayTheoTenSach(AVLTree<DauSach> *&root);
};

void DuLieuThuVien::docFileLSMuonLinkedList(LinkedList<DocGia> &lst)
{
	fstream input("LichSuMuon.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file!";
	}
	else
	{
		while(!input.eof())
		{
			DocGia dg;
			string tmp;
			getline(input, dg.maDG);
			getline(input, dg.tenDG);
			getline(input, dg.SDT);
			input >> dg.soSachDaMuon;
			getline(input, tmp);
			if(input.eof())
			{
				break;
			}
			for(int i=0 ; i<dg.soSachDaMuon; i++)
			{
				CuonSach cs;
				docDuLieu1SachDaMuon(cs, input);
				dg.listMuon.addHead(cs);		
			}	
			lst.addHead(dg);
		}
		input.close();
	}
}

void DuLieuThuVien::chenVaoCayTheoTenSach(AVLTree<DauSach> *&root)
{
	fstream input("DauSach.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file";
	}
	else
	{
		while(!input.eof())
		{
			DauSach ds;
			string tmp;
			getline(input, ds.maDauSach);
			getline(input, ds.tenSach);
			getline(input, ds.theLoai);
			getline(input, ds.tenTacGia);
			input >> ds.namXB;
			getline(input, tmp);
			getline(input, ds.NXB);
			input >> ds.soLuongCuon;
			getline(input, tmp);
			if(input.eof())
				break;
			for(int i=0; i<ds.soLuongCuon; i++)
			{
				CuonSach cs;
				cs.maDauSach = ds.maDauSach;
				docDuLieu1CuonSach(cs, input);
				ds.listCuonSach.addHead(cs);
			}
			root = root->insertByTenSach(root, ds);
		}
		input.close();
	}
}

void DuLieuThuVien::chenDauSachVaoCayTheoMaDS(AVLTree<DauSach> *&root)
{
	fstream input("DauSach.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file";
	}
	else
	{
		while(!input.eof())
		{
			DauSach ds;
			string tmp;
			getline(input, ds.maDauSach);
			getline(input, ds.tenSach);
			getline(input, ds.theLoai);
			getline(input, ds.tenTacGia);
			input >> ds.namXB;
			getline(input, tmp);
			getline(input, ds.NXB);
			input >> ds.soLuongCuon;
			getline(input, tmp);
			if(input.eof())
				break;
			for(int i=0; i<ds.soLuongCuon; i++)
			{
				CuonSach cs;
				cs.maDauSach = ds.maDauSach;
				docDuLieu1CuonSach(cs, input);
				ds.listCuonSach.addHead(cs);
			}
			root = root->insertByMaDS(root, ds);
		}
		input.close();
	}	
}

void DuLieuThuVien::docFileLSMuon(AVLTree<DocGia> *&root)
{
	fstream input("LichSuMuon.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file!";
	}
	else
	{
		while(!input.eof())
		{
			DocGia dg;
			string tmp;
			getline(input, dg.maDG);
			getline(input, dg.tenDG);
			getline(input, dg.SDT);
			input >> dg.soSachDaMuon;
			getline(input, tmp);
			if(input.eof())
			{
				break;
			}
			for(int i=0 ; i<dg.soSachDaMuon; i++)
			{
				CuonSach cs;
				docDuLieu1SachDaMuon(cs, input);
				dg.listMuon.addHead(cs);		
			}	
			root = root->insertByMaDG(root, dg);
		}
		input.close();
	}	
}

void docDuLieu1SachDaMuon(CuonSach& cs, fstream& input)
{
	string tmp;
	string ngay = "Ngay ";
	string muon= "Muon: ";
	string han = "Han ";
	string tra = "Tra: ";
	char slash = '/';
	getline(input, cs.maCuon);
	input >> ngay >> muon >> cs.ngayMuon.dd >> slash >> cs.ngayMuon.mm >> slash >> cs.ngayMuon.yy;
	getline(input, tmp);
	input >> han >> tra >> cs.hanTra.dd >> slash >> cs.hanTra.mm >> slash >> cs.hanTra.yy;
	getline(input, tmp);
	input >> ngay >> tra >> cs.ngayTra.dd >> slash >> cs.ngayTra.mm >> slash >> cs.ngayTra.yy;
	getline(input, tmp);	
}

void DuLieuThuVien::docFileDauSach(LinkedList<DauSach>& lst)
{
	fstream input("DauSach.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file";
	}
	else
	{
		while(!input.eof())
		{
			DauSach ds;
			string tmp;
			getline(input, ds.maDauSach);
			getline(input, ds.tenSach);
			getline(input, ds.theLoai);
			getline(input, ds.tenTacGia);
			input >> ds.namXB;
			getline(input, tmp);
			getline(input, ds.NXB);
			input >> ds.soLuongCuon;
			getline(input, tmp);
			if(input.eof())
				break;
			for(int i=0; i<ds.soLuongCuon; i++)
			{
				CuonSach cs;
				cs.maDauSach = ds.maDauSach;
				docDuLieu1CuonSach(cs, input);
				ds.listCuonSach.addHead(cs);
			}
			lst.addHead(ds);
		}
		input.close();
	}
}

void docDuLieu1CuonSach(CuonSach& cs, fstream& input)
{
	string tmp;
	string day = "DAY ";
	string hang = " HANG ";
	string ngan = " NGAN ";
	char colon = ',';
	input >> cs.maCuon;
	input >> day >> cs.viTri.day >> colon >> hang >> cs.viTri.hang >> colon >> ngan >> cs.viTri.ngan;
	input >> cs.tinhTrang;
	getline(input, tmp);
}

void DuLieuThuVien::docFileDocGia(LinkedList<DocGia>& lst)
{
	fstream input("DocGia.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file";
	}
	else
	{
		while(!input.eof())
		{
			DocGia dg;
			string tmp;
			getline(input, dg.maDG);
			getline(input, dg.tenDG);
			getline(input, dg.SDT);
			input >> dg.soSachDaMuon;
			getline(input, tmp);
			if(input.eof())
			{
				break;
			}
			for(int i=0 ; i<dg.soSachDaMuon; i++)
			{
				CuonSach cs;
				docDuLieu1SachMuon(cs, input);
				dg.listMuon.addHead(cs);		
			}	
			lst.addHead(dg);
		}
		input.close();
	}	
}

void DuLieuThuVien::chenVaoCayTheoMaDG(AVLTree<DocGia> *&root)
{
	fstream input("DocGia.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file";
	}
	else
	{
		while(!input.eof())
		{
			DocGia dg;
			string tmp;
			getline(input, dg.maDG);
			getline(input, dg.tenDG);
			getline(input, dg.SDT);
			input >> dg.soSachDaMuon;
			getline(input, tmp);
			if(input.eof())
			{
				break;
			}
			for(int i=0 ; i<dg.soSachDaMuon; i++)
			{
				CuonSach cs;
				docDuLieu1SachMuon(cs, input);
				dg.listMuon.addHead(cs);		
			}	
			root = root->insertByMaDG(root, dg);
		}
		input.close();
	}
}

void DuLieuThuVien::chenVaoCayTheoTen(AVLTree<DocGia> *&root)
{
	fstream input("DocGia.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file";
	}
	else
	{
		while(!input.eof())
		{
			DocGia dg;
			string tmp;
			getline(input, dg.maDG);
			getline(input, dg.tenDG);
			getline(input, dg.SDT);
			input >> dg.soSachDaMuon;
			getline(input, tmp);
			if(input.eof())
			{
				break;
			}
			for(int i=0 ; i<dg.soSachDaMuon; i++)
			{
				CuonSach cs;
				docDuLieu1SachMuon(cs, input);
				dg.listMuon.addHead(cs);		
			}	
			root = root->insertByName(root, dg);
		}
		input.close();
	}
}

void DuLieuThuVien::chenVaoCayTheoSLCuon(AVLTree<DocGia> *&root)
{
	fstream input("DocGia.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file";
	}
	else
	{
		while(!input.eof())
		{
			DocGia dg;
			string tmp;
			getline(input, dg.maDG);
			getline(input, dg.tenDG);
			getline(input, dg.SDT);
			input >> dg.soSachDaMuon;
			getline(input, tmp);
			if(input.eof())
			{
				break;
			}
			for(int i=0 ; i<dg.soSachDaMuon; i++)
			{
				CuonSach cs;
				docDuLieu1SachMuon(cs, input);
				dg.listMuon.addHead(cs);		
			}
			root = root->insertBySLSach(root, dg);	
		}
		input.close();
	}
}

void DuLieuThuVien::chenVaoCayTheoMaCS(AVLTree<DocGia> *&rootdg, AVLTree<CuonSach> *&rootcs)
{
	fstream input("DocGia.txt", ios::in);
	if(input.fail())
	{
		cout <<"Khong the mo file";
	}
	else
	{
		while(!input.eof())
		{
			DocGia dg;
			string tmp;
			getline(input, dg.maDG);
			getline(input, dg.tenDG);
			getline(input, dg.SDT);
			input >> dg.soSachDaMuon;
			getline(input, tmp);
			if(input.eof())
			{
				break;
			}
			for(int i=0 ; i<dg.soSachDaMuon; i++)
			{
				CuonSach cs;
				docDuLieu1SachMuon(cs, input);
				dg.listMuon.addHead(cs);
				rootcs = rootcs->insertByMaCS(rootcs, cs);		
			}
			rootdg = rootdg->insertBySLSach(rootdg, dg);	
		}
		input.close();
	}
}


void docDuLieu1SachMuon(CuonSach& cs, fstream& input)
{
	string tmp;
	string ngay = "Ngay ";
	string muon= "Muon: ";
	string han = "Han ";
	string tra = "Tra: ";
	char slash = '/';
	getline(input, cs.maCuon);
	input >> ngay >> muon >> cs.ngayMuon.dd >> slash >> cs.ngayMuon.mm >> slash >> cs.ngayMuon.yy;
	getline(input, tmp);
	input >> han >> tra >> cs.hanTra.dd >> slash >> cs.hanTra.mm >> slash >> cs.hanTra.yy;
	getline(input, tmp);	
}

#endif 
