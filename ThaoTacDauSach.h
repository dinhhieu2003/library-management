#ifndef DAUSACH_H
#define DAUSACH_H

#include <cstddef>
#include "LinkedList.h"
#include "DuLieuThuVien.h"
#include "Node.h"
#include "HashTable.h"
#include "AVLTree.h"
#define SIZE_DS 500
#define SIZE_CS 1000
#define SIZE_STRING_HASH 10000

AVLTree<Node<CuonSach>*>* insertNodeCuonSachByMaCS(AVLTree<Node<CuonSach>*> *root, Node<CuonSach>* data);

class ThaoTacDauSach{
	public:
	string chuyenSoSangChuoi(int x);
	bool maDauSachUsed[SIZE_DS] = {false};
	bool maCuonSachUsed[SIZE_CS] = {false};
	bool checkViTri[10][10][10] = {{{false}}};		// false la con trong
	void markIDDauSach(LinkedList<DauSach> lst);
	void markIDCuonSach(LinkedList<DauSach> lst);
	void markViTri(LinkedList<DauSach> lst);
	void timViTriTrong(int viTri[][3], int soLuongCuon);
	int themDauSach(LinkedList<DauSach>& lst, DauSach data);
	Node<DauSach>* timKiemTheoMaDauSach(LinkedList<DauSach>& oldList, string maDauSach);
	int timKiemTheoTheLoai(LinkedList<Node<DauSach>*> oldList, LinkedList<Node<DauSach>*>& newList, string theLoai);
	int timKiemTheoTenNXB(LinkedList<Node<DauSach>*> oldList, LinkedList<Node<DauSach>*>& newList, string tenNXB);
	int timKiemTheoTenTG(LinkedList<Node<DauSach>*> oldList, LinkedList<Node<DauSach>*>& newList, string tenTG);
	int timKiemTheoTenSach(LinkedList<Node<DauSach>*> oldList, LinkedList<Node<DauSach>*>& newList, string tenSach);
	int xoaTheoMaDauSach(LinkedList<DauSach>& originalList, string maDauSach);
	int xoaDauSach(LinkedList<DauSach>& originalList, LinkedList<Node<DauSach>*>& oldList);
	AVLTree<Node<CuonSach>*>* insertCSIntoTree(LinkedList<DauSach> originalList);
	void capNhatFile(LinkedList<DauSach>& lst);
	void printDSList(LinkedList<DauSach> lst);
	void printNodeDSList(LinkedList<Node<DauSach>*> lst);
	void print1DS(Node<DauSach>* ans);
	void print1DSAVLTree(AVLTree<DauSach> *root, int &stt);
	void printListDSAVLTree(AVLTree<DauSach> *root, int &stt);
};

string ThaoTacDauSach::chuyenSoSangChuoi(int x)
{
	string so = "";
	while(x>0)
	{
		int remainder = x%10;
		char remainderCh = remainder + '0';
		so = remainderCh + so;
		x = x/10;
	}
	return so;
}

void ThaoTacDauSach::capNhatFile(LinkedList<DauSach>& lst)
{
	fstream output("DauSach.txt", ios::out);
	Node<DauSach> *tmpDS = lst.head;
	if(output != NULL)
	{
		while(tmpDS!=NULL)
		{
			output << tmpDS->data.maDauSach << endl;
			output << tmpDS->data.tenSach << endl;
			output << tmpDS->data.theLoai << endl;
			output << tmpDS->data.tenTacGia << endl;
			output << tmpDS->data.namXB << endl;
			output << tmpDS->data.NXB << endl;
			output << tmpDS->data.soLuongCuon << endl;
			string day = "DAY ";
			string hang = " HANG ";
			string ngan = " NGAN ";
			char colon = ',';
			Node<CuonSach> *tmp = tmpDS->data.listCuonSach.head;
			while(tmp!=NULL)
			{
				output << tmp->data.maCuon << endl;
				output << day << tmp->data.viTri.day << colon 
						<< hang << tmp->data.viTri.hang << colon << ngan << tmp->data.viTri.ngan << endl;
				output << tmp->data.tinhTrang << endl;
				tmp = tmp->next;
			}
			tmpDS = tmpDS->next;
		}
		output.close();
	}
	cout <<"Cap nhat thanh cong" << endl;
}

