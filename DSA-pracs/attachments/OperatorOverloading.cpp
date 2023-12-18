#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T info;
    Node<T> *next;
    Node(T el, Node<T> *ptr = NULL)
    {
        info = el;
        next = ptr;
    }
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    
public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void addToTail(T el)
    {
        if (head == NULL)
        {
            head = new Node<T>(el);
            tail = head;
            return;
        }
        Node<T> *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = new Node<T>(el);
        tail = p->next;
        return;
    }

    void display()
    {
        Node<T> *p = head;
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
        return;
    }

    LinkedList operator+(const LinkedList l1)
    {
        LinkedList<int> concate;
        Node<T> *x1 = head;
        Node<T> *x2 = l1.head;

        while (x1 != NULL)
        {
            concate.addToTail(x1->info);
            x1 = x1->next;
        }

        while (x2 != NULL)
        {
            concate.addToTail(x2->info);
            x2 = x2->next;
        }

        return concate;
    }

    void operator=(const LinkedList l1)
    {
        LinkedList<int> concate;
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
            addToTail(x2->info);
            x2 = x2->next;
        }
    }
};

int main()
{
    LinkedList<int> p1;
    int num_val;
    cout << endl << "Enter number of values for 1st polynomial : ";
    cin >> num_val;
    for (int i = 0; i < num_val; i++)
    {
        int val;
        cout << "Enter " << i + 1 << "st  element : ";
        cin >> val;
        p1.addToTail(val);
    }
    cout << endl;
    LinkedList<int> p2;
    int num_val2;
    cout << "Enter number of values for 2nd polynomial : ";
    cin >> num_val2;
    for (int i = 0; i < num_val2; i++)
    {
        int val;
        cout << "Enter " << i + 1 << "st  element : ";
        cin >> val;
        p2.addToTail(val);
    }
    LinkedList<int> concate;
    concate = p1 + p2;
    concate.display();
    return 0;
}
