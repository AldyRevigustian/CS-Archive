#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data
{
  int data;
  Data *prev;
  Data *next;
} *head = NULL, *tail = NULL;

void pushMid(int dt)
{
  Data *node = (Data *)malloc(sizeof(Data));
  node->data = dt;
  node->next = node->prev = NULL;

  if (head == NULL)
  {
    head = tail = node;
  }
  else
  {
    if (dt < head->data)
    {
      node->next = head;
      head->prev = node;
      head = node;
    }
    else if (dt > tail->data)
    {
      tail->next = node;
      node->prev = tail;
      tail = node;
    }
    else
    {
      Data *curr = head;

      while (curr->next->data < dt)
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

void popMid(int dt)
{
  if (head != NULL)
  {
    if (head == tail)
    {
      if (head->data == dt)
      {
        free(head);
        head = tail = NULL;
      }
    }
    else
    {
      if (dt == head->data)
      {
        Data *curr = head;
        head = curr->next;
        head->prev = NULL;
        free(curr);
        curr = NULL;
      }
      else if (dt == tail->data)
      {
        Data *curr = tail;
        tail = curr->prev;
        tail->next = NULL;
        free(curr);
        curr = NULL;
      }
      else
      {
        Data *curr = head;
        while (curr->data < dt && curr != tail)
        {
          curr = curr->next;
        }

        if (curr->data == dt)
        {
          curr->next->prev = curr->prev;
          curr->prev->next = curr->next;

          free(curr);
          curr = NULL;
        }
      }
    }
  }
}

int main()
{
  return 0;
}