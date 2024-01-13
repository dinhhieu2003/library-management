#ifndef DOCGIA_H
#define DOCGIA_H
#include <cstddef>
#include "LinkedList.h"
#include "DuLieuThuVien.h"
#include "Node.h"
#include "AVLTree.h"
#include "DateCalculate.h"


class ThaoTacDocGia{
	public:
	void themDocGiaMoi(LinkedList<DocGia> &lst);
	void themDocGia(LinkedList<DocGia>& lst, DocGia data);
	void suaThongTinDocGia(AVLTree<DocGia> *&root, AVLTree<DocGia> *&rootlsm);
	
	void capNhatFile(LinkedList<DocGia> lst);
	void capNhatFileDungAVL(AVLTree<DocGia> *root, fstream &output);
	void capNhatFileDauSachDungAVL(AVLTree<DauSach> *root, fstream &output);
	void capNhatFileLSMuonDungAVL(AVLTree<DocGia> *dglsm, fstream &output);
	void capNhatTinhTrangSachTrenCay(AVLTree<DauSach> *&rootds, string s);
		
	void ghiFile(DocGia dg, fstream &output);
	void ghiFileDS(DauSach ds, fstream &output);
	void ghiFileLSM(DocGia dg, fstream &output);
	
	void xoaTheoMaDG(AVLTree<DocGia> *root);
	
	void timKiemTheoMaDG(AVLTree<DocGia> *root);
	AVLTree<DocGia>* timKiemGiaTriTheoMaDG(AVLTree<DocGia> *root, string maDG);
	
	void xemDocGiaDaMuonSach(AVLTree<DocGia> *root);
	void xemDGMuonSach(AVLTree<DocGia> *root);
	void xemDocGiaTheoTen(AVLTree<DocGia> *root);
	void xemDocGiaTheoMaDG(AVLTree<DocGia> *root);
	
	
	void capNhatThongTinMuonSach(AVLTree<Node<CuonSach>*> *rootCS, AVLTree<DocGia> *rootDG, AVLTree<DocGia> *rootLS,
											string maDG, int soLuongMuon);
	void capNhatThongTinTraSach(AVLTree<DocGia> *&root, AVLTree<DauSach> *&rootds, AVLTree<DocGia> *&rootlsm);	
	
	void xemThongTin(LinkedList<DocGia> lst);
	void xuatThongTinDocGia(AVLTree<DocGia> *root);
	void xemDocGiaMuonQuaHan(AVLTree<DocGia> *root);
	void xemMuonQuaHan(AVLTree<DocGia> *root);
	void xemDocGiaMuonThoiGianCuThe(AVLTree<DocGia> *root);
	void xemMuonTGCuThe(AVLTree<DocGia> *root, int d1, int m1, int y1, int d2, int m2, int y2);
	void xemDocGiaTraThoiGianCuThe(AVLTree<DocGia> *root);
	void xemTraTGCuThe(AVLTree<DocGia> *root, int d1, int m1, int y1, int d2, int m2, int y2);
	
};

void ThaoTacDocGia::xemDocGiaTraThoiGianCuThe(AVLTree<DocGia> *root)
{
	fflush(stdin);
	int d1,m1,y1,d2,m2,y2;
	cout<<"Nhap ngay bat dau: ";
	cin>>d1>>m1>>y1;
	fflush(stdin);
	cout<<"Nhap ngay ket thuc: ";
	cin>>d2>>m2>>y2;
	cout<<"\n================================DANH SACH DOC GIA DA TRA SACH TU NGAY "<<d1<<"/"<<m1<<"/"<<y1
		<<" DEN NGAY "<<d2<<"/"<<m2<<"/"<<y2<<"===============================\n\n";
	cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	cout << left << setw(16) << "|   Ma Doc Gia" << left << setw(23) <<"|    Ten Doc Gia" << left << setw(19) <<"|  So Dien Thoai" <<
	left << setw(20) << "|  So Sach Da Tra " << left
         << setw(16)<< "| Ma Cuon Sach" << left << setw(22) << "|   Ngay Muon-Han Tra  "  << left << setw(11)
         << "| Ngay Tra" << right << setw(1) << "|" << endl;
    cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	xemTraTGCuThe(root,d1,m1,y1,d2,m2,y2);
	cout<<"\n=================================================================================================================================\n";
}

