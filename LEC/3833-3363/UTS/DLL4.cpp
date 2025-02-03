#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data
{
  int data;
  Data *next;
  Data *prev;
};

struct LinkedList
{
  Data *head;
  Data *tail;
};

void insertNode(LinkedList *list, int dt)
{
  Data *node = (Data *)malloc(sizeof(Data));
  node->next = NULL;
  node->data = dt;

  if (list->head == NULL)
  {
    list->head = node;
    list->tail = node;
  }
  else
  {
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
  }
}

void printList(LinkedList *list)
{
  Data *curr = list->head;

  while (curr != NULL)
  {
    printf("%d, ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void mergeList(LinkedList *list1, LinkedList *list2)
{
  if (list2->head == NULL)
  {
    return;
  }

  if (list1->head == NULL)
  {
    list1->head = list2->head;
    list1->tail = list2->tail;
  }
  else
  {
    list1->tail->next = list2->head;
    list2->head->prev = list1->tail;

    list1->tail = list2->tail;
  }

  list2->head = list2->tail = NULL;
}

int main()
{
  LinkedList list1 = {NULL, NULL};
  LinkedList list2 = {NULL, NULL};

  insertNode(&list1, 10);
  insertNode(&list2, 20);

  printList(&list1);
  mergeList(&list1, &list2);
  printList(&list1);
  printList(&list2);

  return 0;
}