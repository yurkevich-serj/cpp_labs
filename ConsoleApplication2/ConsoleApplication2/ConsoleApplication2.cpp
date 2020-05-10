#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber
{
private:
    double x;
    double y;
public:
    //конструкторы
    ComplexNumber();
    ComplexNumber(double x, double y);

    //вывод комплексного числа
    void showComplexNumber();

    //вычисление модуля комплексного числа
    double module();

    //перегруженные операции: сложение, вычитание, деление, умножение
    ComplexNumber operator+(ComplexNumber num);
    ComplexNumber operator-(ComplexNumber num);
    ComplexNumber operator*(ComplexNumber num);
    ComplexNumber operator/(ComplexNumber num);
};

void ComplexNumber::showComplexNumber()
{
    cout << x << showpos << y << "i" << noshowpos;
}

ComplexNumber::ComplexNumber()
{
    x = 0;
    y = 0;
}

ComplexNumber::ComplexNumber(double x, double y)
{
    this->x = x;
    this->y = y;
}

double ComplexNumber::module()
{
    return sqrt(x * x + y * y);
}

ComplexNumber ComplexNumber::operator+(ComplexNumber num)
{
    ComplexNumber newNum(x + num.x, y + num.y);
    return newNum;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber num)
{
    ComplexNumber newNum(x - num.x, y - num.y);
    return newNum;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber num)
{
    ComplexNumber newNum(x * num.x - y * num.y, y * num.x + x * num.y);
    return newNum;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber num)
{
    ComplexNumber newNum((x * num.x + y * num.y) / (num.x * num.x + num.y * num.y), (y * num.x - x * num.y) / (num.x * num.x + num.y * num.y));
    return newNum;
}

int main()
{
    ComplexNumber z1(1, 3);
    ComplexNumber z2(2, 1);

    cout << "We have two complex numbers:" << '\n';
    cout << "z1=";
    z1.showComplexNumber();
    cout << "   ";
    cout << "z2=";
    z2.showComplexNumber();
    cout << '\n';

    cout << "Module of z1:" << z1.module() << '\n';
    cout << "Module of z2:" << z2.module() << '\n';

    cout << "z1 + z2 = ";
    (z1 + z2).showComplexNumber();
    cout << '\n';
    cout << "z1 - z2 = ";
    (z1 - z2).showComplexNumber();
    cout << '\n';
    cout << "z1 * z2 = ";
    (z1 * z2).showComplexNumber();
    cout << '\n';
    cout << "z1 / z2 = ";
    (z1 / z2).showComplexNumber();
    cout << '\n';
    return 0;
}