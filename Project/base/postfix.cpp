#include "postfix.h"
#include "stack.h"

bool IsOperation(char elem);
bool IsOperationForCorrect(char elem);
int Priority(char elem);
Polynom Result(Polynom & op1, Polynom & op2, char operat);
bool IsNumber(char elem);

string TPostfix::GetInfix()
{
	return infix;
}
string TPostfix::GetPostfix()
{
	return postfix;
}
void TPostfix::ChangeInfix(string _infix)
{
	infix = _infix;
	postfix.clear();
}
bool TPostfix::IsCorrect() //проверка на корректность выражения
{
	int flag = 0;
	stackOperation.Clear();
	if (IsOperationForCorrect(infix[0]) || IsOperationForCorrect(infix[infix.size() - 1]))//выражение не начинается и не заканчивается операцией
		return false;
	for (int i = 1; i < infix.size() - 1; i++) // в выражении нет двух операций подряд
		if (IsOperationForCorrect(infix[i]) && IsOperationForCorrect(infix[i + 1]))
			return false;
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
			stackOperation.Push(1);
		if (infix[i] == ')')
		{
			if (stackOperation.IsEmpty())
				flag = 1;
			stackOperation.Erase();
		}
	}
	if (flag)
		return false;
	return (stackOperation.IsEmpty()) ? true : false;
}
void TPostfix::ToPostfix() // получение постфикса
{
	stackOperation.Clear();
	int a = 0;
	for (int i = 0; i < infix.size(); i++)
	{
		if (!IsOperation(infix[i]))
		{
			postfix += infix[i];
			if (i == infix.size() - 1 || IsOperation(infix[i + 1]))
				postfix += ' ';
		}
		else
		{
			if (infix[i] != ')')
			{
				if (Priority(infix[i]) == 0 || stackOperation.IsEmpty() || Priority(infix[i]) > Priority(stackOperation.PopWithoutDelete()))
					stackOperation.Push(infix[i]);
				else
				{
					a = stackOperation.Length();
					for (int j = 0; j < a; j++)
					{
						if (Priority(stackOperation.PopWithoutDelete()) >= Priority(infix[i]))
						{
							postfix += stackOperation.Pop();
							postfix += ' ';
						}
						else
							break;
					}
					stackOperation.Push(infix[i]);
				}
			}
			else
			{
				a = stackOperation.Length();
				for (int j = 0; j < a; j++)
				{
					if (stackOperation.PopWithoutDelete() != '(')
					{
						postfix += stackOperation.Pop();
						postfix += ' ';
					}
					else
					{
						stackOperation.Erase();
						break;
					}
				}
			}
		}
	}
	a = stackOperation.Length();
	for (int j = 0; j < a; j++)
	{
		postfix += stackOperation.Pop();
		if (j != a - 1)
			postfix += ' ';
	}
}
void TPostfix::ReadArguments() //ввод значений переменных
{
	stackArguments.Clear();
	stackValue.Clear();
	string ss;
	for (int i = infix.size() - 1; i >= 0; i--)
		if (!IsOperation(infix[i]) && !IsNumber(infix[i]) && infix[i] != '.')
		{
			ss += infix[i];
			if (i != 0 && !IsOperation(infix[i - 1]) && !IsNumber(infix[i - 1]))
				continue;
			reverse(ss.begin(), ss.end());
			stackArguments.Push(ss);
			ss.clear();
		}
	int res = stackArguments.Length();
	value = new Polynom[res];
	for (int i = 0; i < res; i++)
		value[i] = polinoms.Find(stackArguments.Pop())->data;
	for (int i = res - 1; i >= 0; i--)
		stackValue.Push(value[i]);
}
Polynom TPostfix::Calculate() // вычисление
{
	stackValuePostfix.Clear();
	Polynom tmp;
	string ss;
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] != ' ')
		{
			if (!IsOperation(postfix[i]))
			{
				if (i != postfix.size() - 1 && postfix[i + 1] != ' ')
					continue;
				stackValuePostfix.Push(stackValue.Pop());
			}
			else
			{
				tmp = Result(stackValuePostfix.Pop(), stackValuePostfix.Pop(), postfix[i]);
				stackValuePostfix.Push(tmp);
			}
		}
		else continue;
	}
	return stackValuePostfix.Pop();
}

bool IsOperation(char elem)
{
	return (elem == '(' || elem == ')' || elem == '+' || elem == '-' || elem == '*' || elem == '/') ? true : false;
}

bool IsOperationForCorrect(char elem)
{
	return (elem == '+' || elem == '-' || elem == '*' || elem == '/') ? true : false;
}

int Priority(char elem)
{
	if (!IsOperation(elem))
		throw "data is not correct";
	if (elem == '(')
		return 0;
	else if (elem == ')')
		return 1;
	else if (elem == '+' || elem == '-')
		return 2;
	return 3;
}

Polynom Result(Polynom & op1, Polynom & op2, char operat)
{
	if (operat == '+')
		return op1.Add(op2);
	else if (operat == '-')
		return op1.Sub(op2);
	else if (operat == '*')
		return op1.Mult(op2);
	else
		return op1.Divide(op2, 0);
}