void ThaoTacDocGia::xemTraTGCuThe(AVLTree<DocGia> *root, int d1, int m1, int y1, int d2, int m2, int y2)
{
	if (root == NULL)
    	return;
	xemTraTGCuThe(root->left,d1,m1,y1,d2,m2,y2);
	
	int co = 0;
	DateCalculate date;
	Node <CuonSach> *cs = root->data.listMuon.head;
	while(cs != NULL)
	{
		if( (date.soSanhNgay(cs->data.ngayTra.dd,cs->data.ngayTra.mm,cs->data.ngayTra.yy,
							d1,m1,y1) < 0) ||
			(date.soSanhNgay(cs->data.ngayTra.dd,cs->data.ngayTra.mm,cs->data.ngayTra.yy,
							d2,m2,y2) > 0) )
		{
			root->data.listMuon.deleteNode(cs);
		}	
		else
		{
			co += 1;
		}
		cs=cs->next;
	}
	if(co != 0)
	{
	    cout << "|";
		Node<CuonSach> *tmp2 = root->data.listMuon.head;
		cout << left << setw(15) << root->data.maDG << setw(1) << "|";
		cout << left << setw(22) << root->data.tenDG << setw(1) << "|";
		cout << left << setw(18) << root->data.SDT << setw(2) << "|";
		cout << left << setw(18) << co << setw(1) << "|";
		while(tmp2 != NULL)
		{
			cout << left << setw(15) << tmp2->data.maCuon << setw(1) << "|" ;
			cout << left << setw(2) << tmp2->data.ngayMuon.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.ngayMuon.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.ngayMuon.yy;
			cout << left << setw(1) << "-";
			cout << left << setw(2) << tmp2->data.hanTra.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.hanTra.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.hanTra.yy;
			cout << right << setw(2) << "|";
			cout << left << setw(2) << tmp2->data.ngayTra.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.ngayTra.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.ngayTra.yy;
			cout << right << setw(1) << "|" << endl;
			if(tmp2->next != NULL)
				cout << left << setw(16) << "|" << setw(23) << "|" << setw(19) << "|" << setw(20) << "|" << setw(1) << "|";
			tmp2 = tmp2->next;	
		}
		cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	}
	
	xemTraTGCuThe(root->right,d1,m1,y1,d2,m2,y2);		
}

void ThaoTacDocGia::xemDocGiaMuonThoiGianCuThe(AVLTree<DocGia> *root)
{
	fflush(stdin);
	int d1,m1,y1,d2,m2,y2;
	cout<<"Nhap ngay bat dau: ";
	cin>>d1>>m1>>y1;
	fflush(stdin);
	cout<<"Nhap ngay ket thuc: ";
	cin>>d2>>m2>>y2;
	cout<<"\n===============================DANH SACH DOC GIA DA MUON SACH TU NGAY "<<d1<<"/"<<m1<<"/"<<y1
		<<" DEN NGAY "<<d2<<"/"<<m2<<"/"<<y2<<"==============================\n\n";
	cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	cout << left << setw(16) << "|   Ma Doc Gia" << left << setw(23) <<"|    Ten Doc Gia" << left << setw(19) <<"|  So Dien Thoai" <<
	left << setw(20) << "|  So Sach Da Muon " << left
         << setw(16)<< "| Ma Cuon Sach" << left << setw(22) << "|   Ngay Muon-Han Tra  "  << left << setw(11)
         << "| Ngay Tra" << right << setw(1) << "|" << endl;
    cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	xemMuonTGCuThe(root,d1,m1,y1,d2,m2,y2);
	cout<<"\n=================================================================================================================================\n";
}

