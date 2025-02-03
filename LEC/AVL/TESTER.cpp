#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  char name[1000];
  int experience;
  int height;
  Node *left, *right;
} *root = NULL;

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int height(Node *N)
{
  if (N == NULL)
    return 0;

  return N->height;
}

int getDepth(Node *N, char nama[], int exp)
{
  if (N == NULL)
    return 0;

  int depth = 1;
  Node *curr = N;

  while (curr != NULL)
  {
    if (strcmp(curr->name, nama))
    {
      return depth;
    }
    else if (exp < curr->experience)
    {
      curr = curr->left;
    }
    else if (exp > curr->experience)
    {
      curr = curr->right;
    }
    depth++;
  }
  return -1;
}

Node *leftRotate(Node *x)
{
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

Node *rightRotate(Node *y)
{
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return x;
}

int getBalance(Node *N)
{
  if (N == NULL)
    return 0;

  return height(N->left) - height(N->right);
}

Node *insert(Node *node, int exp)
{
  if (node == NULL)
  {
    node = (Node *)malloc(sizeof(Node));
    node->experience = exp;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
  }
  else if (exp < node->experience)
  {
    node->left = insert(node->left, exp);
  }
  else
  {
    node->right = insert(node->right, exp);
  }

  node->height = max(height(node->left), height(node->right)) + 1;

  int balance = getBalance(node);

  if (balance > 1 && exp < node->left->experience)
  {
    return rightRotate(node);
  }

  if (balance > 1 && exp > node->left->experience)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && exp > node->right->experience)
  {
    return leftRotate(node);
  }

  if (balance < -1 && exp < node->right->experience)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
}

Node *maxNode(Node *node)
{
  while (node->right != NULL)
  {
    node = node->right;
  }

  return node;
}

Node *remove(Node *node, int exp)
{
  if (node == NULL)
    return 0;

  if (exp < node->experience)
  {
    node->left = remove(node->left, exp);
  }
  else if (exp > node->experience)
  {
    node->right = remove(node->right, exp);
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
      Node *temp = node;
      node = node->right;
      free(temp);
    }
    else if (node->right == NULL)
    {
      Node *temp = node;
      node = node->right;
      free(temp);
    }
    else
    {
      Node *temp = maxNode(node->left);
      node->experience = temp->experience;
      node->left = remove(node->left, temp->experience);
    }
  }

  if (node == NULL)
    return node;

  node->height = max(height(node->left), height(node->right)) + 1;

  int balance = getBalance(node);

  if (balance > 1 && getBalance(node->left) >= 0)
    return rightRotate(node);
  if (balance < -1 && getBalance(node->right) <= 0)
    return leftRotate(node);

  if (balance > 1 && getBalance(node->left) < 0)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && getBalance(node->right) > 0)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

int main()
{
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  return 0;
}