void ThaoTacDauSach::markIDDauSach(LinkedList<DauSach> lst)
{
	HashTable ht;
	Node<DauSach> *tmp = lst.head;
	while(tmp!=NULL)
	{
		string maTMP = tmp->data.maDauSach;
		int index = ht.hashFuncMaDauSach(maTMP);
		maDauSachUsed[index] = true;
		tmp = tmp->next;
	}
}

void ThaoTacDauSach::markIDCuonSach(LinkedList<DauSach> lst)
{
	HashTable ht;
	Node<DauSach> *tmp = lst.head;
	while(tmp!=NULL)
	{
		Node<CuonSach> *tmp2 = tmp->data.listCuonSach.head;
		while(tmp2!=NULL)
		{
			int index = ht.hashFuncMaDauSach(tmp2->data.maCuon);
			maCuonSachUsed[index] = true;
			tmp2 = tmp2->next;
		}
		
		tmp = tmp->next;
	}
}

void ThaoTacDauSach::markViTri(LinkedList<DauSach> lst)
{
	Node<DauSach> *tmp = lst.head;
	while(tmp!=NULL)
	{
		Node<CuonSach> *tmp2 = tmp->data.listCuonSach.head;
		while(tmp2!=NULL)
		{
			checkViTri[tmp2->data.viTri.day][tmp2->data.viTri.hang][tmp2->data.viTri.ngan] = true;
			tmp2 = tmp2->next;
		}
		
		tmp = tmp->next;
	}
	
}

void ThaoTacDauSach::timViTriTrong(int viTri[][3], int soLuongCuon)
{
	int slot = 0;
	int cnt = 0;
	do{
		int day = 1 + rand() % 10;
		for(int hang = 1; hang <= 10; hang++)
		{	
			for(int ngan = 1; ngan <= 10; ngan++)
			{
				if(checkViTri[day][hang][ngan] == false)
				{
					slot = 10 - ngan + 1;
					int j = ngan;
					int size = (slot>soLuongCuon)?(soLuongCuon):slot;
					for(int i=cnt; i<size; i++)
					{
						viTri[i][0] = day;
						viTri[i][1] = hang;
						viTri[i][2] = j++;
						cnt=i;
					}
					++cnt;
					break;
				}
			}
			if(cnt==soLuongCuon)
				break;
		}
	}while(cnt < soLuongCuon);
}

int ThaoTacDauSach::themDauSach(LinkedList<DauSach>& lst, DauSach data)
{
	Node<DauSach> *tmp = lst.head;
	int maSoDauSach = 1 + rand() % (SIZE_DS);
	// Ma Dau Sach da co
	while(maDauSachUsed[maSoDauSach])	
	{
		maSoDauSach = 1 + rand() % (SIZE_DS);
	}
	data.maDauSach = "MDS" + chuyenSoSangChuoi(maSoDauSach);
	maDauSachUsed[maSoDauSach] = true;
	while(tmp != NULL)
	{
		if(tmp->data.same(tmp->data, data) == true)
		{
			cout << "Da co dau sach nay trong thu vien!!" << endl;
			return 1;
		}
		tmp = tmp->next;
	}
	// tim vi tri cho cuon sach
	int viTri[data.soLuongCuon][3];
	timViTriTrong(viTri, data.soLuongCuon);
	for(int i=1; i<=data.soLuongCuon; i++)
	{
		CuonSach x;
		int maSoCuonSach;
		do{
			maSoCuonSach = 1 + rand() % (SIZE_CS);
		}while(maCuonSachUsed[maSoCuonSach]);
		x.maCuon = "MCS" + chuyenSoSangChuoi(maSoCuonSach);
		maCuonSachUsed[maSoCuonSach] = true;
		x.tinhTrang = 0;
		x.viTri.day = viTri[i-1][0];
		x.viTri.hang = viTri[i-1][1];
		x.viTri.ngan = viTri[i-1][2];
		data.listCuonSach.addHead(x);
	}
	lst.addHead(data);
	capNhatFile(lst);
	cout <<"Them dau sach thanh cong!!" << endl;
	return 2;
}

