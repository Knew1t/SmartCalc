#include "backend.h"
/*! \mainpage Drawing Shapes
 *
 *
 * This is a Calculator. It evaluates expressions and draws graphs based on
 * them.
 */

int Calculate(char input_string[256], double *answer, char *x_string_value) {
  int error = IsInputCorrect(input_string);
  // IsInputCorrect() = 0 - okay
  // IsInputCorrect() = 1 - input is a number => do nothing
  // IsInputCorrect() = 2 - input is wrong => return error
  int x_flag = IsXPresent(input_string, x_string_value);
  double x_value = 0;
  double *x_ptr = NULL;
  *answer = 0;
  if (error == 0 && x_flag != 2) {
    LexemeList *rpn_line_head = NULL;
    CreateLinkedList(&rpn_line_head);
    ParseMathExpression(rpn_line_head, input_string);
    // PrintRPNLine(rpn_line_head);
    if (x_flag == 1) {
      x_value = atof(x_string_value);
      x_ptr = &x_value;
    }
    if (ConvertStringsToNumbers(rpn_line_head, x_ptr)) {
      EvaluateExpression(&rpn_line_head);
      *answer = rpn_line_head->number;
    } else {
      error = 2;
    }
    DeleteLinkedList(&rpn_line_head);
  } else if (error == 1) {
    if (x_flag != 1)
      *answer = atof(input_string);
    else
      *answer = atof(x_string_value);
    error = 0;
  }
  return error;
}

int IsInputCorrect(char input_string[]) {
  // IsInputCorrect = 0 - okay
  // IsInputCorrect = 1 - input is a number => do nothing
  // IsInputCorrect = 2 - input is wrong => return error
  if (*input_string == '\0' || strlen(input_string) > 255)
    return 2;
  int return_value = 0;
  // check if only numbers
  for (char *ptr = input_string; *ptr != '\0'; ++ptr) {
    if (IsDigit(ptr) && *ptr != 'x') {
      return_value = 1;
    } else {
      return_value = 0;
      break;
    }
  }
  if (return_value != 1) {
    return_value = CheckForWrongSymbols(input_string);
  }
  if (return_value == 0) {
    return_value = CountBrackets(input_string);
  }
  return return_value;
}

