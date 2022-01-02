#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int info;
    int sum_digits;
    int freq;
    node *next;
};

struct list
{
    node *head, *tail;
};

const char *orderWeight(const std::string &str);
const char *RemoveExtraSpaces(char *str);
void remove_tail(char *);
void remove_head(char *);
void initialize_list(list &l);
void add_tail(list &l, int x, int y);
void print_list(list l);
void quick_sort_up_list(list &l);
void count_freq(list &l);
int count_element(list l);
void remove_duplicate(int *a, int &n);
int getFirstDigit(int x);
std::string int_to_string(int x);

int main()
{
    std::string str;
    cout << "input: ";
    getline(std::cin, str);
    const char *p = orderWeight(str);
    cout << p;
    return 0;
}

void initialize_list(list &l)
{
    l.head = l.tail = NULL;
}

void add_tail(list &l, int x, int y)
{
    node *pnew = new node;
    pnew->info = x;
    pnew->sum_digits = y;
    pnew->freq = 0;
    pnew->next = NULL;

    if (l.head == NULL)
    {
        l.head = l.tail = pnew;
    }
    else
    {
        l.tail->next = pnew;
        l.tail = pnew;
    }
}

const char *orderWeight(const std::string &str)
{
    // because argument is a const type, we cannot alter it
    // so have to make a copy and work on that copy

    int length = str.size();
    char *temp = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        temp[i] = str[i];
    }
    temp[length] = '\0';

    // convert from string to char* because argument of
    // RemoveExtraSpaces is a char*

    // also because RemoveExtraSpaces returns a const char* type
    // so have to initialize temp1 with a const char* type

    const char *temp1 = RemoveExtraSpaces(temp);

    // convert string to linked_list of numbers
    // with additional SumOfDigits field

    length = strlen(temp1);
    list l;
    initialize_list(l);
    int number = 0, convert = 0, sum = 0;
    for (int i = 0; i < length; i++)
    {
        while (temp1[i] != ' ')
        {
            convert = temp1[i] - '0';
            sum = sum + convert;
            number = number * 10 + convert;
            i++;
            if (i == length)
            {
                break;
            }
        }
        add_tail(l, number, sum);
        number = 0;
        sum = 0;
    }

    // sort list in ascending order
    quick_sort_up_list(l);

    // count the frequency of the SumOfDigits
    count_freq(l);

    // create a 1D-array to store the SumOfDigits
    int size = count_element(l);
    int *b = new int[size];
    int index = 0;
    node *p = l.head;
    while (p != NULL)
    {
        if (p->freq > 1)
        {
            b[index++] = p->sum_digits;
        }
        p = p->next;
    }

    // find unique values of the SumOfDigits
    remove_duplicate(b, index);

    // create a new list to sort the numbers in alphabetical order
    list l1;
    initialize_list(l1);
    int t;
    for (int i = 0; i < index; i++)
    {
        node *p = l.head;
        while (p != NULL)
        {
            if (p->sum_digits == b[i])
            {
                t = getFirstDigit(p->info);
                add_tail(l1, p->info, t);
            }
            p = p->next;
        }
        quick_sort_up_list(l1);

        // paste back the sorted value to the main list
        p = l.head;
        node *q = l1.head;
        while (p != NULL)
        {
            if (p->sum_digits == b[i])
            {
                p->info = q->info;
                q = q->next;
                if (q == NULL)
                    break;
            }
            p = p->next;
        }
        l1.head = l1.tail = NULL;
    }
    delete[] b;

    // convert the linked_list of numbers back to string
    std::string temp2 = "", final = "";
    p = l.head;
    while (p != NULL)
    {
        temp2 = int_to_string(p->info);
        final = final + temp2;
        if (p->next != NULL)
        {
            final = final + ' ';
        }
        p = p->next;
    }

    // convert string to char*
    length = final.size();
    char *Final = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        Final[i] = final[i];
    }
    Final[length] = '\0';
    return Final;
}

std::string int_to_string(int x)
{
    if (x == 0)
        return "0";
    std::string temp = "", result = "";
    int rem = 0;
    char convert;
    while (x > 0)
    {
        rem = x % 10;
        convert = rem + '0';
        temp.push_back(convert);
        x = x / 10;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        result.push_back(temp[temp.size() - i - 1]);
    }
    return result;
}

int getFirstDigit(int x)
{
    int rem = 0;
    while (x != 0)
    {
        rem = x % 10;
        x = x / 10;
    }
    return rem;
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

void remove_head_list(list &l, int &a, int &b)
{
    node *p = l.head;
    a = p->info;
    b = p->sum_digits;
    l.head = p->next;
    delete p;
}

void quick_sort_up_list(list &l)
{
    if (l.head == NULL)
        return;
    list A1, A2, B;
    initialize_list(A1);
    initialize_list(A2);
    initialize_list(B);
    int x, a, b;
    x = l.head->sum_digits;
    while (l.head != NULL)
    {
        remove_head_list(l, a, b);
        if (b < x)
            add_tail(A1, a, b);
        else if (b > x)
            add_tail(A2, a, b);
        else
            add_tail(B, a, b);
    }
    quick_sort_up_list(A1);
    quick_sort_up_list(A2);
    if (A1.head != NULL)
    {
        A1.tail->next = B.head;
        B.head = A1.head;
    }
    if (A2.head != NULL)
    {
        B.tail->next = A2.head;
        B.tail = A2.tail;
    }
    l = B;
}

void count_freq(list &l)
{
    node *p = l.head;
    int count = 0;
    while (p != NULL)
    {
        node *p1 = l.head;
        while (p1 != p)
        {
            if (p1->sum_digits == p->sum_digits)
            {
                break;
            }
            p1 = p1->next;
        }

        if (p1 == p)
        {
            count = 1;
            node *q = p->next;
            while (q != NULL)
            {
                if (q->sum_digits == p->sum_digits)
                {
                    count++;
                }
                q = q->next;
            }
            p->freq = count;
        }
        else
        {
            p->freq = p1->freq;
        }

        p = p->next;
    }
}

int count_element(list l)
{
    int count = 0;
    node *p = l.head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void remove_duplicate(int *a, int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] == a[i])
            {
                for (int k = j; k < n - 1; k++)
                {
                    a[k] = a[k + 1];
                }
                --j;
                --n;
            }
        }
    }
}