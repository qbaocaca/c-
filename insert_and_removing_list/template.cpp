#include <iostream>
// #include <list>
// #include <algorithm>
// typedef std::list<int> list;
// using std::find;
using std::cin;
using std::cout;

// Write your code here

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    list a;
    int x, b, c;

    do
    {
        cin >> x;
        switch (x)
        {
        case 0:
            cin >> b;
            a.push_front(b);
            break;
        case 1:
            cin >> b;
            a.push_back(b);
            break;
        case 2:
        {
            cin >> b >> c;
            auto it = find(a.begin(), a.end(), b);
            a.insert(++it, c);
        }
        break;
        case 3:
        {
            cin >> b;
            auto it = find(a.begin(), a.end(), b);
            if (it != a.end())
                a.erase(it);
        }
        break;
        case 4:
            cin >> b;
            a.remove(b);
            break;
        case 5:
            if (a.size())
                a.erase(a.begin());
            break;
        }
    } while (x != 6);

    if (a.size() == 0)
        cout << "blank\n";
    else
    {
        for (auto it = a.begin(); it != a.end(); it++)
        {
            cout << *it << " ";
        }
    }
    return 0;
}
