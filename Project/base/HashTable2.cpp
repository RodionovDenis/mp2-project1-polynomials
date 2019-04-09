#include "tables.h"


using namespace std;

int HashTable2::Count()
{
	return size;
}
bool HashTable2::IsEmpty()
{
	if (size == 0)
		return true;
	return false;
}
bool HashTable2::IsFull()
{
	if (size == NMAX)
		return true;
	return false;
}
bool HashTable2::Add(Polynom _data, string _key)
{
	if (IsFull())
		return false;
	TRecord record(_data, _key);
	int hashNumber = hash(_key);
	if (flags[hashNumber] == '-')
		table[hashNumber] = record;
	for (int i = hashNumber + 1; i != hashNumber; i++)
	{
		if (flags[(i-1) % NMAX] == '-')
		{
			flags[(i-1) % NMAX] = '+';
			size++;
			table[(i-1) % NMAX] = record;
			return true;
		}
	}
	return false;
}
bool HashTable2::Remove(string _key)
{
	if (IsEmpty())
		return false;
	int hashNumber = hash(_key);
	for (int i = hashNumber + 1; i != hashNumber; i++)
		if (table[(i - 1) % NMAX].key == _key)
		{
			flags[(i - 1) % NMAX] = '-';
			return true;
		}
	return false;
}
TRecord * HashTable2::Find(string _key)
{
	if (IsEmpty())
		return nullptr;
	int hashNumber = hash(_key);
	for (int i = hashNumber + 1; i != hashNumber; i++)
		if (table[(i - 1) % NMAX].key == _key)
			return &table[(i - 1) % NMAX];
	return nullptr;
}
void HashTable2::Print()
{
	for (int i = 0; i < NMAX; i++)
	{
		if (flags[i] == '+')
			cout << table[i].key << " : " << table[i].data.ReturnForm() << endl;
	}
}
