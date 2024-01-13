#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_set>
#include "LinkedList.h"
#include "DuLieuThuVien.h"
#include "Node.h"
#include "ThaoTacDauSach.h"
#include "ThaoTacDocGia.h"
#include "HashTable.h"
#define SIZE_DS 500
#define SIZE_CS 1000
#define SIZE_STRING_HASH 10000

using namespace std;

DuLieuThuVien data;
LinkedList<DauSach> originalLst;
LinkedList<Node<DauSach>*> saveLst;
LinkedList<Node<DauSach>*> oldLst;

void menu();
void menuTimKiemDauSach(int& op, ThaoTacDauSach& tt);
void menuThemDauSach(ThaoTacDauSach& tt);
void menuXoaDauSach(int& op, ThaoTacDauSach& tt);
void menuLocDauSach(int& op, ThaoTacDauSach tt);
void menuSapXepDauSach(int& op, ThaoTacDauSach tt);
void menuDauSach();
void menuDocGia();
void member();
string danhSachTenNXB();
string danhSachTenTheLoai();
string danhSachTenTG();
string danhSachTenSach();

int main()
{
	member();
	system("pause");
	system("cls");
	menu();
	return 0;
}

void member()
{
	cout <<"\t\t\t\t\t      NHOM: 11" << endl;
	cout <<"\t\t\t\t\t DE TAI: QUAN LY THU VIEN" << endl;
	cout <<"\t\t\t\t\t  THANH VIEN THUC HIEN" << endl;
	cout <<"\t\t\t\t+===+================+=========+============+" << endl;
	cout <<"\t\t\t\t|";
	cout << setw(3) << "STT" << left << setw(17) << "|   HO VA TEN" << left << setw(10) << "|  MSSV" << right << setw(1) <<"|" 
			<< left << setw(12) << " HOAN THANH " << right << setw(1) << "|" << endl;
	cout <<"\t\t\t\t+===+================+=========+============+" << endl;
	cout <<"\t\t\t\t|";
	cout << setw(3) <<" 1 " << left << setw(17) << "|Vuong Dinh Hieu" << left << setw(10) << "|21110181" << right << setw(1) <<"|"
		<< left << setw(12) << "    100%    " << right << setw(1) << "|" << endl;
	cout <<"\t\t\t\t+===+================+=========+============+" << endl;
	cout <<"\t\t\t\t|";
	cout << setw(3) <<" 2 " << left << setw(17) << "|Nguyen Van Hao" << left << setw(10) << "|21110175" << right << setw(1) <<"|"
		<< left << setw(12) << "    100%    " << right << setw(1) << "|" << endl;
	cout <<"\t\t\t\t+===+================+=========+============+" << endl;
}

void menu()
{
	data.docFileDauSach(originalLst);
	originalLst.saveNode(saveLst);
	srand((unsigned)time(NULL));
	int op;
    do{
	    cout<<"\n               			QUAN LY THU VIEN          		   ";
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n     |               NHAN PHIM 1: THAO TAC DAU SACH                        |";              
	    cout<<"\n     +=====================================================================+";
	    
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n     |                NHAN PHIM 2: THAO TAC DOC GIA                        |";              
	    cout<<"\n     +=====================================================================+";
	    
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n     |                NHAN PHIM 0 DE THOAT CHUONG TRINH                    |";              
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n                      NHAN PHIM DE THUC HIEN THAO TAC: ";
    	cin >> op;
    	system("cls");
    	switch(op)
    	{
    		case 1:{
    			menuDauSach();
    			break;
    		}
    		
    		case 2:{
    			menuDocGia();
				break;
			}
		}
	}while(op!=0);
}

