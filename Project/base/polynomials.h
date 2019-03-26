#ifndef __POLYNOMIALS_H__
#define __POLYNOMIALS_H__ 

#include "list.h"
#include <string>

struct Monom
{
	double coeff; //коэффициент
	int deg; //свернутая степень
	Monom(double _coeff = 0.0, int _deg = 0): coeff(_coeff), deg(_deg) {} // конструктор 
	bool operator>= (const Monom & _monom) //перегрузка сравнения для монома
	{
		if (deg >= _monom.deg)
			return true;
		return false;
	}
	bool operator= (const Monom & _monom) //перегрузка сравнения для монома
	{
		if (deg = _monom.deg)
			return true;
		return false;
	}
	bool operator> (const Monom & _monom) //перегрузка сравнения для монома
	{
		if (deg > _monom.deg)
			return true;
		return false;
	}
};

class Polynom
{
	List<Monom> monoms; //упорядоченный по степеням список мономов
	string form; //строка - представление многочлена в алгебраическом виде 
	string name; //имя полинома
public:
	Polynom(string _form, string _name) :monoms(), form(_form), name(_name) //конструктор1
	{
		string str;
		for (int i = 0; i < form.size(); i++)
		{
			if (IsOperation(form[i]))
			{
				Monom mon(ReturnCoeff(str), ReturnDeg(str));
				monoms.Insert(mon);
				str.clear();
				continue;
			}
			str += form[i];
		}
	}
	 
	Polynom(List<Monom> _monoms): monoms(_monoms), name("-") {} // конструктор2
	{
		string degs;
		for (int i = 0; i < monoms.Size(); i++)
		{
			form += dtos(monoms[i].coeff);
			degs = itos(monoms[i].deg);
			form += 'x' += degs[0] += 'y' += degs[1] += 'z' += degs[2];
		}
	}
	Polynom operator+(const Polynom & polynom)
	{
		List<Monom> l;
		int i = 0, j = 0;
		while (i < monoms.Size() && j < polynom.monoms.Size())
		{
			if (monoms[i] == polynom.monoms[j])
			{
				Monom m(monoms[i].coeff + polynom.monoms[j].coeff, monoms[i].deg);
				l.Insert(m);
				i++, j++;
			}
			else if (monoms[i] > polynom.monoms[j])
			{
				Monom m(monoms[i].coeff, monoms[i].deg);
				l.Insert(m);
				i++;
			}
			else
			{
				Monom m(polynom.monoms[j].coeff, polynom.monoms[j].deg);
				l.Insert(m);
				j++;
			}
		}
		Polynom p(l);
		return p;
	}
	Polynom operator*(double c)
	{
		List<Monom> l;
		int i = 0;
		while (i < monoms.Size())
		{
			Monom m = monoms[i];
			m.coeff *= c;
			l.Insert(m);
		}
		Polynom p(l);
		return p;
	}
	Polynom operator-(Polynom & polynom)
	{
		Polynom p = polynom * -1;
		return *this + p;
	}
};

bool IsVariable(char character) // переменная или нет?
{
	if (character == 'x' || character == 'y' || character == 'z')
		return true;
	else return false;
}
bool IsOperation(char ch) //операция?
{
	if (ch == '+' || ch == '-')
		return true;
	return false;
}
bool IsNumber(char character) // проверка на степень
{
	for (char i = '0'; i <= '9'; i++)
		if (character == i)
			return true;
	return false;
}
bool IsValidCharacter(char ch) //проверка символа на допустимое значение
{
	if (IsVariable(ch) || IsOperation(ch) || IsNumber(ch))
		return true;
	return false;
}
bool IsPolynomCorrect(string polynom) //проверка строки с полиномом на корректность
{
	for (int i = 0; i < polynom.size(); i++)
		if (!IsValidCharacter(polynom[i]))
			return false;
	return true;
}
double ReturnCoeff(string monom) //вернуть коэффициент из монома
{
	string flag;
	for (int i = 0; i < monom.size(); i++)
		if (monom[i] != 'x')
			flag += monom[i];
		else break;
	return stod(flag);
}
int ReturnDeg(string monom) //вернуть свернутую степень у монома
{
	string flag;
	for (int i = 0; i < monom.size(); i++)
		if (monom[i] == 'x' || monom[i] == 'y' || monom[i] == 'z')
			flag += monom[i + 1];
	return stoi(flag);
}
#endif
