#ifndef __POLYNOMIALS_H__

#define __POLYNOMIALS_H__ 

#include "list.h"
#include <string>
#include <sstream>
#include <random>


inline bool IsVariable(char character); // переменная или нет?
inline bool _IsOperation(char ch);//операция?
inline bool IsNumber(char character); // проверка на степень
inline bool IsValidCharacter(char ch); //проверка символа на допустимое значение
inline bool IsPolynomCorrect(string polynom); //проверка строки с полиномом на корректность
inline double ReturnCoeff(string monom);
inline int ReturnDeg(string monom);

struct Monom
{
	double coeff; //коэффициент
	int deg; //свернутая степень
	Monom(double _coeff = 0, int _deg = 0) : coeff(_coeff), deg(_deg) {} // конструктор 
	bool operator>= (const Monom & _monom) //перегрузка сравнения для монома
	{
		if (deg >= _monom.deg)
			return true;
		return false;
	}
	bool operator== (const Monom & _monom) //র椰󧪠 񰠢鿠嬿 �ﭠ
	{
		if (deg == _monom.deg)
			return true;
		return false;
	}
	bool operator> (const Monom & _monom) //র椰󧪠 񰠢鿠嬿 �ﭠ
	{
		if (deg > _monom.deg)
			return true;
		return false;
	}
	Monom operator+(const Monom & m)
	{
		return Monom(coeff + m.coeff, deg);
	}
};

