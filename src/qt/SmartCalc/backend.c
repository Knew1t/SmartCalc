#include "backend.h"

int Calculate(char input_string[255]) {
  if (IsInputCorrect(input_string)) {
    // DO NOT FORGET TO CHECK IF STRING CONTAINS ONLY DIGITS

    LexemeList *rpn_line_head = NULL;
    CreateLinkedList(&rpn_line_head);
    ParseMathExpression(rpn_line_head, input_string);
    /* PrintRPNList(rpn_line_head); */
    DeleteLinkedList(rpn_line_head);
  }
  return 0;
}

int ParseMathExpression(LexemeList *rpn_line_head, char input_string[255]) {
  if (strlen(input_string) == 0)
    return OK;

  LexemeList *stack_head = NULL;
  CreateLinkedList(&stack_head);

  for (char *letter_pointer = input_string; *letter_pointer != '\0';
       letter_pointer++) {
    if (IsDigit(letter_pointer)) {
      char *lexeme = NULL;
      GetNumberLexeme(&lexeme, &letter_pointer);
      ToRPNQue(rpn_line_head, lexeme);
      free(lexeme);
    }
    if (IsLetter(letter_pointer)) {
    }
    if (IsOperator(letter_pointer)) {
      char operator= *(letter_pointer);
      if (stack_head->lexeme) {
        while (CompareToStackOperator(stack_head, operator)) {
          ToRPNQue(rpn_line_head, stack_head->lexeme);
          DeleteHeadNode(&stack_head);
        };
      }
      ToStack(&stack_head, &operator);
    }
  }
  DeleteLinkedList(stack_head);
  return OK;
}

int CompareToStackOperator(LexemeList *head, char operator) {
  int priority = 0;
  int stack_operator_priority = 0;
  AssignPriority(&priority, &operator);
  AssignPriority(&stack_operator_priority, head->lexeme);
  return priority < stack_operator_priority;
}

void AssignPriority(int *priority, const char *operator) {
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
  tmp->lexeme = calloc(1, sizeof(incoming_lexeme));
  CheckIfAllocationFailed(tmp->lexeme);
  strcpy(tmp->lexeme, incoming_lexeme);
  return OK;
}

int ToStack(LexemeList **head, char *incoming_lexeme) {
  LexemeList *tmp = calloc(1, sizeof(incoming_lexeme));
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

int DeleteLinkedList(LexemeList *head) {
  LexemeList *tmp = head;
  while (tmp != NULL) {
    tmp = tmp->link;
    free(head);
    free(head->lexeme);
    head = tmp;
  }
  return 0;
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

bool IsDigit(char const *letter_pointer) {
  return (*letter_pointer >= 48 && *letter_pointer <= 57) ||
         *letter_pointer == '.';
}

bool IsLetter(char const *letter_pointer) {
  return (*letter_pointer >= 65 && *letter_pointer <= 90) ||
         (*letter_pointer >= 97 && *letter_pointer <= 122);
}

bool IsOperator(char const *letter_pointer) {
  return *letter_pointer == '+' || *letter_pointer == '-' ||
         *letter_pointer == '*' || *letter_pointer == '/';
}

bool IsInputCorrect(char input_string[]) {
  //
  return true;
}
