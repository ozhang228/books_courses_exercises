#include <assert.h>
#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/time.h>
// #include <sys/wait.h>
#include <unistd.h>

int main() {
  int x;
  x = 100;

  int rc = fork();

  assert(rc != -1);
  // 0 means this is the new process
  if (rc == 0) {
    x = 10;
    printf("Child: %d\n", x);
  } else {
    x = 20;
    printf("Parent: %d\n", x);
  }

  return 0;
}
