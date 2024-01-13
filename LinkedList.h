#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

using namespace std;

template<typename T>
class LinkedList{
	public:
		Node<T> *head;
		LinkedList()
		{
			head = NULL;
		}
		bool isEmpty()
		{ 
			return (head == NULL); 
		}
		void addHead(T data);
		void addNode(Node<T>* data);
		void deleteHead();
		void deleteLinkedList();
		void saveNode(LinkedList<Node<T>*>& saveLst);
		int deleteNode(Node<T>* node);
};

template<typename T>
void LinkedList<T>::addNode(Node<T>* data)
{
	data->next = head;
	head = data;
}

template<typename T>
void LinkedList<T>::addHead(T data)
{
	Node<T> *newNode = new Node<T>(data);
	newNode->next = head;
	head = newNode;
}

template<typename T>
void LinkedList<T>::deleteHead()
{
	if(head == NULL)
	{
		return;
	}
	Node<T> *tmp = head;
	head = head->next;
	delete(tmp);
}

template<typename T>
void LinkedList<T>::deleteLinkedList()
{
	while(head!=NULL)
	{
		deleteHead();
	}
}

template<typename T>
void LinkedList<T>::saveNode(LinkedList<Node<T>*>& saveLst)
{
	Node<T> *tmp = head;
	while(tmp!=NULL)
	{
		saveLst.addHead(tmp);
		tmp = tmp->next;
	}
}

template<typename T>
int LinkedList<T>::deleteNode(Node<T>* node)
{
	if(node==head)
	{
		deleteHead();
		return 1;
	}
	Node<T> *tmp = node;
	Node<T> *prev = head;
	while(prev->next!=NULL && prev->next!=node)
	{
		prev = prev->next;
	}
	if(prev->next == NULL)
	{
		return 0;
	}
	prev->next = node->next;
	delete(tmp);
}

#endif 
