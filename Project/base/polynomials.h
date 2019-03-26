#ifndef __POLYNOMIALS_H__
#define __POLYNOMIALS_H__ 

#include "list.h"
#include <string>

struct Monom
{
	double coeff; //�����������
	int deg; //��������� �������
	Monom(double _coeff, int _deg): coeff(_coeff), deg(_deg) {} // ����������� 
	bool operator>= (const Monom & _monom) //���������� ��������� ��� ������
	{
		if (deg >= _monom.deg)
			return true;
		return false;
	}
};

class Polynom
{
	List<Monom> monoms; //������������� �� �������� ������ �������
	string form; //������ - ������������� ���������� � �������������� ���� 
	string name; //��� ��������
public:
	Polynom(string _form, string _name) :monoms(), form(_form), name(_name) //�����������1
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
	Polynom(List<Monom> _monoms): monoms(_monoms), name("-") {} // �����������2
	{
		string degs;
		for (int i = 0; i < monoms.Size(); i++)
		{
			form += dtos(monoms[i].coeff);
			degs = itos(monoms[i].deg);
			form += 'x' += degs[0] += 'y' += degs[1] += 'z' += degs[2];
		}
	}
	/*Polynom operator+(const Polynom & polynom)
	{

	}*/
};

bool IsVariable(char character) // ���������� ��� ���?
{
	if (character == 'x' || character == 'y' || character == 'z')
		return true;
	else return false;
}
bool IsOperation(char ch) //��������?
{
	if (ch == '+' || ch == '-')
		return true;
	return false;
}
bool IsNumber(char character) // �������� �� �������
{
	for (char i = '0'; i <= '9'; i++)
		if (character == i)
			return true;
	return false;
}
bool IsValidCharacter(char ch) //�������� ������� �� ���������� ��������
{
	if (IsVariable(ch) || IsOperation(ch) || IsNumber(ch))
		return true;
	return false;
}
bool IsPolynomCorrect(string polynom) //�������� ������ � ��������� �� ������������
{
	for (int i = 0; i < polynom.size(); i++)
		if (!IsValidCharacter(polynom[i]))
			return false;
	return true;
}
double ReturnCoeff(string monom) //������� ����������� �� ������
{
	string flag;
	for (int i = 0; i < monom.size(); i++)
		if (monom[i] != 'x')
			flag += monom[i];
		else break;
	return stod(flag);
}
int ReturnDeg(string monom) //������� ��������� ������� � ������
{
	string flag;
	for (int i = 0; i < monom.size(); i++)
		if (monom[i] == 'x' || monom[i] == 'y' || monom[i] == 'z')
			flag += monom[i + 1];
	return stoi(flag);
}
#endif
