#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
  int key;
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

int getBalance(Node *N)
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

int getDepth(int key)
{
  int depth = 1;
  Node *curr = root;

  while (curr != NULL)
  {
    if (curr->key == key)
      return depth;
    else if (key < curr->key)
      curr = curr->left;
    else if (key > curr->key)
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
    node = node->right;
  return node;
}

Node *insert(Node *node, int key)
{
  if (node == NULL)
  {
    node = (Node *)malloc(sizeof(Node));
    node->height = 1;
    node->key = key;
    node->left = node->right = NULL;
    return node;
  }
  else if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  node->height = max(height(node->left), height(node->right)) + 1;
  int balance = getBalance(node);

  if (balance > 1 && key < node->left->key)
  {
    return rightRotate(node);
  }

  if (balance < -1 && key > node->right->key)
  {
    return leftRotate(node);
  }

  if (balance > 1 && key > node->left->key)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key)
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

  if (key < node->key)
    node->left = deleteNode(node->left, key);
  else if (key > node->key)
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
      Node *tmp = node;
      node = node->right;
      free(tmp);
    }
    else if (node->right == NULL)
    {
      Node *tmp = node;
      node = node->left;
      free(tmp);
    }
    else
    {
      Node *tmp = maxNode(node->left);
      node->key = tmp->key;
      node->left = deleteNode(node->left, tmp->key);
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


void inOrder(Node* root, int* arr, int* index) {
    if (root != NULL) {
        inOrder(root->left, arr, index);
        arr[(*index)++] = root->key;
        inOrder(root->right, arr, index);
    }
}

int findKthSmallest(Node* root, int k) {
    int arr[100];
    int index = 0;
    inOrder(root, arr, &index);
    return arr[k - 1];
}

int main(){
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);

  printf("%d", findKthSmallest(root, 6));
  return 0;
}
