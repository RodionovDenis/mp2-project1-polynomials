#include "postfix.h"
#include <clocale>
#include <conio.h>

//�������

HashTable1 ht1;
HashTable2 ht2;
LinearArray arrl;
OrderedArray arro;
ListTable list;
SearchTree tree;

void AddAll(Polynom _data, string _key);
void DeleteAll(string _key);

int main()
{
	setlocale(LC_ALL, "Russian");
	char tmp;
	int a;
	string frm;
	string name;
n:cout << "�������� ��������:" << endl;
	cout << "1. �������� �������" << endl;
	cout << "2. ������������� n ���������" << endl;
	cout << "3. ������� �������" << endl;
	cout << "4. ������� ���������" << endl;
	cout << "5. ����������� �������" << endl;
	cout << "6. ����� �� ���������" << endl;
	cout << "->";
	cin >> tmp;
	switch (tmp)
	{
	case '1':
	{
		system("cls");
		cout << "������� �������" << endl;
		cout << "������ ��������: 1x5y2z4+1.5x1y1z1-5x0y0z0" << endl;
		cout << "����� ������� ����������" << endl;
		cout << "->";
		cin >> frm;
		cout << "������� �������� �������� ��������." << endl;
		cout << "->";
		cin >> name;
		Polynom p(frm);
		AddAll(p, name);
		cout << "������� ������� ��������." << endl;
		_sleep(800);
		system("cls");
		goto n;
	}
	case '2':
	{
		system("cls");
		name = "gen1";
		char v = '1';
		cout << "�������� ��������������� ���������: gen*" << endl;
		cout << "������� n=";
		cin >> a;
		cout << "��������������� ��������� ��������: " << endl << endl;
		for (int i = 0; i < a; i++, v++)
		{
			Polynom p = Polynom::GenerationPolynom();
			name[3] = v;
			cout << i + 1 << ". " << name << " : " << p.ReturnForm() << endl;
			AddAll(p, name);
		}
		cout << endl << "��������� ������ �������." << endl;
		_sleep(3000);
		system("cls");
		goto n;
	}
	case '3':
	{
		system("cls");
		cout << "������� ��������� �� ������ ������: " << endl << endl;
		arro.Print();
		cout << endl << "������� �������� ��������, ������� ������� �������:" << endl;
		cout << "->";
		cin >> name;
		if (arro.Find(name) == nullptr)
			cout << "������� � ����� ��������� �����������." << endl;
		else
		{
			DeleteAll(name);
			cout << "������� ������� ������." << endl;
		}
		_sleep(800);
		system("cls");
		goto n;
	}
	case '4':
	{
	metka:	system("cls");
		char b;
		cout << "1. �������������� ���������" << endl;
		cout << "2. �����������������" << endl;
		cout << "3. ��������������" << endl;
		cout << "4. ���������� � �����" << endl;
		cout << "5. ��������� �����" << endl;
		cout << "->";
		cin >> b;
		switch (b)
		{
		case '1':
		{
			system("cls");
			string exp;
			cout << "������� �������������� ��������� ���������� ����:" << endl;
			cout << "������ ��������������� ���������: a+b*c, ��� a,b,c - �������������� ����� ���������" << endl << endl;
			cout << "������� ��������� �� ������ ������:" << endl << endl;
			arro.Print();
			cout << endl << "������� �������������� ���������:" << endl;
			cout << "->";
			cin >> exp;
			TPostfix postf(exp, arro);
			postf.ToPostfix();
			postf.ReadArguments();
			Polynom p = postf.Calculate();
			cout << "��������� ����������:" << p.ReturnForm() << endl;
			cout << "������� ����� ������." << endl;
			_getch();
			goto metka;
		}
		case '2':
		{
			system("cls");
			string exp;
			cout << "������� ��������� �� ������ ������:" << endl << endl;
			arro.Print();
			cout << endl << "������� �������� ��������, ������� ������ �������������������:" << endl;
			cout << "->";
			cin >> exp;
			cout << endl << "dx : " << arro.Find(exp)->data.Partial(0).ReturnForm() << endl;
			cout << "dy : " << arro.Find(exp)->data.Partial(1).ReturnForm() << endl;
			cout << "dz : " << arro.Find(exp)->data.Partial(2).ReturnForm() << endl;
		}
		case '3':
		{
			system("cls");
			string exp;
			cout << "������� ��������� �� ������ ������:" << endl << endl;
			arro.Print();
			cout << endl << "������� �������� ��������, ������� ������ ����������������:" << endl;
			cout << "->";
			cin >> exp;
			cout << endl << "dx : " << arro.Find(exp)->data.Integration(0).ReturnForm() << endl;
			cout << "dy : " << arro.Find(exp)->data.Integration(1).ReturnForm() << endl;
			cout << "dz : " << arro.Find(exp)->data.Integration(2).ReturnForm() << endl;
		}
		case '4':
		{
			system("cls");
			string exp;
			cout << "������� ��������� �� ������ ������:" << endl << endl;
			arro.Print();
			cout << endl << "������� �������� �������� ��� ���������� � �����:" << endl;
			cout << "->";
			cin >> exp;
			double x;
			double y;
			double z;
			cout << "x->";
			cin >> x;
			cout << "y->";
			cin >> y;
			cout << "z->";
			cin >> z;
			cout << "���������: " << arro.Find(exp)->data.Calculate(x, y, z) << endl;
			cout << "������� ����� ������." << endl;
			_getch();
			goto metka;
		}
		case '5':
		{
			system("cls");
			goto n;
		}
		}
	}
	case '5':
	{
		char w;
	k:	system("cls");
		cout << "1. �������� ���-�������" << endl;
		cout << "2. ���-������� - �������� ���������" << endl;
		cout << "3. �������� �� �������" << endl;
		cout << "4. ������������� �� �������" << endl;
		cout << "5. �������� �� ������" << endl;
		cout << "6. ������ ������" << endl;
		cout << "7. ��������� �����" << endl;
		cout << "->";
		cin >> w;
		switch (w)
		{
		case '1':
		{
			system("cls");
			cout << "�������� ���-�������: " << endl << endl;
			ht1.Print();
			cout << endl << "������� ����� ������" << endl;
			_getch();
			goto k;
		}
		case '2':
		{
			system("cls");
			cout << "���-������� - �������� ���������:" << endl << endl;
			ht2.Print();
			cout << endl << "������� ����� ������" << endl;
			_getch();
			goto k;
		}
		case '3':
		{
			system("cls");
			cout << "�������� �� �������:" << endl << endl;
			arrl.Print();
			cout << endl << "������� ����� ������" << endl;
			_getch();
			goto k;
		}
		case '4':
		{
			system("cls");
			cout << "������������� �� �������: " << endl << endl;
			arro.Print();
			cout << endl << "������� ����� ������" << endl;
			_getch();
			goto k;
		}
		case '5':
		{
			system("cls");
			cout << "�������� �� ������: " << endl << endl;
			list.Print();
			cout << endl << "������� ����� ������" << endl;
			_getch();
			goto k;
		}
		case '6':
		{
			system("cls");
			cout << "������ ������:" << endl << endl;
			tree.Print();
			cout << endl << "������� ����� ������" << endl;
			_getch();
			goto k;
		}
		case '7':
		{
			system("cls");
			goto n;
		}
		}
	}
	case '6': break;
	}

}


void AddAll(Polynom _data, string _key)
{
	ht1.Add(_data, _key);
	ht2.Add(_data, _key);
	arrl.Add(_data, _key);
	arro.Add(_data, _key);
	list.Add(_data, _key);
	tree.Add(_data, _key);
}
void DeleteAll(string _key)
{
	ht1.Remove(_key);
	ht2.Remove(_key);
	arrl.Remove(_key);
	arro.Remove(_key);
	list.Remove(_key);
	tree.Remove(_key);
}