Node<DauSach>* ThaoTacDauSach::timKiemTheoMaDauSach(LinkedList<DauSach>& oldList, string maDauSach)
{
	HashTable ptr;
	ptr.insertItemMaDauSachTable(ptr.TableMaDauSach, oldList);
	int index = ptr.hashFuncMaDauSach(maDauSach);
	return ptr.TableMaDauSach[index];
}

int ThaoTacDauSach::timKiemTheoTheLoai(LinkedList<Node<DauSach>*> oldList, LinkedList<Node<DauSach>*>& newList, string theLoai)
{
	transform(theLoai.begin(), theLoai.end(),theLoai.begin(), ::toupper);
	HashTable ptr;
	ptr.insertItemTheLoaiTable(ptr.TableTheLoai, oldList);
	int index = ptr.hashFuncString(theLoai);
	int co=0;
	for(int i = 0; i < ptr.TableTheLoai[index].size(); i++)
    {
        if(ptr.TableTheLoai[index][i]->data->data.theLoai == theLoai)
        {
        	co = 1;
            newList.addHead(ptr.TableTheLoai[index][i]->data);	
        }
    }
    if(co==0)
    {
    	cout << "Khong tim thay the loai nay!!" << endl;
	}
}

int ThaoTacDauSach::timKiemTheoTenNXB(LinkedList<Node<DauSach>*> oldList, LinkedList<Node<DauSach>*>& newList, string tenNXB)
{
	transform(tenNXB.begin(), tenNXB.end(),tenNXB.begin(), ::toupper);
	HashTable ptr;
	ptr.insertItemTenNXBTable(ptr.TableTenNXB, oldList);
	int index = ptr.hashFuncString(tenNXB);
	int co=0;
	for(int i = 0; i < ptr.TableTenNXB[index].size(); i++)
    {
        if(ptr.TableTenNXB[index][i]->data->data.NXB == tenNXB)
        {
        	co = 1;
            newList.addHead(ptr.TableTenNXB[index][i]->data);
        }
    }
    if(co==0)
    {
    	cout << "Khong tim thay ten NXB nay!!" << endl;
	}
}

int ThaoTacDauSach::timKiemTheoTenTG(LinkedList<Node<DauSach>*> oldList, LinkedList<Node<DauSach>*>& newList, string tenTG)
{
	transform(tenTG.begin(), tenTG.end(),tenTG.begin(), ::toupper);
	HashTable ptr;
	ptr.insertItemTenTGTable(ptr.TableTenTG, oldList);
	int index = ptr.hashFuncString(tenTG);
	int co=0;
	for(int i = 0; i < ptr.TableTenTG[index].size(); i++)
    {
        if(ptr.TableTenTG[index][i]->data->data.tenTacGia == tenTG)
        {
        	co = 1;
            newList.addHead(ptr.TableTenTG[index][i]->data);
        }
    }
    if(co==0)
    {
    	cout << "Khong tim thay ten tac gia nay!!" << endl;
	}
}

int ThaoTacDauSach::timKiemTheoTenSach(LinkedList<Node<DauSach>*> oldList, LinkedList<Node<DauSach>*>& newList, string tenSach)
{
	transform(tenSach.begin(), tenSach.end(),tenSach.begin(), ::toupper);
	HashTable ptr;
	ptr.insertItemTenSachTable(ptr.TableTenSach, oldList);
	int index = ptr.hashFuncString(tenSach);
	int co=0;
	for(int i = 0; i < ptr.TableTenSach[index].size(); i++)
    {
        if(ptr.TableTenSach[index][i]->data->data.tenSach == tenSach)
        {
        	co = 1;
            newList.addHead(ptr.TableTenSach[index][i]->data);
        }
    }
    if(co==0)
    {
    	cout << "Khong tim thay ten sach nay!!" << endl;
	}
}

