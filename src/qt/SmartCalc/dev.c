#include "backend.h"

int main(int argc, char *argv[]) {

  /* char ts[5] = "hell"; */
  /* printf("sizeof(ptr) = %lu\n", sizeof(ts)); */
  /* printf("strlen(ts) = %lu\n", strlen(ts)); */

  if (argc > 1) {
    char string[256] = {0};
    strcat(string, argv[argc - 1]);
    printf("before calculation %s\n", string);
    Calculate(string);
    printf("answer %s\n", string);
  } else {
    printf("error: no arguments given\n");
  }

  return 0;
}
