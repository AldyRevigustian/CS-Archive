#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data
{
  int number;
  struct Data *left;
  struct Data *right;
} *root;

struct Data *insert(struct Data *node, int n)
{
  if (node == NULL)
  {
    node = (Data *)malloc(sizeof(Data));
    node->number = n;
    node->left = node->right = NULL;
  }
  else if (n < node->number)
  {
    node->left = insert(node->left, n);
  }
  else if (n > node->number)
  {
    node->right = insert(node->right, n);
  }
  return node;
}

Data *findMaxNode(struct Data *node)
{
  while (node->right != NULL)
  {
    node = node->right;
  }

  return node;
}

struct Data *del(Data *node, int n)
{
  if (node == NULL)
  {
    return NULL;
  }
  else
  {
    if (n < node->number)
    {
      node->left = del(node->left, n);
    }
    else if (n > node->number)
    {
      node->right = del(node->right, n);
    }
    else
    {
      if (node->left == NULL && node->right == NULL)
      {
        free(node);
        node = NULL;
      }
      else if (node->left == NULL)
      {
        Data *temp = node;
        node = node->right;
        free(temp);
        temp = NULL;
      }
      else if (node->right == NULL)
      {
        Data *temp = node;
        node = node->left;
        free(temp);
        temp = NULL;
      }
      else
      {
        Data *temp = findMaxNode(node->left);
        node->number = temp->number;
        node->left = del(node->left, temp->number);
      }
    }
    return node;
  }
}

void inOrder(Data *node)
{
  // Kiri atas kanan
  if (node != NULL)
  {
    inOrder(node->left);
    printf("%d, ", node->number);
    inOrder(node->right);
  }
}

void preOrder(Data *node)
{
  // Atas kiri kanan
  if (node != NULL)
  {
    printf("%d, ", node->number);
    preOrder(node->left);
    preOrder(node->right);
  }
}

void postOrder(Data *node)
{
  // kiri kanan atas
  if (node != NULL)
  {
    postOrder(node->left);
    postOrder(node->right);
    printf("%d, ", node->number);
  }
}

Data *delAll(Data *node)
{
  if (node != NULL)
  {
    node->left = delAll(node->left);
    node->right = delAll(node->right);
    free(node);
    node = NULL;
  }
  return NULL;
}
int main()
{
  root = insert(root, 10);
  root = insert(root, 40);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 5);

  root = del(root, 30);
  postOrder(root);
  return 0;
}