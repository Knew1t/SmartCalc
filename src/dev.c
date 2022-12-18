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
    strcat(x_value, argv[argc - 1]);
    printf("before calculation %s\n", string);
    // answer = IsInputCorrect(string);
    char expression_string[256] =
        "tan( 3.764) ^sin( 9.445-sin( 7.2889 /  8.0438 -cos( sin(cos( "
        "tan(8.4448))) - 4.482)  )  / tan(cos(cos(sin(cos( "
        "cos(2.003)) )  ) / 0.1315) ))  -  8.8453/ 0.3612";
    int err = Calculate(expression_string, &answer, x_value);
    printf("answer %lf\n", answer);
    printf("error_output = %d", err);
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
