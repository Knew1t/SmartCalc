#ifndef BACKEND_H
#define BACKEND_H

/*!
\file
*backend header
*/
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

///
///  Main function
///\param string incoming math expression
///\param answer incoming pointer to result variable
///\param x_value incoming pointer to x value
int Calculate(char string[256], double *answer, char *x_value);

///
/// Parses math expression into reverse polish notation que (which is really a
/// deck)
///\param string incoming math expression
///\param head head node of linked list
///
int ParseMathExpression(LexemeList *head, char string[255]);

///
/// Calculates incoming que into a number
///\param head head node of linked list
///
double EvaluateExpression(LexemeList **head);

///
///\brief Iterates over the elements of the RPN que , starting with selected
///node, to find function or operator \param lexeme_pointer node of linked list
///
void FindFirstFunctionOrOperator(LexemeList **lexeme_pointer);

///
///\brief Calculates two previous nodes and erases one of them
///
double CalculatePreviousNodes(double *result_of_calculation,
                              LexemeList **lexeme_pointer, LexemeList **head);
///
///\brief Converts strings in RPN que to double numbers
///
bool ConvertStringsToNumbers(LexemeList *rpn_line_head, double *x_ptr);
///
/// Takes incoming lexeme and creates node for it, checking what kind of lexeme
/// it is
///
int GetLexeme(char **lexeme, char **pointer_to_symbol,
              bool (*checker_function)(char const *));

///\brief Compares priorities of operators
int CompareToStackOperator(LexemeList *head, char operato[]);

///\brief Assings priority to an operator;
void GetPriority(int *priority, const char *operato);

///\brief Creates Linked List
int CreateLinkedList(LexemeList **head);

///\brief Deletes linked list
int DeleteLinkedList(LexemeList **head);

///\brief Deletes Head Node from list
int DeleteHeadNode(LexemeList **head);

///\brief Deletes tail node from list
int DeleteTailNode(LexemeList **node);

///\brief deletes selected node
int DeleteSelectedNode(LexemeList **node, LexemeList **head);

///\brief inserts node at the end of a list
int AddNodeAtTheEnd(LexemeList **head, char *incoming_lexeme);

///\brief inserts lexeme into rpn que
int ToRPNQue(LexemeList *head, char *lexeme);

///\brief inserts lexeme to stack
int ToStack(LexemeList **head, char *lexeme);

///\brief prints RPN deck
void PrintRPNLine(LexemeList *rpn_line_head);

///\brief checks if incoming string can be calculated
int IsInputCorrect(char input_string[]);

///\brief checks if incoming string can be calculated
int CheckForWrongSymbols(char input_string[]);

///
/// finds next in line lexeme (for example 3+2, if lexeme is '+', it finds
///'2')
int CheckLexemeNextToOperator(char *lexeme_finder);

///
/// finds previous in line lexeme (for example 3+2, if lexeme is '+', it finds
///'3')
int CheckLexemePreviousToOperator(char *lexeme_finder, char input_string[]);

///
/// Checks if 'x' occures in incoming string
///
int IsXPresent(char input_string[], char *x_string_value);

///\brief checks if calloc returned NULL
bool CheckIfAllocationFailed(void *ptr);

///\brief checks if current lexeme is digit (while in string)
bool IsDigit(char const *pointer_to_symbol);

///\brief checks if current lexeme is made of letters (while in string)
bool IsLetter(char const *lexeme);

///\brief checks if current lexeme is operator (while in string)
bool IsOperator(char const *lexeme);

///\brief checks if current lexeme is operator (while in string)
bool IsFunction(char const *lexeme);

///\brief checks if current lexeme is mod (while in string)
bool IsMod(char const *pointer_to_symbol);
///\brief counts brackts
int CountBrackets(char input_string[]);
///\brief checks if + or - is unary
bool CheckIfUnary(char *pointer_to_symbol, char input_string[]);
#endif /* ifndef BACKEND_H */
