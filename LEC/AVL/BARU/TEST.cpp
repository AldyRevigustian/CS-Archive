#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  int exp;
  int height;
  Node *left, *right;
} *root = NULL;

int max(int a, int b)
{
  return (a > b) ? a : b;
};

int height(Node *node)
{
  if (node == NULL)
    return 0;
  return node->height;
}

int getBalance(Node *node)
{
  return height(node->left) - height(node->right);
}

int getDepth(int key)
{
  int depth = 1;
  Node *curr = root;

  while (curr != NULL)
  {
    if (curr->exp == key)
    {
      return depth;
    }
    else if (curr->exp < key)
      curr = curr->left;
    else if (curr->exp > key)
      curr = curr->right;

    ++depth;
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

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

Node *maxNode(Node *node)
{
  while (node->right != NULL)
  {
    node = node->right;
  }

  return node;
}

Node *insert(Node *node, int key)
{
  if (node == NULL)
  {
    node = (Node *)malloc(sizeof(Node));
    node->exp = key;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
  }
  else if (key < node->exp)
    node->left = insert(node->left, key);
  else if (key > node->exp)
    node->right = insert(node->right, key);

  node->height = max(height(node->left), height(node->right)) + 1;
  int balance = getBalance(node);

  if (balance > 1 && key < node->left->exp)
    return rightRotate(node);
  if (balance < -1 && key > node->right->exp)
    return leftRotate(node);

  if (balance > 1 && key > node->left->exp)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->exp)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

Node *deleteNode(Node *node, int key)
{
  if (node == NULL)
    return NULL;

  if (key < node->exp)
    node->left = deleteNode(node->left, key);
  else if (key > node->exp)
    node->right = deleteNode(node->right, key);
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
      node = node->left;
      free(temp);
    }
    else
    {
      Node *temp = maxNode(node->left);
      node->exp = temp->exp;
      node->left = deleteNode(node->left, temp->exp);
    }
  }

  if (node == NULL)
    return NULL;

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

void inOrder(Node *node)
{
  if (node != NULL)
  {
    inOrder(node->left);
    printf("%d ", node->exp);
    inOrder(node->right);
  }
}

void recur(Node *node, int *arr, int *index)
{
  if (node != NULL)
  {
    recur(node->left, arr, index);
    arr[(*index)++] = node->exp;
    recur(node->right, arr, index);
  }
}

int searchMin(Node *node, int k)
{
  int arr[101];
  int index = 0;
  recur(node, arr, &index);
  return arr[k - 1];
}

int main()
{
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 10);
  root = insert(root, 50);
  root = insert(root, 40);

  inOrder(root);

  printf("\n\nDeletion\n");
  root = deleteNode(root, 50);
  root = deleteNode(root, 20);
  inOrder(root);


  printf("\n\nSearch Min\n");
  printf("%d", searchMin(root, 3));
  return 0;
}