#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node
{
    int info;
    node *next;
};

class list
{
private:
    node *head, *tail;
    void deepcopy(const list &other);

public:
    list();
    list(const list &other);
    ~list();
    list &operator=(const list &other);
    void add_tail(int x);
    void print_list();
    node *view_head();
};

void list::deepcopy(const list &other)
{
    node *p = other.head;
    while (p != NULL)
    {
        this->add_tail(p->info);
        p = p->next;
    }
}

list::list()
{
    this->head = this->tail = NULL;
}

list::list(const list &other)
{
    this->head = this->tail = NULL;
    this->deepcopy(other);
}

list::~list()
{
    node *p = this->head;
    while (p != NULL)
    {
        node *q = p;
        this->head = p->next;
        p = this->head;
        delete q;
    }
}

list &list::operator=(list const &other)
{
    this->deepcopy(other);
    return *this;
}

void list::add_tail(int x)
{
    node *pnew = new node;
    pnew->info = x;
    pnew->next = NULL;

    if (this->head == NULL)
    {
        this->head = this->tail = pnew;
    }
    else
    {
        this->tail->next = pnew;
        this->tail = pnew;
    }
}

void list::print_list()
{
    node *p = this->head;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

node *list::view_head()
{
    return this->head;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    list l;
    int i = 0, n, x;
    cin >> n;
    while (i < n)
    {
        cin >> x;
        l.add_tail(x);
        i++;
    }

    // l.print_list();

    list l2;

    for (int i = 0; i < 10000; i++)
    {
        l2 = l;
    }

    // l2.print_list();

    node *p = l.view_head(), *q = l2.view_head();
    while (p != NULL)
    {
        if (p == q || p->info != q->info)
        {
            cout << "WRONG";
            cout << p->info << endl;
        }
        p = p->next;
        q = q->next;
    }

    cout << "NO COPY ERROR!";
    return 0;
}