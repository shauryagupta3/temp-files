#include <iostream>

using namespace std;

template <class T>
class node
{
public:
    T info;
    node<T> *next;
    node(T el, node<T> *ptr = NULL)
    {
        info = el;
        next = ptr;
    }
};

template <class T>
class Cirlist
{
private:
    node<T> *back;

public:
    Cirlist()
    {
        back = NULL;
    }

    ~Cirlist();

    bool isempty()
    {
        return (back == NULL);
    }

    void add_front(T el)
    {
        if (isempty())
        {
            back = new node<T>(el);
            back->next = back;
        }
        else
        {
            back->next = new node<T>(el, back->next);
        }
    }

    void add_back(T el)
    {
        if (isempty())
        {
            back = new node<T>(el);
            back->next = back;
        }
        else
        {
            back->next = new node<T>(el, back->next);
            back = back->next;
        }
    }

    T delete_front()
    {
        node<T> *temp = back->next;
        T el = temp->info;

        if (back->next == back)
        {
            back = NULL;
        }
        else
        {
            back->next = temp->next;
        }

        delete temp;
        return el;
    }

    T delete_back()
    {
        T el = back->info;

        if (back->next == back)
        {
            delete back;
            back = NULL;
        }
        else
        {
            node<T> *temp = back->next;

            for (; temp->next != back; temp = temp->next)
                ;

            temp->next = back->next;

            delete back;
            back = temp;
        }

        return el;
    }

    void delete_node(T el)
    {
        if (back != NULL)
        {
            if (back == back->next && el == back->info)
            {
                delete back;
                back = NULL;
            }
            else if (el == back->next->info)
            {
                node<T> *temp = back->next;
                back->next = temp->next;
                delete temp;
            }
            else
            {
                node<T> *pred, *temp;

                for (pred = back->next, temp = pred->next; temp != back->next && !(temp->info == el);
                     pred = pred->next, temp = temp->next)
                    ;

                if (temp != back->next)
                {
                    pred->next = temp->next;

                    if (temp == back)
                    {
                        back = pred;
                    }
                    delete temp;
                }
            }
        }
    }

    void reverse()
    {
        if (isempty())
        {
            return;
        }

        node<T> *q, *r, *s, *last;

        last = q = back->next;
        back->next = NULL;
        r = NULL;

        do
        {
            s = r;
            r = q;
            q = q->next;

            r->next = s;
            last->next = r;
        } while (q != NULL);

        back = last;
    }

    bool search(T el)
    {
        node<T> *temp = back;
        for (node<T> *p = back; p != NULL; p = p->next)
        {
            if (p->info == el)
            {
                temp = p;
                break;
            }
        }
        return temp;
    }

    int count_node()
    {
        int count = 0;
        node<T> *p = back->next;

        do
        {
            count++;
            p = p->next;
        } while (p != back->next);
        return count;
    }

    void display()
    {
        node<T> *j = back->next;

        do
        {
            cout << j->info << " ";
            j = j->next;

            cout << " ";
        } while (j != back->next);

        cout << endl;
        return;
    }
    void add_position(T el, T aftervalue)
    {
        if (isempty())
        {
            cout << "List is empty. Cannot insert after element " << aftervalue << "." << endl;
            return;
        }

        node<T> *a = back->next;
        bool check = false;

        do
        {
            if (a->info == aftervalue)
            {
                node<T> *temp = new node<T>(el);
                temp->next = a->next;
                a->next = temp;
                check = true;
                break;
            }
            a = a->next;
        } while (a != back->next);

        if (!check)
        {
            cout << "Element " << aftervalue << " not found in the list. Cannot insert after it." << endl;
        }
    }

    Cirlist<T> concat(const Cirlist<T> &B)
    {
        Cirlist<T> result;

        node<T> *current = back->next;
        do
        {
            result.add_back(current->info);
            current = current->next;
        } while (current != back->next);

        current = B.back->next;
        do
        {
            result.add_back(current->info);
            current = current->next;
        } while (current != B.back->next);

        return result;
    }
};

template <class T>
Cirlist<T>::~Cirlist()
{
    node<T> *p, *q;
    p = back->next;
    while (!(p == back))
    {
        q = p;
        p = p->next;
        delete q;
    }
    delete back;
}

int main()
{
    Cirlist<int> l1;
    Cirlist<int> l2;

    l2.add_back(99);
    l2.add_back(10);
    l2.display();
    l1.add_front(7);
    l1.add_back(9);
    l1.add_back(23);
    l1.add_front(8);
    l1.add_position(111, 9);
    l1.display();
    Cirlist<int> l3 = l1.concat(l2);
    l3.display();
}