class Polynom
{
	List<Monom> monoms; //упорядоченный по степеням список мономов
	string form; //строка - представление многочлена в алгебраическом виде 

public:
	Polynom() : monoms(), form() {}
	Polynom(string _form) :monoms(), form(_form) //конструктор 1
	{
		string str;
		for (int i = 0; i < form.size(); i++)
		{
			if (_IsOperation(form[i]))
			{
				Monom mon(ReturnCoeff(str), ReturnDeg(str));
				monoms.Insert(mon);
				str.clear();
				if (form[i] == '-')
					str += '-';
				continue;
			}
			str += form[i];
		}
		Monom mon(ReturnCoeff(str), ReturnDeg(str));
		monoms.Insert(mon);
		Similar();
	}
	Polynom(List<Monom> _monoms) : monoms(_monoms) // конструктор 2
	{
		string degs;
		for (int i = 0; i < monoms.Size(); i++)
		{
			ostringstream ss;
			ss << monoms[i].coeff;
			if (monoms[i].coeff > 0 && i != 0)
				form += '+';
			form += ss.str();
			ss.str("");
			ss.clear();
			ss << monoms[i].deg;
			if (ss.str().size() == 1)
				degs += "00";
			else if (ss.str().size() == 2)
				degs += '0';
			degs += ss.str();
			form = form + 'x' + degs[0] + 'y' + degs[1] + 'z' + degs[2];
			degs.clear();
		}
		if (form.size() == 0)
			form = "0";
	}
	void Change(List<Monom> _monoms)
	{
		monoms = _monoms;
		form.clear();
		string degs;
		for (int i = 0; i < monoms.Size(); i++)
		{
			ostringstream ss;
			ss << monoms[i].coeff;
			if (monoms[i].coeff > 0 && i != 0)
				form += '+';
			form += ss.str();
			ss.str("");
			ss.clear();
			ss << monoms[i].deg;
			if (ss.str().size() == 1)
				degs += "00";
			else if (ss.str().size() == 2)
				degs += '0';
			degs += ss.str();
			form = form + 'x' + degs[0] + 'y' + degs[1] + 'z' + degs[2];
			degs.clear();
		}
		if (form.size() == 0)
			form = "0";
	}
	string ReturnForm()
	{
		return form;
	}
	void Similar()
	{
		if (monoms.Size() == 1)
			return;
		int j = 1, i = 0;
		while (i < monoms.Size())
		{
			while (j > i && j < monoms.Size())
			{
				if (monoms[i] == monoms[j])
				{
					if (monoms[i].coeff == -monoms[j].coeff)
					{
						monoms.Delete(j);
						monoms.Delete(i);
						j--;
						continue;
					}
					monoms.Merge(i, j);
					j--;
				}
				j++;
			}
			i++;
			j = i + 1;
		}
		Polynom p(monoms);
		form = p.ReturnForm();
	}
	Monom MaxDegY()
	{
		Monom max = monoms[0];
		for (int i = 1; i < monoms.Size(); i++)
		{
			if ((monoms[i].deg / 10) % 10 > (max.deg /10) % 10)
				max = monoms[i];
		}
		return max;
	}
	Monom MaxDegZ()
	{
		Monom max = monoms[0];
		for (int i = 1; i < monoms.Size(); i++)
		{
			if ((monoms[i].deg % 100) % 10 > (max.deg % 100) % 10)
				max = monoms[i];
		}
		return max;
	}
	Polynom Add(Polynom & polynom)
	{
		List<Monom> l;
		int i = 0, j = 0;
		while (i < monoms.Size())
		{
			l.Insert(monoms[i]);
			i++;
		}
		while (j < polynom.monoms.Size())
		{
			l.Insert(polynom.monoms[j]);
			j++;
		}
		Polynom p(l);
		p.Similar();
		return p;
	}
	Polynom MullConst(double c)
	{
		List<Monom> l;
		int i = 0;
		while (i < monoms.Size())
		{
			Monom m = monoms[i];
			m.coeff *= c;
			l.Insert(m);
			i++;
		}
		Polynom p(l);
		return p;
	}
	Polynom Sub(Polynom & polynom)
	{
		Polynom p = polynom.MullConst(-1.0);
		return p.Add(*this);
	}
	Polynom Mult(Polynom & polynom)
	{
		List<Monom> multMonoms;
		int i = 0, j = 0;
		while (i < monoms.Size())
		{
			while (j < polynom.monoms.Size())
			{
				Monom m(monoms[i].coeff * polynom.monoms[j].coeff, monoms[i].deg + polynom.monoms[j].deg);
				multMonoms.Insert(m);
				j++;
			}
			i++;
			j = 0;
		}
		Polynom p(multMonoms);
		p.Similar();
		return p;
	}
	Polynom Partial(int a) 
	{
		List<Monom> monomPatrial;
		Monom mn(0, 0.0);
		int i = 0;
		if (a == 0)
		{
			while (i < monoms.Size())
			{
				if (monoms[i].deg / 100 == 0)
				{
					i++;
					continue;
				}
				mn.coeff = monoms[i].coeff * (monoms[i].deg / 100);
				mn.deg = monoms[i].deg - 100;
				monomPatrial.Insert(mn);
				i++;
			}
		}
		else if (a == 1)
		{
			while (i < monoms.Size())
			{
				if (monoms[i].deg % 100 / 10 == 0)
				{
					i++;
					continue;
				}
				mn.coeff = monoms[i].coeff * (monoms[i].deg % 100 / 10);
				mn.deg = monoms[i].deg - 10;
				monomPatrial.Insert(mn);
				i++;
			}
		}
		else
		{
			while (i < monoms.Size())
			{
				if (monoms[i].deg % 100 % 10 == 0)
				{
					i++;
					continue;
				}
				mn.coeff = monoms[i].coeff * (monoms[i].deg % 100 % 10);
				mn.deg = monoms[i].deg - 1;
				monomPatrial.Insert(mn);
				i++;
			}
		}
		Polynom p(monomPatrial);
		p.Similar();
		return p;
	}
	Polynom Integration(int a) 
	{
		List<Monom> monomPatrial;
		Monom mn(0, 0.0);
		double m;
		int i = 0;
		if (a == 0)
		{
			while (i < monoms.Size())
			{
				m = (double)1 / ((monoms[i].deg + 100) / 100);
				mn.coeff = monoms[i].coeff * m;
				mn.deg = monoms[i].deg + 100;
				monomPatrial.Insert(mn);
				i++;
			}
		}
		else if (a == 1)
		{
			while (i < monoms.Size())
			{
				m = (double)1 / (((monoms[i].deg + 110)%100) / 10);
				mn.coeff = monoms[i].coeff * m;
				mn.deg = monoms[i].deg + 10;
				monomPatrial.Insert(mn);
				i++;
			}
		}
		else
		{
			while (i < monoms.Size())
			{
				m = (double)1 / ((monoms[i].deg + 101) % 10);
				mn.coeff = monoms[i].coeff * m;
				mn.deg = monoms[i].deg + 1;
				monomPatrial.Insert(mn);
				i++;
			}
		}
		Polynom p(monomPatrial);
		p.Similar();
		return p;
	}
	Polynom Divide(Polynom & polynom, int a)  // 0 - целая часть , 1 - остаток
	{
		List<Monom> divide;
		int flag = 0;
		if (polynom.monoms[0].deg / 100 == 0)
			flag = 1;
		if (polynom.monoms[0].deg % 10 != 0)
			flag = 2;
		if (flag == 0)
		{
			if (polynom.monoms[0].deg > monoms[0].deg)
			{
				if (a == 0)
					return Polynom();
				return *this;
			}
			Polynom p = *(this);
			Polynom z;
			while (p.monoms[0].deg >= polynom.monoms[0].deg)
			{
				List<Monom> tmp;
				Monom m((p.monoms[0].coeff / polynom.monoms[0].coeff), p.monoms[0].deg - polynom.monoms[0].deg);
				tmp.Insert(m);
				divide.Insert(m);
				Polynom pflag(tmp);
				z = pflag;
				Polynom mult = polynom.Mult(pflag);
				p = p.Sub(mult);
				tmp.Delete(0);
			}
			if (a == 0)
			{
				Polynom m(divide);
				return m;
			}
			return p;
		}
		else if(flag == 1)
		{
			if (polynom.MaxDegY() > MaxDegY())
			{
				if (a == 0)
					return Polynom();
				return *this;
			}
			Polynom p = *(this);
			Polynom z;
			while (p.MaxDegY().deg % 100 >= polynom.MaxDegY().deg % 100)
			{
				List<Monom> tmp;
				Monom m((p.MaxDegY().coeff / polynom.MaxDegY().coeff), p.MaxDegY().deg - polynom.MaxDegY().deg);
				divide.Insert(m);
				tmp.Insert(m);
				Polynom pflag(tmp);
				z = pflag;
				Polynom mult = polynom.Mult(pflag);
				p = p.Sub(mult);
			}
			if (a == 0)
			{
				Polynom m(divide);
				return m;
			}
			return p;
		}
		else
		{
			if (polynom.MaxDegZ() > MaxDegZ())
			{
				if (a == 0)
					return Polynom();
				return *this;
			}
			Polynom p = *(this);
			Polynom z;
			while (p.MaxDegZ().deg % 10 >= polynom.MaxDegZ().deg % 10)
			{
				List<Monom> tmp;
				Monom m((p.MaxDegZ().coeff / polynom.MaxDegZ().coeff), p.MaxDegZ().deg - polynom.MaxDegZ().deg);
				divide.Insert(m);
				tmp.Insert(m);
				Polynom pflag(tmp);
				z = pflag;
				Polynom mult = polynom.Mult(pflag);
				p = p.Sub(mult);
			}
			if (a == 0)
			{
				Polynom m(divide);
				return m;
			}
			return p;
		}
	}
	double Calculate(double x, double y, double z)
	{
		double result = 0;
		double x1 = 1, y1 = 1, z1 = 1;
		int i = 0;
		while (i < monoms.Size())
		{
			for (int j = 0; j < monoms[i].deg / 100; j++)
				x1 *= x;
			for (int j = 0; j < (monoms[i].deg % 100) / 10; j++)
				y1 *= y;
			for (int j = 0; j < monoms[i].deg % 10; j++)
				z1 *= z;
			result += monoms[i].coeff*x1*y1*z1;
			i++;
		}
		return result;
	}
	static Polynom GenerationPolynom()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1, 9);
		uniform_int_distribution<> rnd(0,999);
		int n = dis(gen);
		List<Monom> l;
		for (int i = 0; i < n; i++)
		{
			double c = dis(gen);
			int deg = rnd(gen);
			Monom m(c, deg);
			l.Insert(m);
		}
		Polynom p(l);
		p.Similar();
		return p;
	}
};

