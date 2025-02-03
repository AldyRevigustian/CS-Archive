#include <stdio.h>
#include <stdlib.h>

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
        node = (struct Data *)malloc(sizeof(struct Data));
        node->number = n;
        node->left = node->right = NULL;
    }
    else if (n < node->number)
    {
        // Fokus Left
        node->left = insert(node->left, n);
    }
    else if (n > node->number)
    {
        // Fokus Right
        node->right = insert(node->right, n);
    }
    return node;
}

struct Data *search(struct Data *node, int key)
{
    if (node == NULL || node->number == key)
    {
        return node;
    }

    if (key < node->number)
    {
        // Cari ke kiri
        return search(node->left, key);
    }
    // Cari ke kanan
    return search(node->right, key);
}

struct Data *findMaxNode(struct Data *node)
{
    while (node->right != NULL)
    {
        node = node->right;
    }

    return node;
}

struct Data *del(struct Data *node, int n)
{
    if (node == NULL)
    {
        printf("Data Not Found\n");
        return NULL;
    }
    else
    {
        if (n < node->number)
        {
            // Fokus Ke Kiri
            node->left = del(node->left, n);
        }
        else if (n > node->number)
        {
            // Fokus Ke Kanan
            node->right = del(node->right, n);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                // Leaf
                free(node);
                node = NULL;
            }
            else if (node->left == NULL)
            {
                // Only have right child
                struct Data *temp = node;
                node = node->right;
                free(temp);
                temp = NULL;
            }
            else if (node->right == NULL)
            {
                // Only have left child
                struct Data *temp = node;
                node = node->left;
                free(temp);
                temp = NULL;
            }
            else
            {
                // Have left and right child
                struct Data *temp = findMaxNode(node->left);
                node->number = temp->number;
                node->left = del(node->left, temp->number);
            }
        }
        return node;
    }
}

void inOrder(struct Data *curr)
{
    if (curr != NULL)
    {
        inOrder(curr->left);
        printf("%d ", curr->number);
        inOrder(curr->right);
    }
}

void preOrder(struct Data *curr)
{
    if (curr != NULL)
    {
        printf("%d ", curr->number);
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

void postOrder(struct Data *curr)
{
    if (curr != NULL)
    {
        postOrder(curr->left);
        postOrder(curr->right);
        printf("%d ", curr->number);
    }
}

struct Data *delAll(struct Data *curr)
{
    if (curr != NULL)
    {
        curr->left = delAll(curr->left);
        curr->right = delAll(curr->right);
        free(curr);
        curr = NULL;
    }
    return NULL;
}

int main()
{
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 60);

    root = del(root, 60);
    root = del(root, 80);
    root = del(root, 50);

    printf("In Order : ");
    inOrder(root);

    return 0;
}
