#include <iostream>
#include <math.h>

using namespace std;

template<class T,int size>
class twoStack
{
private:
    int top1,top2;
    T* nums = new T[size];
public:
    twoStack(){
        top1=-1;
        top2=size/2-1;
    }
    ~twoStack(){
        delete nums;
    }
    void push1(T el){
        if (top1+1==size/2)
        {
            cout<<"No space in Stack 1"<<endl;
            return;
        }
        nums[++top1] = el;
    }
    void push2(T el){
        if (top2+1==size)
        {
            cout<<"No space in Stack 2"<<endl;
            return;
        }
        nums[++top2] = el;
    }
    const T pop1(){
        if (top1==-1)
        {
            cout<<"Empty Stack"<<endl;
            return -1;
        }
        return nums[top1--];
    }
    const T pop2(){
        if (top2==size/2-1)
        {
            cout<<"Empty Stack"<<endl;
            return -1;
        }
        return nums[top2--];
    }
    void display1(){
        for (int i = 0; i <= top1; i++)
        {
            cout<<nums[i]<<" ";            
        }
        cout<<endl;
    }
    void display2(){
        for (int i = size/2; i <= top2; i++)
        {
            cout<<nums[i]<<" ";            
        }
        cout<<endl;
    }
    void menu() {
        int choice;
        T element;

        do {
            cout << "Two Stack Menu:" << endl;
            cout << "1. Push to Stack 1" << endl;
            cout << "2. Push to Stack 2" << endl;
            cout << "3. Pop from Stack 1" << endl;
            cout << "4. Pop from Stack 2" << endl;
            cout << "5. Display Stack 1" << endl;
            cout << "6. Display Stack 2" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter element to push to Stack 1: ";
                    cin >> element;
                    push1(element);
                    break;
                case 2:
                    cout << "Enter element to push to Stack 2: ";
                    cin >> element;
                    push2(element);
                    break;
                case 3:
                    cout << "Popped from Stack 1: " << pop1() << endl;
                    break;
                case 4:
                    cout << "Popped from Stack 2: " << pop2() << endl;
                    break;
                case 5:
                    cout << "Stack 1: ";
                    display1();
                    break;
                case 6:
                    cout << "Stack 2: ";
                    display2();
                    break;
                case 0:
                    cout << "Exiting the menu." << endl;
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
            }
        } while (choice != 0);
    }
};

int main(int argc, char const *argv[])
{
    twoStack<int,20> x;
    x.menu();
    return 0;
}
