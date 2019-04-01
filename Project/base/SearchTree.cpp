#include <string>
#include "tables.h"

using namespace std;

NodeTree SearchTree::*FindMinChild(NodeTree *_NodeTree)
{
	NodeTree *Cur = _NodeTree;
	while (Cur->left)
		Cur = Cur->left;
	return Cur;
};
void SearchTree::DeleteNode(NodeTree *_NodeTree)
{
	if (!_NodeTree->right)
	{
		if (_NodeTree == root)
		{
			root = _NodeTree->left;
			if (!root)
			{
				root = new NodeTree(0, nullptr);
			}
		}
		else if (_NodeTree == _NodeTree->parent->left)
		{
			_NodeTree->parent->left = _NodeTree->left;
		}
		else if (_NodeTree == _NodeTree->parent->right)
		{
			_NodeTree->parent->right = _NodeTree->left;
		}
		if (_NodeTree->left)
		{
			_NodeTree->left->parent = _NodeTree->parent;
		}
	}
	else if (!_NodeTree->left) 
	{
		if (_NodeTree == root) 
		{
			root = _NodeTree->right;
			if (!root) 
			{
				root = new NodeTree(0, nullptr);
			}
		}
		else if (_NodeTree == _NodeTree->parent->left) 
		{
			_NodeTree->parent->left = _NodeTree->right;
		}
		else if (_NodeTree == _NodeTree->parent->right) 
		{
			_NodeTree->parent->right = _NodeTree->right;
		}
		if (_NodeTree->right) 
		{
			_NodeTree->right->parent = _NodeTree->parent;
		}
	}
	NodeTree *Cur = _NodeTree->parent;
	delete _NodeTree;
};
void AddNode(int _key)
{

}
NodeTree Find(int _key)
{

}
void Remove(int _key)
{

}
void ClearTree()
{

}