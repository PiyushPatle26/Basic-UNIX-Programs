#include <sys/stat.h>
#define _GNU_SOURCE
#include "errno.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("Hello, ls clone!\n");
  return 0;
}
