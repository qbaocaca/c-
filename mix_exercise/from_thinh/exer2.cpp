#include <iostream>
#include <string.h>

using namespace std;

const char *RemoveExtraSpaces(char *str);
void remove_tail(char *);
void remove_head(char *);

int main()
{
    char *s = new char[100];
    cout << "input: ";
    cin.getline(s, 100);
    cout << "--------------------------------------" << endl;
    cout << "INPUT: '" << s << "' "
         << "input length: " << strlen(s) << endl;
    const char *kq = RemoveExtraSpaces(s);
    cout << "OUTPUT: '" << kq << "' "
         << "output length: " << strlen(kq) << endl;

    return 0;
}

const char *RemoveExtraSpaces(char *str)
{
    remove_head(str);
    remove_tail(str);

    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (int j = i; j < n; j++)
            {
                str[j] = str[j + 1];
            }
            --i;
            --n;
        }
    }
    return str;
}

void remove_tail(char *s)
{
    int i = strlen(s);
    while (s[i - 1] == ' ')
    {
        s[i - 1] = s[i];
        i--;
    }
}

void remove_head(char *s)
{
    int n = strlen(s);
    while (s[0] == ' ')
    {
        for (int i = 0; i < n; i++)
        {
            s[i] = s[i + 1];
        }
        --n;
    }
}