void ThaoTacDocGia::xemMuonTGCuThe(AVLTree<DocGia> *root, int d1, int m1, int y1, int d2, int m2, int y2)
{
	if (root == NULL)
    	return;
	xemMuonTGCuThe(root->left,d1,m1,y1,d2,m2,y2);
	
	int co = 0;
	DateCalculate date;
	Node <CuonSach> *cs = root->data.listMuon.head;
	while(cs != NULL)
	{
		if( (date.soSanhNgay(cs->data.ngayMuon.dd,cs->data.ngayMuon.mm,cs->data.ngayMuon.yy,
							d1,m1,y1) < 0) ||
			(date.soSanhNgay(cs->data.ngayMuon.dd,cs->data.ngayMuon.mm,cs->data.ngayMuon.yy,
							d2,m2,y2) > 0) )	
		{
			root->data.listMuon.deleteNode(cs);
		}
		else
		{
			co++;
		}
		cs=cs->next;
	}
	if(co != 0)
	{
	    cout << "|";
		Node<CuonSach> *tmp2 = root->data.listMuon.head;
		cout << left << setw(15) << root->data.maDG << setw(1) << "|";
		cout << left << setw(22) << root->data.tenDG << setw(1) << "|";
		cout << left << setw(18) << root->data.SDT << setw(2) << "|";
		cout << left << setw(18) << co << setw(1) << "|";
		while(tmp2 != NULL)
		{
			cout << left << setw(15) << tmp2->data.maCuon << setw(1) << "|" ;
			cout << left << setw(2) << tmp2->data.ngayMuon.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.ngayMuon.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.ngayMuon.yy;
			cout << left << setw(1) << "-";
			cout << left << setw(2) << tmp2->data.hanTra.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.hanTra.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.hanTra.yy;
			cout << right << setw(2) << "|";
			
			if(tmp2->data.ngayTra.dd == 0)
			{
				cout << setw(10) << "Dang muon";
			}
			else
			{
				cout << left << setw(2) << tmp2->data.ngayTra.dd << left << setw(1) << "/";
				cout << left << setw(2) << tmp2->data.ngayTra.mm << left << setw(1) << "/";
				cout << left << setw(4) << tmp2->data.ngayTra.yy;
			}
			cout << right << setw(1) << "|" << endl;
			if(tmp2->next != NULL)
				cout << left << setw(16) << "|" << setw(23) << "|" << setw(19) << "|" << setw(20) << "|" << setw(1) << "|";
			tmp2 = tmp2->next;	
		}
		cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	}
	
	xemMuonTGCuThe(root->right,d1,m1,y1,d2,m2,y2);		
}

void ThaoTacDocGia::xoaTheoMaDG(AVLTree<DocGia> *root)
{
	string s;
	fflush(stdin);
	cout<<"\nNhap ma doc gia muon xoa: ";
	getline(cin, s);
	
	AVLTree<DocGia> *check=root->searchNodeMaDG(root,s);
	if(check != NULL)
	{
		root = root->deleteNode(root, s);
		fstream output("DocGia.txt", ios::out);
		if(output!=NULL)
		{
			capNhatFileDungAVL(root,output);
			cout<<"\nDa xoa thanh cong!\n";
			output.close();
		}
		else
		{
			cout<"\nKhong mo duoc file!!!";
			output.close();
		}
	}
	else
		cout<<"\nKhong ton tai doc gia mang ma nay!!!";
}

void ThaoTacDocGia::xemDocGiaMuonQuaHan(AVLTree<DocGia> *root)
{
	cout<<"\n==========================================DANH SACH DOC GIA DA TRA SACH QUA HAN==================================================\n\n";
	cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	cout << left << setw(16) << "|   Ma Doc Gia" << left << setw(23) <<"|    Ten Doc Gia" << left << setw(19) <<"|  So Dien Thoai" <<
	left << setw(20) << "|  So Sach Qua Han " << left
         << setw(16)<< "| Ma Cuon Sach" << left << setw(22) << "|   Ngay Muon-Han Tra  "  << left << setw(11)
         << "| Ngay Tra" << right << setw(1) << "|" << endl;
    cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	xemMuonQuaHan(root);
	cout<<"\n=================================================================================================================================\n\n";
}
void ThaoTacDocGia::xemMuonQuaHan(AVLTree<DocGia> *root)
{
	if (root == NULL)
    	return;
	xemMuonQuaHan(root->left);
	
	int co = 0;
	DateCalculate date;
	Node <CuonSach> *cs = root->data.listMuon.head;
	while(cs != NULL)
	{
		if(date.soSanhNgay(cs->data.ngayTra.dd,cs->data.ngayTra.mm,cs->data.ngayTra.yy,
									cs->data.hanTra.dd,cs->data.hanTra.mm,cs->data.hanTra.yy) <= 0)
		{
			root->data.listMuon.deleteNode(cs);
		}
		else
		{
			co++;
		}
		cs=cs->next;
	}
	if(co != 0)
	{
	    cout << "|";
		Node<CuonSach> *tmp2 = root->data.listMuon.head;
		cout << left << setw(15) << root->data.maDG << setw(1) << "|";
		cout << left << setw(22) << root->data.tenDG << setw(1) << "|";
		cout << left << setw(18) << root->data.SDT << setw(2) << "|";
		cout << left << setw(18) << co << setw(1) << "|";
		while(tmp2 != NULL)
		{
			cout << left << setw(15) << tmp2->data.maCuon << setw(1) << "|" ;
			cout << left << setw(2) << tmp2->data.ngayMuon.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.ngayMuon.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.ngayMuon.yy;
			cout << left << setw(1) << "-";
			cout << left << setw(2) << tmp2->data.hanTra.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.hanTra.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.hanTra.yy;
			cout << right << setw(2) << "|";
			cout << left << setw(2) << tmp2->data.ngayTra.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.ngayTra.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.ngayTra.yy;
			cout << right << setw(1) << "|" << endl;
			if(tmp2->next != NULL)
				cout << left << setw(16) << "|" << setw(23) << "|" << setw(19) << "|" << setw(20) << "|" << setw(1) << "|";
			tmp2 = tmp2->next;
		}
		cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	}
	
	xemMuonQuaHan(root->right);	
}

