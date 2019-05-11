## Program for pipe() - systemcall

# 1. Interprocess communication with pipe

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/InterProcessCommunication/pipe/5.pipe_message.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/raw/master/InterProcessCommunication/pipe/5.pipe_message.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/InterProcessCommunication/pipe/README.md#output1)

### Algorithm

Step 1 − Create a pipe.

Step 2 − Create a child process.

Step 3 − Parent process writes to the pipe.

Step 4 − Child process retrieves the message from the pipe and writes it to the standard output.

Step 5 − Repeat step 3 and step 4 once again.

## Output1

![output_image](/.github/out_img/p_04_out.png)

# 2. Sorting using pipe() communication

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/InterProcessCommunication/pipe/6.pipe_sort.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/raw/master/InterProcessCommunication/pipe/6.pipe_sort.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/Network-Programming-lab/blob/master/InterProcessCommunication/pipe/README.md#output2)

## Output2

![output_image](/.github/out_img/p_05_out.png)

## Theory

A pipe is a connection between two processes, such that the standard output from one process becomes the standard input of the other process.

Parent and child sharing a pipe

When we use fork in any process, file descriptors remain open across child process and also parent process. If we call fork after creating a pipe, then the parent and child can communicate via the pipe.

![image](/.github/out_img/sharing-pipe.jpg)

## Syntax

```
    int pipe(int fd[2]);

    Parameters :

    fd[0] will be the fd(file descriptor) for the
    read end of pipe.

    fd[1] will be the fd(file descriptor) for the write end of pipe.
    Returns : 0 on Success.
    -1 on error.
```

### Whatever is written into fd[1] can be read from fd[0].

## Terms

- File descriptor is integer that uniquely identifies an open file of the process.

- **read()** systemcall

      From the file indicated by the file descriptor fd, the read() function reads cnt bytes of input into the memory area indicated by buf. A successful read() updates the access time for the file.

      Syntax in C language

      ```size_t read (int fd, void* buf, size_t cnt); ```

      Parameters
      - fd: file descripter
      - buf: buffer to read data from
      - cnt: length of buffer

      Returns: How many bytes were actually read
      - return Number of bytes read on success
      - return 0 on reaching end of file
      - return -1 on error
      - return -1 on signal interrupt

      Note
      - **buf** needs to point to a valid memory location with length not smaller than the specified size because of overflow.
      - **fd** should be a valid file descriptor returned from open() to perform read operation because if fd is NULL then read should generate error.
      - **cnt** is the requested number of bytes read, while the return value is the actual number of bytes read. Also, some times read system call should read less bytes than cnt.

  <hr />

- **write()**: Writes cnt bytes from buf to the file or socket associated with fd. cnt should not be greater than INT_MAX (defined in the limits.h header file). If cnt is zero, write() simply returns 0 without attempting any other action.

  ```
  #include <fcntl.h>
  size_t write (int fd, void* buf, size_t cnt);
  ```

  Parameters

  - fd: file descripter
  - buf: buffer to write data to
  - cnt: length of buffer

  Returns: How many bytes were actually written

  - return Number of bytes written on success
  - return 0 on reaching end of file
  - return -1 on error
  - return -1 on signal interrupt

  Important points

  - The file needs to be opened for write operations
    buf needs to be at least as long as specified by cnt because if buf size less than the cnt then buf will lead to the overflow condition.
  - cnt is the requested number of bytes to write, while the return value is the actual number of bytes written. This happens when fd have a less number of bytes to write than cnt.
  - If write() is interrupted by a signal, the effect is one of the following:
    -If write() has not written any data yet, it returns -1 and sets errno to EINTR.
    -If write() has successfully written some data, it returns the number of bytes it wrote before it was interrupted.

<hr />

- **open()** : Used to Open the file for reading, writing or both.
  ```
  Syntax
  #include<sys/types.h>
  #includ<sys/stat.h>
  #include <fcntl.h>
  int open (const char* Path, int flags [, int mode ]);
  ```
  **Parameters**


    - Path : path to file which you want to use
        use absolute path begin with “/”, when you are not work in same directory of file.
        Use relative path which is only file name with extension, when you are work in same directory of file.
    - flags : How you like to use
        - **O_RDONLY**: read only
        - **O_WRONLY**: write only
        - **O_RDWR**: read and write
        - **O_CREAT**: create file if it doesn’t exist
        - **O_EXCL**: prevent creation if it already exists
        - **O_TRUNC**: If the file exists and is a regular file, and the file is successfully opened O_RDWR or O_WRONLY, its length is truncated to 0 and the mode and owner are unchanged.

    ### How it works in OS
    - Find existing file on disk
    - Create file table entry
    - Set first unused file descriptor to point to file table entry
    - Return file descriptor used, -1 upon failure

<hr />

**sys/stat.h**: The <sys/stat.h> header defines the structure of the data returned by the functions fstat(), lstat(), and stat().

- **S_IRUSR**
  read permission, owner
- **S_IWUSR**
  write permission, owner
- **S_IXUSR**
  execute/search permission, owner
- **S_IRWXU** is the bitwise OR of **S_IRUSR**, **S_IWUSR** and **S_IXUSR**.

### References:

- [GeeksForGeeks](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)
- [OpenGroup](http://pubs.opengroup.org/onlinepubs/7908799/xsh/open.html)
- [opengroup 2](http://pubs.opengroup.org/onlinepubs/7908799/xsh/sysstat.h.html)
