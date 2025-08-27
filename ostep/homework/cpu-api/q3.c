#include <assert.h>
#include <stdio.h>
#include <unistd.h>
int main() {
  int rc = fork();
  assert(rc != -1);

  if (rc == 0) {
    printf("hello");
  } else {
    sleep(2);
    printf("goodbye");
  }

  return 0;
}
