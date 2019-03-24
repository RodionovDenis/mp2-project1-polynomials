#include <iostream>
#include <string>

using namespace std;

struct  Node
{
	string data;
	int key;
	Node *Next;
};

class ListTable
{
	Node *head, *end;
	int size;
public:
	ListTable():head(NULL), end(NULL), size(0) {};
	~ListTable()
	{
		while (size != 0)                        
		{
			Node *temp = head->Next;
			delete head;                           
			head = temp;                          
			size--;                                
		}
	}
	int Count()
	{
		return size;
	}
	bool IsEmpty()
	{
		if (size == 0)
			return 1;
		return 0;
	}
	void Add(int _key, string _data)
	{
		size++;                                    
		Node  *temp = new Node;                    
		temp->Next = head;                         
		temp->key = _key;                               
		temp->data = _data;
		if (!IsEmpty())                       
		{
			end->Next = temp;                    
			end = temp;                          
		}
		else 
			head = end = temp;                
	}
	void Delete(int _key)
	{
		Node* tmp1;
		if (IsEmpty())
		{
			cout << "Element not found" << endl;
			return;
		}
		if (head == head->Next)
		{
			delete head;
			head = NULL;
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
	Node* Find(int _key)
	{
		if (IsEmpty())
		{
			cout << "Element not found" << endl;
			return NULL;
		}
		for (Node *tmp = head; tmp = end; tmp = tmp->Next)
			if (tmp->key == _key)
				return tmp;
		cout << "Element not found" << endl;
		return NULL;
	}
};