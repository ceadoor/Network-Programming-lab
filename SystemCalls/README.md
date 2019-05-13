# System Calls

- [fork()](fork/README.md)
- [wait()](wait/README.md)

PROCESS SYSTEM CALL

- **getpid()** and **getppid()**

  - The **getpid** system call returns process ID of the calling process
  - The **getppid** system call returns parent process ID of the calling process

- **fork()**

  - The fork system call is used to create a new process called child process.
    - The return value is 0 for a child process.
    - The return value is negative if process creation is unsuccessful.
    - For the parent process, return value is positive
  - The child process is an exact copy of the parent process.
  - Both the child and parent continue to execute the instructions following fork call.
  - The child can start execution before the parent or vice-versa.

- **wait()**

  - The wait system call causes the parent process to be blocked until a child terminates.
  - When a process terminates, the kernel notifies the parent by sending the **SIGCHLD** signal to the parent.
  - Without wait, the parent may finish first leaving a zombie child, to be adopted by init process

- **exit()**

  - The exit system call is used to terminate a process either normally or abnormally
  - Closes all standard I/O streams.

- **execl()**

  - The **exec** family of function (**execl**, **execv**, **execle**, **execve**, **execlp**, **execvp**) is used by the child process to load a program and execute.
  - **execl** system call requires path, program name and null pointer

- **stat()**

  - The stat system call is used to return information about a file as a structure.

- **opendir()**, **readdir()** and **closedir()**
  - The opendir system call is used to open a directory
    - It returns a pointer to the first entry
    - It returns NULL on error.
      - The readdir system call is used to read a directory as a dirent structure
    - It returns a pointer pointing to the next entry in directory stream
    - It returns NULL if an error or end-of-file occurs.
  - The closedir system call is used to close the directory stream
    - Write to a directory is done only by the kernel.
