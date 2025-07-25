#include <assert.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int rc = fork();
  assert(rc != -1);

  if (rc == 0) {
    printf("child \n");
    int pid = wait(&rc);
    printf("%d", pid);
    return 0;
  }

  int pid = wait(&rc);
  // printf("%d", pid);
  return 0;
}
