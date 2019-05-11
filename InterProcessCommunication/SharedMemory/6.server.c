/* 
    Author     : abhijithvijayan
    Created on : 11 May 19, 09:58
    title      : Server
    Aim        : Interprocess communication with shared memory
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    // ftok to generate unique key
    key_t key = ftok("ipc_shared_memory", 7777);

    // shmget returns an identifier
    int id = shmget(key, 1024, 0666 | IPC_CREAT);

    // shmat to attach to shared memory
    char *str = (char *)shmat(id, NULL, 0);

    printf("Server : Write data to memory: ");

    // %s is for reading strings
    // %[^\n] will read input till \n is encountered
    // when reading strings with scanf always add width modifier to prevent buffer overrun
    scanf("%79[^\n]", str);

    printf("Server : Data written to memory: %s\n", str);

    //detach from shared memory
    shmdt(str);

    return 0;
}