void menuDocGia()
{
	int op;
	do
	{
		DuLieuThuVien sour;
		LinkedList<DocGia> lst;
		LinkedList<DocGia> lichSu;
		AVLTree<DocGia> *root=NULL;
		ThaoTacDocGia ttdg;
		cout<<"\n+===================THAO TAC DOC GIA===========================+";
		cout<<"\n|1. Them doc gia moi                                           |";
		cout<<"\n|2. Xem danh sach doc gia                                      |";
		cout<<"\n|3. Xem danh sach doc gia da dang ky                           |";
		cout<<"\n|4. Xem danh sach doc gia da muon sach                         |";
		cout<<"\n|5. Tim kiem thong tin doc gia theo ma doc gia                 |";
		cout<<"\n|6. Xoa doc gia khoi danh sach dang ky                         |";
		cout<<"\n|7. Cap nhat them sach muon cho doc gia                        |";
		cout<<"\n|8. Cap nhat tra sach muon cho doc gia                         |";
		cout<<"\n|9. Xem thong tin toan bo doc gia                              |";
		cout<<"\n|10. Xem danh sach doc gia da muon qua han                     |";
		cout<<"\n|11. Xem danh sach doc gia muon trong khoang thoi gian cu the  |";
		cout<<"\n|12. Xem danh sach doc gia tra trong khoang thoi gian cu the   |";
		cout<<"\n|13. Xem lich su muon cua toan bo doc gia                      |";
		cout<<"\n|14. Xem lich su muon cua mot doc gia                          |";
		cout<<"\n|15. Sua doi thong tin doc gia                                 |";
		cout<<"\n|0. Thuc hien thao tac khac                                    |";
		cout<<"\n+==============================================================+";
		cout<<"\nXin moi nhap lua chon: ";
		cin>>op;
		system("cls");
		switch(op)
		{
			case 0:{
				break;
			}
			case 1:
				{		
					sour.docFileDocGia(lst);
					ttdg.themDocGiaMoi(lst);
					break;
				}
			case 2:
				{
					sour.chenVaoCayTheoMaDG(root);
					ttdg.xemDocGiaTheoMaDG(root);			
					break;
				}
			case 3:
				{
					sour.chenVaoCayTheoTen(root);
					ttdg.xemDocGiaTheoTen(root);
					break;
				}
			case 4:
				{
					sour.chenVaoCayTheoSLCuon(root);
					ttdg.xemDocGiaDaMuonSach(root);
					break;
				}
			case 5:
				{
					sour.chenVaoCayTheoMaDG(root);
					ttdg.timKiemTheoMaDG(root);
					break;
				}
			case 6:
				{
					string s;
					sour.chenVaoCayTheoMaDG(root);
					ttdg.xoaTheoMaDG(root);
					break;
				}
			case 7:
				{	
					ThaoTacDauSach tt;
					AVLTree<DocGia> *rootDG = NULL;
					AVLTree<Node<CuonSach>*> *rootCS = NULL;
					sour.chenVaoCayTheoMaDG(rootDG);
					rootCS = tt.insertCSIntoTree(originalLst);
					AVLTree<DocGia> *rootlsm= NULL;
					sour.docFileLSMuon(rootlsm);
					cout << "Nhap ma doc gia: ";
					string maDG;
					cin >> maDG;
					cout <<"So luong sach muon: ";
					int soLuong;
					cin >> soLuong;
					ttdg.capNhatThongTinMuonSach(rootCS, rootDG, rootlsm, maDG, soLuong);
					tt.capNhatFile(originalLst);
					break;
				}
			case 8:
				{
					sour.chenVaoCayTheoMaDG(root);
					AVLTree<DauSach> *rootds = NULL;
					sour.chenDauSachVaoCayTheoMaDS(rootds);
					AVLTree<DocGia> *rootlsm= NULL;
					sour.docFileLSMuon(rootlsm);
					ttdg.capNhatThongTinTraSach(root, rootds, rootlsm);
					break;
				}	
			case 9:
				{
					sour.docFileDocGia(lst);
					ttdg.xemThongTin(lst);
					break;
				}
			case 10:
				{
					AVLTree<DocGia> *rootls = NULL;				
					sour.docFileLSMuon(rootls);
					ttdg.xemDocGiaMuonQuaHan(rootls);
					break;
				}
			case 11:
				{
					AVLTree<DocGia> *rootls= NULL;
					sour.docFileLSMuon(rootls);
					ttdg.xemDocGiaMuonThoiGianCuThe(rootls);
					break;
				}
			case 12:
				{
					AVLTree<DocGia> *rootls = NULL;
					sour.docFileLSMuon(rootls);
					ttdg.xemDocGiaTraThoiGianCuThe(rootls);
					break;
				}
			case 13:
				{
					sour.docFileLSMuonLinkedList(lichSu);
					ttdg.xemThongTin(lichSu);
					lichSu.deleteLinkedList();
					break;
				}
				
			case 14:
				{
					AVLTree<DocGia> *rootlsm = NULL;
					sour.docFileLSMuon(rootlsm);
					cout <<"Nhap ma doc gia: ";
					string maDG;
					cin >> maDG;
					AVLTree<DocGia> *ans = ttdg.timKiemGiaTriTheoMaDG(rootlsm, maDG);
					cout << "\n========================================================THONG TIN DOC GIA========================================================\n\n";
					cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
					cout << left << setw(16) << "|   Ma Doc Gia" << left << setw(23) <<"|    Ten Doc Gia" << left << setw(19) <<"|  So Dien Thoai" <<
					left << setw(19) << "| So Luong Cuon Muon" << left
				         << setw(16)<< "| Ma Cuon Sach" << left << setw(22) << "|   Ngay Muon-Han Tra  "  << left << setw(11)
				         << "| Ngay Tra" << right << setw(1) << "|" << endl;
				    cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;		
					ttdg.xuatThongTinDocGia(ans);
					break;
				}
			case 15:
				{
					sour.chenVaoCayTheoMaDG(root);
					AVLTree<DocGia> *rootlsm = NULL;
					sour.docFileLSMuon(rootlsm);
					ttdg.suaThongTinDocGia(root, rootlsm);
					break;
				}
		}		
	}while(op!=0);
}

