#include <cmath>
#include <iostream>
#include <ctime>
using namespace std;

int scanf_number();

class class_Q
{
public:
    int n;
    double* a, x, * b, res, res_2, Qx_2 = 0, Qx = 0;
    bool isTrue;

    void foo() {
        cout << "Введите n: ";
        n = scanf_number();
        a = new double[n + 1];
        b = new double[n + 1];

        for (int i = 0; i <= n; i++)
        {
            a[i] = rand() % 10;
            b[i] = rand() % 10;
        }
    }
    void show_array() {
        for (int i = 0; i <= n; i++)
            cout << "a[" << i << "]: " << a[i] << endl;
        cout << endl;
    }
    void show_array_2() {
        for (int i = 0; i <= n; i++)
            cout << "b[" << i << "]: " << b[i] << endl;

    }
    void calcQ(double x) {
        for (int i = 0; i <= n; i++)
            Qx += (a[i]) / pow(x, i);
        cout << "Q1(x) = " << Qx << endl;
    }
    void calcQ_2(double x) {
        for (int i = 0; i <= n; i++)
            Qx_2 += (b[i]) / pow(x, i);
        cout << "Q2(x) = " << Qx_2 << endl;
        cout << endl;
    }
    class_Q operator+ (bool isTrue) {
        if (isTrue == true)
            res = Qx + Qx_2;
        cout << "Результат сложения Q1(x) + Q2(x): " << res << endl;
        return *this;
    }
    class_Q operator- (bool isTrue) {
        if (isTrue == true)
            res = Qx - Qx_2;
        cout << "Результат вычитания Q1(x) - Q2(x): " << res << endl;
        return *this;
    }
    class_Q operator* (int num) {
        if (num != 0) {
            res = Qx * num;
            res_2 = Qx_2 * num;
        }
        cout << "Результат умножения Q1(x) на число: " << res << endl;
        cout << "Результат умножения Q2(x) на число: " << res_2 << endl;
        return *this;
    }
    class_Q operator/ (int num) {
        if (num != 0) {
            res = Qx / num;
            res_2 = Qx_2 / num;
        }
        cout << "Результат деления Q1(x) на число: " << res << endl;
        cout << "Результат деления Q2(x) на число: " << res_2 << endl;
        return *this;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    class_Q obj;
    obj.foo();
    obj.show_array();
    obj.show_array_2();
    cout << endl;
    cout << "Введите x: ";
    double x = scanf_number();
    obj.calcQ(x);
    obj.calcQ_2(x);
    cout << "Введите число на которое нужно умножениить/разделить Q1(x) и Q2(x): ";
    int  value = scanf_number();
    obj + true;
    obj - true;
    obj* value;
    obj / value;
}

int scanf_number()
{
    while (true) {
        int num;
        cin >> num;
        if (cin.fail() || num <= 0) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некорректный ввод, введите положительное число: " << endl;
        }
        else  return num;
    }
}