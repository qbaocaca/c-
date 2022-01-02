#include <iostream>
#include <string.h >
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

void orderWeight(const std::string &str);
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
    cout << endl;
    cout << "Input string: " << str << endl;
    cout << endl;
    cout << "Processing ===============>" << endl;
    orderWeight(str);

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

void print_list(list l)
{
    node *p = l.head;
    while (p != NULL)
    {
        cout << p->info << " " << p->sum_digits << " ";
        cout << p->freq << "  ";
        p = p->next;
    }
}
void orderWeight(const std::string &str)
{
    int length = str.size();
    char *temp = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        temp[i] = str[i];
    }
    temp[length] = '\0';

    const char *result = RemoveExtraSpaces(temp);
    cout << "RemoveExtraSpaces: " << endl;
    cout << result << endl;

    length = strlen(result);
    list l;
    initialize_list(l);
    int number = 0, convert = 0, sum = 0;
    for (int i = 0; i < length; i++)
    {
        while (result[i] != ' ')
        {
            convert = result[i] - '0';
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
    cout << "calculate weight:" << endl;
    print_list(l);
    quick_sort_up_list(l);
    cout << endl;
    count_freq(l);
    cout << "sort up according to weight and count the weight occurrences:" << endl;
    print_list(l);

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
    cout << endl;
    cout << "print out weight occurrences > 1:" << endl;
    for (int i = 0; i < index; i++)
    {
        cout << b[i] << " ";
    }
    remove_duplicate(b, index);
    cout << endl;
    cout << "identify the groups needed to be sorted alphabetically:" << endl;
    for (int i = 0; i < index; i++)
    {
        cout << b[i] << " ";
    }

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
        cout << endl;
        cout << "sort the group that has weight=" << b[i] << endl;
        print_list(l1);

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
    cout << endl;
    cout << "Done!" << endl;
    print_list(l);
    delete[] b;

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
    cout << endl;
    cout << "Finished, thank you! ================================" << endl;
    cout << endl;
    cout << "Final String: " << final << endl;
    cout << endl;
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
        if (p->info != 0)
        {
            count++;
        }
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