#include <iostream>
#include <stdlib.h>
#include <time.h>

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
    int na = 0;
    int *A;
    int capacity_a = 1;

public:
    void insert_(int x)
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
            this->na++;
        }
        else
        {
            this->A[this->na] = x;
            this->na++;
        }
    }

    void print_list()
    {
        for (int i = 0; i < this->na; i++)
        {
            cout << this->A[i] << " ";
        }
        delete_(this->A);
    }
};

int main()
{
    Array *A;
    int m;
    cout << "how many test cases? input: ";
    cin >> m;
    A = new Array[m + 1];

    srand(time(0));

    for (int i = 0; i < m; i++)
    {
        int n = rand() % 6;
        int b = rand() % 11;
        if (n == 0 || n == 1 || n == 3 || n == 4)
        {
            A[i].insert_(n);
            b = rand() % 11;
            A[i].insert_(b);
        }
        else if (n == 2)
        {
            A[i].insert_(n);
            b = rand() % 11;
            A[i].insert_(b);
            b = rand() % 11;
            A[i].insert_(b);
        }
        else
        {
            A[i].insert_(n);
        }
    }

    A[m].insert_(6);

    for (int i = 0; i < m + 1; i++)
    {
        A[i].print_list();
        cout << endl;
        cout << endl;
    }

    return 0;
}
