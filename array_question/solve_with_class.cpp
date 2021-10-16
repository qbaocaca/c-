#include <iostream>

using namespace std;

void allocate_(int *&a, int size)
{
    a = new int[size];
}

void delete_(int *a)
{
    delete a;
}

class Array
{
private:
    int na = 0; // actual number of elements
    int *A;
    int capacity_a = 1; // maximum number of elements

public:
    Array(); // non-parameterised or default constructor
    void insert_(int x);
    int view_elements(int i);
    void set_elements(int i, int x);
};

Array::Array()
{
    this->na = 0;
    this->capacity_a = 1;
    allocate_(this->A, 1);
}

void Array::insert_(int x)
{
    if (this->na == 0)
    {
        allocate_(this->A, 1);
        this->A[0] = x;
        this->na++;
    }
    else if (this->na == this->capacity_a)
    {
        this->capacity_a = 2 * this->na + 2;
        int *B;
        allocate_(B, this->capacity_a);
        for (int i = 0; i < this->na; i++)
        {
            B[i] = this->A[i];
        }

        B[this->na] = x;
        delete_(this->A);
        allocate_(A, this->capacity_a);
        for (int i = 0; i <= this->na; i++)
        {
            this->A[i] = B[i];
        }
        delete_(B);
        this->na++;
    }
    else
    {
        this->A[this->na] = x;
        this->na++;
    }
}

int Array::view_elements(int i)
{
    return this->A[i];
}

void Array::set_elements(int i, int x)
{
    this->A[i] = x;
}

int pow_of_2(int n)
{
    int t = 1, i = 0;
    while (i < n)
    {
        t = t * 2;
        i++;
    }
    return t;
}

int main()
{
    int a, b;
    cin >> a >> b;
    Array A;
    int i = 0, x;
    while (i < a)
    {
        cin >> x;
        if (x != 0 && x != 1)
        {
            cout << "WRONG!";
            return 0;
        }
        A.insert_(x);
        i++;
    }

    i = 0;
    int y, z, result = 0, k, c;
    while (i < b)
    {
        cin >> x;
        switch (x)
        {
        case 0:
        {
            k = 0;
            cin >> y >> z;
            for (int j = z; j >= y; j--)
            {
                if (A.view_elements(j) == 1)
                {
                    result = result + pow_of_2(k);
                }
                k++;
            }

            if (result % 2 == 0)
                cout << "EVEN" << endl;
            else
                cout << "ODD" << endl;
            break;
        }

        case 1:
        {
            cin >> c;
            if (A.view_elements(c) == 0)
            {
                A.set_elements(c, 1);
            }
            else
            {
                A.set_elements(c, 0);
            }
            break;
        }
        default:
        {
            cout << "WRONG!" << endl;
            return 0;
        }
        }
        i++;
    }

    return 0;
}
