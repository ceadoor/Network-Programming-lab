## Program using Threads

- 1. Prime-Fibonaci | Illustration using threads

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/Threads/4.prime_fib_threads.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/raw/master/Threads/4.prime_fib_threads.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/Threads/README.md#output1)

## Output1

![output_image](/.github/out_img/p_04_out.png)

- 2. Readers-Writers Problem

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/Threads/9.readerwriter.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/raw/master/Threads/9.readerwriter.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/Threads/README.md#output2)

## Output1

![output_image](/.github/out_img/p_09_out.png)

<hr />

# Theory

![](/.github/out_img/threads.png)

### Process : It is an instance of a program, that is under execution.

Processes are completely dynamic in nature. It is continuously changing as the CPU executes instructions. Linux kernel is designed in such a way that each process has its own rights and permissions. An issue in one process cannot impact the other processes running in the system. This is because each process has its segregated address space.

### A thread of execution is often regarded as the smallest unit of processing that a scheduler works on.

A process can have multiple threads of execution which are executed **asynchronously.**

#### Use of Threads

Synchronous model of execution cannot be applied everywhere and hence was the requirement of asynchronous model of execution felt which is implemented by using threads.

**Thread ID** is represented by the type ‘pthread_t’. As we already discussed that in most of the cases this type is a structure, so there has to be a function that can compare two thread IDs.

```
    #include <pthread.h>
    int pthread_equal(pthread_t tid1, pthread_t tid2);
```

So as you can see that the above function takes two thread IDs and returns nonzero value if both the thread IDs are equal or else it returns zero.

Another case may arise when a thread would want to know its own thread ID. For this case the following function provides the desired service.

```
    #include <pthread.h>
    pthread_t pthread_self(void);
```

### Thread Creation

Normally when a program starts up and becomes a process, it starts with a default thread. So we can say that every process has at least one thread of control. A process can create extra threads using the following function :

```
    #include <pthread.h>
    int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void), void *restrict arg)
```

- The first argument is a pthread_t type address. Once the function is called successfully, the variable whose address is passed as first argument will hold the thread ID of the newly created thread.
- The second argument may contain certain attributes which we want the new thread to contain. It could be priority etc.
- The third argument is a function pointer. This is something to keep in mind that each thread starts with a function and that functions address is passed here as the third argument so that the kernel knows which function to start the thread from.
- As the function (whose address is passed in the third argument above) may accept some arguments also so we can pass these arguments in form of a pointer to a void type. Now, why a void type was chosen? This was because if a function accepts more than one argument then this pointer could be a pointer to a structure that may contain these arguments.

#### Sample Example

https://pastebin.com/raw/tHsfjtye

### pthread

pthread_create() takes 4 arguments.

- The first argument is a pointer to thread_id which is set by this function.
- The second argument specifies attributes. If the value is NULL, then default attributes shall be used.
- The third argument is name of function to be executed for the thread to be created.
- The fourth argument is used to pass arguments to the function, myThreadFun.
- The pthread_join() function for threads is the equivalent of wait() for processes. A call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.

### Compiling

To compile a multithreaded program using gcc, we need to link it with the pthreads library.

```
    user@ubuntu:~/$ gcc 4.prime_fib_threads.c -lpthread
```

Refer:

https://www.thegeekstuff.com/2012/04/create-threads-in-linux/
https://www.computerhope.com/unix/usleep.htm
http://man7.org/linux/man-pages/man3/pthread_join.3.html

<hr />

## Description

A mutex is a MUTual EXclusion device, and is useful for
protecting shared data structures from concurrent modifi-
cations, and implementing critical sections and monitors.

    A  mutex  has  two possible states: unlocked (not owned by
    any thread), and locked (owned by one thread). A mutex can
    never  be owned by two different threads simultaneously. A
    thread attempting to lock a mutex that is  already  locked
    by  another  thread  is  suspended until the owning thread
    unlocks the mutex first.
