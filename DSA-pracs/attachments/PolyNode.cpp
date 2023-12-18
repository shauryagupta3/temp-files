#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T coff;
    T exponent;
    Node<T> *next;
    Node(T el, T el1, Node<T> *ptr = NULL)
    {
        coff = el;
        exponent = el1;
        next = ptr;
    }
};

template <class T>
class polynomial
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    polynomial()
    {
        head = tail = NULL;
    }

    void addToTail(T el, T el1)
    {
        if (head == NULL)
        {
            head = new Node<T>(el, el1);
            tail = head;
            return;
        }
        Node<T> *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = new Node<T>(el, el1);
        tail = p->next;
        return;
    }

    void display()
    {
        Node<T> *p = head;
        while (p != NULL)
        {
            cout << p->coff << "x^" << p->exponent << " ";
            p = p->next;
        }
        cout << endl;
        return;
    }

    polynomial<int> addition(polynomial p2)
    {
        polynomial<int> ans;
        Node<T> *p = head;
        Node<T> *q = p2.head;
        while (p != NULL && q != NULL)
        {
            if (p->exponent == q->exponent)
            {
                int sum = p->coff + q->coff;
                ans.addToTail(sum, p->exponent);
                p = p->next;
                q = q->next;
            }
            else if (p->exponent > q->exponent)
            {
                ans.addToTail(p->coff, p->exponent);
                p = p->next;
            }
            else if (q->exponent > p->exponent)
            {
                ans.addToTail(q->coff, q->exponent);
                q = q->next;
            }
        }

        while (p != NULL)
        {
            ans.addToTail(p->coff, p->exponent);
            p = p->next;
        }
        while (q != NULL)
        {
            ans.addToTail(q->coff, q->exponent);
            q = q->next;
        }
        return ans;
    }
};

int main()
{
    polynomial<int> p1;
    int num_val;
    cout << endl << "Enter No. of Values for 1st Polynomial : ";
    cin >> num_val;
    for (int i = 0; i < num_val; i++)
    {
        int coff, exp;
        cout << endl << "Enter Coefficient Element " << i + 1 << " : ";
        cin >> coff;
        cout << "Enter Exponent "<< i + 1  << " : ";
        cin >> exp;
        p1.addToTail(coff, exp);
    }
    cout<<endl;
    polynomial<int> p2;
    int num_val2;
    cout<< endl << "Enter No. of Values for 2nd Polynomial : ";
    cin >> num_val2;
    for (int i = 0; i < num_val2; i++)
    {
        int coff, exp;
        cout << endl << "Enter Coefficient Element " << i + 1 << " : ";
        cin >> coff;
        cout << "Enter Exponent "<< i + 1  << " : ";
        cin >> exp;
        p2.addToTail(coff, exp);
    }

    polynomial<int> p3 = p1.addition(p2);
    cout << endl;
    p3.display();
    return 0;
}
