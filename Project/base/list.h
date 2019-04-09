#ifndef __LIST_H__
#define __LIST_H__ 

#include <iostream>

using namespace std;

template <class T>
struct Node //структура звена
{
	T data; //данные
	Node<T> * pNext; //указатель на следующее звено
	Node() : data(), pNext(nullptr) {} //коструктор по умолчанию
};

template <class T>
class List
{
	Node<T> * pFirst;
	int size;
public:
	List() : pFirst(nullptr), size(0) {} //конструктор
	~List() //деструктор
	{
		Node<T> * p = pFirst;
		while (p != nullptr)
		{
			pFirst = p->pNext;
			delete p;
			p = pFirst;
		}
	} //деструктор
	List(const List<T> & list) //конструктор копирования
	{
		if (list.pFirst == nullptr)
		{
			pFirst = nullptr;
			size = 0;
		}
		else
		{
			pFirst = new Node<T>;
			pFirst->data = list.pFirst->data;
			size = list.size;
			Node<T> * ptr = list.pFirst->pNext, *p = pFirst, *tmp;
			while (ptr != nullptr)
			{
				tmp = new Node<T>;
				tmp->data = ptr->data;
				p->pNext = tmp;
				p = tmp;
				ptr = ptr->pNext;
			}
		}
	}
	List<T>  operator=(const List<T> & list) //оператор присваивания
	{
		if (list.pFirst == nullptr)
		{
			pFirst = nullptr;
			size = 0;
			return *this;
		}
		if (size == list.size)
		{
			Node<T> *ptr = list.pFirst, *p = pFirst;
			while (ptr != nullptr)
			{
				p->data = ptr->data;
				p = p->pNext;
				ptr = ptr->pNext;
			}
			return *this;
		}
		Node<T> * p1 = pFirst;
		while (p1 != nullptr)
		{
			pFirst = p1->pNext;
			delete p1;
			p1 = pFirst;
		}
		size = list.size;
		pFirst = new Node<T>;
		pFirst->data = list.pFirst->data;
		Node<T> * ptr = list.pFirst->pNext, *p = pFirst, *tmp;
		while (ptr != nullptr)
		{
			tmp = new Node<T>;
			tmp->data = ptr->data;
			p->pNext = tmp;
			p = tmp;
			ptr = ptr->pNext;
		}
		return *this;
	}
	int Size() //получить размер
	{
		return size;
	}
	T & operator[](int i) //перегрузка скобок
	{
		if (i >= size)
			throw "data is not correct";
		int j = 0;
		Node<T> * ptr = pFirst;
		while (i != j)
		{
			ptr = ptr->pNext;
			j++;
		}
		return ptr->data;
	}
	void Insert(T _data) //вставить
	{
		size++;
		if (pFirst == nullptr)
		{
			pFirst = new Node<T>;
			pFirst->data = _data;
			return;
		}
		Node<T> * ptr = pFirst, *p = pFirst;
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
	void Delete(int m) 	
	{
		if (m >= size)
			throw "data is not correct";
		int i = 0;
		Node<T> *ptr = pFirst, *p = pFirst;
		if (m == 0)
		{
			pFirst = pFirst->pNext;
			delete ptr;
			size--;
			return;
		}
		while (i < m)
		{
			p = ptr;
			ptr = ptr->pNext;
			i++;
		}
		p->pNext = ptr->pNext;
		delete ptr;
		size--;
	}
	void Merge(int m1, int m2)
	{
		if (m1 >= size || m2 >= size)
			throw "data is not correct";
		if (m1 == m2)
			return;
		Node<T> nd;
		nd.data = (*this)[m1] + (*this)[m2];
		if (m1 > m2)
		{
			Delete(m1);
			Delete(m2);
		}
		else
		{
			Delete(m2);
			Delete(m1);
		}
		Insert(nd.data);
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