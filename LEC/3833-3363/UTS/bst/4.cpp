#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data
{
  int num;
  Data *left;
  Data *right;
} *root;

Data *insert(Data *node, int n)
{
  if (node == NULL)
  {
    node = (Data *)malloc(sizeof(Data));
    node->num = n;
    node->left = node->right = NULL;
  }
  else if (n < node->num)
  {
    node->left = insert(node->left, n);
  }
  else if (n > node->num)
  {
    node->right = insert(node->right, n);
  }

  return node;
}

Data *findMaxNode(Data *node)
{
  while (node->right != NULL)
  {
    node = node->right;
  }

  return node;
}

Data *del(Data *node, int n)
{
  if (node == NULL)
  {
    return NULL;
  }
  else
  {
    if (n < node->num)
    {
      node->left = del(node->left, n);
    }
    else if (n > node->num)
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
        Data *tmp = node;
        node = node->right;

        free(tmp);
        tmp = NULL;
      }
      else if (node->right == NULL)
      {
        Data *tmp = node;
        node = node->left;

        free(tmp);
        tmp = NULL;
      }
      else
      {
        Data *tmp = findMaxNode(node->left);
        node->num = tmp->num;
        node->left = del(node->left, tmp->num);
      }
    }
  }
}

void inOrder(Data *node)
{
  if (node != NULL)
  {
    inOrder(node->left);
    printf("%d, ", node->num);
    inOrder(node->right);
  }
}
void preOrder(Data *node)
{
  if (node != NULL)
  {
    printf("%d, ", node->num);
    preOrder(node->left);
    preOrder(node->right);
  }
}
void postOrder(Data *node)
{
  if (node != NULL)
  {
    postOrder(node->left);
    postOrder(node->right);
    printf("%d, ", node->num);
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
}

Data *search(Data *node, int n)
{
  if (node == NULL || node->num == n)
  {
    return node;
  }

  if (n < node->num)
  {
    return search(node->left, n);
  }
  return search(node->right, n);
}

int main()
{

  return 0;
}