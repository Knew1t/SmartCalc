#include "backend.h"

int Calculate(char input_string[256]) {
  int error = IsInputCorrect(input_string);
  if (error == 1) {
    LexemeList *rpn_line_head = NULL;
    CreateLinkedList(&rpn_line_head);
    ParseMathExpression(rpn_line_head, input_string);
    EvaluateExpression(rpn_line_head);
    DeleteLinkedList(&rpn_line_head);
  } else if (error == 0) {
    memset(input_string, 0, sizeof(char) * 256);
    strcat(input_string, "Wrong Input (check parenthesis)");
  }
  return 0;
}

int EvaluateExpression(LexemeList *head) {

  //
  return 0;
}

int ParseMathExpression(LexemeList *rpn_line_head, char input_string[255]) {
  if (strlen(input_string) == 0)
    return OK;
  LexemeList *stack_head = NULL;
  CreateLinkedList(&stack_head);
  PreviousSymbolsFlags previous_sym = {.previous_sym_is_bracket = false,
                                       .previous_sym_is_operator = false,
                                       .first_symbol = true};

  for (char *pointer_to_symbol = input_string; *pointer_to_symbol != '\0';
       pointer_to_symbol++) {
    if (IsDigit(pointer_to_symbol)) {
      char *lexeme = NULL;
      GetLexeme(&lexeme, &pointer_to_symbol, IsDigit);
      ToRPNQue(rpn_line_head, lexeme);
      free(lexeme);
    }
    if (IsFunction(pointer_to_symbol)) {
      char *lexeme = NULL;
      GetLexeme(&lexeme, &pointer_to_symbol, IsLetter);
      ToStack(&stack_head, lexeme);
    }
    if (*pointer_to_symbol == '(') {
      char lexeme[2] = {0};
      lexeme[0] = *pointer_to_symbol;
      ToStack(&stack_head, pointer_to_symbol);
    }
    if (IsOperator(pointer_to_symbol)) {
      if (*pointer_to_symbol == '+') {
        if (CheckIfUnary(pointer_to_symbol, &previous_sym)) {
          continue;
        }
      }
      char operator[2] = {0};
      operator[0] = * pointer_to_symbol;
      if (*pointer_to_symbol == '-') {
        if (CheckIfUnary(pointer_to_symbol, &previous_sym)) {
          ToStack(&stack_head, operator);
          stack_head->unary = true;
        }
      }
      while (stack_head->lexeme &&
             CompareToStackOperator(stack_head, operator)) {
        ToRPNQue(rpn_line_head, stack_head->lexeme);
        DeleteHeadNode(&stack_head);
      };
      ToStack(&stack_head, operator);
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
  first_node->link_next = NULL;
  first_node->lexeme = NULL;
  first_node->link_previous = NULL;
  first_node->unary = false;
  *head = first_node;
  return OK;
}

int ToRPNQue(LexemeList *head, char *incoming_lexeme) {
  if (head->lexeme != NULL) {
    AddNodeAtTheEnd(&head, incoming_lexeme);
  } else {
    head->lexeme = calloc(strlen(incoming_lexeme) + 1, sizeof(char));
    CheckIfAllocationFailed(head->lexeme);
    strcpy(head->lexeme, incoming_lexeme);
  }
  return OK;
}

int ToStack(LexemeList **head, char *incoming_lexeme) {
  LexemeList *tmp = calloc(1, sizeof(LexemeList));
  tmp->lexeme = calloc(strlen(incoming_lexeme) + 1, sizeof(char));
  strcpy(tmp->lexeme, incoming_lexeme);
  tmp->link_next = (*head);
  tmp->link_previous = NULL; // just in case
  tmp->unary = false;
  *head = tmp;
  return 0;
}

int AddNodeAtTheEnd(LexemeList **head, char *incoming_lexeme) {
  LexemeList *tmp = *head;
  LexemeList *ptr_to_previous_node = NULL;
  while (tmp->link_next != NULL) {
    tmp = tmp->link_next;
  }
  tmp->link_next = calloc(1, sizeof(LexemeList));
  CheckIfAllocationFailed(tmp->link_next);
  ptr_to_previous_node = tmp;
  tmp = tmp->link_next;
  tmp->link_next = NULL;
  tmp->link_previous = ptr_to_previous_node;
  tmp->unary = false;
  tmp->lexeme = calloc(strlen(incoming_lexeme) + 1, sizeof(char));
  CheckIfAllocationFailed(tmp->lexeme);
  strcpy(tmp->lexeme, incoming_lexeme);
  return 0;
}

int DeleteHeadNode(LexemeList **head) {
  LexemeList *new_head = (*head)->link_next;
  free((*head)->lexeme);
  free(*head);
  *head = new_head;
  return 0;
}

int DeleteLinkedList(LexemeList **head) {
  LexemeList *tmp = *head;
  while (tmp != NULL) {
    tmp = tmp->link_next;
    free((*head)->lexeme);
    free(*head);
    *head = tmp;
  }
  return 0;
}

/* Gets lexemes, depending on function pointer it count digits or symbols */

int GetLexeme(char **lexeme, char **pointer_to_symbol,
              bool (*checker)(char const *pointer_to_symbol)) {
  int count_symbols = 0;
  do {
    ++count_symbols;
    *(pointer_to_symbol) += 1;
  } while (checker(*pointer_to_symbol));
  *lexeme = malloc(sizeof(char) * count_symbols + 1);
  CheckIfAllocationFailed(*lexeme);
  memcpy(*lexeme, *(pointer_to_symbol)-count_symbols,
         sizeof(char) * count_symbols);
  *((*lexeme) + count_symbols) = '\0'; // adds null terminator
  return 0;
}

void PrintRPNLine(LexemeList *rpn_line_head) {
  LexemeList *ptr = rpn_line_head;
  while (ptr != NULL) {
    printf("%s\n", ptr->lexeme);
    ptr = ptr->link_next;
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

int IsInputCorrect(char input_string[]) {
  int return_value = 2;
  for (char *ptr = input_string; *ptr != '\0'; ptr++) {
    if (IsDigit(ptr)) {
    } else {
      return_value = 1;
      break;
    }
  }
  if (return_value == 1) {
    return_value = CountBrackets(input_string);
  }
  return return_value;
}

bool IsFunction(char const *lexeme) { return IsLetter(lexeme); }

int CountBrackets(char input_string[]) {
  short open_bracket_count = 0;
  short close_bracket_count = 0;
  for (char *ptr = input_string; *ptr != '\0'; ptr++) {
    if (*ptr == '(')
      ++open_bracket_count;
    if (*ptr == ')')
      ++close_bracket_count;
  }

  return close_bracket_count == open_bracket_count;
}

bool CheckIfUnary(char *pointer_to_symbol, PreviousSymbolsFlags *check) {
  /* FindPreviousSymbol(pointer_to_symbol); */

  return false;
}
