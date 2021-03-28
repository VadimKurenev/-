#include <iostream>
#include <cmath>

using namespace std;

int value();

int main()
{
	setlocale(LC_ALL, "Ru");

	int n = value();
	double m_1 = 0, m_2 = 0, d = 0;

	double* e = new double[n];
	for (int i = 0; i < n; i++)
	{
		do
		{
			cout << "Введите значение " << i + 1 << ": ";
			cin >> e[i];
			if (cin.fail() || e[i] < 0)
			{
				cin.clear();
				cin.ignore(10, '\n');
				cout << "Значение введено не корректно " << endl;
			}
			else
			{
				break;
			}
		} while (true);
	}
	cout << endl;

	double* p = new double[n];

	for (int i = 0; i < n; i++)
	{
		do
		{
			cout << "Введите вероятность " << i + 1 << ": ";
			cin >> p[i];
			if (cin.fail() || p[i] < 0 || p[i] > 1)
			{
				cin.clear();
				cin.ignore(10, '\n');
				cout << "Значение введено не корректно " << endl;
			}
			else
			{
				break;
			}
		} while (true);
	}

	for (int i = 0; i < n; i++)
	{
		m_1 += e[i] * p[i];
	}

	for (int i = 0; i < n; i++)
	{
		m_2 += pow(e[i], 2) * p[i];
	}

	d = m_2 - pow(m_1, 2);

	delete[] e;
	delete[] p;
	cout << "Дисперсия случайно величины = " << d << endl;
}
int value()
{
	int n;
	while (true)
	{
		cout << "Введите количество элементов массива: ";
		cin >> n;
		if (cin.fail() || n < 0)
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout << "Значение введено не корректно " << endl;
		}
		else
		{
			return n;
		}
	}
}