#include <assert.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd = open("test.txt", O_WRONLY);

  int rc = fork();
  assert(rc != -1);

  if (rc == 0) {
    char *text = "hello";
    write(fd, text, 5);
  } else {
    char *text = "world";
    write(fd, text, 5);
  }

  return 0;
}