void ThaoTacDauSach::printDSList(LinkedList<DauSach> lst)
{
	
	cout << "+===============+======================+=====================+================+==============+========================+" << endl;
	cout << left << setw(16) << "|  Ma Dau Sach" << left << setw(23) <<"| Ten Sach/ The Loai" << left << setw(22) <<"|Ten Tac Gia / TenNXB" <<
	left << setw(17) << "| So luong cuon" << left
         << setw(15)<< "| Ma Cuon Sach" << left << setw(25) << "|         Vi Tri"  << "|" <<endl;
    cout << "+===============+======================+=====================+================+==============+========================+" << endl;
	Node<DauSach> *tmp = lst.head;
	int i=1;
	while(tmp != NULL)
	{
		int cnt = 0;
		cout << "|";
		Node<CuonSach> *tmp2 = tmp->data.listCuonSach.head;
		cout << left << setw(3) << i++ << left << setw(1) << ".";
		cout << left << setw(11) << tmp->data.maDauSach << setw(1) <<"|";
		cout << left << setw(22) << tmp->data.tenSach << setw(1) <<"|";
		cout << left << setw(21) << tmp->data.tenTacGia << setw(1) <<"|";
		cout << left << setw(16) << tmp->data.soLuongCuon << setw(1) <<"|";
		while(tmp2 != NULL)
		{
			cout << left << setw(14) << tmp2->data.maCuon;
			cout <<right << setw(1) <<"|" ;
			cout << left << setw(4) << "DAY ";
			cout << left << setw(2) << tmp2->data.viTri.day;
			cout << left << setw(6) << " HANG ";
			cout << left << setw(2) << tmp2->data.viTri.hang;
			cout << left << setw(6) << " NGAN ";
			cout << left << setw(2) << tmp2->data.viTri.ngan;
			cout << right << setw(3) << "|" << endl;
			if(tmp2->next == NULL && tmp->data.soLuongCuon > 1)
			{
				break;
			}
			cout <<left <<setw(1) <<"|";
			cout << right << setw(16) <<"|";
			if(cnt<1)
			{
				cout << left << setw(22) << tmp->data.theLoai << setw(1) << "|";
				cout << left << setw(21) << tmp->data.NXB << setw(1) << "|";
				++cnt;
			}
			else
			{
				cout << right << setw(23) <<"|";
				cout << right << setw(22) <<"|";
			}
			cout << right << setw(17) <<"|";
			if(tmp->data.soLuongCuon == 1)
			{
				cout << right << setw(15)  << "|";
				cout << right << setw(25) << "|" << endl;
			}
			tmp2 = tmp2->next;
		}
		cout << "+===============+======================+=====================+================+==============+========================+" << endl;
		tmp = tmp->next;
	}
	--i;
	cout <<"TONG SO: " << i << endl;
}

void ThaoTacDauSach::print1DS(Node<DauSach>* ans)
{	
	cout << "+===============+======================+=====================+================+==============+========================+" << endl;
	cout << left << setw(16) << "|  Ma Dau Sach" << left << setw(23) <<"| Ten Sach/ The Loai" << left << setw(22) <<"|Ten Tac Gia / TenNXB" <<
	left << setw(17) << "| So luong cuon" << left
         << setw(15)<< "| Ma Cuon Sach" << left << setw(25) << "|         Vi Tri"  << "|" <<endl;
    cout << "+===============+======================+=====================+================+==============+========================+" << endl;
    cout << "|";
    cout << left << setw(15) << ans->data.maDauSach << setw(1) <<"|";
	cout << left << setw(22) << ans->data.tenSach << setw(1) <<"|";
	cout << left << setw(21) << ans->data.tenTacGia << setw(1) <<"|";
	cout << left << setw(16) << ans->data.soLuongCuon << setw(1) <<"|";
	Node<CuonSach> *tmp = ans->data.listCuonSach.head;
	int cnt = 0;
	while(tmp != NULL)
	{
		cout << left << setw(14) << tmp->data.maCuon;
		cout << right << setw(1) <<"|" ;
		cout << left << setw(4) << "DAY ";
		cout << left << setw(2) << tmp->data.viTri.day;
		cout << left << setw(6) << " HANG ";
		cout << left << setw(2) << tmp->data.viTri.hang;
		cout << left << setw(6) << " NGAN ";
		cout << left << setw(2) << tmp->data.viTri.ngan;
		cout << right << setw(3) << "|" << endl;
		if(tmp->next == NULL && ans->data.soLuongCuon > 1)
		{
			break;
		}
		cout <<left <<setw(1) <<"|";
		cout << right << setw(16) <<"|";
		if(cnt<1)
		{
			cout << left << setw(22) << ans->data.theLoai << setw(1) << "|";
			cout << left << setw(21) << ans->data.NXB << setw(1) << "|";
			++cnt;
		}
		else
		{
			cout << right << setw(23) <<"|";
			cout << right << setw(22) <<"|";
		}
		cout << right << setw(17) <<"|";
		if(ans->data.soLuongCuon == 1)
		{
			cout << right << setw(15)  << "|";
			cout << right << setw(25) << "|" << endl;
		}
		tmp = tmp->next;
	}
	cout << "+===============+======================+=====================+================+==============+========================+" << endl;

}

