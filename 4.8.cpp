#include <iostream>
#include <cmath>

using namespace std;
int value();
double factorial(int n);

int main()
{
	setlocale(LC_ALL, "Ru");
	int n = value();
	cout << "Двойной факториал числа " << n << "! = " << factorial(n) << endl;
}
double factorial(int n)
{
	double factorial = n;
	double composition;
	if (n == 1)
	{
		factorial = n;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			composition = n - pow(2, i);
			factorial *= composition;
		}
	}
	return factorial;
}
int value()
{
	int n;
	while (true)
	{
		cout << "Введите число n = ";
		cin >> n;

		if (cin.fail() || n <= 0)
		{
			cin.clear();
			cin.ignore(36, '\n');
			cout << "Некорректный ввод, повторите ввод" << endl;
		}
		else
		{
			return n;
		}
	}
}