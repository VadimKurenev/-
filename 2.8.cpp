#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	int n;
	do
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
			break;
		}

	} while (true);

	long int factorial = n;
	long int composition;

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
	cout << "Двойной факториал числа " << n << "!! = " << factorial << endl;
}
