#include <stdio.h>
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

int height(Node *node)
{
  if (node == NULL)
    return 0;
  return node->height;
}

int getBalance(Node *node)
{
  if (node == NULL)
    return 0;
  return height(node->left) - height(node->right);
}

int getDepth(Node *node, int key)
{
  if (node == NULL)
    return 0;

  int depth = 1;
  Node *curr = node;

  while (curr != NULL)
  {
    if (key == node->key)
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

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

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
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
  }
  else if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  node->height = max(height(node->left), height(node->right)) + 1;
  int balance = getBalance(node);

  if (balance > 1 && key < node->left->key)
    return rightRotate(node);
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

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

Node *remove(Node *node, int key)
{
  if (node == NULL)
    return NULL;

  if (key < node->key)
    node->left = remove(node->left, key);
  else if (key > node->key)
    node->right = remove(node->right, key);
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
      Node *pred = maxNode(node->left);
      node->key = pred->key;
      node->left = remove(node->left, pred->key);
    }
  }

  if(node == NULL) return node;

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

Node *findNode(Node *node, int key)
{
  if (node == NULL)
    return NULL;

  if (node->key == key)
    return node;
  else if (key < node->key)
    return findNode(node->left, key);
  else
    return findNode(node->right, key);
}

Node *findPredecessor(Node *root, int key)
{
  Node *node = findNode(root, key);

  if (node->left != NULL)
    return maxNode(node->left);

  Node *tmp = root;
  Node *predec = NULL;

  while (tmp != NULL)
  {
    if (key > tmp->key)
    {
      predec = tmp;
      tmp = tmp->right;
    }
    else if (key < tmp->key)
    {
      tmp = tmp->left;
    }
    else
    {
      break;
    }
  }

  return predec;
}

void inOrder(Node *node)
{
  if (node != NULL)
  {
    inOrder(node->left);
    printf("%d\n", node->key);
    inOrder(node->right);
  }
}

int main()
{

  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 20);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 15);
  inOrder(root);

  printf("\nFind Predec 10\n");
  printf("%d", findPredecessor(root, 10)->key);

  root = insert(root, 12);
  printf("\nFind Predec 12 \n");
  printf("%d", findPredecessor(root, 12)->key);

  printf("\nFind Predec 7\n");
  printf("%d", findPredecessor(root, 7)->key);

  printf("\n\nAFTER DELETION 7\n");
  root = remove(root, 7);
  inOrder(root);

  printf("\nFind Node\n");
  printf("%d", findNode(root, 10)->key);

  return 0;
}