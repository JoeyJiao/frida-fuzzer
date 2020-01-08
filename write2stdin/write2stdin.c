#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int write2stdin(char *buf, ssize_t len) {
  int fd;

#ifdef __ANDROID__
  fd = open("/data/local/tmp/tmp.bin", O_RDWR | O_CREAT, S_IRWXU);
#else
  fd = open("/tmp/tmp.bin", O_RDWR | O_CREAT, S_IRWXU);
#endif

  if (fd == -1) {
    printf("error %d: %s\n", errno, strerror(errno));
    return -1;
  }

  close(0);
  int newFd = dup(fd);
  if (newFd) {
    printf("error %d: %s\n", errno, strerror(errno));
    return -2;
  }

  printf("%s: write %ld bytes to stdin\n", __func__, len);
  write(0, buf, len);
  fflush(0);

  lseek(0, 0, SEEK_SET);

  return 0;
}
