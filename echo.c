#include <dirent.h>
#include <stdio.h>
#include <string.h>

static void echo(char **argv[]) {
  if (**argv[1] == NULL) {
    printf("Usage: echo [string]\n");
    return;
  }

  printf("%s\n", **argv[1]);
}

int main(int argc, char *argv[]) {
  echo(**argv[]);
  return (0);
}
