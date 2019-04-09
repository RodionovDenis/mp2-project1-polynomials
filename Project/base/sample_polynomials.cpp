#include "list.h"
#include "polynomials.h"


int main()
{
	List<Monom> monoms;
	string form;
	Monom m1(1.5, 111);
	Monom m2(-5, 234);
	Monom m3(1, 453);
	Monom m4(2, 123);
	monoms.Insert(m1);
	monoms.Insert(m2);
	monoms.Insert(m3);
	monoms.Insert(m4);
	form = "1x2y3z2+2x1y1z6+1.5x2y2z2";
	Polynom a(monoms);
	Polynom b(form, "b");
	cout << a.Calculate(2, 1, 3) << endl;
	cout << b.Calculate(4, 2, 1) << endl;
}