void ThaoTacDocGia::capNhatThongTinTraSach(AVLTree<DocGia> *&root, AVLTree<DauSach> *&rootds, AVLTree<DocGia> *&rootlsm)
{
	string s;
	fflush(stdin);
	cout<<"\nNhap ma doc gia muon cap nhat tra sach: ";
	getline(cin, s);

	AVLTree<DocGia> *root1 = root->searchNodeMaDG(root, s);
	AVLTree<DocGia> *dglsm = rootlsm->searchNodeMaDG(rootlsm, s);
	if(root1 == NULL)
	{
		cout<<"\nKhong co doc gia mang ma nay!!!\n";
		return;
	}

	int sl;
	fflush(stdin);
	cout<<"\nNhap so sach muon tra: ";
	cin>>sl;
	for(int i=0; i<sl; i++)
	{
		CuonSach cs1;
		
		fflush(stdin);
		cout<<"\nMa cuon: ";
		getline(cin, cs1.maCuon);
		
		fflush(stdin);
		cout<<"\nNgay tra: ";
		cin>>cs1.ngayTra.dd>>cs1.ngayTra.mm>>cs1.ngayTra.yy;
		
		Node<CuonSach> *csm = dglsm->data.listMuon.head;
		while(csm!=NULL)
		{
			if(csm->data.compareMC(csm->data.maCuon, cs1.maCuon) == 0)
				{
					csm->data.ngayTra.dd = cs1.ngayTra.dd;
					csm->data.ngayTra.mm = cs1.ngayTra.mm;
					csm->data.ngayTra.yy = cs1.ngayTra.yy;
				}
			csm=csm->next ;
		}
		
		capNhatTinhTrangSachTrenCay(rootds, cs1.maCuon);
		
		Node<CuonSach> *cs = root1->data.listMuon.head;
		while(cs!=NULL)
		{
			if(cs->data.compareMC(cs->data.maCuon, cs1.maCuon) == 0)
				{
					root1->data.listMuon.deleteNode(cs);
					break;
				}
			cs=cs->next;
		}	
	}
	root1->data.soSachDaMuon-=sl;
	
	fstream output("DocGia.txt", ios::out);
	capNhatFileDungAVL(root, output);
	output.close();
	cout<<"\nCap nhat thanh cong!\n";
	
	fstream output1("DauSach.txt", ios::out);
	capNhatFileDauSachDungAVL(rootds, output1);
	output1.close();
	cout<<"\nCap nhat tren file dau sach thanh cong!\n";
	
	fstream output2("LichSuMuon.txt", ios::out);
	capNhatFileLSMuonDungAVL(rootlsm, output2);
	output2.close();
	cout<<"\nCap nhat tren file lich su muon thanh cong!\n";
}

void ThaoTacDocGia::capNhatFileLSMuonDungAVL(AVLTree<DocGia> *dglsm, fstream &output)
{
	if(dglsm == NULL)
		return;
	capNhatFileLSMuonDungAVL(dglsm->left,output);		
	
	DocGia dg = dglsm->data;
	ghiFileLSM(dg, output);
	
	capNhatFileLSMuonDungAVL(dglsm->right,output);		
}

void ThaoTacDocGia::capNhatTinhTrangSachTrenCay(AVLTree<DauSach> *&rootds, string s)
{
	if(rootds == NULL)
		return ;
	capNhatTinhTrangSachTrenCay(rootds->left, s);
	
	DauSach ds = rootds->data;
	Node<CuonSach> *cs = ds.listCuonSach.head;
	while(cs != NULL)
	{
		if(cs->data.compareMC(cs->data.maCuon, s) == 0)
			{
				cs->data.tinhTrang = 0;
			}
		cs=cs->next;
	}
	
	capNhatTinhTrangSachTrenCay(rootds->right, s);
}

