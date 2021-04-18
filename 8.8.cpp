#include <iostream>
#include <cmath>
#define Pi 3.14

using namespace std;

class complex_class
{
public:
    double Re;
    double Im;

    void algebr_form()
    {
        cout << "\nКомплексное число z в алгебраической форме: " << Re << " + i" << Im << endl;
    }

    void trig_to_algebr_form()
    {
        double fi = atan(Im / Re) * 180.0 / Pi;
        double p = sqrt(Re * Re + Im * Im);

        cout << "Тригонометрическая форма числа z: " << p << "(cos(" << fi << ") + i * sin(" << fi << "))" << endl;
    }
};

double value()
{
    while (true)
    {
        double value;
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(4000, '\n');
            cout << "Некорректный ввод, повторите ввод: ";
        }
        else
        {
            cin.ignore(4000, '\n');
            return value;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    complex_class a;

    cout << "Введите число x: ";
    a.Re = value();

    cout << "Введите число y: ";
    a.Im = value();

    a.algebr_form();
    a.trig_to_algebr_form();

    return 0;
}