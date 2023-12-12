#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void parentCode()
{
    printf("This is the parent process.\n");
}

void childCode()
{
    printf("This is the child process.\n");
}

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
        childCode();
    }
    else
    {
        // Parent process
        wait(NULL);
        parentCode();
    }

    return 0;
}
