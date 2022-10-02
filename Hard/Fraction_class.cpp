//code by Romijul Laskar
//Date : 21-03-2022 03:21 PM
#include <bits/stdc++.h>
using namespace std;
class Fraction
{
private:
    int nu;
    int de;

public:
    Fraction(int n, int d)
    {
        nu = n;
        de = d;
    }
    Fraction()
    {
        nu = 0;
        de = 1;
    }
    void input()
    {
        cout << "Enter numerator and denominator : ";
        cin >> nu;
        cin >> de;
    }
    Fraction operator+(const Fraction &f2)
    {
        Fraction r;
        r.nu = (nu * f2.de) + (f2.nu * de);
        r.de = de * f2.de;
        return r;
    }
    Fraction operator-(const Fraction &f2)
    {
        Fraction r;
        r.nu = (nu * f2.de) - (f2.nu * de);
        r.de = de * f2.de;
        return r;
    }
    Fraction operator*(const Fraction &f2)
    {
        Fraction r;
        r.nu = (nu) * (f2.nu);
        r.de = de * f2.de;
        return r;
    }
    Fraction operator/(const Fraction &f2)
    {
        Fraction r;
        r.nu = (nu) * (f2.de);
        r.de = de * f2.nu;
        return r;
    }
    void normalize()
    {
        int gcd = __gcd(nu, de);
        nu = nu / gcd;
        de = de / gcd;
    }
    const bool operator==(const Fraction &right) const
    {
        if ((nu == right.nu) && (de == right.de))
            return true;
        else
            return false;
    }
    const Fraction &operator=(const Fraction &right)
    {
        nu = right.nu;
        de = right.de;
        return *this;
    }
    void subsript()
    {
        int key;
        cout << "Enter 0 for numerator\t1 for denominator :";
        cin >> key;
        if (key == 0)
        {
            cout << nu << endl;
        }
        if (key == 1)
        {
            cout << de << endl;
        }
    }
    friend ostream &operator<<(ostream &output, const Fraction &f)
    {
        output << '(' << f.nu << " | " << f.de << ')';
        return output;
    }
    friend istream &operator>>(istream &input, Fraction &f)
    {
        input >> f.nu;
        input >> f.de;
        return input;
    }
};
void menu()
{
    int key;
    cout << "\n1 ::Add 2 ::Subtract\n3 ::Multiply 4 ::Divide\n5 ::Comapare 6 ::Copy 7 ::Subscript\n";
    cin >> key;
    switch (key)
    {
    case 1:
    { // add
        Fraction c1, c2, res;
        cout << "Enter first Fraction number:\n";
        c1.input();
        cout << "Enter second Fraction number:\n";
        c2.input();
        cout << "c1+c2=";
        res = c1 + c2;
        res.normalize();
        cout << res << endl;
        menu();
    }
    break;
    case 2: // sub
    {
        Fraction c1, c2, res;
        cout << "Enter first Fraction number:\n";
        c1.input();
        cout << "Enter second Fraction number:\n";
        c2.input();
        cout << "c1-c2=";
        res = c1 - c2;
        res.normalize();
        cout << res << endl;
        menu();
    }
    break;
    case 3: // mul
    {
        Fraction c1, c2, res;
        cout << "Enter first Fraction number:\n";
        c1.input();
        cout << "Enter second Fraction number:\n";
        c2.input();
        cout << "c1*c2=";
        res = c1 * c2;
        res.normalize();
        cout << res << endl;
        menu();
    }
    break;
    case 4: // div
    {
        Fraction c1, c2, res;
        cout << "Enter first Fraction number:\n";
        c1.input();
        cout << "Enter second Fraction number:\n";
        c2.input();
        cout << "c1/c2=";
        res = c1 / c2;
        res.normalize();
        cout << res << endl;
        menu();
    }
    break;
    case 5: // compare
    {
        Fraction c1, c2;
        cout << "Enter first Fraction number:\n";
        c1.input();
        cout << "Enter second Fraction number:\n";
        c2.input();
        if (c1 == c2)
        {
            cout << "Both are SAME" << endl;
        }
        else
        {
            cout << "NOT SAME " << endl;
        }
        menu();
    }
    break;
    case 6: // copy
    {
        Fraction c1, c2;
        cout << "Enter first Fraction number:\n";
        c1.input();
        c2 = c1;
        cout << "The Copy of C1 is :" << c2 << endl;
        menu();
    }
    break;
    case 7: // subsript
    {
        Fraction c1;
        cout << "Enter the Fraction number:\n";
        c1.input();
        c1.subsript();
        menu();
    }
    break;
    default:
        cout << "ERROR .. Invalid selection" << endl;
        break;
    }
}
int main()
{
    menu();
}
