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
	TStack<char> stackOperation; // для преобразования в постфикс и проверки на корректность
	Polynom * value; 
	TStack<string> stackArguments; // для хранение аргументов
	TStack<Polynom> stackValue; //для хранения соответствующих значений
	TStack<Polynom> stackValuePostfix; //для высчитывания результата
	OrderedArray polinoms; //таблица полиномов

public:
	TPostfix(string _infix, OrderedArray _polinoms) : infix(_infix), postfix(""), polinoms(_polinoms) {}
	string GetInfix();
	string GetPostfix();
	void ChangeInfix(string _infix);
	bool IsCorrect(); //проверка на корректность выражения
	void ToPostfix(); // получение постфикса
	void ReadArguments(); //считывание переменных
	Polynom Calculate(); // вычисление
};
#endif