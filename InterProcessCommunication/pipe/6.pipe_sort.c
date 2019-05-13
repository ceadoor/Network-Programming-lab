/* 
    Author     : abhijithvijayan
    Created on : 1 Apr 19, 11:32
    title      : Pipe() System call - Sorting
    Aim        : Interprocess communication with pipe()
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int n, A[20], B[20];
char writeFileName[20], readFileName[20];

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int Ar[])
{
    int i, j;
    for (i = 0; i < n - 1; ++i)
    {
        for (j = 0; j < n - 1 - i; ++j)
        {
            if (Ar[j] > Ar[j + 1])
            {
                swap(&Ar[j], &Ar[j + 1]);
            }
        }
    }
}

void readArray()
{
    int i;
    printf("Enter filename: ");
    scanf("%s", writeFileName);
    printf("How many numbers: ");
    scanf("%d", &n);
    printf("Enter the array\n");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
    }
}

void displayContents(int Ar[])
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d ", Ar[i]);
    }
}

void main()
{
    int pipeFds[2], pId, fd;
    readArray();

    fd = open(writeFileName, O_CREAT | O_TRUNC | O_RDWR | S_IRWXU);
    write(fd, A, sizeof(A));
    close(fd);
    printf("File created successfully");

    int status = pipe(pipeFds);
    if (status < 1)
    {
        printf("Pipe creation failure!");
    }
    pId = fork();
    if (pId == 0)
    {
        printf("Child Process: \n");
        write(pipeFds[1], writeFileName, (strlen(writeFileName) + 1));
        exit(0);
    }
    else if (pId > 0)
    {
        printf("Parent Process: \n");
        close(pipeFds[1]);
        read(pipeFds[0], readFileName, sizeof(readFileName));
        printf("Received file %s", readFileName);
        fd = open(readFileName, O_RDONLY);
        read(fd, B, sizeof(B));
        close(fd);
        displayContents(B);
        sort(B);
        displayContents(B);
    }
}