void menuDauSach()
{
	int op1;
	ThaoTacDauSach tt;
	do{
		//cout <<"\n*****************************************************************************";
	    cout<<"\n               			THAO TAC DAU SACH          		   ";
	    
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n     |                NHAN PHIM 1: THEM DAU SACH MOI                       |";              
	    cout<<"\n     +=====================================================================+";
	    
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n     |                NHAN PHIM 2: XOA DAU SACH                            |";              
	    cout<<"\n     +=====================================================================+";
	    
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n     |                NHAN PHIM 3: TIM KIEM DAU SACH                       |";              
	    cout<<"\n     +=====================================================================+";
	     
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n     |                NHAN PHIM 4: SAP XEP DAU SACH                        |";              
	    cout<<"\n     +=====================================================================+";
	    
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n     |                NHAN PHIM 5: IN DANH SACH                            |";              
	    cout<<"\n     +=====================================================================+";
	    
		cout<<"\n     +=====================================================================+";
	    cout<<"\n     |                NHAN PHIM 0: THUC HIEN THAO TAC KHAC                 |";              
	    cout<<"\n     +=====================================================================+";
	    cout<<"\n                      NHAN PHIM DE THUC HIEN THAO TAC: ";
	    cin >> op1;
	    system("cls");
	    switch(op1)
	    {
	    	case 1:{
	    		menuThemDauSach(tt);
				break;
			}
			
			case 2:{
				int op2;
				do{
					menuXoaDauSach(op2, tt);
				}while(op2!=0);
				break;
			}
			
			case 3:{
				int op3;
				do{
					menuTimKiemDauSach(op3, tt);
				}while(op3!=0);
				break;
			}
			
			case 4:{
				int op4;
				do{
					menuSapXepDauSach(op4, tt);
				}while(op4!=0);
				break;
			}
			
			case 5:{
				tt.printDSList(originalLst);
				break;
			}
		}
	}while(op1!=0);
}

string danhSachTenNXB()
{
	unordered_set<string> NXB;
	vector<string> indexNXB;
	Node<DauSach> *tmp = originalLst.head;
	while(tmp != NULL)
	{
		NXB.insert(tmp->data.NXB);
		tmp = tmp->next;
	}
	for(auto item : NXB)
	{
		indexNXB.push_back(item);
	}
	cout<<"\n               		   	DANH SACH CAC NXB          		             ";
    for(int i=0; i<indexNXB.size(); i++)
    {
    	cout<<"\n     +---------------------------------------------------------------------+";
    	cout<<"\n     |" << left << setw(2) << i << setw(2) <<". " << left << setw(30) << indexNXB[i] << right << setw(36) <<"|";
	}
	cout<<"\n     +---------------------------------------------------------------------+" << endl;
	int op;
	cout <<"Nhap lua chon cua ban (nhap so): ";
	cin >> op;
	return indexNXB[op];
}

