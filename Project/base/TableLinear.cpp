#include "tables.h"

using namespace std;




bool TableLinear::IsFull()
{
	if (last >= 999)
		return 1;
	return 0;
}
bool TableLinear::IsEmpty()
{
	if (last == 0)
		return 1;
	return 0;
}
void TableLinear::Add(string _data, int _key)
{
	if (IsFull())
		return;
	table[last].data = _data;
	table[last].key = _key;
	last++;
}
void TableLinear::Remove(int _key)
{
	if (IsEmpty())
		return;
	for (int i = 0; i <= last; i++)
	{
		if (table[i].key == _key)
		{
			if (i == last)
			{
				table[i].data = "empty";
				table[i].key = -1;
				last--;
			}
			table[i].data = table[last].data;
			table[i].key = table[last].key;
			table[last].data = "empty";
			table[last].key = -1;
			last--;
		}
	}
}
Element TableLinear::Find(int _key)
{
	if (IsEmpty())
		throw;
	for (int i = 0; i <= last; i++)
		if (table[i].key == _key)
			return table[i];
	throw;
}