#include "backend.h"

int Calculate(char input_string[255]) {
  if (IsInputCorrect(input_string)) {
    // DO NOT FORGET TO CHECK IF STRING CONTAINS ONLY DIGITS

    LexemeList *rpn_line_head = NULL;
    CreateLinkedList(&rpn_line_head);
    ParseMathExpression(rpn_line_head, input_string);
    /* PrintRPNList(rpn_line_head); */
    DeleteLinkedList(&rpn_line_head);
  }
  return 0;
}

int ParseMathExpression(LexemeList *rpn_line_head, char input_string[255]) {
  if (strlen(input_string) == 0)
    return OK;

  LexemeList *stack_head = NULL;
  CreateLinkedList(&stack_head);

  for (char *pointer_to_symbol = input_string; *pointer_to_symbol != '\0';
       pointer_to_symbol++) {
    if (IsDigit(pointer_to_symbol)) {
      char *lexeme = NULL;
      GetNumberLexeme(&lexeme, &pointer_to_symbol);
      ToRPNQue(rpn_line_head, lexeme);
      free(lexeme);
    }
    if (*pointer_to_symbol == '(') {
      char lexeme[2] = {0};
      lexeme[0] = *pointer_to_symbol;
      ToStack(&stack_head, pointer_to_symbol);
    }
    if (IsFunction(pointer_to_symbol)) {
      char *lexeme = NULL;
      GetFunctionLexeme(&lexeme, &pointer_to_symbol);
      ToStack(&stack_head, pointer_to_symbol);
    }
    if (*pointer_to_symbol == ')') {
      while (stack_head->lexeme && *(stack_head->lexeme) != '(') {
        ToRPNQue(rpn_line_head, stack_head->lexeme);
        DeleteHeadNode(&stack_head);
      }
      if (stack_head->lexeme == NULL)
        exit(FAILURE);
      DeleteHeadNode(&stack_head);
      if (IsFunction(stack_head->lexeme)) {
        ToRPNQue(rpn_line_head, stack_head->lexeme);
        DeleteHeadNode(&stack_head);
      }
    }
    if (IsOperator(pointer_to_symbol)) {
      char operator[2] = {0};
      operator[0] = * pointer_to_symbol;
      while (stack_head->lexeme &&
             CompareToStackOperator(stack_head, operator)) {
        ToRPNQue(rpn_line_head, stack_head->lexeme);
        DeleteHeadNode(&stack_head);
      };
      ToStack(&stack_head, operator);
    }
  }
  // puts remaining lexemes to RPNline
  while (stack_head->lexeme) {
    ToRPNQue(rpn_line_head, stack_head->lexeme);
    DeleteHeadNode(&stack_head);
  }
  PrintRPNLine(rpn_line_head);
  DeleteLinkedList(&stack_head);
  return OK;
}

int CompareToStackOperator(LexemeList *head, char operator[]) {
  int priority = 0;
  int stack_operator_priority = 0;
  GetPriority(&priority, operator);
  GetPriority(&stack_operator_priority, head->lexeme);
  return priority < stack_operator_priority;
}

void GetPriority(int *priority, const char *operator) {
  if (*operator== '-') {
    *priority = 1;
  }
  if (*operator== '+') {
    *priority = 2;
  }
  if (*operator== '/') {
    *priority = 3;
  }
  if (*operator== '*') {
    *priority = 4;
  }
}

int CreateLinkedList(LexemeList **head) {
  LexemeList *first_node = calloc(1, sizeof(LexemeList));
  CheckIfAllocationFailed(first_node);
  first_node->link = NULL;
  first_node->lexeme = NULL;
  *head = first_node;
  return OK;
}

int ToRPNQue(LexemeList *head, char *incoming_lexeme) {
  LexemeList *tmp = head;
  while (tmp->link != NULL) {
    tmp = tmp->link;
  }
  AddNodeAtTheEnd(&(tmp->link));
  tmp->lexeme = calloc(strlen(incoming_lexeme) + 1, sizeof(char));
  CheckIfAllocationFailed(tmp->lexeme);
  strcpy(tmp->lexeme, incoming_lexeme);
  return OK;
}

int ToStack(LexemeList **head, char *incoming_lexeme) {
  LexemeList *tmp = calloc(1, sizeof(LexemeList));
  tmp->lexeme = calloc(strlen(incoming_lexeme) + 1, sizeof(char));
  strcpy(tmp->lexeme, incoming_lexeme);
  tmp->link = (*head);
  *head = tmp;
  return 0;
}

int AddNodeAtTheEnd(LexemeList **node) {
  *node = calloc(1, sizeof(LexemeList));
  CheckIfAllocationFailed(*node);
  (*node)->link = NULL;
  return 0;
}

int DeleteHeadNode(LexemeList **head) {
  LexemeList *new_head = (*head)->link;
  free(*head);
  *head = new_head;
  return 0;
}

int DeleteLinkedList(LexemeList **head) {
  LexemeList *tmp = *head;
  while (tmp != NULL) {
    tmp = tmp->link;
    free((*head)->lexeme);
    free(*head);
    *head = tmp;
  }
  return 0;
}

int GetNumberLexeme(char **lexeme, char **pointer_to_symbol) {
  int count_digits = 0;
  do {
    ++count_digits;
    *(pointer_to_symbol) += 1;
  } while (IsDigit(*pointer_to_symbol));
  *lexeme = malloc(sizeof(char) * count_digits + 1);
  CheckIfAllocationFailed(*lexeme);
  memcpy(*lexeme, *(pointer_to_symbol)-count_digits,
         sizeof(char) * count_digits);
  *((*lexeme) + count_digits) = '\0'; // adds null terminator
  return 0;
}

int GetFunctionLexeme(char **lexeme, char **pointer_to_symbol) {
  int count_digits = 0;
  do {
    ++count_digits;
    *(pointer_to_symbol) += 1;
  } while (IsLetter(*pointer_to_symbol));
  *lexeme = malloc(sizeof(char) * count_digits + 1);
  CheckIfAllocationFailed(*lexeme);
  memcpy(*lexeme, *(pointer_to_symbol)-count_digits,
         sizeof(char) * count_digits);
  *((*lexeme) + count_digits) = '\0'; // adds null terminator
  return 0;
}

void PrintRPNLine(LexemeList *rpn_line_head) {
  LexemeList *ptr = rpn_line_head;
  while (ptr != NULL) {
    printf("%s\n", ptr->lexeme);
    ptr = ptr->link;
  }
}

bool CheckIfAllocationFailed(void *ptr) {
  if (ptr == NULL)
    exit(FAILURE);
  return 0;
}

bool IsDigit(char const *pointer_to_symbol) {
  return (*pointer_to_symbol >= 48 && *pointer_to_symbol <= 57) ||
         *pointer_to_symbol == '.';
}

bool IsLetter(char const *pointer_to_symbol) {
  return (*pointer_to_symbol >= 65 && *pointer_to_symbol <= 90) ||
         (*pointer_to_symbol >= 97 && *pointer_to_symbol <= 122);
}

bool IsOperator(char const *pointer_to_symbol) {
  return *pointer_to_symbol == '+' || *pointer_to_symbol == '-' ||
         *pointer_to_symbol == '*' || *pointer_to_symbol == '/';
}

bool IsInputCorrect(char input_string[]) {

  //
  return true;
}

bool IsFunction(char const *lexeme) {

  //
  return true;
}
