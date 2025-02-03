#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct Data
// {
//   int NIM;
//   char nama[101];
//   Data *next;
//   Data *prev;
// } *head = NULL, *tail = NULL;

// // Push Head
// void pushHead(int N, char name[])
// {
//   Data *node = (Data *)malloc(sizeof(Data));
//   strcpy(node->nama, name);
//   node->NIM = N;
//   node->next = NULL;
//   node->prev = NULL;

//   if (head == NULL)
//   {
//     head = node;
//     tail = node;
//   }
//   else
//   {
//     node->next = head;
//     head->prev = node;
//     head = node;
//   }
// }

// // Push Tail
// void pushTail(int N, char name[])
// {
//   Data *node = (Data *)malloc(sizeof(Data));
//   strcpy(node->nama, name);
//   node->NIM = N;
//   node->next = NULL;
//   node->prev = NULL;

//   if (head == NULL)
//   {
//     head = tail = node;
//   }
//   else
//   {
//     tail->next = node;
//     node->prev = tail;
//     tail = node;
//   }
// }

// // Push Mid
// void pushMid(int N, char name[])
// {
//   if (head == NULL)
//   {
//     pushHead(N, name);
//   }
//   else
//   {
//     if (strcmp(name, head->nama) <= 0)
//     {
//       pushHead(N, name);
//     }
//     else if (strcmp(name, tail->nama) >= 0)
//     {
//       pushTail(N, name);
//     }
//     else
//     {
//       Data *node = (Data *)malloc(sizeof(Data));
//       strcpy(node->nama, name);
//       node->NIM = N;
//       node->prev = NULL;
//       node->next = NULL;

//       Data *curr = head;

//       while (strcmp(curr->next->nama, name) < 0)
//       {
//         curr = curr->next;
//       }

//       curr->next
//     }
//   }
// }

// // Pop Head
// // Pop Tail
// // Pop Mid
// // PrintAll

int main()
{
  printf("%d", strcmp("ALDY", "Aldy"));
  return 0;
}