int CheckForWrongSymbols(char input_string[]) {
  short error_flag = 0;
  for (char *ptr_to_symbol = input_string;
       *ptr_to_symbol != '\0' && !error_flag; ++ptr_to_symbol) {
    if (IsLetter(ptr_to_symbol)) {
      if (!strncmp(ptr_to_symbol, "sin(", sizeof(char) * 4)) {
        ptr_to_symbol += 3;
      } else if (!strncmp(ptr_to_symbol, "asin(", sizeof(char) * 5)) {
        ptr_to_symbol += 4;
      } else if (!strncmp(ptr_to_symbol, "cos(", sizeof(char) * 4)) {
        ptr_to_symbol += 3;
      } else if (!strncmp(ptr_to_symbol, "acos(", sizeof(char) * 5)) {
        ptr_to_symbol += 4;
      } else if (!strncmp(ptr_to_symbol, "tan(", sizeof(char) * 4)) {
        ptr_to_symbol += 3;
      } else if (!strncmp(ptr_to_symbol, "atan(", sizeof(char) * 5)) {
        ptr_to_symbol += 4;
      } else if (!strncmp(ptr_to_symbol, "sqrt(", sizeof(char) * 5)) {
        ptr_to_symbol += 4;
      } else if (!strncmp(ptr_to_symbol, "ln(", sizeof(char) * 3)) {
        ptr_to_symbol += 2;
      } else if (!strncmp(ptr_to_symbol, "log(", sizeof(char) * 4)) {
        ptr_to_symbol += 3;
      } else if (!strncmp(ptr_to_symbol, "mod", sizeof(char) * 3) &&
                 ptr_to_symbol != input_string) {
        ptr_to_symbol += 2;
        char *lexeme_finder = ptr_to_symbol;
        error_flag = CheckLexemeNextToOperator(lexeme_finder);
      } else if (*ptr_to_symbol == 'x') {
        char *lexeme_finder = ptr_to_symbol + 1;
        while (*lexeme_finder == ' ') {
          ++lexeme_finder;
        }
        if (IsDigit(lexeme_finder))
          error_flag = 2;
        lexeme_finder = ptr_to_symbol - 1;
        while (*lexeme_finder == ' ') {
          --lexeme_finder;
        }
        if (IsDigit(lexeme_finder))
          error_flag = 2;
      } else {
        error_flag = 2;
        break;
      }
    } else if (*ptr_to_symbol == ' ') {
    } else if (*ptr_to_symbol == '(') {
      char *lexeme_finder = ptr_to_symbol + 1;
      while (*lexeme_finder == ' ') {
        ++lexeme_finder;
      }
      if (*lexeme_finder == ')')
        error_flag = 2;
    } else if (*ptr_to_symbol == ')') {
      char *lexeme_finder = ptr_to_symbol - 1;
      while (*lexeme_finder == ' ') {
        --lexeme_finder;
      }
      if (*lexeme_finder == '(')
        error_flag = 2;
      lexeme_finder = ptr_to_symbol + 1;
      while (*lexeme_finder == ' ') {
        ++lexeme_finder;
      }
      if (IsDigit(lexeme_finder))
        error_flag = 2;
    } else if (*ptr_to_symbol == '.') {
      if ((!IsDigit(ptr_to_symbol + 1) || *(ptr_to_symbol + 1) == '.') ||
          !IsDigit(ptr_to_symbol - 1) || *(ptr_to_symbol - 1) == '.') {
        error_flag = 2;
      }
    } else if (IsDigit(ptr_to_symbol) && *ptr_to_symbol != 'x') {
      char *lexeme_finder = ptr_to_symbol + 1;
      while (*lexeme_finder == ' ' || IsDigit(lexeme_finder)) {
        ++lexeme_finder;
      }
      if (*lexeme_finder == '(' ||
          (IsLetter(lexeme_finder) && *lexeme_finder != 'm'))
        error_flag = 2;
    } else if (IsOperator(ptr_to_symbol)) {
      char *lexeme_finder = ptr_to_symbol;
      if (lexeme_finder == input_string) {
        error_flag = !CheckLexemeNextToOperator(lexeme_finder) &&
                     *lexeme_finder != '*' && *lexeme_finder != '/' &&
                     *lexeme_finder != 'm' && *lexeme_finder != '^';
        error_flag = error_flag ? 0 : 2;
      } else {
        error_flag =
            !CheckLexemeNextToOperator(lexeme_finder) &&
            !CheckLexemePreviousToOperator(lexeme_finder, input_string);
        error_flag = !error_flag ? 2 : 0;
      }
    } else {
      error_flag = 2;
    }
  }
  return error_flag;
}

int CheckLexemeNextToOperator(char *lexeme_finder) {
  int error_flag = 0;
  while (!error_flag && *lexeme_finder != '\0') {
    ++lexeme_finder;
    if (*lexeme_finder == ' ') {
    } else if (IsDigit(lexeme_finder) || IsFunction(lexeme_finder) ||
               *lexeme_finder == '(' || *lexeme_finder == '+' ||
               *lexeme_finder == '-') {
      error_flag = 0;
      break;
    } else {
      error_flag = 2;
    }
  }
  return error_flag;
}

int CheckLexemePreviousToOperator(char *lexeme_finder, char input_string[]) {
  int error_flag = 0;
  char save_oper = *lexeme_finder;
  while (!error_flag && lexeme_finder != input_string) {
    --lexeme_finder;
    if (*lexeme_finder == ' ') {
    } else if (IsDigit(lexeme_finder) || *lexeme_finder == ')' ||
               *lexeme_finder == '(' ||
               ((save_oper == '-' || save_oper == '+') &&
                    (*lexeme_finder == '(') ||
                *lexeme_finder == '*' || *lexeme_finder == '/')) {
      error_flag = 0;
      break;
    } else {
      error_flag = 2;
    }
  }
  return error_flag;
}

int IsXPresent(char input_string[], char *x_string_value) {
  bool return_value = 0;
  char *ptr_to_symbol = input_string;
  while (*ptr_to_symbol != '\0') {
    if (*ptr_to_symbol == 'x') {
      return_value = 1;
      break;
    }
    ++ptr_to_symbol;
  }
  if (return_value == 1 && (*x_string_value == '\0'))
    return_value = 2;
  return return_value;
}

double EvaluateExpression(LexemeList **head) {
  double result_value = 0;
  while ((*head)->link_next != NULL) {
    LexemeList *lexeme_pointer = *head;
    FindFirstFunctionOrOperator(&lexeme_pointer);
    CalculatePreviousNodes(&result_value, &lexeme_pointer, head);
  }
  return result_value;
}

