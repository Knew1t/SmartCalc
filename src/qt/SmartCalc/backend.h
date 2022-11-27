#ifndef BACKEND_H
#define BACKEND_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LexemeList {
  char *lexeme;
  bool unary;
  struct LexemeList *link_next;
  struct LexemeList *link_previous;
} LexemeList;

typedef struct PreviousSymbolsFlags {
  bool previous_sym_is_bracket;
  bool previous_sym_is_operator;
  bool first_symbol;
} PreviousSymbolsFlags;

enum { OK, FAILURE };

int Calculate(char string[256]);
int ParseMathExpression(LexemeList *head, char string[255]);
int EvaluateExpression(LexemeList *head);
int GetNumberLexeme(char **lexeme, char **pointer_to_symbol);
int GetFunctionLexeme(char **lexeme, char **pointer_to_symbol);
int GetLexeme(char **lexeme, char **pointer_to_symbol,
              bool (*checker_function)(char const *));
int CompareToStackOperator(LexemeList *head, char operato[]);
void GetPriority(int *priority, const char *operato);

int CreateLinkedList(LexemeList **head);
int DeleteLinkedList(LexemeList **head);
int AddNodeAtTheEnd(LexemeList **head, char *incoming_lexeme);
int ToRPNQue(LexemeList *head, char *lexeme);
int ToStack(LexemeList **head, char *lexeme);
int DeleteHeadNode(LexemeList **head);
void PrintRPNLine(LexemeList *rpn_line_head);

int IsInputCorrect(char input_string[]);
bool CheckIfAllocationFailed(void *ptr);
bool IsDigit(char const *pointer_to_symbol);
bool IsLetter(char const *lexeme);
bool IsOperator(char const *lexeme);
bool IsFunction(char const *lexeme);

int CountBrackets(char input_string[]);
bool CheckIfUnary(char *pointer_to_symbol, PreviousSymbolsFlags *check);
#endif /* ifndef BACKEND_H */
