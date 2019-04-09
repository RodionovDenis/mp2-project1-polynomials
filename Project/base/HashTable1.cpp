#include "tables.h"


using namespace std;

int HashTable1::Count()
{
	return size;
}
bool HashTable1::IsEmpty()
{
	if (size == 0)
		return true;
	return false;
}
bool HashTable1::IsFull()
{
	if (size == NMAX)
		return true;
	return false;
}
bool HashTable1::Add(Polynom _data, string _key)
{
	Node1 *tmp = new Node1;
	int hashNumber = hash(_key);
	tmp->rec.data = _data;
	tmp->rec.key = _key;
	if (IsFull())
		return false;
	if (table[hashNumber] == nullptr)
	{
		table[hashNumber] = tmp;
		size++;
		return true;
	}
	while (table[hashNumber]->pNext != nullptr)
		table[hashNumber] = table[hashNumber]->pNext;
	table[hashNumber]->pNext = tmp;
	size++;
	return true;
}
bool HashTable1::Remove(string _key)
{
	int hashNumber = hash(_key);
	if (IsEmpty())
		return false;
	if (table[hashNumber] == nullptr)
		return false;
	Node1 * tmp = table[hashNumber];
	Node1 * ptmp = table[hashNumber];
	if (tmp->rec.key == _key)
	{
		table[hashNumber] = tmp->pNext;
		delete tmp;
		size--;
		return true;
	}
	while (tmp != nullptr)
	{
		if (tmp->rec.key == _key)
		{
			ptmp->pNext = tmp->pNext;
			delete tmp;
			size--;
			return true;
		}
		ptmp = tmp;
		tmp = tmp->pNext;
	}
	return false;
}
TRecord * HashTable1::Find(string _key)
{
	int hashNumber = hash(_key);
	Node1 *result = table[hashNumber];
	if (result == nullptr)
		return nullptr;
	while (result->rec.key != _key)
	{
		if (result->pNext == nullptr)
			return nullptr;
		result = result->pNext;
	}
	return &(result->rec);
}
void HashTable1::Print()
{
	Node1 * tmp;
	for (int i = 0; i < NMAX; i++)
	{
		if (table[i] == nullptr)
			continue;
		tmp = table[i];
		while (tmp != nullptr)
		{
			cout << tmp->rec.key << " : " << tmp->rec.data.ReturnForm() << endl;
			tmp = tmp->pNext;
		}
	}
}