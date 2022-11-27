#ifndef BACKEND_H
#define BACKEND_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LexemeList {
  char *lexeme;
  struct LexemeList *link;
} LexemeList;

enum { OK, FAILURE };

int Calculate(char string[255]);
int ParseMathExpression(LexemeList *head, char string[255]);
int GetNumberLexeme(char **lexeme, char **pointer_to_symbol);
int GetFunctionLexeme(char **lexeme, char **pointer_to_symbol);
int GetLexeme(char **lexeme, char **pointer_to_symbol,
              bool (*checker_function)(char const *));
int CompareToStackOperator(LexemeList *head, char operato[]);
void GetPriority(int *priority, const char *operato);

int CreateLinkedList(LexemeList **head);
int DeleteLinkedList(LexemeList **head);
int AddNodeAtTheEnd(LexemeList **current_node);
int ToRPNQue(LexemeList *head, char *lexeme);
int ToStack(LexemeList **head, char *lexeme);
int DeleteHeadNode(LexemeList **head);
void PrintRPNLine(LexemeList *rpn_line_head);

bool IsInputCorrect(char input_string[]);
bool CheckIfAllocationFailed(void *ptr);
bool IsDigit(char const *pointer_to_symbol);
bool IsLetter(char const *lexeme);
bool IsOperator(char const *lexeme);
bool IsFunction(char const *lexeme);

#endif /* ifndef BACKEND_H */