void ThaoTacDocGia::capNhatThongTinMuonSach(AVLTree<Node<CuonSach>*> *rootCS, AVLTree<DocGia> *rootDG, AVLTree<DocGia> *rootLS,
											string maDG, int soLuongMuon)
{		
	AVLTree<DocGia> *docGia = timKiemGiaTriTheoMaDG(rootDG, maDG);
	if(docGia == NULL)
	{
		cout <<"Khong co doc gia nay!!" << endl;
		return;
	}
	AVLTree<DocGia> *lichSu = timKiemGiaTriTheoMaDG(rootLS, maDG);
	if(lichSu == NULL)
	{
		rootLS = rootLS->insertByMaDG(rootLS, docGia->data);
		lichSu = timKiemGiaTriTheoMaDG(rootLS, maDG);
	}
	cout << docGia->data.tenDG << endl;
	cout << docGia->data.soSachDaMuon << endl;
	for(int i=0; i<soLuongMuon; i++)
	{
		AVLTree<Node<CuonSach>*> *root = NULL;
		string maCuonSach;
		NHAPLAIMCS:
		cout <<"Nhap ma cuon sach: ";
		cin >> maCuonSach;
		root = root->searchNodeCuonSach(rootCS, maCuonSach);
		if(root==NULL)
		{
			cout <<"MCS NAY KHONG TON TAI. XIN HAY NHAP LAI" << endl;
			goto NHAPLAIMCS;
		}
		if(root->data->data.tinhTrang == 1)
		{
			cout <<"SACH NAY DANG CO NGUOI MUON. XIN HAY MUON CUON KHAC" << endl;
			goto NHAPLAIMCS;
		}
		cout <<"Nhap ngay muon: ";
		cin >> root->data->data.ngayMuon.dd >> root->data->data.ngayMuon.mm >> root->data->data.ngayMuon.yy;
		cout <<"Nhap han tra: ";
		cin >> root->data->data.hanTra.dd >> root->data->data.hanTra.mm >> root->data->data.hanTra.yy;
		// set default Ngay Tra
		root->data->data.ngayTra.dd = 0;
		root->data->data.ngayTra.mm = 0;
		root->data->data.ngayTra.yy = 0;
		//
		root->data->data.tinhTrang = 1;
		docGia->data.listMuon.addHead(root->data->data);
		lichSu->data.listMuon.addHead(root->data->data);
	}
	fstream output("DocGia.txt", ios::out);
	docGia->data.soSachDaMuon+=soLuongMuon;
	capNhatFileDungAVL(rootDG, output);
	output.close();
	cout<<"Cap nhat thanh cong!\n";
	
	fstream outputLS("LichSuMuon.txt", ios::out);
	lichSu->data.soSachDaMuon+=soLuongMuon;
	capNhatFileLSMuonDungAVL(rootLS, outputLS);
	outputLS.close();
	cout<<"Cap nhat lich su thanh cong!\n";
}

void ThaoTacDocGia::themDocGiaMoi(LinkedList<DocGia> &lst)
{
	ThaoTacDocGia ttdg;
	DocGia dg;
	fflush(stdin);
	cout<<"\nNhap ma doc gia: ";
	getline(cin, dg.maDG);
	
	cout<<"\nNhap ten doc gia: ";
	getline(cin, dg.tenDG);
	cout<<"\nNhap so dien thoai: ";
	getline(cin, dg.SDT);
	
	fflush(stdin);
	cout<<"\nNhap so cuon sach da muon: ";
	cin>>dg.soSachDaMuon;
	
	int sl=dg.soSachDaMuon;
	while(sl > 0)
	{
		CuonSach cs;
		fflush(stdin);
		cout<<"\nNhap ma cuon da muon: ";
		getline(cin, cs.maCuon);
		fflush(stdin);
		cout<<"\nNhap ngay muon: ";
		cin>>cs.ngayMuon.dd>>cs.ngayMuon.mm>>cs.ngayMuon.yy;
		cout<<"\nNhap han tra: ";
		cin>>cs.hanTra.dd>>cs.hanTra.mm>>cs.hanTra.yy;
		dg.listMuon.addHead(cs);
		sl--;
	}
	themDocGia(lst,dg);
}

void ThaoTacDocGia::capNhatFile(LinkedList<DocGia> lst)
{
	fstream output("DocGia.txt", ios::out);
	Node<DocGia> *tmpDG = lst.head;
	if(output!=NULL)
	{
		while(tmpDG!=NULL)
		{
			output << tmpDG->data.maDG << endl;
			output << tmpDG->data.tenDG<< endl;
			output << tmpDG->data.SDT << endl;
			output << tmpDG->data.soSachDaMuon << endl;
			string ngayMuon = "Ngay Muon: ";
			string hanTra = "Han Tra: ";
			char slash = '/';
			Node<CuonSach> *tmp = tmpDG->data.listMuon.head;
			while(tmp!=NULL)
			{
				output << tmp->data.maCuon << endl;
				output << ngayMuon << tmp->data.ngayMuon.dd << slash << tmp->data.ngayMuon.mm << slash 
						<< tmp->data.ngayMuon.yy << endl; 
				output << hanTra << tmp->data.hanTra.dd << slash << tmp->data.hanTra.mm << slash << tmp->data.hanTra.yy << endl;
				tmp = tmp->next;
			}
			tmpDG = tmpDG->next;
		}
		output.close();
	}
}

