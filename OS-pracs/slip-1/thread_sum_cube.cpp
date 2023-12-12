#include <iostream>
#include <thread>
#include <functional>

using namespace std;

void calculateSum(int n, int &result)
{
    result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result += i;
    }
}

void calculateCube(int x, int &result)
{
    result = x * x * x;
}

int main()
{
    int n, sumResult, cubeResult;

    cout << "Enter the value of n: ";
    cin >> n;

    // Declare the thread objects
    thread sumThread(calculateSum, n, std::ref(sumResult));
    thread cubeThread(calculateCube, n, std::ref(cubeResult));

    // Wait for both threads to finish their execution
    sumThread.join();
    cubeThread.join();

    cout << "The sum of the first " << n << " natural numbers is: " << sumResult << endl;
    cout << "The cube of " << n << " is: " << cubeResult << endl;

    return 0;
}
