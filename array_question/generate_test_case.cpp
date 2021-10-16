#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int n, choice;
    cout << "input no of elements n = ";
    cin >> n;
    cout << "no of query = ";
    cin >> choice;
    cout << n << " " << choice << endl;

    srand(time(0));
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 2;
        cout << arr[i] << " ";
    }
    cout << endl;

    int i = 0, k, a, b, c;

    while (i < choice)
    {
        k = rand() % 2;
        switch (k)
        {
        case 0:
        {
            do
            {
                a = rand() % n;
                b = rand() % n;
            } while (a > b);

            cout << k << " " << a << " " << b << endl;
            break;
        }
        case 1:
        {
            c = rand() % (n - 1);
            cout << k << " " << c << endl;
            break;
        }
        }
        i++;
    }
    return 0;
}