void ThaoTacDocGia::themDocGia(LinkedList<DocGia>& lst, DocGia data)
{
	Node<DocGia> *tmp = lst.head;
	while(tmp != NULL)
	{
		if(tmp->data.compareMaDG(tmp->data,data) == 0)
		{
			cout <<"\nTrung ma doc gia - Khong the them vao!!!\n" << endl;
			return;
		}
		tmp = tmp->next;
	}
	lst.addHead(data);
	capNhatFile(lst);
	cout <<"\nThem doc gia thanh cong!\n" << endl;
}

void ThaoTacDocGia::suaThongTinDocGia(AVLTree<DocGia> *&root, AVLTree<DocGia> *&rootlsm)
{
	string s;
	cout<<"\nNhap ma doc gia muon sua thong tin: ";
	fflush(stdin);
	getline(cin,s);
	AVLTree<DocGia> *dg1 = root->searchNodeMaDG(root,s);
	AVLTree<DocGia> *dg2 = rootlsm->searchNodeMaDG(rootlsm,s);
	fflush(stdin);
	cout<<"\nNhap ten sau khi sua: ";
	getline(cin,s);
	dg1->data.tenDG = s;
	dg2->data.tenDG = s;
	cout<<"\nNhap so dien thoai sau khi sua: ";
	fflush(stdin);
	getline(cin,s);
	dg1->data.SDT=s;
	dg2->data.SDT=s;
	
	fstream output("DocGia.txt", ios::out);
	capNhatFileDungAVL(root, output);
	output.close();
	cout<<"\nCap nhat thanh cong!\n";
	fstream output2("LichSuMuon.txt", ios::out);
	capNhatFileLSMuonDungAVL(rootlsm, output2);
	output2.close();
	cout<<"\nCap nhat tren file lich su muon thanh cong!\n";
}

void ThaoTacDocGia::timKiemTheoMaDG(AVLTree<DocGia> *root)
{
	fflush(stdin);
	string s;
	cout<<"\nNhap ma doc gia: ";
	getline(cin,s);
	root=root->searchNodeMaDG(root,s);
	if(root == NULL)
		{
			cout<<"\nKhong tim thay thong tin doc gia!\n";
			return;			
		}
	else
	{
		cout << "\n========================================================THONG TIN DOC GIA========================================================\n\n";
		cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
		cout << left << setw(16) << "|   Ma Doc Gia" << left << setw(23) <<"|    Ten Doc Gia" << left << setw(19) <<"|  So Dien Thoai" <<
		left << setw(19) << "| So Luong Cuon Muon" << left
	         << setw(16)<< "| Ma Cuon Sach" << left << setw(22) << "|   Ngay Muon-Han Tra  "  << left << setw(11)
	         << "| Ngay Tra" << right << setw(1) << "|" << endl;
	    cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;		
		xuatThongTinDocGia(root);
	}
}

void ThaoTacDocGia::xuatThongTinDocGia(AVLTree<DocGia> *root)
{
    cout << "|";
	Node<CuonSach> *tmp2 = root->data.listMuon.head;
	cout << left << setw(15) << root->data.maDG << setw(1) << "|";
	cout << left << setw(22) << root->data.tenDG << setw(1) << "|";
	cout << left << setw(18) << root->data.SDT << setw(2) << "|";
	cout << left << setw(18) << root->data.soSachDaMuon << setw(1) << "|";
	if(root->data.soSachDaMuon == 0)
	{
		cout<< "               |                      |          |"<<endl;
	}
	while(tmp2 != NULL)
	{
		cout << left << setw(15) << tmp2->data.maCuon << setw(1) << "|" ;
		cout << left << setw(2) << tmp2->data.ngayMuon.dd << left << setw(1) << "/";
		cout << left << setw(2) << tmp2->data.ngayMuon.mm << left << setw(1) << "/";
		cout << left << setw(4) << tmp2->data.ngayMuon.yy;
		cout << left << setw(1) << "-";
		cout << left << setw(2) << tmp2->data.hanTra.dd << left << setw(1) << "/";
		cout << left << setw(2) << tmp2->data.hanTra.mm << left << setw(1) << "/";
		cout << left << setw(4) << tmp2->data.hanTra.yy;
		cout << right << setw(2) << "|";
		if(tmp2->data.ngayTra.dd == 0)
		{
			cout << setw(10) << "Dang muon";
		}
		else
		{
			cout << left << setw(2) << tmp2->data.ngayTra.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.ngayTra.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.ngayTra.yy;
		}
		cout << right << setw(1) << "|" << endl;
		if(tmp2->next != NULL)
			cout << left << setw(16) << "|" << setw(23) << "|" << setw(19) << "|" << setw(20) << "|" << setw(1) << "|";
		tmp2 = tmp2->next;
	}
	cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
}

