#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
  char name[1000];
  int experience;
  int height;
  Node *left, *right;
} *root = NULL;

Node *createNode(char *name, int experience)
{
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int getHeight(Node *data)
{
  if (data == NULL)
  {
    return 0;
  }
  else
  {
    return data->height;
  }
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
  int balance = getHeight(node->left) - getHeight(node->right);

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

int findEx(Node *root, char *name)
{
  if (root == NULL)
  {
    return -1;
  }
  if (strcmp(root->name, name) == 0)
  {
    return root->experience;
  }
  int leftResult = findEx(root->left, name);
  if (leftResult != -1)
  {
    return leftResult;
  }
  return findEx(root->right, name);
}

Node *maxValueNode(Node *node)
{
  Node *current = node;

  while (current->right != NULL)
    current = current->right;

  return current;
}

Node *deleteNode(Node *root, char *name, int expe)
{
  if (root == NULL)
  {
    printf("Data tidak ditemukan\n");
    return NULL;
  }

  if (expe < root->experience)
  {
    root->left = deleteNode(root->left, name, expe);
  }
  else if (expe > root->experience)
  {
    root->right = deleteNode(root->right, name, expe);
  }
  else if (strcmp(name, root->name) == 0)
  {
    if ((root->left == NULL) || (root->right == NULL))
    {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else
      {
        *root = *temp;
      }
      free(temp);
    }
    else
    {
      Node *temp = maxValueNode(root->left);
      strcpy(root->name, temp->name);
      root->experience = temp->experience;
      root->left = deleteNode(root->left, temp->name, temp->experience);
    }
  }
  else
  {
    return root;
  }

  if (root == NULL)
  {
    return root;
  }

  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  int bF = getHeight(root->left) - getHeight(root->right);

  if (bF > 1 && getHeight(root->left->left) >= getHeight(root->left->right))
  {
    return rightRotate(root);
  }

  if (bF > 1 && getHeight(root->left->left) < getHeight(root->left->right))
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (bF < -1 && getHeight(root->right->right) >= getHeight(root->right->left))
  {
    return leftRotate(root);
  }

  if (bF < -1 && getHeight(root->right->right) < getHeight(root->right->left))
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

int main()
{
  root = insert(root, "Sasuke", 5);
  root = insert(root, "Naruto", 6);
  root = insert(root, "Sakura", 4);
  root = insert(root, "Madara", 14);
  root = insert(root, "Orochimaru", 20);
  root = insert(root, "Kakashi", 15);
  root = insert(root, "Tsunade", 19);
  root = insert(root, "Hiruzen", 2);
  root = insert(root, "Jiraya", 34);
  root = insert(root, "Lee", 3);

  view(root);

  deleteNode(root, "Sasuke", findEx(root, "Sasuke"));
  printf("\n");
  view(root);
  return 0;
}