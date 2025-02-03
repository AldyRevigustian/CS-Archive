#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
  int NIM;
  char nama[200];
  struct Data *next;
} *head, *tail;

void pushHead(int nomor, char name[])
{
  struct Data *node = (struct Data *)malloc(sizeof(struct Data));
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
};

void pushTail(int nomor, char name[])
{
  struct Data *node = (struct Data *)malloc(sizeof(struct Data));
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
};

void pushAntara(int nomor, char name[])
{
  struct Data *node = (struct Data *)malloc(sizeof(struct Data));
  strcpy(node->nama, name);
  node->NIM = nomor;
  node->next = NULL;

  struct Data *curr = head;
  while (curr->next->NIM < nomor)
  {
    curr = curr->next;
  }

  node->next = curr->next;
  curr->next = node;
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

void popHead(){
  if(head != NULL){
    if(head == tail){
      free(head);
      head = tail = NULL;
    }else{
      struct Data *curr = head;
      head = curr->next;
      
      free(curr);
      curr = NULL;
    }
  }
};

void popTail(){
  if(head != NULL){
    if(head == tail){
      free(head);
      head = tail = NULL;
    }else{
      struct Data *curr = head;

      while(curr->next != tail){
        curr = curr->next;
      }

      tail = curr;
      free(tail->next);
      tail->next = NULL;
    }
  }
};

void popMid(int nomor){
  if(head != NULL){
    if(head == tail){
      if(nomor == head->NIM){
        free(head);
        head = tail = NULL;
      }else{
        printf("NOT FOUND\n");
      }
    }else{
        if(nomor == head->NIM){
          popHead();
        }else if( nomor == tail->NIM){
          popTail();
        }else{
          struct Data *curr = head;

          while(curr->next->NIM < nomor && curr->next != tail){
            curr = curr->next;
          }

          if(curr->next->NIM == nomor){
            struct Data *del = curr->next;
            curr->next = del->next;
            free(del);
            del = NULL;
          }else{
            printf("NOT FOUND\n");
          }
        }
      }
  }
};
void popAll(){
  while(head != NULL) popHead();
};

void printList()
{
  if (head != NULL)
  {
    struct Data *temp = head;

    while (temp != NULL)
    {
      printf("NIM : %d, Nama : %s", temp->NIM, temp->nama);
      printf("\n");
      temp = temp->next;
    }
  }else{
    printf("NOT FOUND\n");
  }
}
int main()
{
  pushMid(270, "Aldy");
  pushMid(272, "Revi");
  pushMid(271, "Gustian");

  // popHead();
  // popHead();
  // popTail();
  // popHead();
  // popMid(1000);
  
  popAll();

  // pushTail(270, "Aldy");
  // pushTail(271, "Revi");
  // pushHead(270, "Aldy");
  // pushHead(271, "Revi");

  printList();
  return 0;
}