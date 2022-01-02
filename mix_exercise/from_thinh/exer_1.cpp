#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool insertX(int, int *, int &);
int binary_search(int *, int, int);
void quick_sort_up(int *, int, int);
int linear_search(int *, int, int);
// bool insertX(int X, int *arr, int arrLength);

int main()
{
    srand(time(NULL));
    int n = rand() % 11;
    cout << "input n: ";
    cout << n;
    // cin >> n;
    int *a;
    a = new int[n];

    for (int i = 0; i < n; i++)
    {
        // cin >> a[i];
        a[i] = rand() % 101;
    }
    cout << endl;
    cout << "array: ";
    quick_sort_up(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    int x = rand() % 101;
    cout << endl;
    cout << "input x: ";
    cout << x;
    // cin >> x;
    bool t = insertX(x, a, n);
    cout << endl;
    if (t == 0)
    {
        cout << "false" << endl;
    }
    else
        cout << "true" << endl;

    cout << "array after: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

bool insertX(int X, int *array, int &arrLength)
{
    int t = binary_search(array, arrLength, X);
    if (t != -1)
        return false;
    else
    {
        int c = linear_search(array, arrLength, X);
        for (int i = arrLength; i > c; i--)
        {
            array[i] = array[i - 1];
        }
        array[c] = X;
        ++arrLength;
    }
    return true;
}

int binary_search(int *a, int n, int x)
{
    int left = 0, right = n - 1, mid;
    do
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    } while (left <= right);
    return -1;
}

void quick_sort_up(int *a, int left, int right)
{
    int i = left, j = right, x = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
        quick_sort_up(a, left, j);
    if (i < right)
        quick_sort_up(a, i, right);
}

int linear_search(int *a, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
            return i;
    }
}