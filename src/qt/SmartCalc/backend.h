#ifndef BACKEND_H
#define BACKEND_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ConversionStackLexemes {
  char *lexeme;

  /* ConversionStackLexemes *link; */
} ConversionStackLexemes;

typedef struct ReversedPolishNotationLine {
  char *lexeme;

  // ReversedPolishNotationLine *link;
} ReversedPolishNotationLine;

enum { OK, FAILURE };

int Calculate(char string[255]);
int ParseMathExpression(char string[255]);
int GetNumberLexeme(char **lexeme, char **letter_pointer);

int ToStack(char *lexeme);
int ToLine(ReversedPolishNotationLine *head, char *lexeme);

bool IsInputCorrect(char input_string[]);
bool CheckIfAllocationFailed(void *ptr);
bool IsDigit(char const *letter_pointer);
bool IsLetter(char const *lexeme);
bool IsSign(char const *lexeme);

#endif /* ifndef BACKEND_H */
