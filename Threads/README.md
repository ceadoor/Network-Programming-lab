## Program using Threads

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/Threads/3.prime_fib_threads.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge )](https://github.com/KTU-CSE/Network-Programming-lab/raw/master/Threads/3.prime_fib_threads.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/Threads/README.md#output)

![](/.github/out_img/threads.png)


### Process : It is an instance of a program, that is under execution.
Processes are completely dynamic in nature. It is continuously changing as the CPU executes instructions. Linux kernel is designed in such a way that each process has its own rights and permissions. An issue in one process cannot impact the other processes running in the system. This is because each process has its segregated address space. 

### A thread of execution is often regarded as the smallest unit of processing that a scheduler works on.

A process can have multiple threads of execution which are executed **asynchronously.**

#### Use of Threads
Synchronous model of execution cannot be applied everywhere and hence was the requirement of asynchronous model of execution felt which is implemented by using threads.

## Output

![output_image](/.github/out_img/p_03_out.png)