int ParseMathExpression(LexemeList *rpn_line_head, char input_string[255]) {
  if (strlen(input_string) == 0)
    return OK;
  LexemeList *stack_head = NULL;
  CreateLinkedList(&stack_head);
  for (char *pointer_to_symbol = input_string; *pointer_to_symbol != '\0';
       ++pointer_to_symbol) {
    if (IsDigit(pointer_to_symbol)) {
      char *lexeme = NULL;
      GetLexeme(&lexeme, &pointer_to_symbol, IsDigit);
      ToRPNQue(rpn_line_head, lexeme);
      free(lexeme);
    }
    if (IsFunction(pointer_to_symbol) && *pointer_to_symbol != 'x') {
      char *lexeme = NULL;
      GetLexeme(&lexeme, &pointer_to_symbol, IsLetter);
      ToStack(&stack_head, lexeme);
      free(lexeme);
    }
    if (*pointer_to_symbol == '(') {
      char lexeme[2] = {0};
      lexeme[0] = *pointer_to_symbol;
      ToStack(&stack_head, lexeme);
    }
    if (IsOperator(pointer_to_symbol)) {
      if (*pointer_to_symbol == '+') {
        if (CheckIfUnary(pointer_to_symbol, input_string)) {
          continue;
        }
      }
      char operator[2] = {0};
      operator[0] = * pointer_to_symbol;
      if (*pointer_to_symbol == '-') {
        if (CheckIfUnary(pointer_to_symbol, input_string)) {
          operator[0] = '~';
        }
      }
      while (stack_head->lexeme &&
             CompareToStackOperator(stack_head, operator)) {
        ToRPNQue(rpn_line_head, stack_head->lexeme);
        DeleteHeadNode(&stack_head);
      };
      // CHECK IF WORKS
      if (IsMod(pointer_to_symbol))
        pointer_to_symbol += 2;
      ToStack(&stack_head, operator);
    }
    if (*pointer_to_symbol == ')') {
      while (stack_head->lexeme && *(stack_head->lexeme) != '(') {
        ToRPNQue(rpn_line_head, stack_head->lexeme);
        DeleteHeadNode(&stack_head);
      }
      if (*(stack_head->lexeme) == '(')
        DeleteHeadNode(&stack_head);
      if (stack_head->lexeme && IsFunction(stack_head->lexeme)) {
        ToRPNQue(rpn_line_head, stack_head->lexeme);
        DeleteHeadNode(&stack_head);
      }
      // if (stack_head->lexeme == NULL)
      //   exit(FAILURE);
    }
  }
  // puts remaining lexemes to RPNline
  while (stack_head->lexeme) {
    ToRPNQue(rpn_line_head, stack_head->lexeme);
    DeleteHeadNode(&stack_head);
  }
  DeleteLinkedList(&stack_head);
  return OK;
}

int CompareToStackOperator(LexemeList *head, char operator[]) {
  int current_operator_priority = 0;
  int stack_operator_priority = 0;
  int return_value = 0;
  GetPriority(&current_operator_priority, operator);
  GetPriority(&stack_operator_priority, head->lexeme);
  if (*operator== *(head->lexeme) && *operator== '^') {
    return_value = false;
  } else {
    return_value = current_operator_priority <= stack_operator_priority;
  }
  return return_value;
}

void GetPriority(int *priority, const char *operator) {
  if (*operator== '^') {
    *priority = 4;
  } else if (*operator== '-') {
    *priority = 1;
  } else if (*operator== '+') {
    *priority = 1;
  } else if (*operator== 'm') {
    *priority = 2;
  } else if (*operator== '/') {
    *priority = 3;
  } else if (*operator== '*') {
    *priority = 3;
  } else if (*operator== '~') {
    *priority = 5;
  }
}

