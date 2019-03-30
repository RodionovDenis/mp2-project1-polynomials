#ifndef __TABLES_H__
#define __TABLES_H__
#include <iostream>
#include <string>
using namespace std;
struct Node1
{
	string key;
	Polynom data;
	Node1* Next = NULL;
};
struct Element
{
	Polynom data;
	string key;
};
struct  Node
{
	Polynom data;
	string key;
	Node *Next = NULL;
};
class HashTable
{
	Node1 *table[100];
	int size = 0;

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
	HashTable()
	{
		for (int i = 99; i >= 0; i--)
		{ 
			table[i] = NULL;
		}
	}

	~HashTable()
	{
		for (int i = 0; i < 100; i++)
			delete table[i];
	}
	int Count();
	bool IsEmpty();
	bool IsFull();
	void Add(Polynom _data, string _key);
	void Remove(string _key);
	Node1* Find(string _key);
};
class TableLinear
{
	Element table[1000];
	int last = 0;
public:
	TableLinear()
	{
		for (int i = 0; i < 1000; i++)
		{
			table[i].data = "empty";
			table[i].key = "-1";
		}
	}
	bool IsFull();
	bool IsEmpty();
	void Add(string _data, string _key);
	void Remove(string _key);
	Element Find(string _key);
};
class ListTable
{
	Node *head, *end;
	int size;
public:
	ListTable() :head(NULL), end(NULL), size(0) {};
	~ListTable()
	{
		while (size != 0)
		{
			Node *temp = head->Next;
			delete head;
			head = temp;
			size--;
		}
	}
	int Count();
	bool IsEmpty();
	void Add(string _key, Polynom _data);
	void Delete(string _key);
	Node* Find(string _key);
};
#endif