/*#include <string>
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
void HashTable2::Find(string _key)
{
	int hashNumber = hash(_key);
	Node1 *result = table[hashNumber];
	if (result == NULL)
	{
		return NULL;
	}
	while (result->key != _key)
	{
		if (result->Next == NULL)
		{
			return NULL;
		}
		result = result->Next;
	}
	return result;
}
*/