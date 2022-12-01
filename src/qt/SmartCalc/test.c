#include <stdio.h>
#include <stdlib.h>
int List_data = 1;
typedef struct List {
  int data;
  struct List *next;
  struct List *prev;
} List;
void CreateLinkedList(List **head) {
  *head = calloc(1, sizeof(List));
  (*head)->data = List_data++;
  (*head)->next = NULL;
  (*head)->prev = NULL;
}
void AddNodeAtTheEnd(List **head) {
  List *tmp = *head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  List *tmp_penult_node = tmp;
  tmp = tmp->next;
  tmp = calloc(1, sizeof(List));
  tmp_penult_node->next = tmp;
  tmp->next = NULL;
  tmp->prev = tmp_penult_node;
  tmp->data = List_data++;
}
void PrintList(List *head) {
  List *tmp = head;
  while (tmp->next != NULL) {
    printf("data = %d\n", tmp->data);
    tmp = tmp->next;
  }
}
void FindNode(List **node, List **head, int node_id) {
  *node = *head;
  while ((*node)->next != NULL && node_id != (*node)->data)
    (*node) = (*node)->next;
}
int DeleteNode(List **node, List **head) {
  if (*head == NULL || *node == NULL)
    return 1;

  if (*head == *node) {
    *head = (*head)->next;
  }

  /* if ((*node)->next == NULL) { */
  /*   (*node)->prev->next = NULL; */
  /* } */
  if ((*node)->next != NULL)
    (*node)->next->prev = (*node)->prev;

  if ((*node)->next != NULL) {
    (*node)->prev->next = (*node)->next;
  }
  free(*node);
  return 0;
}
void DeleteLinkedList(List **head) {
  List *tmp = *head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
    free(*head);
    *head = tmp;
  }
  free(tmp);
  *head = NULL;
}
int main(void) {
  List *head = NULL;
  List *node = NULL;
  CreateLinkedList(&head);
  for (int i = 0; i < 15; i++) {
    AddNodeAtTheEnd(&head);
  }
  PrintList(head);
  FindNode(&node, &head, 8);
  printf("\nnode found = %d\n", node->data);
  node = node->prev->prev;
  DeleteNode(&node, &head);
  printf("\nafter node deletion\n");
  PrintList(head);
  DeleteLinkedList(&head);

  return 0;
}