void ThaoTacDocGia::xemDocGiaTheoMaDG(AVLTree<DocGia> *root)
{

	cout<<"\n----------DANH SACH DOC GIA----------\n";
	root->printName_MaDG(root);
	cout<<"\n-------------------------------------\n\n";
}

void ThaoTacDocGia::xemDocGiaTheoTen(AVLTree<DocGia> *root)//Co doc gia dang ky nhung khong muon
{
	cout<<"\n----------DANH SACH DOC GIA DA DANG KY----------\n";
	root->printName(root);
	cout<<"\n------------------------------------------------\n\n";	
}

void ThaoTacDocGia::xemDocGiaDaMuonSach(AVLTree<DocGia> *root)
{
	cout<<"\n--------------------------------------------------DANH SACH DOC GIA DA MUON SACH-------------------------------------------------\n\n";
	cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	cout << left << setw(16) << "|   Ma Doc Gia" << left << setw(23) <<"|    Ten Doc Gia" << left << setw(19) <<"|  So Dien Thoai" <<
	left << setw(19) << "| So Luong Cuon Muon" << left
         << setw(16)<< "| Ma Cuon Sach" << left << setw(22) << "|   Ngay Muon-Han Tra  "  << left << setw(11)
         << "| Ngay Tra" << right << setw(1) << "|" << endl;
    cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
  
	xemDGMuonSach(root);	
	cout<<"\n---------------------------------------------------------------------------------------------------------------------------------\n\n";
}

void ThaoTacDocGia::xemDGMuonSach(AVLTree<DocGia> *root)
{
	if(root == NULL)
		return;
	xemDGMuonSach(root->left);
	if(root->data.soSachDaMuon > 0)
		{
			xuatThongTinDocGia(root);
		}
	xemDGMuonSach(root->right);
}

void ThaoTacDocGia::xemThongTin(LinkedList<DocGia> lst)
{	
	cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
	cout << left << setw(16) << "|   Ma Doc Gia" << left << setw(23) <<"|    Ten Doc Gia" << left << setw(19) <<"|  So Dien Thoai" <<
	left << setw(19) << "| So Luong Cuon Muon" << left
         << setw(16)<< "| Ma Cuon Sach" << left << setw(22) << "|   Ngay Muon-Han Tra  "  << left << setw(11)
         << "| Ngay Tra" << right << setw(1) << "|" << endl;
    cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
  
    Node<DocGia> *tmp = lst.head;
	int i=1;
	while(tmp != NULL)
	{
		cout << "|";
		Node<CuonSach> *tmp2 = tmp->data.listMuon.head;
		cout << left << setw(15) << tmp->data.maDG << setw(1) << "|";
		cout << left << setw(22) << tmp->data.tenDG << setw(1) << "|";
		cout << left << setw(18) << tmp->data.SDT << setw(2) << "|";
		cout << left << setw(18) << tmp->data.soSachDaMuon << setw(1) << "|";
		if(tmp->data.soSachDaMuon == 0)
		{
			cout<< "               |                      |          |"<<endl;
		}
		while(tmp2 != NULL)
		{
			cout << left << setw(15) << tmp2->data.maCuon << setw(1) << "|" ;
			cout << left << setw(2) << tmp2->data.ngayMuon.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.ngayMuon.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.ngayMuon.yy;
			cout << left << setw(1) << "-";
			cout << left << setw(2) << tmp2->data.hanTra.dd << left << setw(1) << "/";
			cout << left << setw(2) << tmp2->data.hanTra.mm << left << setw(1) << "/";
			cout << left << setw(4) << tmp2->data.hanTra.yy;
			cout << right << setw(2) << "|";
			if(tmp2->data.ngayTra.dd == 0 || tmp2->data.ngayTra.dd > 31)
			{
				cout << setw(10) << "Dang muon";
			}
			else
			{
				cout << left << setw(2) << tmp2->data.ngayTra.dd << left << setw(1) << "/";
				cout << left << setw(2) << tmp2->data.ngayTra.mm << left << setw(1) << "/";
				cout << left << setw(4) << tmp2->data.ngayTra.yy;
			}
			cout << right << setw(1) << "|" << endl;
			if(tmp2->next != NULL)
				cout << left << setw(16) << "|" << setw(23) << "|" << setw(19) << "|" << setw(20) << "|" << setw(1) << "|";
			tmp2 = tmp2->next;
		}
		cout << "+===============+======================+==================+===================+===============+======================+==========+" << endl;
		tmp = tmp->next;
		++i;
	}
	cout<<"\nTONG SO DOC GIA LA: "<<i-1<<endl;
}