inline bool IsVariable(char character) // переменная или нет?
{
	if (character == 'x' || character == 'y' || character == 'z')
		return true;
	else return false;
}
inline bool _IsOperation(char ch) //операция?
{
	if (ch == '+' || ch == '-')
		return true;
	return false;
}
inline bool IsNumber(char character) // проверка на степень
{
	for (char i = '0'; i <= '9'; i++)
		if (character == i)
			return true;
	return false;
}
inline bool IsValidCharacter(char ch) //проверка символа на допустимое значение
{
	if (IsVariable(ch) || _IsOperation(ch) || IsNumber(ch))
		return true;
	return false;
}
inline bool IsPolynomCorrect(string polynom) //проверка строки с полиномом на корректность
{
	for (int i = 0; i < polynom.size(); i++)
		if (!IsValidCharacter(polynom[i]))
			return false;
	return true;
}
inline double ReturnCoeff(string monom) //вернуть коэффициент из монома
{
	string flag;
	for (int i = 0; i < monom.size(); i++)
		if (monom[i] != 'x')
			flag += monom[i];
		else break;
		return stod(flag);
}
inline int ReturnDeg(string monom) //вернуть свернутую степень у монома
{
	string flag;
	for (int i = 0; i < monom.size(); i++)
		if (monom[i] == 'x' || monom[i] == 'y' || monom[i] == 'z')
			flag += monom[i + 1];
	return stoi(flag);
}

#endif
