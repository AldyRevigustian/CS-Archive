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

int getHeight(Node *N)
{
  if (N == NULL)
    return 0;

  return N->height;
}

int getDepth(Node *data, char *name, int experience)
{
  int depth = 1;
  Node *curr = root;
  while (curr != NULL)
  {
    if (strcmp(name, curr->name) == 0)
    {
      return depth;
    }
    else if (experience < curr->experience)
    {
      curr = curr->left;
    }
    else if (experience > curr->experience)
    {
      curr = curr->right;
    }
    ++depth;
  }
  return -1;
}

int getBalance(Node *node)
{
  if (node == NULL)
    return 0;

  return getHeight(node->left) - getHeight(node->right);
}

Node *leftRotate(Node *x)
{
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

  return y;
}

Node *rightRotate(Node *y)
{
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

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

Node *insert(Node *node, char *name, int experience)
{
  if (node == NULL)
  {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->experience = experience;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
  }
  else if (experience < node->experience)
    node->left = insert(node->left, name, experience);
  else if (experience > node->experience)
    node->right = insert(node->right, name, experience);

  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  int balance = getBalance(node);

  if (balance > 1 && experience < node->left->experience)
    return rightRotate(node);
  if (balance < -1 && experience > node->right->experience)
    return leftRotate(node);

  if (balance > 1 && experience > node->left->experience)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && experience < node->right->experience)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

Node *deleteNode(Node *node, char *name, int experience)
{
  if (node == NULL)
    return NULL;

  if (experience < node->experience)
    node->left = deleteNode(node->left,name, experience);
  else if (experience > node->experience)
    node->right = deleteNode(node->right,name, experience);
  
  else if (strcmp(name, node->name) == 0)
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
      strcpy(node->name, tmp->name);
      node->experience = tmp->experience;
      node->left = deleteNode(node->left, tmp->name, tmp->experience);
    }
  }

  if (node == NULL)
    return node;

  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
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

Node *findNode(Node *node, int experience)
{
  if (node == NULL)
    return NULL;

  if (node->experience == experience)
    return node;

  if (experience < node->experience)
  {
    return findNode(node->left, experience);
  }
  else
  {
    return findNode(node->right, experience);
  }
}

int findEx(Node *node, char *name)
{
  if (node == NULL)
  {
    return -1;
  }

  if (strcmp(node->name, name) == 0)
  {
    return node->experience;
  }

  int leftResult = findEx(node->left, name);
  if (leftResult != -1)
  {
    return leftResult;
  }
  return findEx(node->right, name);
}

Node *findPredecessor(Node *node, int experience)
{
  Node *tmp = findNode(root, experience);

  if(tmp == NULL) return NULL;

  if (tmp->left != NULL)
    return maxNode(tmp->left);

  Node *predecessor = NULL;
  Node *current = root;

  while (current != NULL)
  {
    if (experience > current->experience)
    {
      predecessor = current;
      current = current->right;
    }
    else if (experience < current->experience)
    {
      current = current->left;
    }
    else
    {
      break;
    }
  }

  return predecessor;
}

void view(Node *node)
{
  if (node != NULL)
  {
    view(node->left);
    if (getDepth(root, node->name, node->experience) == 1)
    {
      printf("Research Leader : ");
    }
    else if (getDepth(root, node->name, node->experience) == 2)
    {
      if (strcmp(node->name, root->left->name) == 0)
      {
        if (node->left == NULL && node->right == NULL)
        {
          printf("Staff : ");
        }
        else
        {
          printf("Deputy Head 1 :");
        }
      }
      else if (strcmp(node->name, root->right->name) == 0)
      {
        if (node->left == NULL && node->right == NULL)
        {
          printf("Staff : ");
        }
        else
        {
          printf("Deputy Head 2 :");
        }
      }
    }
    else if (getDepth(root, node->name, node->experience) == 3)
    {
      if (node->left == NULL && node->right == NULL)
      {
        printf("Staff : ");
      }
      else
      {
        printf("Officer : ");
      }
    }
    else
    {
      printf("Staff : ");
    }
    printf("%d Years Exp %s\n", node->experience, node->name);
    view(node->right);
  }
}


void inOrder(Node *node)
{
  if (node != NULL)
  {
    inOrder(node->left);
    printf("%d ", node->experience);
    inOrder(node->right);
  }
}

void recur(Node *node, int *arr, int *index)
{
  if (node != NULL)
  {
    recur(node->left, arr, index);
    arr[(*index)++] = node->experience;
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
  root = insert(root, "Sasuke", 5);
  root = insert(root, "Naruto", 6);
  root = insert(root, "Sakura", 4);
  root = insert(root, "Madara", 14);
  root = insert(root, "Orochimaru", 20);
  root = insert(root, "Kakashi", 15);

  view(root);

  printf("%d\n", findEx(root, "Sakura"));
  printf("%s\n", findNode(root, 5)->name);

  deleteNode(root, "Sasuke", findEx(root, "Sasuke"));
  printf("\n");

  view(root);

  printf("\nFind Predec 20\n");
  Node *predec =findPredecessor(root, 20);

  if(predec != NULL){
    printf("%d", predec->experience);
  } 

  return 0;
}
