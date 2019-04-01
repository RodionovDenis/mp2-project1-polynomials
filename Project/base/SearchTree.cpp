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
void SearchTree::AddNode(int _key)
{
	if (!NodeCount)
	{
		root->key = _key;
		NodeCount++;
		return;
	}

	NodeTree *Cur = root;
	while (true) 
	{
		if (_key < Cur->key) 
		{
			if (Cur->left) 
				Cur = Cur->left;
			else 
			{
				Cur->left = new NodeTree(_key, Cur);
				break;
			}
		}
		else 
		{
			if (Cur->right) 
			{
				Cur = Cur->right;
			}
			else 
			{
				Cur->right = new NodeTree(_key, Cur);
				break;
			}
		}
	}
	NodeCount++;
}
NodeTree SearchTree::Find(int _key)
{
		NodeTree *Cur = root;
		while (Cur && Cur->key != _key) 
			if (_key < Cur->key) 
				Cur = Cur->left;
			else 
				Cur = Cur->right;
		return Cur;
}
void SearchTree::Remove(int _key)
{
	NodeTree *Rem = Find(_key);
	if (NodeCount && Rem) 
	{
		if (!Rem->left || !Rem->right)
			DeleteNode(Rem);
		else 
		{  
			NodeTree *Heir= FindMinChild(Rem->right);
			Rem->key = Heir->key;
			DeleteNode(Heir);
		}
		NodeCount--;
	}
}
void SearchTree::ClearTree()
{
	Clear(root->left);
	Clear(root->right);
	NodeCount = 0;
	root->left = nullptr;
	root->right = nullptr;
	root->height = 1;
}