#include <cmath>
#include <iostream>
#include <ctime>
using namespace std;

int scanf_number()
{
    while (true) {
        int num;
        cin >> num;
        if (cin.fail() || num <= 0) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некорректный ввод, введите положительное число" << endl;
        }
        else  return num;
    }
}

class class_Q
{
public:
    int n;
    double* a, x, result, Qx = 0;
    bool isTrue;

    void foo() {
        cout << "Введите n: ";
        n = scanf_number();
        a = new double[n + 1];
        for (int i = 0; i <= n; i++) a[i] = rand() % 10;
    }
    void show_array() {
        cout << "\nRandom a: \n";
        for (int i = 0; i <= n; i++) cout << "a[" << i << "]: " << a[i] << endl;
    }
    void calcQ(double x) {
        for (int i = 0; i <= n; i++) Qx += (a[i]) / pow(x, i);
        cout << "Q(x) = " << Qx << endl << endl;
        isTrue = true;
    }
    class_Q operator+ (int num) {
        if (isTrue == true) result = Qx + num;
        cout << "Результат сложения: " << result << endl;
        return *this;
    }
    class_Q operator- (int num) {
        if (isTrue == true) result = Qx - num;
        cout << "Результат вычитания: " << result << endl;
        return *this;
    }
    class_Q operator* (int num) {
        if (isTrue == true) result = Qx * num;
        cout << "Результат умножения Q(x) на число: " << result << endl;
        return *this;
    }
    class_Q operator/ (int num) {
        if (isTrue == true) result = Qx / num;
        cout << "Результат деления Q(x) на число: " << result << endl;
        return *this;
    }
};
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    class_Q object;
    object.foo();
    object.show_array();
    cout << endl;
    cout << "Введите x: ";
    double x = scanf_number();
    object.calcQ(x);
    cout << "Введите число на которое нужно умножениить/разделить Q(x): ";
    int  num = scanf_number();
    object + num;
    object - num;
    object* num;
    object / num;

    return 0;
}