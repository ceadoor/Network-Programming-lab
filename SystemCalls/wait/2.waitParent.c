
/* 
    Author     : abhijithvijayan
    Created on : 06 Feb 19, 11:50
    title      : wait() - systemcall
    Aim        : To block a parent process until child completes using wait system call.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    int pId;
    pId = fork();
    if (pId < 0)
    {
        printf("Process creation is Unsuccessful!");
    }
    // The return value is 0 for a child process
    else if (pId == 0)
    {
        printf("Child process:");
        printf("\nChild : Child’s PID: %d", getpid());
        printf("\nChild : Parent’s PID: %d", getppid());
    }
    // The return value is positive for a parent process
    else if (pId > 0)
    {
        wait(NULL);
        printf("\nParent process:");
        printf("\nParent : Parent’s PID: %d", getpid());
        printf("\nParent : Child’s PID: %d\n", pId);
    }
}