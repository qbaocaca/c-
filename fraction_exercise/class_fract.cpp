#include <bits/stdc++.h>

using namespace std;

class fract
{
private:
    int num, de, num_, de_;
    void reduce();
    void deepcopy(const fract &other);

public:
    fract();             // non-parameterized or default constructor
    fract(int a, int b); // parameterized constructor
    // fract(int a);        // implicit conversion constructor
    explicit fract(int a) // explicit conversion constructor
    {
        this->num = a;
        this->de = 1;
        this->reduce();
    }
    fract(const fract &other); // copy constructor
    ~fract();                  // destructor

    void set_fract();
    void print_fract();
    void print_fract_();

    int view_num(); // define accessor function
    int view_de();
    int view_num_();
    int view_de_();

    void add_(fract a);
    void subtract_(fract a);
    void multiply_(fract a);
    void divide_(fract a);

    double decimal(); // converts fract to decimal point
    double decimal_();

    // overloading operator: fract + fract
    fract operator+(fract a); // a method within class
    // friend fract operator+(fract a, fract b); // a method made friend with class
    fract operator+(int a);                 // fract + int
    friend fract operator+(int a, fract b); // int + fract

    fract operator-(); // negates fract

    fract &operator=(const fract &other); // assignment operator

    friend istream &operator>>(istream &in, fract &a);
    friend ostream &operator<<(ostream &out, fract a);

    bool equal_(fract a); // check two equal fracts

    fract &operator++();                   // prefix increment operator
    fract operator++(int other);           // postfix increment operator
    fract &operator+=(const fract &other); // addition assignment operator

    operator int(); // fract to int conversion function
};

void fract::reduce()
{
    int gcd = std::__gcd(num, de);

    num_ = num / gcd;
    de_ = de / gcd;

    if ((num_ > 0 && de_ < 0) || (num_ < 0 && de_ < 0))
    {
        num_ = -num_;
        de_ = -de_;
    }
}

void fract::deepcopy(const fract &other)
{
    num = other.num;
    de = other.de;
    num_ = other.num_;
    de_ = other.de_;
}

fract::fract()
{
    this->num = this->num_ = 0;
    this->de = this->de_ = 1;
}

fract::fract(int a, int b)
{
    this->num = a;
    if (b != 0)
    {
        this->de = b;
    }
    else
    {
        this->de = 1;
    }
    this->reduce();
}

// fract::fract(int a)
// {
//     this->num = a;
//     this->de = 1;
//     this->reduce();
// }

fract::fract(const fract &other)
{
    this->num = this->num_ = 0;
    this->de = this->de_ = 1;
    this->deepcopy(other);
}

fract::~fract()
{
    return;
}

void fract::set_fract()
{
    cin >> num >> de;
    if (this->num == 0 || this->de == 0)
    {
        throw std::domain_error("TRASH");
    }
    this->reduce();
}

void fract::print_fract()
{
    if (this->de == 1)
    {
        cout << this->num;
    }
    else
    {
        cout << this->num << "/" << this->de;
    }
}

void fract::print_fract_()
{
    if (this->de_ == 1)
    {
        cout << this->num_;
    }
    else
    {
        cout << this->num_ << "/" << this->de_;
    }
}

int fract::view_num()
{
    return this->num;
}

int fract::view_de()
{
    return this->de;
}

int fract::view_num_()
{
    return this->num_;
}

int fract::view_de_()
{
    return this->de_;
}

void fract::add_(fract a)
{
    this->num = this->num * a.de + this->de * a.num;
    this->de = this->de * a.de;
    this->reduce();
}

void fract::subtract_(fract a)
{
    this->num = this->num * a.de - this->de * a.num;
    this->de = this->de * a.de;
    this->reduce();
}

void fract::multiply_(fract a)
{
    this->num = this->num * a.num;
    this->de = this->de * a.de;
    this->reduce();
}

void fract::divide_(fract a)
{
    this->num = this->num * a.de;
    this->de = this->de * a.num;
    this->reduce();
}

double fract::decimal()
{
    return (double)this->num / (double)this->de;
}

double fract::decimal_()
{
    return (double)this->num_ / (double)this->de_;
}

fract fract::operator+(fract a)
{
    fract result;
    result.num = this->num * a.de + this->de * a.num;
    result.de = this->de * a.de;
    result.reduce();
    return result;
}

