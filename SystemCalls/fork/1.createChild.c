
/* 
    Author     : abhijithvijayan
    Created on : 06 Feb 19, 11:00
    title      : fork() - systemcall    
    Aim        : To create a new child process using fork system call.
*/

#include <stdio.h>
#include <unistd.h>

main()
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
        printf("\nProcess id is %d", getpid());
        printf("\nProcess id of parent is %d\n", getppid());
    }
    // The return value is positive for a parent process
    else if (pId > 0)
    {
        printf("\nParent process:");
        printf("\nProcess id is %d", getpid());
        printf("\nProcess id of shell is %d\n", getppid());
    }
}