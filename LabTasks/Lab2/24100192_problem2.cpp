#include <iostream>
using namespace std;
// ! REMOVE THIS
/*A rational number is a real number that can be represented by a fraction p / q, where p and q
are integers. Create a structure �RationalNumber� with two member variables �p� and �q�.
Write the following functions for manipulating the rational numbers.

Add: Returns the sum of two rational numbers in reduced form.
	2. Subtract : Returns the difference of two rational numbers in reduced form.
	3. Multiply : Returns the product of two rational numbers in reduced form.
	4. Divide : Returns the quotient of two rational numbers in reduced form.
	5. Compare : Compare two rational numbers
		a. return 0 if two rational numbers are equal
		b. return 1 if the first rational number is greater than the second rational number
		c. return -1 if the first rational number is less than the second rational number
	* The return type of the first four functions must be a structure of type �RationalNumber�.
	* If the result of a function is 6 / 16, return the final answer in the reduced form as 3 / 8 (p = 3,
		q = 8).*/

//Instructions
// Name of the fuctions should be as mentioned.
// Do not print anything insdie the function
// Rename the file problem2.cpp and uploaded it direclty without compressing it
// There weill be 20% deduction for not following the instructions

struct RationalNumber
{
    // p / q
    int p = 0;
    int q = 0;
};

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

RationalNumber reduce(RationalNumber n)
{
    RationalNumber result;
    if (n.q == 0 || n.p == 0)
    {
        result.p = 0;
        result.q = 0;
    }
    else
    {
        int gcd = calc_gcd(n.p, n.q);
        result.p = n.p / gcd;
        result.q = n.q / gcd;
    }

    return result;
}

RationalNumber add(RationalNumber a, RationalNumber b)
{
    RationalNumber result;

    result.p = (a.p * b.q) + (b.p * a.q);
    result.q = a.q * b.q;

    return reduce(result);
}

RationalNumber subtract(RationalNumber a, RationalNumber b)
{
    RationalNumber result;

    result.p = (a.p * b.q) - (b.p * a.q);
    result.q = a.q * b.q;

    return reduce(result);
}

RationalNumber multiply(RationalNumber a, RationalNumber b)
{
    RationalNumber result;

    result.p = a.p * b.p;
    result.q = a.q * b.q;

    return reduce(result);
}

RationalNumber divide(RationalNumber a, RationalNumber b)
{
    RationalNumber result;

    int temp = a.p;
    a.p = a.q;
    a.q = temp;

    // multiply function
    result.p = a.p * b.p;
    result.q = a.q * b.q;

    return reduce(result);
}

int compare(RationalNumber a, RationalNumber b)
{
    a = reduce(a);
    b = reduce(b);

    a.p = (a.p * b.q);
    b.p = (b.p * a.q);

    // a. return 0 if two rational numbers are equal
    // b. return 1 if the first rational number is greater than the second rational number
    // c. return -1 if the first rational number is less than the second rational number

    if (a.p > b.p)
    {
        return 1;
    }
    else if (a.p < b.p)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    RationalNumber a = {0, 1};
    RationalNumber b = {2, 4};

    RationalNumber result;

    result = add(a, b);
    cout << result.p << " / " << result.q << endl;

    result = subtract(a, b);
    cout << result.p << " / " << result.q << endl;

    result = multiply(a, b);
    cout << result.p << " / " << result.q << endl;

    result = divide(a, b);
    cout << result.p << " / " << result.q << endl;

    // a = {1, 3};
    // b = {4, 12};

    // cout << compare(a, b) << endl;

    return 0;
}