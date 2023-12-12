#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork(); // Fork the process

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process is executing. PID: %d\n", getpid());
    }
    else
    {
        // Parent process
        printf("Parent process is executing. PID: %d\n", getpid());
    }

    return 0;
}
