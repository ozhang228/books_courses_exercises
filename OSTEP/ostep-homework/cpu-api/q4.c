#include <assert.h>
#include <unistd.h>

int main() {
  int rc = fork();
  assert(rc != -1);

  char *argv[2] = {".", NULL};
  if (rc == 0) {
    execv("/bin/ls", argv);
  }

  return 0;
}
