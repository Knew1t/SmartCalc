#ifndef BACKEND_H
#define BACKEND_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LexemeList {
  char *lexeme;
  double number;
  struct LexemeList *link_next;
  struct LexemeList *link_previous;
} LexemeList;

enum { OK, FAILURE };

int Calculate(char string[256], double *answer, char* x_value);
int ParseMathExpression(LexemeList *head, char string[255]);
double EvaluateExpression(LexemeList **head);
void FindFirstFunctionOrOperator(LexemeList **lexeme_pointer,
                                 LexemeList **head);
double CalculatePreviousNodes(double *result_of_calculation,
                              LexemeList **lexeme_pointer, LexemeList **head);
bool ConvertStringsToNumbers(LexemeList *rpn_line_head, double * x_ptr );
int GetNumberLexeme(char **lexeme, char **pointer_to_symbol);
int GetFunctionLexeme(char **lexeme, char **pointer_to_symbol);
int GetLexeme(char **lexeme, char **pointer_to_symbol,
              bool (*checker_function)(char const *));
int CompareToStackOperator(LexemeList *head, char operato[]);
void GetPriority(int *priority, const char *operato);

int CreateLinkedList(LexemeList **head);
int DeleteLinkedList(LexemeList **head);
int DeleteHeadNode(LexemeList **head);
int DeleteTailNode(LexemeList **node);
int DeleteSelectedNode(LexemeList **node, LexemeList **head);
int AddNodeAtTheEnd(LexemeList **head, char *incoming_lexeme);
int ToRPNQue(LexemeList *head, char *lexeme);
int ToStack(LexemeList **head, char *lexeme);
void PrintRPNLine(LexemeList *rpn_line_head);

int IsInputCorrect(char input_string[]);
int CheckForWrongSymbols(char input_string[]);
bool IsXPresent(char input_string[]);
bool CheckIfAllocationFailed(void *ptr);
void ErrorOutput(char input_string[], char *error_string);
bool IsDigit(char const *pointer_to_symbol);
bool IsLetter(char const *lexeme);
bool IsOperator(char const *lexeme);
bool IsFunction(char const *lexeme);
bool IsMod(char const *pointer_to_symbol);

int CountBrackets(char input_string[]);
bool CheckIfUnary(char *pointer_to_symbol, char input_string[]);
#endif /* ifndef BACKEND_H */
