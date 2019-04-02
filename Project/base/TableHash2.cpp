#include <string>
#include "tables.h"

using namespace std;

int HashTable2::Count()
{
	return size;
}

bool HashTable2::IsEmpty()
{
	if (size == 0)
		return 1;
	return 0;
}

bool HashTable2::IsFull()
{
	if (size == 1000)
		return 1;
	return 0;
}

// Вставляет элемент в таблицу
void HashTable2::Add(Polynom _data, string _key)
{
	if (IsFull())
		return;
	int hf = hash(_key);
	while (table[hf].BL)
	{
		hf++;
	}
	if (!table[hf].BL)
	{
		table[hf].data = _data;
		table[hf].key = _key;
		size++;
	}
}
//Убирает элемент из таблицы 
void HashTable2::Remove(string _key)
{
	int hashNumber = hash(_key);
	if (IsEmpty())
		return;
	for (int i= 0; i< )
	return;
}

// Получает элемент из таблицы по его ключу.
ElementHT HashTable2::Find(string _key)
{
	int hf = hash(_key);
	while (table[hf].key != _key)
	{
		hf++;
	}
	if (table[hf].key == _key)
		return table[hf].data;
	else
		throw "Error";
}
