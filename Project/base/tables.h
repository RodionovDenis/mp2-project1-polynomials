#ifndef __TABLES_H__
#define __TABLES_H__

#define NMAX 100

#include "polynomials.h"

struct TRecord
{
	Polynom data;
	string key;
	TRecord() : data(), key() {}
	TRecord(Polynom _data, string _key) : data(_data), key(_key) {}
};

struct Node1
{
	TRecord rec;
	Node1* pNext;
	Node1():rec(), pNext(nullptr) {}
};

struct Node2
{
	TRecord rec;
	Node2 * pRight;
	Node2 * pLeft;
	Node2(): rec(), pRight(nullptr), pLeft(nullptr) {}
};

class HashTable1
{
	Node1 ** table;
	int size;
	int hash(string _key)
	{
		int sum = 0;
		for (int i = 0; i < _key.length(); i++)
			sum += _key[i];
		if (sum >= 0)
			return sum % 100;
		if (sum < 0)
			return -1 * sum % 100;
	}

public:
	HashTable1()
	{
		table = new Node1 *[NMAX];
		for (int i = 0; i < NMAX; i++)
			table[i] = nullptr;
		size = 0;
	}

	~HashTable1()
	{
		for (int i = 0; i < 100; i++)
			delete table[i];
	}

	int Count();
	bool IsEmpty();
	bool IsFull();
	bool Add(Polynom _data, string _key);
	bool Remove(string _key);
	TRecord* Find(string _key);
	void Print();
};
class HashTable2
{
	TRecord * table;
	int size;
	char * flags;
	int hash(string _key)
	{
		int sum = 0;
		for (int i = 0; i < _key.length(); i++)
			sum += _key[i];
		if (sum >= 0)
			return sum % 100;
		if (sum < 0)
			return -1 * sum % 100;
	}
public:
	HashTable2()
	{
		table = new TRecord[NMAX];
		flags = new char[NMAX];
		for (int i = 0; i < NMAX; i++)
			flags[i] = '-';
		size = 0;
	}

	~HashTable2()
	{
		delete[] table;
		delete[] flags;
	}

	int Count();
	bool IsEmpty();
	bool IsFull();
	bool Add(Polynom _data, string _key);
	bool Remove(string _key);
	TRecord * Find(string _key);
	void Print();
};
class LinearArray
{
	TRecord * table;
	int last;
public:
	LinearArray()
	{
		table = new TRecord[NMAX];
		last = -1;
	}
	~LinearArray()
	{
		delete[] table;
	}
	bool IsFull();
	bool IsEmpty();
	bool Add(Polynom _data, string _key);
	bool Remove(string _key);
	TRecord * Find(string _key);
	void Print();
};
class ListTable
{
	Node1 *pFirst;
	int size;
public:
	ListTable() : pFirst(nullptr), size(0) {};
	~ListTable()
	{
		Node1 * p = pFirst;
		while (p != nullptr)
		{
			pFirst = p->pNext;
			delete p;
			p = pFirst;
		}
	}
	int Count();
	bool IsEmpty();
	void Add(Polynom _data, string _key);
	bool Remove(string _key);
	TRecord * Find(string _key);
	void Print();
};
class OrderedArray
{
	TRecord * table;
	int last;
	int BinarySearch(string _key);
public:
	OrderedArray()
	{
		table = new TRecord[NMAX];
		last = -1;
	}
	~OrderedArray()
	{
		delete[] table;
	}
	OrderedArray(const OrderedArray & t);
	OrderedArray & operator=(const OrderedArray & t);
	bool IsFull();
	bool IsEmpty();
	bool Add(Polynom _data, string _key);
	bool Remove(string _key);
	TRecord * Find(string _key);
	void Print();

};
class SearchTree
{
	Node2 * pFirst;
	void DeleteTree(Node2 * tmp)
	{
		if (tmp != nullptr)
		{
			DeleteTree(tmp->pRight);
			DeleteTree(tmp->pLeft);
			delete tmp;
		}
	}
	void PrintTree(Node2 * tmp)
	{
		if (tmp != nullptr)
		{
			PrintTree(tmp->pRight);
			cout << tmp->rec.key << " : " << tmp->rec.data.ReturnForm() << endl;
			PrintTree(tmp->pLeft);
		}
	}
public:
	SearchTree() : pFirst(nullptr) {}

	~SearchTree()
	{
		DeleteTree(pFirst);
	}

	bool IsEmpty();
	void Add(Polynom _data, string _key);
	bool Remove(string _key);
	TRecord * Find(string _key);
	void Print();
};

#endif