#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
  int NIM;
  char nama[101];
  Data *next;
} *head, *tail;

void pushHead(int nomor, char name[])
{
  Data *node = (Data *)malloc(sizeof(Data));
  strcpy(node->nama, name);
  node->NIM = nomor;
  node->next = NULL;

  if (head == NULL)
  {
    head = tail = node;
  }
  else
  {
    node->next = head;
    head = node;
  }
};

void pushTail(int nomor, char name[])
{
  Data *node = (Data *)malloc(sizeof(Data));
  strcpy(node->nama, name);
  node->NIM = nomor;
  node->next = NULL;

  if (head == NULL)
  {
    head = tail = node;
  }
  else
  {
    tail->next = node;
    tail = node;
  }
}

void pushMiddle(int nomor, char name[])
{
  Data *node = (Data *)malloc(sizeof(Data));
  strcpy(node->nama, name);
  node->NIM = nomor;
  node->next = NULL;

  Data *curr = head;
  while (curr->next->NIM < nomor)
  {
    curr = curr->next;
  }

  node->next = curr->next;
  curr->next = node;
}

void pushReq(int nomor, char name[])
{
  if (head == NULL)
  {
    pushHead(nomor, name);
  }
  else
  {
    if (nomor < head->NIM)
    {
      pushHead(nomor, name);
    }
    else if (nomor > tail->NIM)
    {
      pushTail(nomor, name);
    }
    else
    {
      pushMiddle(nomor, name);
    }
  }
}

void printAll()
{
  if (head != NULL)
  {
    Data *curr = head;
    while (curr != NULL)
    {
      printf("NIM : %d, NAMA : %s\n", curr->NIM, curr->nama);
      curr = curr->next;
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
      head = head->next;

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
      Data *del = head;
      while (del->next != tail)
      {
        del = del->next;
      }

      tail = del;
      free(tail->next);
      tail->next = NULL;
    }
  }
}

void popReq(int nomor)
{
  if (head != NULL)
  {
    if (head == tail)
    {
      if (head->NIM == nomor)
      {
        popHead();
      }
    }
    else if (head->NIM == nomor)
    {
      popHead();
    }
    else if (tail->NIM == nomor)
    {
      popTail();
    }
    else
    {
      Data *curr = head;
      while (head->next->NIM < nomor && head->next != NULL)
      {
        curr = curr->next;
      }

      Data *del = curr->next;
      curr->next = del->next;
      free(del);
      del = NULL;
    }
  }
}

int main()
{
  pushHead(100, "A");
  pushHead(101, "B");
  pushHead(102, "C");

  pushTail(1001, "Ad");
  pushTail(1011, "Bd");
  pushTail(1021, "Cd");
  
  pushReq(200, "Ada");
  pushReq(201, "Bda");
  pushReq(202, "Cda");

  popHead();
  popTail();

  popReq(101);

  printAll();
  return 0;
}