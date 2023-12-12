#include <iostream>
#include <thread>
#include <functional>

using namespace std;

void calculateSquare(int x, int &result)
{
    result = x * x;
}

int main()
{
    int n, squareResult;

    cout << "Enter the value of n: ";
    cin >> n;

    // Declare the thread objects
    thread squareThread(calculateSquare, n, std::ref(squareResult));

    // Wait for both threads to finish their execution
    squareThread.join();

    cout << "The Square of " << n << " is: " << squareResult << endl;

    return 0;
}
