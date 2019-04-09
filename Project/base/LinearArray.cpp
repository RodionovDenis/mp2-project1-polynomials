#include "tables.h"

bool LinearArray::IsFull()
{
	if (last == NMAX - 1)
		return true;
	return false;
}
bool LinearArray::IsEmpty()
{
	if (last == -1)
		return true;
	return false;
}
bool LinearArray::Add(Polynom _data, string _key)
{
	if (IsFull())
		return false;
	last++;
	TRecord record(_data, _key);
	table[last] = record;
	return true;
}
bool LinearArray::Remove(string _key)
{
	if (IsEmpty())
		return false;
	for (int i = 0; i <= last; i++)
	{
		if (table[i].key == _key)
		{
			table[i] = table[last];
			last--;
			return true;
		}
	}
	return false;
}
TRecord * LinearArray::Find(string _key)
{
	if (IsEmpty())
		return nullptr;
	for (int i = 0; i <= last; i++)
		if (table[i].key == _key)
			return &table[i];
	return nullptr;
}
void LinearArray::Print()
{
	for (int i = 0; i <= last; i++)
		cout << table[i].key << " : " << table[i].data.ReturnForm() << endl;
}