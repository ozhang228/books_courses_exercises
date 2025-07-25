#include <assert.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int fd[2];
  int pipeRes = pipe(fd);
  assert(pipeRes != -1);

  pid_t pids[2];
  pids[0] = fork();
  assert(pids[0] != -1);

  if (pids[0] == 0) {
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    printf("hello");
  } else {
    pids[1] = fork();
    assert(pids[1] != -1);

    if (pids[1] == 0) {
      close(fd[1]);
      dup2(fd[0], STDIN_FILENO);
      char buf[100];
      read(fd[0], buf, 100);
      printf("%s", buf);
    }
  }

  int status;
  waitpid(pids[0], &status, 0);
  waitpid(pids[1], &status, 0);

  return 0;
}
