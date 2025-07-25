#include <assert.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  int rc = fork();
  assert(rc != -1);

  if (rc == 0) {
    printf("child\n");
    return 0;
  }

  int status;
  waitpid(rc, &status, 0);

  return 0;
}
