#include <iostream>

using namespace std;

bool insertX(int, int *, int &);
int binary_search(int *, int, int);
int linear_search(int *, int, int);

int main()
{
    int n;
    cout << "input n: ";
    cin >> n;
    int *a;
    a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "array: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    int x;
    cout << endl;
    cout << "input x: ";
    cin >> x;
    bool t = insertX(x, a, n);
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

int linear_search(int *a, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
            return i;
    }
}