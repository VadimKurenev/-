#include <iostream>
using namespace std;

class dbl_fact
{
public:
    long int n;
    void calc()
    {
        long double res = n;

        for (double i = (n - 2); i > 0; i -= 2) res *= i;

        cout << "\nДвойной факториал числа " << n << "!! = " << res << endl;
    }
};

long int value()
{
    {
        int n;
        while (true)
        {
            cout << "Введите целочисленное число n = ";
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
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Данная программа вычисляет двойной факториал числа n" << endl;

    long int factorial = value();

    dbl_fact add;
    add.n = factorial;

    add.calc();

    return 0;
}