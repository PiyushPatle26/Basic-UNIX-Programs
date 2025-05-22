#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void print() {
  DIR *dirp;
  struct dirent *dp;
  long size;
  char *buf;
  char *ptr;
  size = pathconf(".", _PC_PATH_MAX);

  if ((dirp = opendir(".")) == NULL) {
    perror("couldn't open '.'");
    return;
  }
  if ((dp = readdir(dirp)) != NULL) {
    if ((buf = (char *)malloc((size_t)size)) != NULL)
      ptr = getcwd(buf, (size_t)size);
    if (ptr != NULL)
      printf("%s\n", ptr);
    free(buf);
  }

  closedir(dirp);
  return;
}

int main() {
  print();
  return 0;
}

/* Got to know about telldir seekdir and finally getcwd */
