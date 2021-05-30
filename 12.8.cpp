#include <cmath>
#include <iostream>
using namespace std;

const double pi = 3.14;

double inpDouble();

int inpInt();

template <typename Type>
double expFoo(Type z);

long int factorNum(int x);

class Complex {
public:
    void setOneForm();
    void printComplexNumber();
    Complex exponentComplex();

private:
    void transitForm();
    double x, y;
    double absb, phi;
    bool expForm = false;
    bool trigForm = false;
};

void Complex::setOneForm()
{
    cout << "Выберите форму комплексного числа:\n" << "1 - Алгебраическая  " << "2 - Триганометрическая\n" << ">>> ";
    int type;
    while (true) {
        type = inpInt();
        if (type == 1 || type == 2)
            break;
        else
            cout << "Ошибка: Введено недопустимое значение. Введите число 1 или 2: ";
    }

    if (type == 1) {
        cout << "Алгебраическая форма: х + у * i" << endl;;
        cout << "Введите х: ";
        x = inpDouble();

        cout << "Введите y: ";
        y = inpDouble();
        cout << endl;

        expForm = true;
        transitForm();
    }

    if (type == 2) {
        cout << "Триганометрическая форма комплексного числа: |z| * (cos(phi) + i * sin(phi)" << endl;
        cout << "Введите |z|: ";
        absb = inpDouble();

        cout << "Введите угол phi: ";
        phi = inpDouble();

        trigForm = true;
        transitForm();
    }
}

void Complex::printComplexNumber()
{
    cout << "Алгебраической формы: " << x << " + " << y << " * i" << endl;
    cout << "Триганометрической формы: " << absb << " * (cos(" << phi << ") + i * sin(" << phi << ")" << endl;
}

Complex Complex::exponentComplex()
{
    Complex res;
    res.x = expFoo(x);
    res.y = expFoo(y);
    res.expForm = true;
    res.transitForm();
    return res;
}

void Complex::transitForm()
{
    if (expForm) {
        absb = sqrt(pow(x, 2) + pow(y, 2));
        double cos = acos(x / absb);
        double sin = asin(y / absb);
        double stockPhi = abs(sin);

        if (sin < 0 && cos < 0)
            phi = -pi + stockPhi;
        else if (cos < 0 && sin > 0)
            phi = pi - stockPhi;
        else if (sin < 0 && cos>0)
            phi = -stockPhi;
        else if (cos > 0 && sin > 0)
            phi = stockPhi;
        else
            phi = stockPhi;
    }

    else if (trigForm) {
        x = cos(phi) * absb;
        y = sin(phi) * absb;
    }
}


int main()
{
    setlocale(LC_ALL, "RU");

    Complex num;
    num.setOneForm();

    cout << "Ваше число в комплексном виде: " << endl;
    num.printComplexNumber();

    Complex expNumber;
    expNumber = num.exponentComplex();

    cout << "\nЭкспонента от комплексного числа: " << endl;
    expNumber.printComplexNumber();
    return 0;
}

double inpDouble()
{
    while (true) {
        double num;
        cin >> num;

        if (cin.fail()) {
            cout << "Ошибка: введено недопустимое значение.\nПовторите ввод: ";
            cin.clear();
            cin.ignore(6666, '\n');
        }
        else {
            cin.ignore(6666, '\n');
            return num;
        }
    }
}

int inpInt()
{
    while (true) {
        int num;
        cin >> num;

        if (cin.fail()) {
            cout << "Ошибка: введено недопустимое значение.\nПовторите ввод: ";
            cin.clear();
            cin.ignore(3333, '\n');
        }
        else {
            cin.ignore(3333, '\n');
            return num;
        }
    }
}

long int factorNum(int x)
{
    if (x > 1)
        return x * factorNum(x - 1);
    else if (x == 0 || x == 1)
        return 1;
    else
        return 0;
}

template <typename Type>
double expFoo(Type z)
{
    z = -z;
    double temp, res = 0;
    for (int i = 0; i < 20; i++) {
        long int fact = factorNum(i);
        temp = pow(-1, i) * pow(z, i) / fact;
        res += temp;
    }
    return res;
}