string danhSachTenTheLoai()
{
	unordered_set<string> theLoai;
	vector<string> indexTheLoai;
	Node<DauSach> *tmp = originalLst.head;
	while(tmp != NULL)
	{
		theLoai.insert(tmp->data.theLoai);
		tmp = tmp->next;
	}
	for(auto item : theLoai)
	{
		indexTheLoai.push_back(item);
	}
	cout<<"\n               		  DANH SACH CAC THE LOAI          		       ";
    for(int i=0; i<indexTheLoai.size(); i++)
    {
    	cout<<"\n     +---------------------------------------------------------------------+";
    	cout<<"\n     |" << left << setw(2) << i << setw(2) <<". " << left << setw(30) << indexTheLoai[i] << right << setw(36) <<"|";
	}
	cout<<"\n     +---------------------------------------------------------------------+" << endl;
	int op;
	cout <<"Nhap lua chon cua ban (nhap so): ";
	cin >> op;
	return indexTheLoai[op];
}

string danhSachTenTG()
{
	unordered_set<string> tacGia;
	vector<string> indexTG;
	Node<DauSach> *tmp = originalLst.head;
	while(tmp != NULL)
	{
		tacGia.insert(tmp->data.tenTacGia);
		tmp = tmp->next;
	}
	for(auto item : tacGia)
	{
		indexTG.push_back(item);
	}
	cout<<"\n               		  DANH SACH TEN TAC GIA          		       ";
    for(int i=0; i<indexTG.size(); i++)
    {
    	cout<<"\n     +---------------------------------------------------------------------+";
    	cout<<"\n     |" << left << setw(2) << i << setw(2) <<". " << left << setw(30) << indexTG[i] << right << setw(36) <<"|";
	}
	cout<<"\n     +---------------------------------------------------------------------+" << endl;
	int op;
	cout <<"Nhap lua chon cua ban (nhap so): ";
	cin >> op;
	return indexTG[op];
}

string danhSachTenSach()
{
	unordered_set<string> tenSach;
	vector<string> indexTenSach;
	Node<DauSach> *tmp = originalLst.head;
	while(tmp != NULL)
	{
		tenSach.insert(tmp->data.tenSach);
		tmp = tmp->next;
	}
	for(auto item : tenSach)
	{
		indexTenSach.push_back(item);
	}
	cout<<"\n               		  DANH SACH TEN SACH          		       ";
    for(int i=0; i<indexTenSach.size(); i++)
    {
    	cout<<"\n     +---------------------------------------------------------------------+";
    	cout<<"\n     |" << left << setw(2) << i << setw(2) <<". " << left << setw(30) << indexTenSach[i] << right << setw(36) <<"|";
	}
	cout<<"\n     +---------------------------------------------------------------------+" << endl;
	int op;
	cout <<"Nhap lua chon cua ban (nhap so): ";
	cin >> op;
	return indexTenSach[op];
}

