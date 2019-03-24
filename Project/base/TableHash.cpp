#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string key;
	string data;
	Node* Next;
};

class HashTable
{
	Node *table[100];
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
		for (int i = 0; i < 100; i++)
			table[i] = NULL;
	}

	~HashTable()
	{
		for (int i = 0; i < 100; i++)
			delete table[i];
	}

	int Count()
	{
		return size;
	}
	
	bool IsEmpty()
	{
		if (size == 0)
			return 1;
		return 0;
	}

	bool IsFull()
	{
		if (size == 100)
			return 1;
		return 0;
	}

	// Вставляет элемент в таблицу
	void Add(string _data, string _key)
	{
		int hashNumber = hash(_key);
		Node *tmp;
		tmp->data = _data;
		tmp->key = _key;
		if (IsFull())
			return;
		if (table[hashNumber] == NULL)
		{
			table[hashNumber] = tmp;
			size++;
			return;
		}
		while (table[hashNumber]->Next != NULL)
			table[hashNumber] = table[hashNumber]->Next;
		table[hashNumber]->Next = tmp;
		return;
	}

	//Убирает элемент из таблицы 
	void Remove(string _key)
	{
		int hashNumber = hash(_key);
		Node *result = table[hashNumber];
		if (IsEmpty())
			return;
		if (table[hashNumber] == NULL)
		{
			cout << "Element not found" << endl;
			return;
		}
		if (table[hashNumber]->key == _key && table[hashNumber]->Next == NULL)
		{
			table[hashNumber] = NULL;
			size--;
			return;
		}
		if (table[hashNumber]->key == _key && table[hashNumber]->Next != NULL)
		{
			table[hashNumber] = table[hashNumber]->Next;
			return;
		}
		while (result->Next->key != _key)
		{
			if (result->Next == NULL)
			{
				cout << "Element not found" << endl;
				return;
			}
			result = result->Next;
		}
		Node* tmp = result->Next->Next;
		delete result->Next;
		result->Next = tmp;
		return;
	}

	// Получает элемент из таблицы по его ключу.
	Node* Find(string _key)
	{
		int hashNumber = hash(_key);
		Node *result = table[hashNumber];
		if (result == NULL)
		{
			cout << "Element not found" << endl;
			return NULL;
		}
		while (result->key != _key)
		{
			if (result->Next == NULL)
			{
				cout << "Element not found" << endl;
				return NULL;
			}
			result = result->Next;
		}
		return result;
	}
};