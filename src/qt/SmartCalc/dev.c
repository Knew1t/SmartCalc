#include "backend.h"
// #include <cstring>

int main(int argc, char *argv[]) {

  /* char ts[5] = "hell"; */
  /* printf("sizeof(ptr) = %lu\n", sizeof(ts)); */
  /* printf("strlen(ts) = %lu\n", strlen(ts)); */

  if (argc > 1) {
    char string[256] = {0};
    char x_value[256] = {0};
    double answer = 0;
    strcat(string, argv[argc - 2]);
    strcat(x_value, argv[argc-1]);
    printf("before calculation %s\n", string);
    // answer = IsInputCorrect(string);
    Calculate(string, &answer,x_value);
    printf("answer %lf\n", answer);
    // // answer = IsMod(string);
    // printf("%s\n", string);
  } else {
    printf("error: no arguments given\n");
  }
  // double a =  1234.98234;
  //
  // double b = 89812.12456;
  // printf("check from dev.c = %lf\n", a+b);
  return 0;
}