int CreateLinkedList(LexemeList **head) {
  LexemeList *first_node = calloc(1, sizeof(LexemeList));
  CheckIfAllocationFailed(first_node);
  first_node->link_next = NULL;
  first_node->lexeme = NULL;
  first_node->link_previous = NULL;
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
  CheckIfAllocationFailed(tmp);
  tmp->lexeme = calloc(strlen(incoming_lexeme) + 1, sizeof(char));
  CheckIfAllocationFailed(tmp);
  strcpy(tmp->lexeme, incoming_lexeme);
  tmp->link_next = (*head);
  tmp->link_previous = NULL; // just in case
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

int DeleteTailNode(LexemeList **node) {
  LexemeList *tmp_prev = (*node)->link_previous;
  tmp_prev->link_next = NULL;
  free((*node)->lexeme);
  free(*node);
  return 0;
}

int DeleteSelectedNode(LexemeList **node, LexemeList **head) {
  if (*head == NULL || *node == NULL)
    return 1;

  if (*head == *node) {
    DeleteHeadNode(node);
    *head = *node;
  } else if ((*node)->link_next == NULL) {
    DeleteTailNode(node);
  } else {
    LexemeList *tmp_current = *node;
    LexemeList *tmp_prev = tmp_current->link_previous;
    LexemeList *tmp_next = tmp_current->link_next;
    tmp_prev->link_next = tmp_current->link_next;
    tmp_next->link_previous = (*node)->link_previous;
    free((tmp_current)->lexeme);
    free(tmp_current);
  }
  *node = NULL;
  return 0;
}

// Gets lexemes, depending on function pointer it count digits or symbols
int GetLexeme(char **lexeme, char **pointer_to_symbol,
              bool (*checker)(char const *pointer_to_symbol)) {
  int count_symbols = 0;
  do {
    ++count_symbols;
    *(pointer_to_symbol) += 1;
  } while (checker(*pointer_to_symbol));
  *lexeme = malloc(sizeof(char) * (count_symbols + 1));
  CheckIfAllocationFailed(*lexeme);
  memcpy(*lexeme, *(pointer_to_symbol)-count_symbols,
         sizeof(char) * count_symbols);
  *((*lexeme) + count_symbols) = '\0'; // adds null terminator
  return 0;
}

void PrintRPNLine(LexemeList *rpn_line_head) {
  LexemeList *ptr = rpn_line_head;
  while (ptr != NULL) {
    // if (IsDigit(ptr->lexeme))
    //   printf("%g\n", ptr->number);
    // else
    printf("%s\n", ptr->lexeme);
    ptr = ptr->link_next;
  }
  printf("\n");
}

bool CheckIfAllocationFailed(void *ptr) {
  if (ptr == NULL)
    exit(FAILURE);
  return 0;
}

bool IsDigit(char const *pointer_to_symbol) {
  return (*pointer_to_symbol >= 48 && *pointer_to_symbol <= 57) ||
         *pointer_to_symbol == '.' || *pointer_to_symbol == 'x';
}

bool IsLetter(char const *pointer_to_symbol) {
  // allowed letters x, s, a, c, l, m
  return *pointer_to_symbol == 'x' || *pointer_to_symbol == 's' ||
         *pointer_to_symbol == 'a' || *pointer_to_symbol == 'c' ||
         *pointer_to_symbol == 'l' || *pointer_to_symbol == 'm' ||
         *pointer_to_symbol == 'o' || *pointer_to_symbol == 'i' ||
         *pointer_to_symbol == 'n' || *pointer_to_symbol == 'g' ||
         *pointer_to_symbol == 'd' || *pointer_to_symbol == 't' ||
         *pointer_to_symbol == 'q' || *pointer_to_symbol == 'r';
}

bool IsOperator(char const *pointer_to_symbol) {
  return *pointer_to_symbol == '+' || *pointer_to_symbol == '-' ||
         *pointer_to_symbol == '*' || *pointer_to_symbol == '/' ||
         *pointer_to_symbol == '~' || *pointer_to_symbol == '^' ||
         IsMod(pointer_to_symbol);
}

bool IsMod(char const *pointer_to_symbol) {
  return strncmp(pointer_to_symbol, "mod", sizeof(char) * 3) == 0;
}

bool IsFunction(char const *lexeme) {
  return IsLetter(lexeme) && !IsMod(lexeme);
}

int CountBrackets(char input_string[]) {
  short open_bracket_count = 0;
  short close_bracket_count = 0;
  for (char *ptr = input_string;
       *ptr != '\0' && (open_bracket_count >= close_bracket_count); ++ptr) {
    if (*ptr == '(')
      ++open_bracket_count;
    if (*ptr == ')')
      ++close_bracket_count;
  };
  // if (open_bracket_count != close_bracket_count) {
  //   return_value = 2;
  // } else {
  //   return_value = 0;
  // }
  return (open_bracket_count != close_bracket_count) ? 2 : 0;
}

bool CheckIfUnary(char *pointer_to_symbol, char input_string[]) {
  bool return_value = false;
  if (input_string == pointer_to_symbol) {
    return_value = true;
  } else {
    char *tmp_ptr = pointer_to_symbol - 1;
    if (*tmp_ptr == '(' || *tmp_ptr == '*' || *tmp_ptr == '/' ||
        *tmp_ptr == '-' || *tmp_ptr == '+') {
      return_value = true;
    }
  }
  return return_value;
}

void FindFirstFunctionOrOperator(LexemeList **lexeme_pointer) {
  while (IsDigit((*lexeme_pointer)->lexeme) ||
         *((*lexeme_pointer)->lexeme) == 'x') {
    (*lexeme_pointer) = (*lexeme_pointer)->link_next;
  }
}

bool ConvertStringsToNumbers(LexemeList *rpn_line_head, double *x_ptr) {
  if (!IsDigit(rpn_line_head->lexeme) && *(rpn_line_head->lexeme) != 'x')
    return false;
  while (rpn_line_head != NULL) {
    if (IsDigit(rpn_line_head->lexeme)) {
      rpn_line_head->number = atof(rpn_line_head->lexeme);
    }
    if (*(rpn_line_head->lexeme) == 'x') {
      rpn_line_head->number = *x_ptr;
    }
    rpn_line_head = rpn_line_head->link_next;
  }
  return true;
}

double CalculatePreviousNodes(double *result_value, LexemeList **lexeme_pointer,
                              LexemeList **head) {
  double second_value_holder = (*lexeme_pointer)->link_previous->number;
  char *operator=(*lexeme_pointer)->lexeme;
  LexemeList *node_to_be_deleted = NULL;
  if (*operator== '-') {
    *result_value = (*lexeme_pointer)->link_previous->link_previous->number -
                    (*lexeme_pointer)->link_previous->number;
    node_to_be_deleted = (*lexeme_pointer)->link_previous->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (*operator== '+') {
    *result_value = (*lexeme_pointer)->link_previous->link_previous->number +
                    (*lexeme_pointer)->link_previous->number;
    node_to_be_deleted = (*lexeme_pointer)->link_previous->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (*operator== '*') {
    *result_value = (*lexeme_pointer)->link_previous->link_previous->number *
                    (*lexeme_pointer)->link_previous->number;
    node_to_be_deleted = (*lexeme_pointer)->link_previous->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (*operator== '/') {
    *result_value = (*lexeme_pointer)->link_previous->link_previous->number /
                    (*lexeme_pointer)->link_previous->number;
    node_to_be_deleted = (*lexeme_pointer)->link_previous->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (*operator== '^') {
    *result_value = pow((*lexeme_pointer)->link_previous->link_previous->number,
                        (*lexeme_pointer)->link_previous->number);
    node_to_be_deleted = (*lexeme_pointer)->link_previous->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
    // } else if(!strcmp(operator,"mod")) {
  } else if (*operator== 'm') {
    *result_value =
        fmod((*lexeme_pointer)->link_previous->link_previous->number,
             (*lexeme_pointer)->link_previous->number);
    node_to_be_deleted = (*lexeme_pointer)->link_previous->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (*operator== '~') {
    *result_value = second_value_holder * -1;
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (!strcmp(operator, "sin")) {
    *result_value = sin(second_value_holder);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (!strcmp(operator, "cos")) {
    *result_value = cos(second_value_holder);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (!strcmp(operator, "tan")) {
    *result_value = tan(second_value_holder);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (!strcmp(operator, "asin")) {
    *result_value = asin(second_value_holder);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (!strcmp(operator, "acos")) {
    *result_value = acos(second_value_holder);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (!strcmp(operator, "atan")) {
    *result_value = atan(second_value_holder);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (!strcmp(operator, "sqrt")) {
    *result_value = sqrt(second_value_holder);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (!strcmp(operator, "ln")) {
    *result_value = log(second_value_holder);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  } else if (!strcmp(operator, "log")) {
    *result_value = log10(second_value_holder);
    node_to_be_deleted = (*lexeme_pointer)->link_previous;
    DeleteSelectedNode(&node_to_be_deleted, head);
  }
  (*lexeme_pointer)->lexeme[0] = '0';
  (*lexeme_pointer)->number = *result_value;
  // printf("number = %lf\n", (*lexeme_pointer)->number);
  // printf("result_value = %lf\n", *result_value);

  return 0;
}
