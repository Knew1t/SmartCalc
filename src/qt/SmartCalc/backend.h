#ifndef BACKEND_H
#define BACKEND_H

#include <stdio.h>
#include <string.h>

typedef struct ConversionStackLexemes {
  char *lexeme;
  ConversionStackLexemes *link;
} ConversionStackLexemes;

typedef struct ReversedPolishNotationLine {
  char *lexeme;
  ReversedPolishNotationLine *link;
} ReversedPolishNotationLine;

int Calculate(char string[255]);
int ParseMathExpression(char string[255]);

#endif /* ifndef BACKEND_H */
