#include "backend.h"

int main(int argc, char *argv[]) {
  char string[255] = {0};
  strcat(string, argv[argc - 1]);
  printf("before calculation %s\n", string);
  Calculate(string);
  printf("after  calculation %s\n", string);
  return 0;
}
