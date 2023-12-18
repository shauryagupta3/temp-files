#include<iostream>
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
    /* data */
public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void addToHead(T el)
    {
        if (head == NULL)
        {
            head = new Node<T>(el);
            tail = head;
            return;
        }
        Node<T> *p = head->next;
        head->next = new Node<T>(el, p);
        return;
    }

    void addToPos(T el, int pos)
    {
        if (head == NULL)
        {
            head = new Node<T>(el);
            tail = head;
            return;
        }
        int count = 1;
        Node<T> *p = head;
        while (count != pos - 1)
        {
            p = p->next;
            count++;
        }
        Node<T> *temp = p->next;
        p->next = new Node<T>(el, temp);
        return;
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

    void delete_head()
    {
        Node<T> *p = head;
        head = p->next;
        delete p;
        return;
    }

    void delete_tail()
    {
        Node<T> *p = head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        Node<T> *temp = p->next;
        p->next = NULL;
        tail = p;
        delete temp;
    }

    void delete_pos(int pos)
    {
        if (pos == 1)
        {
            delete_head();
            return;
        }
        int count = 1;
        Node<T> *p = head;
        while (count != pos - 1)
        {
            p = p->next;
            count++;
        }

        Node<T> *temp = p->next;
        p->next = temp->next;
        delete temp;
        return;
    }

    Node<T> *searchElem(T el)
    {
        Node<T> *temp = head;
        for (Node<T> *p = head; p != NULL; p = p->next)
        {
            if (p->info == el)
            {
                temp = p;
                break;
            }
        }
        return temp;
    }

    void removeElem(T el)
    {
        Node<T> *p = head;
        if (head->info == el)
        {
            delete_head();
            return;
        }

        while (p != NULL)
        {
            if (p->next->info == el)
            {
                Node<T> *temp = p->next;
                p->next = temp->next;
                delete temp;
                return;
            }
            p = p->next;
        }
        return;
    }

    LinkedList concat_lists(LinkedList p2)
    {
        LinkedList<T> ans;
        Node<T> *x1 = head;
        Node<T> *x2 = p2.head;

        while (x1 != NULL)
        {
            ans.addToTail(x1->info);
            x1 = x1->next;
        }

        while (x2 != NULL)
        {
            ans.addToTail(x2->info);
            x2 = x2->next;
        }

        return ans;
    }

    int countElem()
    {
        int count = 0;
        Node<T> *p = head;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    void reverse()
    {
        Node<T> *currNode = head;
        Node<T> *prevNode = NULL;
        Node<T> *nextNode = NULL;
        while (currNode != NULL)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
    }
};

int main(int argc, char const *argv[])
{
    LinkedList<int> l1;
    int num_val;
    cout << "Enter number of values for 1st list :";
    cin >> num_val;
    for (int i = 0; i < num_val; i++)
    {
        int val;
        cout << "Enter " << i + 1 << "st element : ";
        cin >> val;
        l1.addToTail(val);
    }

    while (true)
    {
        cout << endl
             << "Functions" << endl
             << "1 - Add to head" << endl
             << "2 - Add to tail" << endl
             << "3 - Add to position" << endl
             << "4 - Display" << endl
             << "5 - Delete head" << endl
             << "6 - Delete tail" << endl
             << "7 - Delete position" << endl
             << "8 - Search element" << endl
             << "9 - Remove element" << endl
             << "10 - Concatonate Lists" << endl
             << "11 - Count elements" << endl
             << "12 - Reverse list" << endl
             << "0 - Exit" << endl;

        int value;
        cout << "Enter function to perform : ";
        cin >> value;

        if (value == 0)
        {
            return 0;
        }
        else if (value == 1)
        {
            int num;
            cout << "Enter value to add : ";
            cin >> num;
            l1.addToHead(num);
        }
        else if (value == 2)
        {
            int num;
            cout << "Enter value to add : ";
            cin >> num;
            l1.addToTail(num);
        }
        else if (value == 3)
        {
            int num;
            cout << "Enter value to add : ";
            cin >> num;
            int pos;
            cout << "Enter position to add : ";
            cin >> pos;
            l1.addToPos(num, pos);
        }
        else if (value == 4)
        {
            l1.display();
        }
        else if (value == 5)
        {
            l1.delete_head();
        }
        else if (value == 6)
        {
            l1.delete_tail();
        }
        else if (value == 7)
        {
            int num;
            cout << "Enter positon to remove : ";
            cin >> num;
            l1.delete_pos(num);
        }
        else if (value == 8)
        {
            int num;
            cout << "Enter value to search : ";
            cin >> num;
            cout << l1.searchElem(num);
        }
        else if (value == 9)
        {
            int num;
            cout << "Enter value to remove : ";
            cin >> num;
            l1.removeElem(num);
        }
        else if (value == 10)
        {
            LinkedList<int> l2;
            int num_val;
            cout << "Enter number of values for 2nd list :";
            cin >> num_val;
            for (int i = 0; i < num_val; i++)
            {
                int val;
                cout << "Enter " << i + 1 << "st element : ";
                cin >> val;
                l2.addToTail(val);
            }
            LinkedList<int> l3;
            l3 = l1.concat_lists(l2);
            l3.display();
        }
        else if (value == 11)
        {
            cout << l1.countElem();
        }
        else if (value == 12)
        {
            l1.reverse();
        }
        else
        {
            cout << "Invalid input try again" << endl;
        }
    }

    return 0;
}

// int main(int argc, char const *argv[])
// {
//     LinkedList<int> l1;
//     l1.addToTail(1);
//     l1.addToTail(2);
//     l1.addToTail(3);
//     LinkedList<int> l2;
//     l2.addToTail(1);
//     l2.addToTail(2);
//     l2.addToTail(3);
//     LinkedList<int> l3;
//     l3 = l1.concat_lists(l2);
//     l3.display();

//     return 0;
// }