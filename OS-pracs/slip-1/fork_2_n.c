#include <stdio.h>
#include <unistd.h>

int main()
{
    int n = 4; // You can set the value of n as needed

    for (int i = 0; i < n; ++i)
    {
        fork();
    }

    // All processes (including the original) will print their information
    printf("Process (PID: %d)\n", getpid());

    return 0;
}
