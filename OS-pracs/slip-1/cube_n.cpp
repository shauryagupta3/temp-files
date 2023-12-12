#include <iostream>
#include <thread>
#include <functional>

using namespace std;

void calculateSumOfCubes(int n, int &result)
{
    result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result += i * i * i;
    }
}

int main()
{
    int n, sumOfCubesResult;

    cout << "Enter the value of n: ";
    cin >> n;

    // Declare the thread object
    thread t(calculateSumOfCubes, n, std::ref(sumOfCubesResult));

    // Wait for the thread to finish its execution
    t.join();

    cout << "The sum of cubes of the first " << n << " natural numbers is: " << sumOfCubesResult << endl;

    return 0;
}