fract fract::operator+(int a)
{
    fract result;
    result.num = this->num + this->de * a;
    result.de = this->de;
    result.reduce();
    return result;
}

// fract operator+(fract a, fract b)
// {
//     fract c;
//     c.num = a.num * b.de + b.num * a.de;
//     c.de = a.de * b.de;
//     c.reduce();
//     return c;
// }

fract operator+(int a, fract b)
{
    fract c;
    c.num = a * b.de + b.num;
    c.de = b.de;
    c.reduce();
    return c;
}

fract fract::operator-()
{
    return fract(-this->num, this->de);
}

fract &fract::operator=(fract const &other)
{
    if (this == &other)
        return *this;
    this->deepcopy(other);
    return *this;
}

istream &operator>>(istream &in, fract &a)
{
    in >> a.num >> a.de;
    a.reduce();
    return in;
}

ostream &operator<<(ostream &out, fract a)
{
    if (a.de == 1)
    {
        out << a.num;
    }
    else
    {
        out << a.num << "/" << a.de;
    }
    return out;
}

bool fract::equal_(fract a)
{
    return this->num_ == a.num_ && this->de_ == a.de_;
}

fract &fract::operator++()
{
    this->num = this->num + this->de;
    this->de = this->de;
    this->reduce();
    return *this;
}

fract fract::operator++(int other)
{
    if (other != 0)
    {
        this->num = this->num + other * this->de;
        this->de = this->de;
        this->reduce();
    }
    else
    {
        this->num = this->num + this->de;
        this->de = this->de;
        this->reduce();
    }
    return *this;
}

fract &fract::operator+=(const fract &other)
{
    this->num = this->num * other.de + this->de * other.num;
    this->de = this->de * other.de;
    return *this;
}

fract::operator int()
{
    return this->num / this->de;
}

int main()
{
    // test on parameterized constructor and reduction
    // fract a(25, 35);
    // a.print_fract();
    // cout << endl;
    // a.print_fract_();

    // test on addition
    // fract b(14, 49);
    // a.add_(b);
    // a.print_fract();

    // test for decimal point conversion
    // cout << endl;
    // cout << a.decimal();
    // cout << endl;
    // a.print_fract_();

    // test on copy assignment
    // fract b;
    // for (int i = 0; i < 10000; i++)
    // {
    //     b = a;
    // }
    // b.print_fract();

    // test on an array of fraction
    // fract *A;
    // int m;
    // cin >> m;
    // A = new fract[m];
    // int index = 0, wrong = 0;

    // for (int i = 0; i < m; i++)
    // {
    //     try
    //     {
    //         A[index++].set_fract();
    //     }
    //     catch (exception e)
    //     {
    //         wrong++;
    //     }
    // }
    // m -= wrong;

    // sum of all fractions in array
    // fract sum;
    // for (int i = 0; i < m; i++)
    // {
    //     // A[i].print_fract();
    //     sum.add_(A[i]);
    //     // cout << endl;
    // }

    // int check_double = sum.view_num() % sum.view_de();
    // if (check_double == 0)
    // {
    //     cout << (int)sum.decimal() << endl;
    // }
    // else
    // {
    //     sum.print_fract_();
    // }

    // delete[] A;

    // test on operator overloading
    // fract a(1, 3), c;
    // int b = 8;
    // c = a + (fract)b; // fract + int + explicit constructor
    // cout << "c = " << a << " + " << b << " = " << c << endl;

    // fract b(1, 2);
    // c = a + b; // fract + fract
    // cout << "c = " << a << " + " << b << " = " << c << endl;

    // c = (fract)b + a; // explicit constructor + int + fract
    // cout << "c = " << a << " + " << b << " = " << c << endl;

    // c = -a; // negates fract
    // cout << "c = " << c;

    // c = 8 + a; // implicit constructor + int + fract
    // cout << "c = " << c;
    // c = a + 8;
    // cout << "c = " << c;

    // cout << "++c: "; // prefix increment operator
    // cout << "c = " << ++c << endl;
    // cout << "a = " << a << " + " << c << endl;
    // a += c; // addition assignment operator
    // cout << "a = " << a << endl;
    // b = a; // fract to int conversion function
    // cout << "b = " << b << endl;

    // fract a(1, 3);
    // cout << "a++: ";
    // cout << "a = " << a++ << endl;
    // cout << "a++(25): ";
    // cout << "a = " << a.operator++(25) << endl;

    return 0;
}