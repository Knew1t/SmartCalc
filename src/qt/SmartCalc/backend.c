#include "backend.h"

int Calculate(char input_string[255]) {
  ParseMathExpression(input_string);
  return 0;
}

int ParseMathExpression(char input_string[255]) {
  char *lexeme = calloc(1, sizeof(char));
  CheckIfAllocationFailed(lexeme);
  for (char *letter_pointer = input_string; *letter_pointer != '\0';
       letter_pointer++) {
    if (IsDigit(letter_pointer)) {
      int count_digits = 0;
      do {
        ++count_digits;
        ++letter_pointer;
      } while (IsDigit(letter_pointer));
      lexeme = realloc(lexeme, count_digits + 1);
      CheckIfAllocationFailed(lexeme);
      memcpy(lexeme, letter_pointer, sizeof(char) * count_digits);
    }
    if (IsLetter(letter_pointer)) {
    }
    if (IsSign(letter_pointer)) {
    }
  }
  return 0;
}

int CheckIfAocationFailed(void *ptr) {
  if (ptr == NULL)
    exit(FAILURE);
  return 0;
}

bool IsDigit(char const *letter_pointer) {
  return (*letter_pointer >= 48 && *letter_pointer <= 57) ||
         *letter_pointer == '.';
}

bool IsLetter(char const *letter_pointer) {
  return (*letter_pointer >= 65 && *letter_pointer <= 90) ||
         (*letter_pointer >= 97 && *letter_pointer <= 122);
}

bool IsSign(char const *letter_pointer) {
  return *letter_pointer == '+' || *letter_pointer == '-' ||
         *letter_pointer == '*' || *letter_pointer == '/';
}
