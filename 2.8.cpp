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


	long int factorial = 1;
	long int composition = 0;

	for (int i = 0; i < n; i++)
	{
		composition = n - pow(2, i);
		factorial *= composition;
	}
	cout << "Двойной факториал числа " << n << "!! = " << factorial << endl;

}