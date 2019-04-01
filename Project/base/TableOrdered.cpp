#include "tables.h"

using namespace std;




bool TableOrdered::IsFull()
{
	if (last >= 999)
		return 1;
	return 0;
}
bool TableOrdered::IsEmpty()
{
	if (last == 0)
		return 1;
	return 0;
}
void TableOrdered::Add(string _data, string _key)
{
	if (IsFull())
		return;
	last++;
	a = 0;
	b = last;
	while (a < b)
	{
		c = (a + b) / 2;
		if (table[c].key < _key)
			a = c + 1;
		else b = c;
	}
	table[a].data = _data;
	table[a].key = _key;
	
}
void TableOrdered::Remove(string _key)
{
	if (IsEmpty())
		return;
	a = 0;
	b = last;
	while (a < b)
	{
		c = (a + b) / 2;
		if (table[c].key < _key)
			a = c + 1;
		else b = c;
	}
	for (int i = a+1; i < last; i++)
	{
		table[i-1].data = table[i].data;
		table[i-1].key = table[i].key;
	}
	table[last].data = "empty";
	table[last].key = "-1";
	last--;
}
Element TableOrdered::Find(string _key)
{
	if (IsEmpty())
		throw "Error";
	a = 0;
	b = last;
	while (a < b)
	{
		c = (a + b) / 2;
		if (table[c].key < _key)
			a = c + 1;
		else b = c;
	}
	return table[a];
	throw "Error";
}