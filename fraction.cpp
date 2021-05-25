#include <iostream>

class fraction
{
private:
    int num, den;
public:
    fraction(int n = 1, int d = 1)
    {
        if (d == 0)
        {
            num = 0;
            den = 1;
            throw "Error! Number was changed to 0/1";
        }
        else
        {
            num = n;
            den = d;
            decrease();
        }
    }
    void print() const
    {
        std::cout << num << "/" << den << std::endl;
    }
    void decrease()
    {
        int a = abs(num);
        int b = abs(den);

        while (a != 0 && b != 0)
        {
            if (a > b)
            {
                a %= b;
            }
            else
            {
                b %= a;
            }
        }
        a += b;
        num /= a;
        den /= a;
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
    }
    int getnum() const
    {
        return num;
    }
    int getden() const
    {
        return den;
    }
    fraction& operator+=(const fraction& X) {
        if (den != X.den)
        {
            num = num * X.den + X.num;
            den *= X.den;
        }
        else
        {
            num = num + X.num;
        }
        return *this;
    }
    fraction& operator-=(const fraction& X) {
        if (den != X.den)
        {
            num = num * X.den - X.num;
            den *= X.den;
        }
        else
        {
            num = num - X.num;
        }
        return *this;
    }
    fraction& operator*=(const fraction& X) {
        num *= X.num;
        den *= X.den;
        return *this;
    }
    fraction& operator/=(const fraction& X) {
        num *= X.den;
        den *= X.num;
        return *this;
    }
    fraction operator+ (const fraction& X) const
    {
        if (den != X.den)
        {
            return fraction(num * X.den + X.num, den * X.den);
        }
        else
        {
            return fraction(num + X.num, den);
        }
    }
    fraction operator- (const fraction& X) const
    {
        if (den != X.den)
        {
            return fraction(num * X.den - X.num, den * X.den);
        }
        else
        {
            return fraction(num - X.num, den);
        }
    }
    fraction operator* (const fraction& X) const
    {
        return fraction(num * X.num, den * X.den);;
    }
    fraction operator/ (const fraction& X) const
    {
        return fraction(num * X.den, den * X.num);
    }
    fraction operator- ()
    {
        return fraction(-num, den);
    }

};

std::ostream& operator<<(std::ostream& out, const fraction& X) {
    out << X.getnum();
    if (X.getden() != 1) std::cout << "/" << X.getden();
    return out;
}

std::ostream& operator<<(std::ostream& out, fraction& X) {
    X.decrease();
    out << X.getnum();
    if (X.getden() != 1) std::cout << "/" << X.getden();
    return out;
}

int main()
{
    try {
        fraction A(1, 2);
        fraction B = (1, 2);
        fraction C = A + (A / B - A) + B;
        std::cout << A << '\n' << B << '\n' << C;
    }
    catch (const char* str)
    {
        std::cout << str << std::endl;
    }
}