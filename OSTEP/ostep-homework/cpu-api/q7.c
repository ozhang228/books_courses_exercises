#include <assert.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int rc = fork();
  assert(rc != -1);

  if (rc == 0) {
    fclose(stdout);
    printf("hello");
  }

  printf("parent");
  return 0;
}
