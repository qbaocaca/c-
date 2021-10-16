#include <iostream>

using namespace std;

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
    int *arr = new int[a];

    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1)
        {
            cout << "WRONG!";
            return 0;
        }
    }

    int i = 0;
    int x, y, z, result = 0, k, c;
    while (i < b)
    {
        cin >> x;
        switch (x)
        {
        case 0:
        {
            // uncomment the blocks for print out each steps
            // cout << "before: ";
            // for (int j = 0; j < a; j++)
            // {
            //     cout << arr[j] << " ";
            // }
            // cout << endl;

            k = 0;
            cin >> y >> z;
            for (int j = z; j >= y; j--)
            {
                if (arr[j] == 1)
                {
                    result = result + pow_of_2(k);
                }
                k++;
            }
            // cout << "binary = ";
            // for (int j = z; j >= y; j--)
            // {
            //     cout << arr[j] << " ";
            // }
            // cout << endl;
            // cout << "dec = " << result << " is ";

            if (result % 2 == 0)
                cout << "EVEN" << endl;
            else
                cout << "ODD" << endl;
            break;
        }

        case 1:
        {
            // cout << "before: ";
            // for (int j = 0; j < a; j++)
            // {
            //     cout << arr[j] << " ";
            // }
            // cout << endl;

            cin >> c;
            if (arr[i] == 0)
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
            // cout << "after switch: ";
            // for (int j = 0; j < a; j++)
            // {
            //     cout << arr[j] << " ";
            // }
            // cout << endl;
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