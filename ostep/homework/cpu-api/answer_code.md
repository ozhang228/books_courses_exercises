1. Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). 

- What value is the variable in the child process? 
It is 100 which makes sense because the fork() is basically a clone of the parent.

- What happens to the variable when both the child and parent change the value of x?
They keep their own values of x because memory is separate.

2. Write a program that opens a file and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?

Yes they can both access it. It seems like they are both able to access it as the parent writes to the file first then the child writes after. 1

3. Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?

Just sleep the parent for a few seconds. Would not work when there is more to process.

4. Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. See if you can try all of the variants of exec(), including (on Linux) execl(), execle(), execlp(), execv(), execvp(), and execvpe(). Why do you think there are so many variants of the same basic call?

They are convenience functions to make it easier to use the exec syscall. execl* uses a list of strings instead of a vector and exec*p uses path, etc. 

5. Now write a program that uses wait() to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?

wait() returns the pid of the child process. it errors if you use it in the child

6. Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?

waitpid() is useful for when you have more than one child and you want to wait on a specific one

7. Write a program that creates a child process, and then in the child closes standard output (STDOUT FILENO). What happens if the child calls printf() to print some output after closing the descriptor?

It doesn't print anything in terminal because it closes stdout.

8. Write a program that creates two children, and connects the standard output of one to the standard input of the other, using the pipe() system call.
