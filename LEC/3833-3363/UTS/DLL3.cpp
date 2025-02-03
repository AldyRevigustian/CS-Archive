#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
  char name[31];
  int status;
  struct Data *prev;
  struct Data *next;
} *head = NULL, *tail = NULL;

void pushHead(int stat, char nm[])
{
  Data *node = (Data *)malloc(sizeof(Data));
  strcpy(node->name, nm);
  node->status = stat;
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

void pushTail(int stat, char nm[])
{
  Data *node = (Data *)malloc(sizeof(Data));
  strcpy(node->name, nm);
  node->status = stat;
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

void pushPrior(int stat, char nm[])
{
  if (head == NULL)
  {
    pushHead(stat, nm);
  }
  else
  {
    if (stat < head->status)
    {
      pushHead(stat, nm);
    }
    else if (stat >= tail->status)
    {
      pushTail(stat, nm);
    }
    else
    {
      Data *node = (Data *)malloc(sizeof(Data));
      strcpy(node->name, nm);
      node->status = stat;
      node->next = NULL;
      node->prev = NULL;

      Data *curr = head;

      while (curr->next->status < stat)
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

void waitingRoom()
{
  if (head != NULL)
  {
    printf("Waiting Room: ");
    Data *curr = head;

    if (curr->next == NULL)
    {
      printf("%s", curr->name);
    }
    else
    {
      while (curr != NULL)
      {
        printf("%s, ", curr->name);
        curr = curr->next;
      }
    }
    return;
  }
  else
  {
    puts("None");
    return;
  }
}

void popHead()
{
  if (head != NULL)
  {
    if (head->status == 1)
    {
      printf("%s is in the Emergency Room\n", head->name);
    }
    else if (head->status == 2)
    {
      printf("%s is in the Examination Room\n", head->name);
    }
    else if (head->status == 3 || head->status == 4)
    {
      printf("%s is in the Consultation Room\n", head->name);
    }

    if (head == tail)
    {
      free(head);
      head = tail = NULL;
    }
    else
    {
      Data *del = head;
      head = del->next;
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

      free(tail);
    }
  }
}

int main()
{
  int N;
  scanf("%d", &N);
  getchar();

  for (int i = 0; i < N; i++)
  {
    int status = 0;
    char C1[31];
    char C2[31];
    char C3[31];

    scanf("%s", C1);
    getchar();
    if (strcmp(C1, "ADD") == 0)
    {
      scanf("%s %s", C2, C3);
      getchar();

      if (strcmp(C3, "Critical") == 0)
      {
        status = 1;
      }
      else if (strcmp(C3, "Serious") == 0)
      {
        status = 2;
      }
      else if (strcmp(C3, "Fair") == 0)
      {
        status = 3;
      }
      else if (strcmp(C3, "Good") == 0)
      {
        status = 4;
      }
      else
      {
        status = -1;
      }
      pushPrior(status, C2);
    }
    else if (strcmp(C1, "CALL") == 0)
    {
      popHead();
    }
  }
  waitingRoom();

  return 0;
}