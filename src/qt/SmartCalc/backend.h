#ifndef BACKEND_H
#define BACKEND_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ConversionStackLexemes {
  char *lexeme;

  ConversionStackLexemes *link;
} ConversionStackLexemes;

typedef struct ReversedPolishNotationLine {
  char *lexeme;

  ReversedPolishNotationLine *link;
} ReversedPolishNotationLine;

enum { OK, FAILURE };

int Calculate(char string[255]);
int ParseMathExpression(char string[255]);
int ToStack(char *lexeme);
int ToLine(char *lexeme);
bool CheckIfAllocationFailed(void *ptr);
bool IsDigit(char const *letter_pointer);
bool IsLetter(char const *lexeme);
bool IsSign(char const *lexeme);

#endif /* ifndef BACKEND_H */
