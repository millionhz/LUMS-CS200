#include <iostream>

using namespace std;

class Integer
{
private:
    int number;

protected:
public:
    Integer(int in_x)
    {
        setNumber(in_x);
    }

    void setNumber(int in_number)
    {
        number = in_number;
    }

    int getNumber()
    {
        return number;
    }

    virtual void add(Integer *other_integer)
    {
        number += other_integer->number;
    }

    virtual void subtract(Integer *other_integer)
    {
        number -= other_integer->number;
    }

    virtual void multiply(Integer *other_integer)
    {
        number *= other_integer->number;
    }

    virtual void display()
    {
        cout << number << endl;
    }
};

class Rational : public Integer
{
private:
    int denominator;

    int calc_gcd(int a, int b)
    {
        int gcd = 0;
        int max_val = 0;

        if (b > a)
        {
            max_val = b;
        }
        else
        {
            max_val = a;
        }

        for (int i = 1; i <= max_val; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                gcd = i;
            }
        }

        return gcd;
    }

    void reduce(int p, int q)
    {
        if (q == 0 || p == 0)
        {
            p = 0;
            q = 0;
        }
        else
        {
            int gcd = calc_gcd(p, q);
            p = p / gcd;
            q = q / gcd;
        }

        setNumber(p);
        denominator = q;
    }

    void operate(Integer *other_integer, int (*operation)(int, int))
    {
        int p = getNumber();
        int q = denominator;

        int x = other_integer->getNumber();
        int y = static_cast<Rational *>(other_integer)->denominator;

        p = operation((p * y), (x * q));
        q = q * y;

        setNumber(p);
        denominator = q;

        reduce(getNumber(), denominator);
    }

protected:
public:
    Rational(int in_numerator, int in_denominator)
        : Integer(in_numerator)
    {
        denominator = in_denominator;
    }

    void add(Integer *other_integer)
    {
        operate(other_integer, [](int a, int b)
                { return a + b; });
    }

    void subtract(Integer *other_integer)
    {
        operate(other_integer, [](int a, int b)
                { return a - b; });
    }

    void multiply(Integer *other_integer)
    {
        Integer::multiply(other_integer);
        denominator *= static_cast<Rational *>(other_integer)->denominator;
        reduce(getNumber(), denominator);
    }

    void display()
    {
        cout << getNumber() << "/" << denominator << endl;
    }
};

class Complex : protected Integer
{
private:
    int complex;

protected:
public:
    Complex(int in_real, int in_complex)
        : Integer(in_real)
    {
        complex = in_complex;
    }

    void add(Integer *other_integer)
    {
        Integer::add(other_integer);
        complex += static_cast<Complex *>(other_integer)->complex;
    }

    void subtract(Integer *other_integer)
    {
        Integer::subtract(other_integer);
        complex -= static_cast<Complex *>(other_integer)->complex;
    }

    void multiply(Integer *other_integer)
    {
    }

    void display()
    {
        cout << getNumber() << " + " << complex << "i" << endl;
    }
};

int main()
{
    Rational c1(4, 4);
    Rational c2(2, 2);

    Integer *i = &c2;

    c1.subtract(i);
    c1.display();

    return 0;
}