void ThaoTacDocGia::capNhatFileDungAVL(AVLTree<DocGia> *root, fstream &output)
{
	if(root == NULL)
		return;
	capNhatFileDungAVL(root->left,output);		
	
	DocGia dg = root->data;
	ghiFile(dg, output);
	
	capNhatFileDungAVL(root->right,output);	
}

void ThaoTacDocGia::capNhatFileDauSachDungAVL(AVLTree<DauSach> *root, fstream &output)
{
	if(root == NULL)
		return;
	capNhatFileDauSachDungAVL(root->left,output);		
	
	DauSach ds = root->data;
	ghiFileDS(ds, output);
	
	capNhatFileDauSachDungAVL(root->right,output);	
}

void ThaoTacDocGia::ghiFile(DocGia dg, fstream &output)
{
	if(output!=NULL)
	{
			output << dg.maDG << endl;
			output << dg.tenDG<< endl;
			output << dg.SDT << endl;
			output << dg.soSachDaMuon << endl;
			string ngayMuon = "Ngay Muon: ";
			string hanTra = "Han Tra: ";
			char slash = '/';
			Node<CuonSach> *tmp = dg.listMuon.head;
			while(tmp!=NULL)
			{
				output << tmp->data.maCuon << endl;
				output << ngayMuon << tmp->data.ngayMuon.dd << slash << tmp->data.ngayMuon.mm << slash 
						<< tmp->data.ngayMuon.yy << endl; 
				output << hanTra << tmp->data.hanTra.dd << slash << tmp->data.hanTra.mm << slash << tmp->data.hanTra.yy << endl;
				tmp = tmp->next;
			}
	}
}

void ThaoTacDocGia::ghiFileDS(DauSach ds, fstream &output)
{	
	if(output!=NULL)
	{
			output << ds.maDauSach << endl;
			output << ds.tenSach << endl;
			output << ds.theLoai << endl;
			output << ds.tenTacGia << endl;
			output << ds.namXB << endl;
			output << ds.NXB << endl;
			output << ds.soLuongCuon << endl;
			string day = "DAY ";
			string hang = " HANG ";
			string ngan = " NGAN ";
			char colon = ',';
			Node<CuonSach> *tmp = ds.listCuonSach.head;
			while(tmp!=NULL)
			{
				output << tmp->data.maCuon << endl;
				output << day << tmp->data.viTri.day << colon 
						<< hang << tmp->data.viTri.hang << colon << ngan << tmp->data.viTri.ngan << endl;
				output << tmp->data.tinhTrang << endl;
				tmp = tmp->next;
			}
	}
}

void ThaoTacDocGia::ghiFileLSM(DocGia dg, fstream &output)
{
	if(output!=NULL)
	{
			output << dg.maDG << endl;
			output << dg.tenDG<< endl;
			output << dg.SDT << endl;
			output << dg.soSachDaMuon << endl;
			string ngayMuon = "Ngay Muon: ";
			string hanTra = "Han Tra: ";
			string ngayTra = "Ngay Tra: ";
			char slash = '/';
			Node<CuonSach> *tmp = dg.listMuon.head;
			while(tmp!=NULL)
			{
				output << tmp->data.maCuon << endl;
				output << ngayMuon << tmp->data.ngayMuon.dd << slash << tmp->data.ngayMuon.mm << slash 
						<< tmp->data.ngayMuon.yy << endl; 
				output << hanTra << tmp->data.hanTra.dd << slash << tmp->data.hanTra.mm << slash << tmp->data.hanTra.yy << endl;
				output << ngayTra << tmp->data.ngayTra.dd << slash << tmp->data.ngayTra.mm << slash << tmp->data.ngayTra.yy << endl;
				tmp = tmp->next;
			}
	}
}

AVLTree<DocGia>* ThaoTacDocGia::timKiemGiaTriTheoMaDG(AVLTree<DocGia> *root, string maDG)
{
	root=root->searchNodeMaDG(root,maDG);
	return root;
}

#endif
