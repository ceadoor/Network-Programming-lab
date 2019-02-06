
/* 
    Author     : abhijithvijayan
    Created on : 06 Feb 19, 11:50
    title      : wait() - systemcall
    Aim        : To block a parent process until child completes using wait system call.
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
        wait(NULL);
        printf("\nParent process:");
        printf("\nProcess id is %d", getpid());
        printf("\nProcess id of shell is %d\n", getppid());
    }
}