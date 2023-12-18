#include <iostream>

using namespace std;
template <class T, int size>
class stackArr
{
private:
public:
    int arr[size] = {0};
    int top = -1;
    int *nums = arr;

    stackArr(/* args */);
    void copy(const stackArr &x);
    void push(T el);
    void clear();
    void display();
    void operator=(const stackArr &x);
    ~stackArr();
};

template <class T, int size>
stackArr<T, size>::stackArr(/* args */) {}

template <class T, int size>
stackArr<T, size>::~stackArr(/* args */)
{
    delete[] nums;
}

template <class T, int size>
void stackArr<T, size>::clear()
{
    while (top > -1)
    {
        top--;
    }
}

template <class T, int size>
void stackArr<T, size>::copy(const stackArr &x)
{
    clear();
    int index = 0;
    while (x.top >= index)
    {
        push(x.arr[index++]);
    }
    display();
    return;
}

template <class T, int size>
void stackArr<T, size>::push(T el)
{
    if (top + 1 < sizeof(arr) / sizeof(int))
    {
        arr[++top] = el;
    }
}

template <class T, int size>
void stackArr<T, size>::display()
{
    int index = 0;
    while (index <= top)
    {
        cout << arr[index++] << " ";
    }
    cout << endl;
}
template <class T, int size>
void stackArr<T, size>::operator=(const stackArr &x)
{
    copy(x);
}

int main(int argc, char const *argv[])
{
    /* code */
    stackArr<int, 5> stack;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Clear stack\n";
        cout << "4. Display stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int element;
            cout << "Enter element to push: ";
            cin >> element;
            stack.push(element);
            break;

        case 2:
            // stack.pop();
            break;

        case 3:
            stack.clear();
            break;

        case 4:
            stack.display();
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}