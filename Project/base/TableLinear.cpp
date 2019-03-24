#include <string>
#include <iostream>

using namespace std;

struct Element
{
	string data;
	int key;
};

class Table1
{
	Element table[1000];
	int last = 0;
public:
	Table1()
	{
		for (int i = 0; i < 1000; i++)
		{
			table[i].data = "empty";
			table[i].key = -1;
		}
	}
	bool IsFull()
	{
		if (last >= 999)
			return 1;
		return 0;
	}
	bool IsEmpty()
	{
		if (last == 0)
			return 1;
		return 0;
	}
	void Add(string _data, int _key)
	{
		if (IsFull())
			return;
		table[last].data = _data;
		table[last].key = _key;
		last++;
	}
	void Remove(int _key)
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
				}
				table[i].data = table[last].data;
				table[i].key = table[last].key;
				table[last].data = "empty";
				table[last].key = -1;
			}
		}
		last--;
	}
	Element Find(int _key)
	{
		if (IsEmpty())
			throw;
		for (int i = 0; i <= last; i++)
			if (table[i].key == _key)
				return table[i];
		throw;
	}
};