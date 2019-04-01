/* 
    Author     : abhijithvijayan
    Created on : 1 Apr 19, 11:32
    title      : Pipe() System call - Sorting
    Aim        : Interprocess communication with pipe()
*/

#include <stdio.h>
#include <unistd.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int Ar[], int n) {
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

void main() {
    
}