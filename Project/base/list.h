#ifndef __LIST_H__
#define __LIST_H__ 

#include <iostream>

using namespace std;

template <class T>
struct Node //��������� �����
{
	T data; //������
	Node<T> * pNext; //��������� �� ��������� �����
	Node() : data(), pNext(nullptr) {} //���������� �� ���������
};

template <class T>
class List
{
	Node<T> * pFirst;
public:
	List() : pFirst(nullptr) {} //�����������
	~List() //����������
	{
		Node<T> * p = pFirst;
		while (p != nullptr)
		{
			pFirst = p->pNext;
			delete p;
			p = pFirst;
		}
	} //����������
	List(const List<T> & list) //����������� �����������
	{
		if (list.pFirst != nullptr)
			pFirst = nullptr;
		else
		{
			pFirst = new Node<T>;
			Node<T> p1 = pFirst, p2 = list.pFirst;
			while (p2->pNext != nullptr)
			{
				p1->data = p2->data;
				p1 = p1->pNext;
				p1 = new Node<T>;
				p2 = p2->pNext;
			}
			p1->data = p2->data;
			p1->pNext = nullptr;
		}
	}
	List<T> & operator=(const List<T> & list) //�������� ������������
	{
		if (list.pFirst != nullptr)
		{
			pFirst = nullptr;
			return this;
		}
		if (pFirst != nullptr)
		{
			Link<T> * p = pFirst;
			while (p != nullptr)
			{
				pFirst = p->pNext;
				delete p;
				p = pFirst;
			}
		}
		pFirst = new Node<T>;
		Node<T> p1 = pFirst, p2 = list.pFirst;
		while (p2->pNext != nullptr)
		{
			p1->data = p2->data;
			p1 = p1->pNext;
			p1 = new Node<T>;
			p2 = p2->pNext;
		}
		p1->data = p2->data;
		return this;
	}
	int Size() //�������� ������
	{
		int size = 0;
		Node<T> * ptr = pFirst;
		while (ptr != nullptr)
		{
			size++;
			ptr = ptr->pNext;
		}
		return size;
	}
	T operator[](int i) //���������� ������
	{
		if (i >= size)
			throw "data is not correct";
		int j = 0;
		Node<T> * ptr = pFirst;
		while (i != j)
			ptr = ptr->pNext;
		return ptr->data;
	}
	void Insert(T _data) //��������
	{
		if (pFirst == nullptr)
		{
			pFirst = new Node<T>;
			pFirst->data = _data;
			return;
		}
		Node<T> * ptr = pFirst, * p = pFirst;
		Node<T> * tmp = new Node<T>;
		tmp->data = _data;
		if (_data >= pFirst->data)
		{
			tmp->pNext = pFirst;
			pFirst = tmp;
			return;
		}
		while (ptr != nullptr)
		{
			if (_data >= ptr->data)
			{
				p->pNext = tmp;
				tmp->pNext = ptr;
				return;
			}
			p = ptr;
			ptr = ptr->pNext;
		}
		p->pNext = tmp;
	}
	void Print()
	{
		Node<T> *ptr = pFirst;
		while (ptr != nullptr)
		{
			cout << ptr->data << " ";
			ptr = ptr->pNext;
		}
	}

};

#endif