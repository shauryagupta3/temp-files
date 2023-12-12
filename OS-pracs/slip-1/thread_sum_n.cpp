#include <iostream>
#include <thread>
#include <functional> // Include <functional> for std::ref

using namespace std;

void calculateSum(int n, int &result)
{
    result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result += i;
    }
}

int main()
{
    int n, sum;

    cout << "Enter the value of n: ";
    cin >> n;

    // Declare the thread object
    thread t(calculateSum, n, std::ref(sum)); // Use std::ref

    // Wait for the thread to finish its execution
    t.join();

    cout << "The sum of the first " << n << " natural numbers is: " << sum << endl;

    return 0;
}
