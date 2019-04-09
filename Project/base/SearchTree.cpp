#include "tables.h"


bool SearchTree::IsEmpty()
{
	if (pFirst == nullptr)
		return true;
	return false;
}
void SearchTree::Add(Polynom _data, string _key)
{
	Node2 * tmp = new Node2;
	tmp->rec.data = _data;
	tmp->rec.key = _key;
	Node2 * ptmp = pFirst;
	Node2 * pointer = pFirst;
	if (pFirst == nullptr)
	{
		pFirst = tmp;
		return;
	}
	while (ptmp != nullptr)
	{
		pointer = ptmp;
		if (ptmp->rec.key > _key)
			ptmp = ptmp->pRight;
		else ptmp = ptmp->pLeft;
	}
	if (pointer->rec.key > _key)
		pointer->pRight = tmp;
	else pointer->pLeft = tmp;
}
bool SearchTree::Remove(string _key)
{
	if (IsEmpty())
		return false;
	Node2 * tmp = pFirst;
	Node2 * ptmp = pFirst;
	Node2 * ptmp2 = nullptr;
	Node2 * ptmp3;
	while (tmp->rec.key != _key && tmp != nullptr)
	{
		ptmp = tmp;
		if (tmp->rec.key > _key)
			tmp = tmp->pRight;
		else tmp = tmp->pLeft;
	}
	if (tmp == nullptr)
		return false;
	if (tmp->pLeft == nullptr && tmp->pRight == nullptr)
	{
		if (ptmp->pRight == tmp)
			ptmp->pRight = nullptr;
		else
			ptmp->pLeft = nullptr;
		if (ptmp == pFirst)
			pFirst = nullptr;
		delete tmp;
		return true;
	}
	ptmp3 = ptmp;
	ptmp = tmp->pLeft;
	if (ptmp == nullptr)
	{
		ptmp3->pRight = tmp->pRight;
		delete tmp;
		return true;
	}
	while (ptmp->pRight != nullptr)
	{
		ptmp2 = ptmp;
		ptmp = ptmp->pRight;
	}
	if (ptmp2 == nullptr)
	{
		ptmp->pLeft = tmp->pLeft;
		delete tmp;
		return true;
	}
	ptmp2->pRight = ptmp->pLeft;
	tmp->rec = ptmp->rec;
	delete ptmp;
	return true;
}
TRecord * SearchTree::Find(string _key)
{
	if (IsEmpty())
		return nullptr;
	Node2 * tmp = pFirst;
	while (tmp->rec.key != _key && tmp != nullptr)
	{
		if (tmp->rec.key > _key)
			tmp = tmp->pRight;
		else tmp = tmp->pLeft;
	}
	if (tmp == nullptr)
		return nullptr;
	return &(tmp->rec);
}
void SearchTree::Print()
{
	PrintTree(pFirst);
}