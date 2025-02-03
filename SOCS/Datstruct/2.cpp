#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
  int NIM;
  char nama[101];
  struct Data *next;
} *head, *tail;

void pushHead(int nomor, char name[])
{
  Data *node = (Data *)malloc(sizeof(Data));
  strcpy(node->nama, name);
  node->NIM = nomor;
  node->next = NULL;

  if (head == NULL)
  {
    head = node;
    tail = node;
  }
  else
  {
    node->next = head;
    head = node;
  }
}

void pushTail(int nomor, char name[])
{
  Data *node = (Data *)malloc(sizeof(Data));
  strcpy(node->nama, name);
  node->NIM = nomor;
  node->next = NULL;

  if (head == NULL)
  {
    head = node;
    tail = node;
  }
  else
  {
    tail->next = node;
    tail = node;
  }
}

void pushAntara(int nomor, char name[])
{
  Data *node = (Data *)malloc(sizeof(Data));
  strcpy(node->nama, name);
  node->NIM = nomor;
  node->next = NULL;

  if (head == NULL)
  {
    head = node;
    tail = node;
  }
  else
  {
    Data *curr = head;
    while (curr->next->NIM < nomor)
    {
      curr = curr->next;
    }

    node->next = curr->next;
    curr->next = node;
  }
}

void pushMid(int nomor, char name[])
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
      pushAntara(nomor, name);
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
      Data *dl = head;
      head = dl->next;

      free(dl);
      dl = NULL;
    }
  }
}


void popTail(){
  if(head != NULL){
    if(head == tail){
      free(head);

      head = tail = NULL;
    }else{
      Data *dl = head;
      while(dl->next != tail){
        dl = dl->next;
      }

      tail = dl;
      free(tail->next);
      tail->next = NULL;
    }
  }
}

void popMid(int nomor){
  if(head != NULL){
    if(head == tail){
      if(head->NIM == nomor){
        free(head);
        head = tail = NULL;
      }else{
        printf("NOT FOUND");
      }
    }else{
      if(nomor == head->NIM){
        popHead();
      }else if(nomor == tail->NIM){
        popTail();
      }else{
        Data *curr = head;

        while(curr->next->NIM < nomor && curr->next != tail){
          curr = curr->next;
        }

        if(curr->next->NIM == nomor){
          Data *dl = curr->next;
          curr->next = dl->next;
          free(dl);
          dl = NULL;
        }else{
          printf("NOT FOUNF");
        }
      }
    }
  }
}

void popAll(){
  while(head != NULL) popHead();
}

void printOut()
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
  else
  {
    printf("NOT FOUND");
  }
}
int main()
{
  pushHead(123,"ALDy");
  pushTail(124,"ALDsy");
  pushMid(125,"ALDay");
  pushMid(126,"Revi");
  pushMid(120,"Gustian");

  popHead();
  popTail();
  popMid(123);

  popAll();
  printOut();
  return 0;
}