#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T coeff;
    T exponent;
    Node<T> *next;
    Node(T el, T el1, Node<T> *ptr = NULL)
    {
        coeff = el;
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
            cout << p->coeff << "x^" << p->exponent << " ";
            p = p->next;
        }
        cout << endl;
        return;
    }

    polynomial<int> operator+(polynomial p2)
    {
        polynomial<int> ans;
        Node<T> *p = head;
        Node<T> *q = p2.head;
        while (p != NULL && q != NULL)
        {
            if (p->exponent == q->exponent)
            {
                int sum = p->coeff + q->coeff;
                ans.addToTail(sum, p->exponent);
                p = p->next;
                q = q->next;
            }
            else if (p->exponent > q->exponent)
            {
                ans.addToTail(p->coeff, p->exponent);
                p = p->next;
            }
            else if (q->exponent > p->exponent)
            {
                ans.addToTail(q->coeff, q->exponent);
                q = q->next;
            }
        }

        while (p != NULL)
        {
            ans.addToTail(p->coeff, p->exponent);
            p = p->next;
        }
        while (q != NULL)
        {
            ans.addToTail(q->coeff, q->exponent);
            q = q->next;
        }
        return ans;
    }

    void operator=(const polynomial l1)
    {
        polynomial<int> ans;
        Node<T> *x1 = head;
        while (x1 != NULL)
        {
            Node<T> *temp = x1;
            x1 = x1->next;
            delete temp;
        }

        Node<T> *x2 = l1.head;
        while (x2 != NULL)
        {
            addToTail(x2->coeff, x2->exponent);
            x2 = x2->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    polynomial<int> p1;
    int num_val;
    cout << "Enter number of values for 1st polynamial :";
    cin >> num_val;
    for (int i = 0; i < num_val; i++)
    {
        int coeff, exp;
        cout << "Enter " << i + 1 << "st coeffecient element : ";
        cin >> coeff;
        cout << "Enter " << i + 1 << "st exponent element : ";
        cin >> exp;
        p1.addToTail(coeff, exp);
    }
    cout << endl;
    polynomial<int> p2;
    int num_val2;
    cout << "Enter number of values for 2nd polynamial :";
    cin >> num_val2;
    for (int i = 0; i < num_val2; i++)
    {
        int coeff, exp;
        cout << "Enter " << i + 1 << "st coeffecient element : ";
        cin >> coeff;
        cout << "Enter " << i + 1 << "st exponent element : ";
        cin >> exp;
        p2.addToTail(coeff, exp);
    }

    polynomial<int> p3;
    p3 = p1 + p2;
    p3.display();
    return 0;
}