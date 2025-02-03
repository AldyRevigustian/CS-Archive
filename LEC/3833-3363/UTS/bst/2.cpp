#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Data *findMax(Data *node)
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
    else if (n < node->num)
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
        Data *temp = findMax(node->left);
        node->num = temp->num;
        node->left = del(node->left, temp->num);
      }
    }
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
    node->left = search(node->left, n);
  }
  else
  {
    node->right = search(node->right, n);
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

void inOrder(Data *node)
{
  if (node != NULL)
  {
    inOrder(node->left);
    printf("%s, ", node->num);
    inOrder(node->right);
  }
}
void preOrder(Data *node)
{
  printf("%s, ", node->num);
  preOrder(node->left);
  preOrder(node->right);
}
void postOrder(Data *node)
{
  postOrder(node->left);
  postOrder(node->right);
  printf("%s, ", node->num);
}

int main()
{
  return 0;
}