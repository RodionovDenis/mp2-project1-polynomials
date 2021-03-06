#include "tables.h"



int ListTable::Count()
{
	return size;
}
bool ListTable::IsEmpty()
{
	if (size == 0)
		return 1;
	return 0;
}
void ListTable::Add(int _key, string _data)
{                                 
	Node  *temp = new Node;                                       
	temp->key = _key;                               
	temp->data = _data;
	if (!IsEmpty())                       
	{
		end->Next = temp;                    
		end = temp; 
		size++;
		return;
	}
	else 
		head = end = temp;  
	size++;
	return;
}
void ListTable::Delete(int _key)
{
	Node* tmp1;
	if (IsEmpty())
	{
		return;
	}
	if (head == end)
	{
		delete head;
		size--;
		return;
	}
	for (Node *tmp = head; tmp = end; tmp = tmp->Next)
		if (tmp->Next->key == _key)
		{
			tmp1 = tmp->Next->Next;
			delete tmp->Next;
			tmp->Next = tmp1;
		}
	size--;
	return;
}
Node* ListTable::Find(int _key)
{
	if (IsEmpty())
	{
		return NULL;
	}
	for (Node *tmp = head; tmp = end; tmp = tmp->Next)
		if (tmp->key == _key)
			return tmp;
	return NULL;
}