void ThaoTacDauSach::printNodeDSList(LinkedList<Node<DauSach>*> lst)
{		
	cout << "+===============+======================+=====================+================+==============+========================+" << endl;
	cout << left << setw(16) << "|  Ma Dau Sach" << left << setw(23) <<"| Ten Sach/ The Loai" << left << setw(22) <<"|Ten Tac Gia / TenNXB" <<
	left << setw(17) << "| So luong cuon" << left
         << setw(15)<< "| Ma Cuon Sach" << left << setw(25) << "|         Vi Tri"  << "|" <<endl;
    cout << "+===============+======================+=====================+================+==============+========================+" << endl;
	Node<Node<DauSach>*> *tmp = lst.head;
	int i=1;
	while(tmp != NULL)
	{
		int cnt = 0;
		cout << "|";
		Node<CuonSach> *tmp2 = tmp->data->data.listCuonSach.head;
		cout << left << setw(3) << i++ << left << setw(1) << ".";
		cout << left << setw(11) << tmp->data->data.maDauSach << setw(1) <<"|";
		cout << left << setw(22) << tmp->data->data.tenSach << setw(1) <<"|";
		cout << left << setw(21) << tmp->data->data.tenTacGia << setw(1) <<"|";
		cout << left << setw(16) << tmp->data->data.soLuongCuon << setw(1) <<"|";
		while(tmp2 != NULL)
		{
			cout << left << setw(14) << tmp2->data.maCuon;
			cout <<right << setw(1) <<"|" ;
			cout << left << setw(4) << "DAY ";
			cout << left << setw(2) << tmp2->data.viTri.day;
			cout << left << setw(6) << " HANG ";
			cout << left << setw(2) << tmp2->data.viTri.hang;
			cout << left << setw(6) << " NGAN ";
			cout << left << setw(2) << tmp2->data.viTri.ngan;
			cout << right << setw(3) << "|" << endl;
			if(tmp2->next == NULL && tmp->data->data.soLuongCuon > 1)
			{
				break;
			}
			cout <<left <<setw(1) <<"|";
			cout << right << setw(16) <<"|";
			if(cnt<1)
			{
				cout << left << setw(22) << tmp->data->data.theLoai << setw(1) << "|";
				cout << left << setw(21) << tmp->data->data.NXB << setw(1) << "|";
				++cnt;
			}
			else
			{
				cout << right << setw(23) <<"|";
				cout << right << setw(22) <<"|";
			}
			cout << right << setw(17) <<"|";
			
			if(tmp->data->data.soLuongCuon == 1)
			{
				cout << right << setw(15)  << "|";
				cout << right << setw(25) << "|" << endl;
			}
			tmp2 = tmp2->next;
		}
		cout << "+===============+======================+=====================+================+==============+========================+" << endl;
		tmp = tmp->next;
	}
	--i;
	cout <<"TONG SO: " << i << endl;
}

int ThaoTacDauSach::xoaTheoMaDauSach(LinkedList<DauSach>& originalList, string maDauSach)
{
	Node<DauSach> *node = timKiemTheoMaDauSach(originalList, maDauSach);
	if(node==NULL)
	{
		return 0;
	}
	originalList.deleteNode(node);
	capNhatFile(originalList);
	return 1;
}

