#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");

    int t;
    do
    {
        cout << "Введите время t = ";
        cin >> t;

        if (cin.fail() || t <= 0)
        {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Ошибка! Неверный ввод данных!" << endl;
        }
        else
        {
            break;
        }

    } while (true);

    int v;
    do
    {
        cout << "Введите скорость V = ";
        cin >> v;

        if (cin.fail() || v <= 0)
        {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Ошибка! Неверный ввод данных!" << endl;
        }
        else
        {
            break;
        }

    } while (true);

    double a = v / t;
    double s, s_1, s_2, s_save;
    s_1 = v * t;
    s_2 = (a * pow(t, 2)) / 2;
    s = s_1 + s_2;
    cout << "Путь пройденный поездом = " << s << endl;
    s_save = (3 * v * t) / 2;
    cout << "Путь пройденный поездом проверка = " << s_save << endl;
}
