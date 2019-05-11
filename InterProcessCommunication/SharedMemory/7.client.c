/* 
    Author     : abhijithvijayan
    Created on : 11 May 19, 09:58
    title      : Client
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

    printf("Client : Reading data from memory\n");
    printf("Client: Data read from memory: %s\n", str);

    //detach from shared memory
    shmdt(str);

    // destroy the shared memory
    shmctl(id, IPC_RMID, NULL);

    return 0;
}