void menuTimKiemDauSach(int& op, ThaoTacDauSach& tt)
{
    cout<<"\n               		   TIM KIEM DAU SACH          		   ";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 1: TIM THEO MA DAU SACH                    |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 2: TIM THEO TEN NXB                        |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 3: TIM THEO THE LOAI                       |";              
    cout<<"\n     +=====================================================================+";
     
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 4: TIM THEO TEN TAC GIA                    |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 5: TIM THEO TEN SACH                       |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
	cout<<"\n     |                NHAN PHIM 6: IN DANH SACH BAN DAU                    |";              
	cout<<"\n     +=====================================================================+";
    
	cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 0: THUC HIEN THAO TAC KHAC                 |";              
    cout<<"\n     +=====================================================================+";
    cout<<"\n                   NHAN PHIM DE THUC HIEN THAO TAC: ";

	cin >> op;
	switch(op)
	{
		case 1:{
			string maDauSach;
			cout <<"Nhap ma dau sach: ";
			cin >> maDauSach;
			Node<DauSach>* ans = tt.timKiemTheoMaDauSach(originalLst, maDauSach);
			if(ans==NULL)
			{
				cout << "Khong co MA DAU SACH nay trong thu vien!!"<< endl;
			}
			else
			{
				tt.print1DS(ans);
			}
			break;
		}
		
		case 2:{
			
			int exOp;
			string tenNXB;
			LinkedList<Node<DauSach>*> theoTenNXB;
			tenNXB = danhSachTenNXB();
			timKiemMoi2:
			cout <<"1. Tim kiem moi - Danh sach tim kiem cu se bi mat di!" << endl;
			cout <<"2. Tim kiem tiep tu danh sach tim kiem cu" << endl;
			cout <<"Nhap lua chon cua ban: ";
			cin >> exOp;
			switch(exOp)
			{
				case 1:{
					tt.timKiemTheoTenNXB(saveLst, theoTenNXB, tenNXB);
					break;
				}
				case 2:{
					if(oldLst.head==NULL)
					{
						cout <<"KHONG TIM THAY DANH SACH CU NAO - VUI LONG BAM PHIM 1 DE  TIM KIEM MOI" << endl;
						goto timKiemMoi2;
						break;
					}
					tt.timKiemTheoTenNXB(oldLst, theoTenNXB, tenNXB);
					break;
				}
			}
			oldLst.head = theoTenNXB.head;
			tt.printNodeDSList(theoTenNXB);
			break;
		}
		
		case 3:{
			int exOp;
			string tenTheLoai;
			LinkedList<Node<DauSach>*> theoTheLoai;
			tenTheLoai = danhSachTenTheLoai();
			timKiemMoi3:
			cout <<"1. Tim kiem moi - Danh sach tim kiem cu se bi mat di!" << endl;
			cout <<"2. Tim kiem tiep tu danh sach tim kiem cu" << endl;
			cout <<"Nhap lua chon cua ban: ";
			cin >> exOp;
			switch(exOp)
			{
				case 1:{
					tt.timKiemTheoTheLoai(saveLst, theoTheLoai, tenTheLoai);
					break;
				}
				case 2:{
					if(oldLst.head==NULL)
					{
						cout <<"KHONG TIM THAY DANH SACH CU NAO - VUI LONG BAM PHIM 1 DE TIM KIEM MOI" << endl;
						goto timKiemMoi3;
						break;
					}
					tt.timKiemTheoTheLoai(oldLst, theoTheLoai, tenTheLoai);
					break;
				}
			}
			oldLst.head = theoTheLoai.head;
			tt.printNodeDSList(theoTheLoai);
			break;
		}
		
		case 4:{
			int exOp;
			string tenTG;
			LinkedList<Node<DauSach>*> theoTenTG;
			tenTG = danhSachTenTG();
			timKiemMoi4:
			cout <<"1. Tim kiem moi - Danh sach tim kiem cu se bi mat di!" << endl;
			cout <<"2. Tim kiem tiep tu danh sach tim kiem cu" << endl;
			cout <<"Nhap lua chon cua ban: ";
			cin >> exOp;
			switch(exOp)
			{
				case 1:{
					tt.timKiemTheoTenTG(saveLst, theoTenTG, tenTG);
					break;
				}
				case 2:{
					if(oldLst.head==NULL)
					{
						cout <<"KHONG TIM THAY DANH SACH CU NAO - VUI LONG BAM PHIM 1 DE TIM KIEM MOI" << endl;
						goto timKiemMoi4;
						break;
					}
					tt.timKiemTheoTenTG(oldLst, theoTenTG, tenTG);
					break;
				}
			}
			oldLst.head = theoTenTG.head;
			tt.printNodeDSList(theoTenTG);
			break;
		}
		
		case 5:{
			int exOp;
			string tenSach;
			LinkedList<Node<DauSach>*> theoTenSach;
			tenSach = danhSachTenSach();
			timKiemMoi5:
			cout <<"1. Tim kiem moi - Danh sach tim kiem cu se bi mat di!" << endl;
			cout <<"2. Tim kiem tiep tu danh sach tim kiem cu" << endl;
			cout <<"Nhap lua chon cua ban: ";
			cin >> exOp;
			switch(exOp)
			{
				case 1:{
					tt.timKiemTheoTenSach(saveLst, theoTenSach, tenSach);
					break;
				}
				case 2:{
					if(oldLst.head==NULL)
					{
						cout <<"KHONG TIM THAY DANH SACH CU NAO - VUI LONG BAM PHIM 1 DE TIM KIEM MOI"<< endl;
						goto timKiemMoi5;
						break;
					}
					tt.timKiemTheoTenSach(oldLst, theoTenSach, tenSach);
					break;
				}
			}
			oldLst.head = theoTenSach.head;
			tt.printNodeDSList(theoTenSach);
			break;
		}
		
		case 6:{
			tt.printNodeDSList(saveLst);
			break;
		}
		
		default:{
			oldLst.head = NULL;
			system("cls");
			break;
		}
	}	
}

