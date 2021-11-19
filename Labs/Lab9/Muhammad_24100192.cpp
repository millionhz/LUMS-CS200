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

class Complex : public Integer
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
        int a_r = getNumber();
        int a_c = complex;

        int b_r = other_integer->getNumber();
        int b_c = static_cast<Complex *>(other_integer)->complex;

        setNumber((a_r * b_r) - (a_c * b_c));
        complex = (a_r * b_c) + (a_c * b_r);
    }

    void display()
    {
        cout << getNumber() << " + " << complex << "i" << endl;
    }
};

int main()
{
    while (1)
    {
        int option = 4;

        Integer *num1;
        Integer *num2;

        cout << "Select an option:" << endl;
        cout << "   1: Integer Calculator" << endl;
        cout << "   2: Complex Calculator" << endl;
        cout << "   3: Rational Calculator" << endl;
        cout << "   4: Exit Program" << endl
             << "Option >> ";
        cin >> option;

        if (option == 1)
        {
            int i1;
            int i2;

            cout << "Enter value of integer 1 >> ";
            cin >> i1;

            cout << "Enter value of integer 2 >> ";
            cin >> i2;

            num1 = new Integer(i1);
            num2 = new Integer(i2);
        }
        else if (option == 2)
        {
            int a_r;
            int a_c;
            int b_r;
            int b_c;

            cout << "Enter real part of Complex 1 >> ";
            cin >> a_r;

            cout << "Enter complex part of Complex 1 >> ";
            cin >> a_c;

            cout << "Enter real part of Complex 2 >> ";
            cin >> b_r;

            cout << "Enter complex part of Complex 2 >> ";
            cin >> b_c;

            num1 = new Complex(a_r, a_c);
            num2 = new Complex(b_r, b_c);
        }
        else if (option == 3)
        {
            int p;
            int q;
            int x;
            int y;

            cout << "Enter numerator of Rational 1 >> ";
            cin >> p;

            cout << "Enter denominator of Rational 1 >> ";
            cin >> q;

            cout << "Enter numerator of Rational 2 >> ";
            cin >> x;

            cout << "Enter denominator of Rational 2 >> ";
            cin >> y;

            num1 = new Rational(p, q);
            num2 = new Rational(x, y);
        }
        else
        {
            return 0;
        }

        //////////////////////////////////////////////

        option = 4;
        cout << endl
             << "Select an operation:" << endl;
        cout << "   1: Add" << endl;
        cout << "   2: Subtract" << endl;
        cout << "   3: Multiply" << endl;
        cout << "   4: Exit Program" << endl
             << "Option >> ";
        cin >> option;

        cout << endl;

        if (option == 1)
        {
            num1->add(num2);
            cout << "Sum is ";
            num1->display();
        }
        else if (option == 2)
        {
            num1->subtract(num2);
            cout << "Difference is ";
            num1->display();
        }
        else if (option == 3)
        {
            num1->multiply(num2);
            cout << "Product is ";
            num1->display();
        }
        else
        {
            return 0;
        }

        cout << endl;

        delete num1;
        delete num2;
    }
    return 0;
}