#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char name[1000];
    int experience;
    int height;
    int depth;
    Node *left, *right;
} *root = NULL;

Node *createNode(char *name, int experience)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->experience = experience;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    newNode->depth = 1;
    return newNode;
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

Node *rightRotate(Node *root)
{
    Node *x = root->left;
    Node *subX = x->right;

    x->right = root;
    root->left = subX;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *root)
{
    Node *x = root->right;
    Node *subX = x->left;

    x->left = root;
    root->right = subX;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *insert(Node *root, char *name, int experience)
{
    if (root == NULL)
    {
        return createNode(name, experience);
    }
    else if (experience <= root->experience)
    {
        root->left = insert(root->left, name, experience);
    }
    else if (experience > root->experience)
    {
        root->right = insert(root->right, name, experience);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bF = getHeight(root->left) - getHeight(root->right);

    if (bF > 1 && experience < root->left->experience)
    {
        // rR
        return rightRotate(root);
    }
    else if (bF > 1 && experience > root->left->experience)
    {
        // lrR
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (bF < -1 && experience > root->right->experience)
    {
        return leftRotate(root);
    }
    else if (bF < -1 && experience < root->right->experience)
    {
        // rlR
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
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

Node *maxNode(Node *node)
{
    Node *current = node;

    while (current->right != NULL)
        current = current->right;

    return current;
}

Node *findPredecessor(Node *root, Node *node)
{
    if (node->left != NULL)
        return maxNode(node->left);

    struct Node *predecessor = NULL;
    while (root != NULL)
    {
        if (node->experience > root->experience)
        {
            predecessor = root;
            root = root->right;
        }
        else if (node->experience < root->experience)
        {
            root = root->left;
        }
        else
            break;
    }

    return predecessor;
}

Node *findNode(Node *node, int experience)
{
    if (node == NULL)
        return NULL;

    if (node->experience == experience)
        return node;
    else if (experience < node->experience)
        return findNode(node->left, experience);
    else
        return findNode(node->right, experience);
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
            Node *temp = maxNode(root->left);
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

    view(root);

    printf("%d\n", findEx(root, "Sakura"));
    printf("%s\n", findNode(root, 5)->name);

    deleteNode(root, "Sasuke", findEx(root, "Sasuke"));
    printf("\n");
    
    view(root);
    return 0;
}