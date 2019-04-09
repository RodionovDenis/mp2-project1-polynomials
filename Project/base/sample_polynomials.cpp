#include "postfix.h"
#include <clocale>
#include <conio.h>

//таблицы

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
n:cout << "Выберите действие:" << endl;
	cout << "1. Добавить полином" << endl;
	cout << "2. Сгенерировать n полиномов" << endl;
	cout << "3. Удалить полином" << endl;
	cout << "4. Алгебра полиномов" << endl;
	cout << "5. Распечатать таблицу" << endl;
	cout << "6. Выйти из программы" << endl;
	cout << "->";
	cin >> tmp;
	switch (tmp)
	{
	case '1':
	{
		system("cls");
		cout << "Введите полином" << endl;
		cout << "Пример полинома: 1x5y2z4+1.5x1y1z1-5x0y0z0" << endl;
		cout << "Важен порядок переменных" << endl;
		cout << "->";
		cin >> frm;
		cout << "Введите название текущего полинома." << endl;
		cout << "->";
		cin >> name;
		Polynom p(frm);
		AddAll(p, name);
		cout << "Полином успешно добавлен." << endl;
		_sleep(800);
		system("cls");
		goto n;
	}
	case '2':
	{
		system("cls");
		name = "gen1";
		char v = '1';
		cout << "Название сгенерированных полиномов: gen*" << endl;
		cout << "Введите n=";
		cin >> a;
		cout << "Сгенерировались следующие полиномы: " << endl << endl;
		for (int i = 0; i < a; i++, v++)
		{
			Polynom p = Polynom::GenerationPolynom();
			name[3] = v;
			cout << i + 1 << ". " << name << " : " << p.ReturnForm() << endl;
			AddAll(p, name);
		}
		cout << endl << "Генерация прошла успешно." << endl;
		_sleep(3000);
		system("cls");
		goto n;
	}
	case '3':
	{
		system("cls");
		cout << "Таблица полиномов на данный момент: " << endl << endl;
		arro.Print();
		cout << endl << "Введите название полинома, который желаете удалить:" << endl;
		cout << "->";
		cin >> name;
		if (arro.Find(name) == nullptr)
			cout << "Полином с таким названием отсутствует." << endl;
		else
		{
			DeleteAll(name);
			cout << "Полином успешно удален." << endl;
		}
		_sleep(800);
		system("cls");
		goto n;
	}
	case '4':
	{
	metka:	system("cls");
		char b;
		cout << "1. Алгебраическое выражение" << endl;
		cout << "2. Дифференцирование" << endl;
		cout << "3. Интегрирование" << endl;
		cout << "4. Вычисление в точке" << endl;
		cout << "5. Вернуться назад" << endl;
		cout << "->";
		cin >> b;
		switch (b)
		{
		case '1':
		{
			system("cls");
			string exp;
			cout << "Введите алгебраическое выражение следующего вида:" << endl;
			cout << "Пример алгебраического выражения: a+b*c, где a,b,c - соотвествующие имена полиномов" << endl << endl;
			cout << "Таблица полиномов на данный момент:" << endl << endl;
			arro.Print();
			cout << endl << "Введите алгебраическое выражение:" << endl;
			cout << "->";
			cin >> exp;
			TPostfix postf(exp, arro);
			postf.ToPostfix();
			postf.ReadArguments();
			Polynom p = postf.Calculate();
			cout << "Результат вычисления:" << p.ReturnForm() << endl;
			cout << "Нажмите любую кнопку." << endl;
			_getch();
			goto metka;
		}
		case '2':
		{
			system("cls");
			string exp;
			cout << "Таблица полиномов на данный момент:" << endl << endl;
			arro.Print();
			cout << endl << "Введите название полинома, который хотите продифференцировать:" << endl;
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
			cout << "Таблица полиномов на данный момент:" << endl << endl;
			arro.Print();
			cout << endl << "Введите название полинома, который хотите проинтегрировать:" << endl;
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
			cout << "Таблица полиномов на данный момент:" << endl << endl;
			arro.Print();
			cout << endl << "Введите название полинома для вычисления в точке:" << endl;
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
			cout << "Результат: " << arro.Find(exp)->data.Calculate(x, y, z) << endl;
			cout << "Нажмите любую кнопку." << endl;
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
		cout << "1. Цепочная хэш-таблица" << endl;
		cout << "2. Хэш-таблица - открытая адресация" << endl;
		cout << "3. Линейная на массиве" << endl;
		cout << "4. Упорядоченная на массиве" << endl;
		cout << "5. Линейная на списке" << endl;
		cout << "6. Дерево поиска" << endl;
		cout << "7. Вернуться назад" << endl;
		cout << "->";
		cin >> w;
		switch (w)
		{
		case '1':
		{
			system("cls");
			cout << "Цепочная хэш-таблица: " << endl << endl;
			ht1.Print();
			cout << endl << "Нажмите любую кнопку" << endl;
			_getch();
			goto k;
		}
		case '2':
		{
			system("cls");
			cout << "Хэш-таблица - открытая адресация:" << endl << endl;
			ht2.Print();
			cout << endl << "Нажмите любую кнопку" << endl;
			_getch();
			goto k;
		}
		case '3':
		{
			system("cls");
			cout << "Линейная на массиве:" << endl << endl;
			arrl.Print();
			cout << endl << "Нажмите любую кнопку" << endl;
			_getch();
			goto k;
		}
		case '4':
		{
			system("cls");
			cout << "Упорядоченная на массиве: " << endl << endl;
			arro.Print();
			cout << endl << "Нажмите любую кнопку" << endl;
			_getch();
			goto k;
		}
		case '5':
		{
			system("cls");
			cout << "Линейная на списке: " << endl << endl;
			list.Print();
			cout << endl << "Нажмите любую кнопку" << endl;
			_getch();
			goto k;
		}
		case '6':
		{
			system("cls");
			cout << "Дерево поиска:" << endl << endl;
			tree.Print();
			cout << endl << "Нажмите любую кнопку" << endl;
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