#include "backend.h"

int Calculate(char input_string[255]) {
  if (IsInputCorrect(input_string)) {
    // DO NOT FORGET TO CHECK IF STRING CONTAINS ONLY DIGITS

    LexemeList *rpn_line_head = NULL;
    CreateLinkedList(&rpn_line_head);
    ParseMathExpression(rpn_line_head, input_string);
    PrintRPNLine(rpn_line_head);
    DeleteLinkedList(rpn_line_head);
  }
  return 0;
}

int ParseMathExpression(LexemeList *head, char input_string[255]) {
  if (strlen(input_string) == 0)
    return OK;

  for (char *letter_pointer = input_string; *letter_pointer != '\0';
       letter_pointer++) {
    /* LexemeList *stack_head = NULL; */
    /* CreateLinkedList(stack_head); */
    if (IsDigit(letter_pointer)) {
      char *lexeme = NULL;
      GetNumberLexeme(&lexeme, &letter_pointer);
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

int CreateLinkedList(LexemeList **head) {
  LexemeList *first_node = calloc(1, sizeof(LexemeList));
  CheckIfAllocationFailed(first_node);
  first_node->link = NULL;
  *head = first_node;
  return OK;
}

int ToLine(LexemeList *head, char *incoming_lexeme) {
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

int AddNodeAtTheEnd(LexemeList **node) {
  *node = calloc(1, sizeof(LexemeList));
  CheckIfAllocationFailed(*node);
  (*node)->link = NULL;
  return 0;
}

int DeleteLinkedList(LexemeList *head) {
  LexemeList *tmp = head;
  while (tmp != NULL) {
    tmp = tmp->link;
    free(head);
    head = tmp;
  }

  //
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

bool IsSign(char const *letter_pointer) {
  return *letter_pointer == '+' || *letter_pointer == '-' ||
         *letter_pointer == '*' || *letter_pointer == '/';
}

bool IsInputCorrect(char input_string[]) {
  //
  return true;
}
