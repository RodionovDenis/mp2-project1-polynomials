#include "tables.h"

int ListTable::Count()
{
	return size;
}
bool ListTable::IsEmpty()
{
	if (size == 0)
		return true;
	return false;
}
void ListTable::Add(Polynom _data, string _key)
{
	Node1  *temp = new Node1;
	temp->rec.key = _key;
	temp->rec.data = _data;
	if (size == 0)
		pFirst = temp;
	else
	{
		temp->pNext = pFirst;
		pFirst = temp;
	}
	size++;
}
bool ListTable::Remove(string _key)
{
	if (IsEmpty())
		return false;
	Node1 * tmp = pFirst;
	Node1 * ptmp = pFirst;
	if (tmp->rec.key == _key)
	{
		pFirst = tmp->pNext;
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
TRecord * ListTable::Find(string _key)
{
	if (IsEmpty())
		return nullptr;
	Node1 * tmp = pFirst;
	while (tmp != nullptr)
	{
		if (tmp->rec.key == _key)
			return &(tmp->rec);
		tmp = tmp->pNext;
	}
	return nullptr;

}
void ListTable::Print()
{
	Node1*tmp = pFirst;
	while (tmp != nullptr)
	{
		cout << tmp->rec.key << " : " << tmp->rec.data.ReturnForm() << endl;
		tmp = tmp->pNext;
	}
}