int ThaoTacDauSach::xoaDauSach(LinkedList<DauSach>& originalList, LinkedList<Node<DauSach>*>& oldList)
{
	Node<Node<DauSach>*> *tmp = oldList.head;
	if(tmp==NULL)
	{
		return 0;
	}
	while(tmp != NULL)
	{
		originalList.deleteNode(tmp->data);
		tmp = tmp->next;
	}
	capNhatFile(originalList);
	return 1;
}

AVLTree<Node<CuonSach>*>* insertNodeCuonSachByMaCS(AVLTree<Node<CuonSach>*> *root, Node<CuonSach>* data)
{
	if(root==NULL)
		{
			root = new AVLTree<Node<CuonSach>*>(data);
		}
	else if(root->data->data.compareMaCS(root->data->data,data->data) > 0)
		{
			root->left = insertNodeCuonSachByMaCS(root->left, data);
			root = root->balance(root);
		}
		else
		{
			root->right = insertNodeCuonSachByMaCS(root->right, data);
			root = root->balance(root);
		}
	return root;
}

AVLTree<Node<CuonSach>*>* ThaoTacDauSach::insertCSIntoTree(LinkedList<DauSach> originalList)
{
	Node<DauSach> *tmp = originalList.head;
	AVLTree<Node<CuonSach>*> *root = NULL;
	while(tmp!=NULL)
	{
		Node<CuonSach> *tmpCS = tmp->data.listCuonSach.head;
		while(tmpCS!=NULL)
		{
			root = insertNodeCuonSachByMaCS(root, tmpCS);
			tmpCS = tmpCS->next;
		}
		tmp = tmp->next;
	}
	return root;
}

void ThaoTacDauSach::print1DSAVLTree(AVLTree<DauSach> *root, int &stt)
{
	int cnt = 0;
	cout << "|";
	Node<CuonSach> *tmp2 = root->data.listCuonSach.head;
	cout << left << setw(3) << stt++ << left << setw(1) << ".";
	cout << left << setw(11) << root->data.maDauSach << setw(1) <<"|";
	cout << left << setw(22) << root->data.tenSach << setw(1) <<"|";
	cout << left << setw(21) << root->data.tenTacGia << setw(1) <<"|";
	cout << left << setw(16) << root->data.soLuongCuon << setw(1) <<"|";
	while(tmp2 != NULL)
	{
		cout << left << setw(14) << tmp2->data.maCuon;
		cout <<right << setw(1) <<"|" ;
		cout << left << setw(4) << "DAY ";
		cout << left << setw(2) << tmp2->data.viTri.day;
		cout << left << setw(6) << " HANG ";
		cout << left << setw(2) << tmp2->data.viTri.hang;
		cout << left << setw(6) << " NGAN ";
		cout << left << setw(2) << tmp2->data.viTri.ngan;
		cout << right << setw(3) << "|" << endl;
		if(tmp2->next == NULL && root->data.soLuongCuon > 1)
		{
			break;
		}
		cout <<left <<setw(1) <<"|";
		cout << right << setw(16) <<"|";
		if(cnt<1)
		{
			cout << left << setw(22) << root->data.theLoai << setw(1) << "|";
			cout << left << setw(21) << root->data.NXB << setw(1) << "|";
			++cnt;
		}
		else
		{
			cout << right << setw(23) <<"|";
			cout << right << setw(22) <<"|";
		}
		cout << right << setw(17) <<"|";
		
		if(root->data.soLuongCuon == 1)
		{
			cout << right << setw(15)  << "|";
			cout << right << setw(25) << "|" << endl;
		}
		tmp2 = tmp2->next;
	}
	cout << "+===============+======================+=====================+================+==============+========================+" << endl;
}

void ThaoTacDauSach::printListDSAVLTree(AVLTree<DauSach> *root, int &stt)
{
	if(root==NULL)
	{
		return;
	}
	printListDSAVLTree(root->left, stt);
	print1DSAVLTree(root, stt);
	printListDSAVLTree(root->right, stt);
}

#endif 
