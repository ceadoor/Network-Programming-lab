
/* 
    Author     : abhijithvijayan
    Created on : 06 Feb 19, 11:00
    title      : fork() - systemcall    
    Aim        : To create a new child process using fork system call.
*/

#include <stdio.h>
#include <unistd.h>

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
        printf("\nChild : Parent’s PID: %d\n", getppid());
    }
    // The return value is positive for a parent process
    else if (pId > 0)
    {
        printf("Parent process:");
        printf("\nParent : Parent’s PID: %d", getpid());
        printf("\nParent : Child’s PID: %d\n", pId);
    }
}