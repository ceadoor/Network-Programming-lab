## Program for IPC - SharedMemory

# 1. Interprocess communication with shared memory

Client

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/InterProcessCommunication/SharedMemory/7.client.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/raw/master/InterProcessCommunication/SharedMemory/7.client.c)

Server

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/InterProcessCommunication/SharedMemory/7.server.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/raw/master/InterProcessCommunication/SharedMemory/7.server.c)

[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/InterProcessCommunication/SharedMemory/README.md#output)

## Theory

**ftok()**: is use to generate a unique key.

**shmget()**: int shmget(key_t,size_tsize,intshmflg); upon successful completion, shmget() returns an identifier for the shared memory segment.

**shmat()**: Before you can use a shared memory segment, you have to attach yourself
to it using shmat(). void *shmat(int shmid ,void *shmaddr ,int shmflg);
shmid is shared memory id. shmaddr specifies specific address to use but we should set
it to zero and OS will automatically choose the address.

**shmdt()**: When you’re done with the shared memory segment, your program should
detach itself from it using shmdt(). int shmdt(void \*shmaddr);

**shmctl()**: when you detach from shared memory,it is not destroyed. So, to destroy
shmctl() is used. shmctl(int shmid,IPC_RMID,NULL);

## Output

![output_image](/.github/out_img/p_06_out.png)
