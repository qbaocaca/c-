#include <iostream>

using namespace std;

struct node
{
    int info;
    node *next;
};

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class list
{
private:
    node *head;
    node *tail;

public:
    list()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    node *view_head()
    {
        return this->head;
    }

    node *view_tail()
    {
        return this->tail;
    }

    int view_tail_info()
    {
        return this->tail->info;
    }

    void add_tail(int x)
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

    void add_head(int x)
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
            pnew->next = this->head;
            this->head = pnew;
        }
    }

    void print_list()
    {
        node *p = this->head;
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
    }

    node *search_(int x)
    {
        node *p = this->head;
        while (p != NULL)
        {
            if (p->info == x)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }

    void insert_after(node *d, int x)
    {
        node *p = this->head;
        node *pnew = new node;
        pnew->info = x;
        pnew->next = NULL;

        if (d == p)
        {
            pnew->next = p->next;
            p->next = pnew;
        }
        else if (d == this->tail)
        {
            add_tail(x);
        }
        else
        {
            pnew->next = d->next;
            d->next = pnew;
        }
    }

    void delete_node(int x)
    {
        node *p = this->head;
        node *bp = NULL;
        while (p != NULL)
        {
            if (p->info == x)
            {
                break;
            }
            bp = p;
            p = p->next;
        }

        if (p != NULL)
        {
            if (bp != NULL)
            {
                bp->next = p->next;
                if (p == this->tail)
                {
                    this->tail = bp;
                }
            }
            else
            {
                this->head = this->head->next;
            }
            delete p;
        }
    }

    void remove_all(int x)
    {
        node *t = search_(x);
        while (t != NULL)
        {
            delete_node(x);
            t = search_(x);
        }
    }

    void remove_head()
    {
        node *p = this->head;
        this->head = p->next;
        delete p;
    }

    void control_tail()
    {
        while (this->tail->next != NULL)
        {
            this->tail = this->tail->next;
        }
    }
};

int main()
{
    list l;
    int choice;
    int x, y;
    node *t;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 0:
            cin >> x;
            l.add_head(x);
            if (l.view_tail() != NULL)
            {
                l.control_tail();
            }

            // cout << "after add head: ";
            // l.print_list();
            // cout << endl;

            break;
        case 1:
            cin >> x;
            l.add_tail(x);

            // cout << "after add tail: ";
            // l.print_list();
            // cout << endl;

            break;
        case 2:
            cin >> x >> y;
            t = l.search_(x);
            if (t != NULL)
            {
                l.insert_after(t, y);

                // cout << "after insert " << x << ": ";
                // l.print_list();
                // cout << endl;
            }
            else
            {
                l.add_head(y);
                // cout << "there was no " << x << " in the list, ";
                // cout << "after add head: ";
                // l.print_list();
                // cout << endl;
            }

            if (l.view_tail() != NULL)
            {
                l.control_tail();
            }
            break;
        case 3:
            cin >> x;
            t = l.search_(x);
            if (t != NULL)
            {
                l.delete_node(x);

                // cout << "after delete " << x << ": ";
                // l.print_list();
                // cout << endl;
            }
            // else
            // {
            //     cout << "there was no " << x << " in the list";
            //     cout << endl;
            // }

            if (l.view_tail() != NULL)
            {
                l.control_tail();
            }
            break;
        case 4:
            cin >> x;
            t = l.search_(x);
            if (t != NULL)
            {
                l.remove_all(x);

                // cout << "after delete all " << x << ": ";
                // l.print_list();
                // cout << endl;
            }
            // else
            // {
            //     cout << "there was no " << x << " in the list";
            //     cout << endl;
            // }

            if (l.view_tail() != NULL)
            {
                l.control_tail();
            }
            break;
        case 5:
            if (l.view_head() != NULL)
            {
                l.remove_head();

                // cout << "after delete head: ";
                // l.print_list();
                // cout << endl;
            }
            // else
            // {
            //     cout << "list is empty!" << endl;
            // }

            if (l.view_tail() != NULL)
            {
                l.control_tail();
            }
            break;

        default:
            if (l.view_tail() != NULL)
            {
                l.control_tail();
            }
            break;
        }
    } while (choice != 6);

    if (l.view_head() == NULL)
    {
        cout << "blank";
    }
    else
    {
        // cout << "final: ";
        l.print_list();
    }

    return 0;
}
