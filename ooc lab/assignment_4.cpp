#include <iostream>
using namespace std;

class Complex
{
    float real, img;

public:
    void setComplex(float x, float y)
    {
        real = x;
        img = y;
    }

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = real * c.real - img * c.img;
        temp.img = real * c.img + img * c.real;
        return temp;
    }

    friend Complex operator-(Complex c1, Complex c2);
    friend Complex operator/(Complex c1, Complex c2);

    void printComplex()
    {
        cout << real << " + " << img << "i" << endl;
    }
};

Complex operator-(Complex c1, Complex c2)
{

    Complex temp;
    temp.real = c1.real - c2.real;
    temp.img = c1.img - c2.img;
    return temp;
}

Complex operator/(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = (c1.real * c2.real + c1.img * c2.img) / (c2.real * c2.real + c2.img * c2.img);
    temp.img = (c1.img * c2.real - c1.real * c2.img) / (c2.real * c2.real + c2.img * c2.img);
    return temp;
}

int main()
{
    Complex x, y;
    Complex a, b, c, d;

    x.setComplex(3, 4);
    y.setComplex(5, 6);

    cout << "Complex 1: ";
    x.printComplex();
    cout << "Complex 2: ";
    y.printComplex();
    cout << endl;

    a = x + y;
    b = x - y;
    c = x * y;
    d = x / y;

    cout << "Addition: ";
    a.printComplex();
    cout << "Subtraction: ";
    b.printComplex();
    cout << "Multiplication: ";
    c.printComplex();
    cout << "Division: ";
    d.printComplex();

    return 0;
}