void menuThemDauSach(ThaoTacDauSach& tt)
{
	DauSach ds;
	cin.ignore();
	cout << "Nhap ten sach: ";
	getline(cin, ds.tenSach);
	transform(ds.tenSach.begin(), ds.tenSach.end(),ds.tenSach.begin(), ::toupper);
	cout << "Nhap the loai: " ;
	getline(cin, ds.theLoai);
	transform(ds.theLoai.begin(), ds.theLoai.end(),ds.theLoai.begin(), ::toupper);
	cout << "Nhap ten tac gia: " ;
	getline(cin, ds.tenTacGia);
	transform(ds.tenTacGia.begin(), ds.tenTacGia.end(),ds.tenTacGia.begin(), ::toupper);
	cout << "Nhap ten NXB: ";
	getline(cin, ds.NXB);
	transform(ds.NXB.begin(), ds.NXB.end(),ds.NXB.begin(), ::toupper);
	cout <<"Nhap nam XB: ";
	cin >> ds.namXB;
	cout << "Nhap so luong cuon sach: ";
	cin >> ds.soLuongCuon;
	tt.markIDDauSach(originalLst);
	tt.markIDCuonSach(originalLst);
	
	tt.markViTri(originalLst);
	int themDauSach = tt.themDauSach(originalLst, ds);
	saveLst.addHead(originalLst.head);
	ThaoTacDauSach tt1;
	//tt1.printDSList(originalLst);
	// Thong tin dau sach da co trong danh sach
	if(themDauSach == 1)
	{
		cout <<"Vui long them dau sach khac hoac thuc hien thao tac khac" << endl;
	}
}

void menuXoaDauSach(int& op, ThaoTacDauSach& tt)
{
	//cout <<"\n*****************************************************************************";
    cout<<"\n               		       XOA DAU SACH          		   ";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 1: LOC DANH SACH TRUOC KHI XOA             |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 2: XOA TU DANH SACH BAN DAU                |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
	cout<<"\n     |                NHAN PHIM 3: IN DANH SACH                            |";              
	cout<<"\n     +=====================================================================+";
    
	cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 0: THUC HIEN THAO TAC KHAC                 |";              
    cout<<"\n     +=====================================================================+";
    cout<<"\n                   NHAN PHIM DE THUC HIEN THAO TAC: ";
	cin >> op;
	switch(op)
	{
		case 0:{
			system("cls");
			break;
		}
		case 1:{
			int op1;
			do{
				menuLocDauSach(op1, tt);
			}while(op1!=0);
			int co = tt.xoaDauSach(originalLst, oldLst);
			if(co==1)
			{
				cout << "Xoa thanh cong!" << endl;
				saveLst.deleteLinkedList();
				originalLst.saveNode(saveLst);
			}
			break;
		}
		
		case 2:{
			int op2;
			do{
				cout <<"0. Ket thuc" << endl;
				cout <<"1. Xoa theo ten NXB" << endl;
				cout <<"2. Xoa theo the loai" << endl;
				cout <<"3. Xoa theo ten tac gia" << endl;
				cout <<"4. Xoa theo ten sach" << endl;
				cout <<"5. Xoa theo ma dau sach" << endl;
				cout <<"Nhap lua chon cua ban: ";
				cin >> op2;
				switch(op2)
				{
					case 1:{
						LinkedList<Node<DauSach>*> theoTenNXB;
						string tenNXB;
						tenNXB = danhSachTenNXB();
						tt.timKiemTheoTenNXB(saveLst, theoTenNXB, tenNXB);
						int co = tt.xoaDauSach(originalLst, theoTenNXB);
						if(co==1)
						{
							cout <<"Xoa thanh cong!" << endl;	
							saveLst.deleteLinkedList();
							originalLst.saveNode(saveLst);
						}
						break;
					}
					case 2:{
						LinkedList<Node<DauSach>*> theoTheLoai;
						string theLoai;
						theLoai = danhSachTenTheLoai();
						tt.timKiemTheoTheLoai(saveLst, theoTheLoai, theLoai);
						int co = tt.xoaDauSach(originalLst, theoTheLoai);
						if(co==1)
						{
							cout <<"Xoa thanh cong!" << endl;
							saveLst.deleteLinkedList();
							originalLst.saveNode(saveLst);
						}
						break;
					}
					case 3:{
						LinkedList<Node<DauSach>*> theoTG;
						string tenTG;
						tenTG = danhSachTenTG();
						tt.timKiemTheoTenTG(saveLst, theoTG, tenTG);
						int co = tt.xoaDauSach(originalLst, theoTG);
						if(co==1)
						{
							cout <<"Xoa thanh cong!" << endl;
							saveLst.deleteLinkedList();
							originalLst.saveNode(saveLst);
						}
						break;
					}
					case 4:{
						LinkedList<Node<DauSach>*> theoTenSach;
						string tenSach;
						tenSach = danhSachTenSach();
						tt.timKiemTheoTenSach(saveLst, theoTenSach, tenSach);
						int co = tt.xoaDauSach(originalLst, theoTenSach);
						if(co==1)
						{
							cout <<"Xoa thanh cong!" << endl;
							saveLst.deleteLinkedList();
							originalLst.saveNode(saveLst);	
						}
						break;
					}
					case 5:{
						string maDauSach;
						cout <<"Nhap ma dau sach: ";
						cin >> maDauSach;
						int co = tt.xoaTheoMaDauSach(originalLst, maDauSach);
						if(co==1)
						{
							cout <<"Xoa thanh cong!" << endl;
							saveLst.deleteLinkedList();
							originalLst.saveNode(saveLst);
						}
						break;
					}
				}
			}while(op2!=0);
			break;
		}
		
		case 3:{
			tt.printDSList(originalLst);
			break;
		}
	}
}

