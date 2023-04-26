                        simple_shell 🐚simple_shell 🐚

           Repository Description

This repository contains the files to simulate a basic Unix Shell with its respective commands. It uses the POSIX API to implement many of the same functionalities of the first Ken Thompson's Shell and It is made to carry out the 0x16. C - Simple Shell project at ALX Africa.

The predominantly used calls are read, write, open, execve, exit, fflush, fork, free, malloc, getline, isatty, perror, strtok, wait, and waitpid.

This simple shell is a Shell interface written in C programming language that gives to the user a prompt *Hell_Shell>> *, after it accepts, it executes a user inputted command in a separate process called child process.

               Requirements:
* Operating System: Ubuntu 14.04 LTS

* Compiler: GCC 4.8.4

              Features:
* This program displays a prompt and waits that the user types a command. A command line always ends with a new line (when user push ENTER key).
* The prompt is displayed again each time a command has been executed.
* When the user enters exit, Hell shell will end and returns the status 0.
* When the user enters exit [status], Hell Shell will end and returns the inputted status, where status is a value from 0 to 255.
* The user could stop the program using Ctrl+D (end of file).
* The shell handles the command lines with arguments and pathways.
* The program does not quit when the user imputs ^C (Ctrl+C).
* The program prints the current enviroment when the user types env.
* This program executes the most common shell commands as ls, grep, find, pwd, rm, cp, mv, exit, env, history, etc... with arguments.
* If an executable cannot be found, It prints an error message and displays the prompt again.
* This Shell supports commentaries using #,
* The Hell Shell does NOT support wildcard characters such as ls *.dat in parameters (or commands).
* This shell does NOT support pipes |, shell logical operators as && or ||, neither commands separator ;.

     Allowed functions:
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
perror (man 3 perror)
* read (man 2 read)
readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
wait4 (man 2 wait4)
* write (man 2 write)

    Process Description:
The next steps are a brief description about how the shell works:
1. First, the parent process is created when the user run the program.
2. Then, the isatty() function using STDIN_FILENO file descriptor -fd- to tests if there is an open file descriptor referring to a terminal. If isatty() returns 1, the prompt is showed using write() with STDOUT_FILENO as fd and waits for an input user command line.
3. When the user types a command, getline() function reads an entire line from the stream and strtok() function breaks the inputted command into a sequence of non-empty tokens.
4. Next, it creates a separate child process suing fork() that performs the inputted command. Unless otherwise is specified, the parent process waits for the child to exit before continuing.
5. After tokening the command, execve() function brings and executes it, the it frees all allocated memory with free().
6. Finally, the program returns to main process: prints the prompt, and waits for another user input.
  




Compiling, Debugging and Runing:
* All of your and our programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* To compile your functions use: `
gcc -Wall -Wextra -Werror -pedantic -Wno-format -g *.c -o Hell_Shell


🤝 Contributing:
Contributions, issues, and feature requests are welcome!

Feel free to check the https://github.com/munenepaul/simple_shell/issues

Show your support:
Give a ⭐️ if you like this project!
Authors:
* munenepaul - https://github.com/munenepaul
* Soriala - https://github.com/soriala
