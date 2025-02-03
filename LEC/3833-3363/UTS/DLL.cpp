#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data
{
  char name[100];
  int key;
  Data *next;
  Data *prev;
} *head = NULL, *tail = NULL;

void pushHead(char n[], int k)
{
  Data *node = (Data *)malloc(sizeof(Data));

  strcpy(node->name, n);
  node->key = k;
  node->next = NULL;
  node->prev = NULL;

  if (head == NULL)
  {
    head = tail = node;
  }
  else
  {
    node->next = head;
    head->prev = node;
    head = node;
  }
}

void pushTail(char n[], int k)
{
  Data *node = (Data *)malloc(sizeof(Data));
  strcpy(node->name, n);
  node->key = k;
  node->next = NULL;
  node->prev = NULL;

  if (head == NULL)
  {
    head = tail = node;
  }
  else
  {
    tail->next = node;
    node->prev = tail;
    tail = node;
  }
}

void pushMid(char n[], int k)
{
  if (head == NULL)
  {
    pushHead(n, k);
  }
  else
  {
    if (strcmp(n, head->name) <= 0)
    {
      pushHead(n, k);
    }
    else if (strcmp(n, tail->name) >= 0)
    {
      pushTail(n, k);
    }
    else
    {
      Data *node = (Data *)malloc(sizeof(Data));
      strcpy(node->name, n);
      node->key = k;
      node->next = node->prev = NULL;

      Data *curr = head;

      while (strcmp(curr->next->name, n) < 0)
      {
        curr = curr->next;
      }

      node->next = curr->next;
      curr->next->prev = node;
      node->prev = curr;
      curr->next = node;
    }
  }
}

void popHead()
{
  if (head != NULL)
  {
    if (head == tail)
    {
      free(head);
      head = tail = NULL;
    }
    else
    {
      Data *del = head;
      head = del->next;
      // head->prev = NULL;
      del->next->prev = NULL;
      free(del);
      del = NULL;
    }
  }
}

void popTail()
{
  if (head != NULL)
  {
    if (head == tail)
    {
      free(head);
      head = tail = NULL;
    }
    else
    {
      Data *del = tail;
      tail = del->prev;
      tail->next = NULL;

      free(del);
      del = NULL;
    }
  }
}

void popMid(char n[])
{
  if (head != NULL)
  {
    if (head == tail)
    {
      if (strcmp(head->name, n) == 0)
      {
        free(head);
        head = tail = NULL;
      }
      else
      {
        printf("NOT FOUND");
      }
    }
    else
    {
      if (strcmp(head->name, n) == 0)
      {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
      }
      else if (strcmp(tail->name, n) == 0)
      {
        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
      }
      else
      {
        Data *curr = head;
        while (strcmp(curr->name, n) < 0 && curr != tail)
        {
          curr = curr->next;
        }

        if (strcmp(curr->name, n) == 0)
        {
          curr->prev->next = curr->next;
          curr->next->prev = curr->prev;

          free(curr);
          curr = NULL;
        }
        else
        {
          printf("Not Found");
        }
      }
    }
  }
}

void printOut()
{
  if (head != NULL)
  {
    Data *curr = head;
    while (curr != NULL)
    {
      printf("%d-%s\n", curr->key, curr->name);
      curr = curr->next;
    }
  }
  else
  {
    printf("Data Is Empty\n");
  }
}

void popAll()
{
  while (head != NULL)
    popHead();
}

int main()
{
  // pushHead("Aldy1", 1);
  // pushHead("Aldy2", 2);
  // pushTail("Aldy1", 1);
  // pushTail("Aldy5", 5);
  pushMid("Aldy2", 2);
  pushMid("Aldy4", 4);
  pushMid("Aldy6", 6);
  pushMid("Aldy5", 5);

  // popHead();
  // popTail();
  // popMid("Aldy5");
  // printOut();
  return 0;
}
