#ifndef HASH_H
#define HASH_H

#include<bits/stdc++.h>
#include "DuLieuThuVien.h"
#include "LinkedList.h"
#include "Node.h"
#define SIZE_DS 500
#define SIZE_STRING_HASH 10000

using namespace std;

class HashTable{
	public:
	Node<DauSach>* TableMaDauSach[SIZE_DS] = {NULL};
	vector<Node<Node<DauSach>*>*> TableTheLoai[SIZE_STRING_HASH];
	vector<Node<Node<DauSach>*>*> TableTenNXB[SIZE_STRING_HASH];
	vector<Node<Node<DauSach>*>*> TableTenTG[SIZE_STRING_HASH];
	vector<Node<Node<DauSach>*>*> TableTenSach[SIZE_STRING_HASH];
	int hashFuncMaDauSach(string maDauSach);
	int hashFuncString(string x);
	void insertItemMaDauSachTable(Node<DauSach>* TableMaDauSach[], LinkedList<DauSach> ListDS);
	void insertItemTheLoaiTable(vector<Node<Node<DauSach>*>*> TableTheLoai[SIZE_DS], LinkedList<Node<DauSach>*> ListDS);
	void insertItemTenNXBTable(vector<Node<Node<DauSach>*>*> TableTenNXB[SIZE_DS], LinkedList<Node<DauSach>*> ListDS);
	void insertItemTenTGTable(vector<Node<Node<DauSach>*>*> TableTenTG[SIZE_DS], LinkedList<Node<DauSach>*> ListDS);
	void insertItemTenSachTable(vector<Node<Node<DauSach>*>*> TableTenSach[SIZE_STRING_HASH], LinkedList<Node<DauSach>*> ListDS);
};

int HashTable::hashFuncMaDauSach(string maDauSach)
{
	int index = 0;
	for(int i=3; i< maDauSach.length(); i++)
	{
		index = index*10 + (maDauSach[i]-'0');
	}
	return index;
}

void HashTable::insertItemMaDauSachTable(Node<DauSach>* TableMaDauSach[], LinkedList<DauSach> ListDS)
{
	Node<DauSach> *tmp = ListDS.head;
	while(tmp!=NULL)
	{
		string maTMP = tmp->data.maDauSach;
		int index = hashFuncMaDauSach(maTMP);
		TableMaDauSach[index] = tmp;
		tmp = tmp->next;
	}
}

int HashTable::hashFuncString(string x)
{
	int index=0;
	for(int i=0; i<x.length(); i++)
	{
		
		index += (x[i]*10+1);
	}
	index = index % 2069;
	return index;
}

void HashTable::insertItemTheLoaiTable(vector<Node<Node<DauSach>*>*> TableTheLoai[SIZE_DS], LinkedList<Node<DauSach>*> ListDS)
{
	Node<Node<DauSach>*> *tmp = ListDS.head;
	while(tmp!=NULL)
	{
		string theLoai = tmp->data->data.theLoai;
		int index = hashFuncString(theLoai);
		TableTheLoai[index].push_back(tmp);
		tmp = tmp->next;
	}
}

void HashTable::insertItemTenNXBTable(vector<Node<Node<DauSach>*>*> TableTenNXB[SIZE_DS], LinkedList<Node<DauSach>*> ListDS)
{
	Node<Node<DauSach>*> *tmp = ListDS.head;
	while(tmp!=NULL)
	{
		string tenNXB = tmp->data->data.NXB;
		int index = hashFuncString(tenNXB);
		TableTenNXB[index].push_back(tmp);
		tmp = tmp->next;
	}
}

void HashTable::insertItemTenTGTable(vector<Node<Node<DauSach>*>*> TableTenTG[SIZE_DS], LinkedList<Node<DauSach>*> ListDS)
{
	Node<Node<DauSach>*> *tmp = ListDS.head;
	while(tmp!=NULL)
	{
		string tenTG = tmp->data->data.tenTacGia;
		int index = hashFuncString(tenTG);
		TableTenTG[index].push_back(tmp);
		tmp = tmp->next;
	}
}

void HashTable::insertItemTenSachTable(vector<Node<Node<DauSach>*>*> TableTenSach[SIZE_STRING_HASH], LinkedList<Node<DauSach>*> ListDS)
{
	Node<Node<DauSach>*>* tmp = ListDS.head;
	while(tmp!=NULL)
	{
		string tenSach = tmp->data->data.tenSach;
		int index = hashFuncString(tenSach);
		TableTenSach[index].push_back(tmp);
		tmp = tmp->next;
	}
}

#endif 
