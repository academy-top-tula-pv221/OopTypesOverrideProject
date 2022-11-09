#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Money;

class Fraction
{
    int n;
    int d;
public:
    explicit Fraction(int n = 0, int d = 1) : n{ n }, d{ d } {};
    friend ostream& operator<<(ostream& out, const Fraction& f)
    {
        out << "[" << f.n << "/" << f.d << "]";
        return out;
    }

    explicit operator Money();

    operator double()
    {
        return (double)n / d;
    }
};

class Money
{
    int r;
    int k;
public:
    Money(int r, int k) : r{ r }, k{ k } {};
    friend ostream& operator<<(ostream& out, const Money& m)
    {
        out << m.r << "r. " << m.k << "k.";
        return out;
    }
};

Fraction::operator Money()
{
    int rub = n / d;
    int kop = (double)(n % d) / d * 100;
    return Money(rub, kop);
}


class MyString
{
    char* str = nullptr;
    int size;   
public:
    MyString(char symbol) = delete;

    MyString() : size{ 0 }, str{ nullptr } {}
    explicit MyString(int size) : size{ size }
    {
        if (size)
            str = new char[size + 1];
    }
    MyString(const char* cstr) : size{ (int)strlen(cstr) }
    {
        str = new char[size + 1];
        strcpy(str, cstr);
    }

    /*MyString(char symbol)
    {
        size = 1;
        str = new char[2];
        str[0] = symbol;
        str[1] = '\0';
    }*/

    friend ostream& operator<<(ostream& out, MyString& s)
    {
        out << s.str;
        return out;
    }
};

void StrPrint(MyString s)
{
    cout << s;
}

int main()
{
    /*Fraction f(10, 3);
    cout << f << "\n";

    Money m(0, 0);
    m = (Money)f;
    cout << m << "\n";

    cout << 10.45 + f << "\n";*/

    /*MyString s1(10);
    cout << s1 << "\n";

    MyString s2("Hello");
    cout << s2 << "\n";*/

    MyString s3("#");
}