void menuLocDauSach(int& op, ThaoTacDauSach tt)
{
	//cout <<"\n*****************************************************************************";
    cout<<"\n               		     LOC DAU SACH          		   ";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 1: LOC THEO TEN NXB                        |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 2: LOC THEO THE LOAI                       |";              
    cout<<"\n     +=====================================================================+";
     
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 3: LOC THEO TEN TAC GIA                    |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 4: LOC THEO TEN SACH                       |";              
    cout<<"\n     +=====================================================================+";
    
	cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 0: KET THUC                                |";              
    cout<<"\n     +=====================================================================+";
    cout<<"\n                   NHAN PHIM DE THUC HIEN THAO TAC: ";

	cin >> op;
	switch(op)
	{
		case 1:{
			int exOp;
			string tenNXB;
			LinkedList<Node<DauSach>*> theoTenNXB;
			tenNXB = danhSachTenNXB();
			locMoi1:
			cout <<"1. Loc moi - Danh sach loc cu se bi mat di!" << endl;
			cout <<"2. loc tiep tu danh sach loc cu" << endl;
			cout <<"Nhap lua chon cua ban: ";
			cin >> exOp;
			switch(exOp)
			{
				case 1:{
					tt.timKiemTheoTenNXB(saveLst, theoTenNXB, tenNXB);
					break;
				}
				case 2:{
					if(oldLst.head==NULL)
					{
						cout <<"KHONG TIM THAY DANH SACH CU NAO - VUI LONG BAM PHIM 1 DE LOC MOI" << endl;
						goto locMoi1;
						break;
					}
					tt.timKiemTheoTenNXB(oldLst, theoTenNXB, tenNXB);
					break;
				}
			}
			oldLst.head = theoTenNXB.head;
			tt.printNodeDSList(theoTenNXB);
			break;
		}
		
		case 2:{
			int exOp;
			string tenTheLoai;
			LinkedList<Node<DauSach>*> theoTheLoai;
			tenTheLoai = danhSachTenTheLoai();
			locMoi2:
			cout <<"1. loc moi - Danh sach loc cu se bi mat di!" << endl;
			cout <<"2. loc tiep tu danh sach loc cu" << endl;
			cout <<"Nhap lua chon cua ban: ";
			cin >> exOp;
			switch(exOp)
			{
				case 1:{
					tt.timKiemTheoTheLoai(saveLst, theoTheLoai, tenTheLoai);
					break;
				}
				case 2:{
					if(oldLst.head==NULL)
					{
						cout <<"KHONG TIM THAY DANH SACH CU NAO - VUI LONG BAM PHIM 1 DE LOC MOI" << endl;
						goto locMoi2;
						break;
					}
					tt.timKiemTheoTheLoai(oldLst, theoTheLoai, tenTheLoai);
					break;
				}
			}
			oldLst.head = theoTheLoai.head;
			tt.printNodeDSList(theoTheLoai);
			break;
		}
		
		case 3:{
			int exOp;
			string tenTG;
			LinkedList<Node<DauSach>*> theoTenTG;
			tenTG = danhSachTenTG();
			locMoi3:
			cout <<"1. loc moi - Danh sach loc cu se bi mat di!" << endl;
			cout <<"2. loc tiep tu danh sach loc cu" << endl;
			cout <<"Nhap lua chon cua ban: ";
			cin >> exOp;
			switch(exOp)
			{
				case 1:{
					tt.timKiemTheoTenTG(saveLst, theoTenTG, tenTG);
					break;
				}
				case 2:{
					if(oldLst.head==NULL)
					{
						cout <<"KHONG TIM THAY DANH SACH CU NAO - VUI LONG BAM PHIM 1 DE LOC MOI" << endl;
						goto locMoi3;
						break;
					}
					tt.timKiemTheoTenTG(oldLst, theoTenTG, tenTG);
					break;
				}
			}
			oldLst.head = theoTenTG.head;
			tt.printNodeDSList(theoTenTG);
			break;
		}
		
		case 4:{
			int exOp;
			string tenSach;
			LinkedList<Node<DauSach>*> theoTenSach;
			tenSach = danhSachTenSach();
			locMoi4:
			cout <<"1. loc moi - Danh sach loc cu se bi mat di!" << endl;
			cout <<"2. loc tiep tu danh sach loc cu" << endl;
			cout <<"Nhap lua chon cua ban: ";
			cin >> exOp;
			switch(exOp)
			{
				case 1:{
					tt.timKiemTheoTenSach(saveLst, theoTenSach, tenSach);
					break;
				}
				case 2:{
					if(oldLst.head==NULL)
					{
						cout <<"KHONG TIM THAY DANH SACH CU NAO - VUI LONG BAM PHIM 1 DE LOC MOI" << endl;
						goto locMoi4;
						break;
					}
					tt.timKiemTheoTenSach(oldLst, theoTenSach, tenSach);
					break;
				}
			}
			oldLst.head = theoTenSach.head;
			tt.printNodeDSList(theoTenSach);
			break;
		}
	}
}

