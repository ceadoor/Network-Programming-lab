
/* 
    Author     : abhijithvijayan
    Created on : 11 May 19, 11:28
    title      : wait() - systemcall (Odd / Even)
    Aim        : To suspend a parent process until child completes using wait system call.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pId, i;
    pId = fork();
    if (pId < 0)
    {
        printf("Process creation is Unsuccessful!");
    }
    // The return value is 0 for a child process
    else if (pId == 0)
    {
        printf("Child process: Printing Odd Numbers");
        printf("\nChild : Child’s PID: %d", getpid());
        printf("\nChild : Parent’s PID: %d\n", getppid());
        for (i = 0; i <= 10; ++i)
        {
            if (i % 2 != 0)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    // The return value is positive for a parent process
    else if (pId > 0)
    {
        wait(NULL);
        printf("\nParent process: Printing Even Numbers after Child");
        printf("\nParent : Parent’s PID: %d", getpid());
        printf("\nParent : Child’s PID: %d\n", pId);
        for (i = 0; i <= 10; ++i)
        {
            if (i % 2 == 0)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}