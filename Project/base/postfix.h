#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <vector>
#include "stack.h"
#include "polynomials.h"
#include "tables.h"

using namespace std;

class TPostfix
{
private:
	string infix;
	string postfix;
	TStack<char> stackOperation; // ��� �������������� � �������� � �������� �� ������������
	Polynom * value; 
	TStack<string> stackArguments; // ��� �������� ����������
	TStack<Polynom> stackValue; //��� �������� ��������������� ��������
	TStack<Polynom> stackValuePostfix; //��� ������������ ����������
	OrderedArray polinoms; //������� ���������

public:
	TPostfix(string _infix, OrderedArray _polinoms) : infix(_infix), postfix(""), polinoms(_polinoms) {}
	string GetInfix();
	string GetPostfix();
	void ChangeInfix(string _infix);
	bool IsCorrect(); //�������� �� ������������ ���������
	void ToPostfix(); // ��������� ���������
	void ReadArguments(); //���������� ����������
	Polynom Calculate(); // ����������
};
#endif