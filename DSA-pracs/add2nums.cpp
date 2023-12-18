#include <iostream>
#include <math.h>

using namespace std;

template <class T>
class stack
{
private:
    int top = -1;
    int *nums = new int[5];
    // int *ptr = nums;

public:
    stack(/* args */);
    ~stack();
    void addElem(T el);
    void reverse();
    void display();
    bool isempty();
    const T front();
    const T deleteTop();
};

template <class T>
stack<T>::stack(/* args */)
{
}

template <class T>
stack<T>::~stack()
{
    delete[] nums;
}

template <class T>
bool stack<T>::isempty(/* args */)
{
    return top == -1;
}

template <class T>
void stack<T>::reverse(/* args */)
{
    int copyOfTop = top;
    int i = 0;
    while (i < copyOfTop)
    {
        T temp = nums[i];
        nums[i++] = nums[copyOfTop]; 
        nums[copyOfTop--] = temp; 
    }
}

template <class T>
void stack<T>::display(/* args */)
{
    int i = 0;
    while (i <= top)
    {
        cout<<nums[i++]<<" ";
    }
    cout<<endl;
}


template <class T>
void stack<T>::addElem(T el)
{
    if (top + 1 == 10)
    {
        return;
    }
    nums[++top] = el;
}

template <class T>
const T stack<T>::front()
{
    return nums[top];
}

template <class T>
const T stack<T>::deleteTop()
{
    return nums[top--];
}

int add2nums()
{
    stack<int> x;
    stack<int> y;
    string num1, num2;
    cout << "Enter 1st num : ";
    cin >> num1;
    cout << "Enter 2nd num : ";
    cin >> num2;
    int i = 0;
    while (i < num1.size())
    {
        if (isdigit(num1.at(i)))
        {
            x.addElem(int(num1.at(i) - '0'));
        }
        i++;
    }
    int j = 0;
    while (j < num2.size())
    {
        if (isdigit(num2.at(j)))
        {
            y.addElem(int(num2.at(j) - '0'));
        }
        j++;
    }
    stack<int> ans;
    int carry = 0;
    while (!x.isempty() || !y.isempty())
    {
        x.isempty() ? x.deleteTop() : 0;
        int val = (!x.isempty() ? x.deleteTop() : 0) + (!y.isempty() ? y.deleteTop() : 0);
        int copyOfVal = val % 10 + carry;
        carry = 0;
        if (val > 9)
        {
            carry = val / 10;
        }
        ans.addElem(copyOfVal);
    }
    int val = 0;
    while (!ans.isempty())
    {
        val = val * 10 + ans.deleteTop();
    }

    return val;
}

int main(int argc, char const *argv[])
{
    stack<int> x;
    x.addElem(3);
    x.addElem(5);
    x.addElem(2);
    x.display();
    x.reverse();
    x.display();
}
