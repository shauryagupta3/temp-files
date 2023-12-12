#include <iostream>
#include <thread>
#include <functional>

using namespace std;

void printMultiplicationTable(int number, int n)
{
    cout << "Multiplication table for " << number << ":\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << number << " * " << i << " = " << (number * i) << endl;
    }
}

int main()
{
    int number, n;

    cout << "Enter the number for multiplication table: ";
    cin >> number;

    cout << "Enter the range (up to n) for the multiplication table: ";
    cin >> n;

    // Declare the thread object
    thread t(printMultiplicationTable, number, n);

    // Wait for the thread to finish its execution
    t.join();

    return 0;
}