void menuSapXepDauSach(int& op, ThaoTacDauSach tt)
{
	AVLTree<DauSach> *rootDS = NULL;
	ThaoTacDauSach ttds;
	cout<<"\n               		   SAP XEP DAU SACH          		   ";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 1: SAP XEP MA DAU SACH                     |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 2: SAP XEP TEN SACH                        |";              
    cout<<"\n     +=====================================================================+";
    
    cout<<"\n     +=====================================================================+";
	cout<<"\n     |                NHAN PHIM 3: IN DANH SACH BAN DAU                    |";              
	cout<<"\n     +=====================================================================+";
    
	cout<<"\n     +=====================================================================+";
    cout<<"\n     |                NHAN PHIM 0: THUC HIEN THAO TAC KHAC                 |";              
    cout<<"\n     +=====================================================================+";
    cout<<"\n                   NHAN PHIM DE THUC HIEN THAO TAC: ";
    cin >> op;
    switch(op)
    {
    	case 1:{
    		int stt=1;
    		data.chenDauSachVaoCayTheoMaDS(rootDS);
    		cout << "+===============+======================+=====================+================+==============+========================+" << endl;
			cout << left << setw(16) << "|  Ma Dau Sach" << left << setw(23) <<"| Ten Sach/ The Loai" << left << setw(22) <<"|Ten Tac Gia / TenNXB" <<
			left << setw(17) << "| So luong cuon" << left
		         << setw(15)<< "| Ma Cuon Sach" << left << setw(25) << "|         Vi Tri"  << "|" <<endl;
		    cout << "+===============+======================+=====================+================+==============+========================+" << endl;
    		ttds.printListDSAVLTree(rootDS, stt);
    		cout <<"TONG SO: " << stt-1;
			break;
		}
		
		case 2:{
			int stt=1;
    		data.chenVaoCayTheoTenSach(rootDS);
    		cout << "+===============+======================+=====================+================+==============+========================+" << endl;
			cout << left << setw(16) << "|  Ma Dau Sach" << left << setw(23) <<"| Ten Sach/ The Loai" << left << setw(22) <<"|Ten Tac Gia / TenNXB" <<
			left << setw(17) << "| So luong cuon" << left
		         << setw(15)<< "| Ma Cuon Sach" << left << setw(25) << "|         Vi Tri"  << "|" <<endl;
		    cout << "+===============+======================+=====================+================+==============+========================+" << endl;
    		ttds.printListDSAVLTree(rootDS, stt);
    		cout <<"TONG SO: " << stt-1;
			break;
		}
		
		case 3:{
			tt.printDSList(originalLst);
			break;
		}
	}
}
