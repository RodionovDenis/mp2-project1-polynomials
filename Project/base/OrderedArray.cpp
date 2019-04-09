#include "tables.h"


int OrderedArray::BinarySearch(string _key)
{
	int l = 0;
	int u = last;
	while (l <= u)
	{
		int m = (l + u) / 2;
		if (table[m].key == _key)
			return m;
		if (table[m].key > _key)
		{
			u = m - 1;
			continue;
		}
		if (table[m].key < _key)
			l = m + 1;
	}
	return -1;
}
bool OrderedArray::IsFull()
{
	if (last == NMAX - 1)
		return true;
	return false;
}
bool OrderedArray::IsEmpty()
{
	if (last == -1)
		return true;
	return false;
}
bool OrderedArray::Add(Polynom _data, string _key)
{
	if (IsFull())
		return false;
	TRecord record(_data, _key);
	if (IsEmpty())
	{
		last++;
		table[last] = record;
		return true;
	}
	for (int i = 0; i <= last; i++)
	{
		if (record.key < table[i].key)
		{
			for (int j = last; j >= i; j--)
				table[j + 1] = table[j];
			table[i] = record;
			last++;
			return true;
		}
	}
	last++;
	table[last] = record;
	return true;
}
bool OrderedArray::Remove(string _key)
{
	if (IsEmpty())
		return false;
	int search = BinarySearch(_key);
	if (search == -1)
		return false;
	for (int j = search; j < last; j++)
		table[j] = table[j+1];
	last--;
	return true;
}
TRecord * OrderedArray::Find(string _key)
{
	int search = BinarySearch(_key);
	if (search == -1)
		return nullptr;
	return &table[search];
}
void OrderedArray::Print()
{
	for(int i = 0; i<=last;i++)
		cout << table[i].key << " : " << table[i].data.ReturnForm() << endl;
}
OrderedArray::OrderedArray(const OrderedArray & t)
{
	last = t.last;
	table = new TRecord[NMAX];
	for (int i = 0; i < NMAX; i++)
		table[i] = t.table[i];
}
OrderedArray& OrderedArray::operator=(const OrderedArray & t)
{
	last = t.last;
	for (int i = 0; i < NMAX; i++)
		table[i] = t.table[i];
	return *this;
}