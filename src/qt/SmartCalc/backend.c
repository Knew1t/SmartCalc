#include "backend.h"

int Calculate(char input_string[255]) {
  IsInputCorrect(input_string);
  ParseMathExpression(input_string);
  return 0;
}

int ParseMathExpression(char input_string[255]) {
  if (strlen(input_string) == 0)
    return OK;
  for (char *letter_pointer = input_string; *letter_pointer != '\0';
       letter_pointer++) {
    if (IsDigit(letter_pointer)) {
      char *lexeme = NULL;
      GetNumberLexeme(&lexeme, &letter_pointer);
      ReversedPolishNotationLine *head =
          malloc(sizeof(ReversedPolishNotationLine));
      ToLine(head, lexeme);
      free(lexeme);
    }
    if (IsLetter(letter_pointer)) {
    }
    if (IsSign(letter_pointer)) {
    }
  }
  return OK;
}

int ToLine(ReversedPolishNotationLine *head, char *lexeme) {
  //
  return OK;
}

bool IsInputCorrect(char input_string[]) {
  //
  return true;
}

int GetNumberLexeme(char **lexeme, char **letter_pointer) {
  int count_digits = 0;
  do {
    ++count_digits;
    *(letter_pointer) += 1;
  } while (IsDigit(*letter_pointer));
  *lexeme = malloc(sizeof(char) * count_digits + 1);
  CheckIfAllocationFailed(*lexeme);
  memcpy(*lexeme, *(letter_pointer)-count_digits, sizeof(char) * count_digits);
  *((*lexeme) + count_digits) = '\0'; // adds null terminator
  return 0;
}

bool CheckIfAllocationFailed(void *ptr) {
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
