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
    void deepcopy(const Array &other);

public:
    Array(); // non-parameterised or default constructor
    void insert_(int x);
    Array(const Array &other);            // copy constructor
    ~Array();                             // destructor
    Array &operator=(const Array &other); // copy assignment

    int view_na();
    int view_elements(int i);
    void print_list();
};

void Array::deepcopy(const Array &other)
{
    int i = 0;
    while (i < other.na)
    {
        insert_(other.A[i]);
        i++;
    }
}

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

Array::Array(const Array &other)
{
    allocate_(this->A, other.na);
    this->deepcopy(other);
}

Array::~Array()
{
    delete_(this->A);
}

int Array::view_elements(int i)
{
    return this->A[i];
}

int Array::view_na()
{
    return this->na;
}

void Array::print_list()
{
    for (int i = 0; i < this->na; i++)
    {
        cout << this->A[i] << " ";
    }
}

Array &Array::operator=(const Array &other)
{
    this->deepcopy(other);
    return *this;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

//     Array A;
//     int n, i = 0;
//     cin >> n;
//     int x;
//     while (i < n)
//     {
//         cin >> x;
//         A.insert_(x);
//         i++;
//     }

//     Array A2;

//     for (int i = 0; i < 100000; i++)
//     {
//         A2 = A;
//     }

//     for (int i = 0; i < A.view_na(); i++)
//     {
//         if (A.view_elements(i) != A2.view_elements(i))
//         {
//             cout << "WRONG!" << endl;
//         }
//     }

//     cout << "NO COPY ERROR!";
    
//     Array *A;
//     int m;
//     cin >> m;
//     A = new Array[m];
//     int n, j, x;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> n;
//         j = 0;
//         while (j < n)
//         {
//             cin >> x;
//             A[i].insert_(x);
//             j++;
//         }
//     }

//     for (int i = 0; i < m; i++)
//     {
//         A[i].print_list();
//         cout << endl;
//     }

    return 0;
}
