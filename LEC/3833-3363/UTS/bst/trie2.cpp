#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 128

struct TrieNode
{
  struct TrieNode *child[MAX_NUM];
  char character;
  int isWord;
  char *desc;
};

TrieNode *createNode(char chr)
{
  TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
  node->character = chr;
  node->desc = NULL;
  node->isWord = 0;

  for (int i = 0; i < MAX_NUM; i++)
  {
    node->child[i] = NULL;
  }

  return node;
}

void insertTrie(TrieNode **root, const char *str, const char *desc)
{
  if (*root == NULL)
  {
    *root = createNode('*');
  }

  TrieNode *current = *root;

  for (int i = 0; str[i] != '\0'; i++)
  {
    if (current->child[str[i]] == NULL)
    {
      current->child[str[i]] = createNode(str[i]);
    }
    current = current->child[str[i]];
  }

  current->isWord = 1;
  current->desc = strdup(desc);
}

void printTrie(TrieNode *node, char *buffer, int depth)
{
  if (node == NULL)
    return;

  buffer[depth] = node->character;
  if (node->isWord)
  {
    buffer[depth + 1] = '\0';
    printf("%s : %s\n", buffer + 1, node->desc);
  }

  for (int i = 0; i < MAX_NUM; i++)
  {
    if (node->child[i] != NULL)
    {
      printTrie(node->child[i], buffer, depth + 1);
    }
  }
}

void searchPref(TrieNode *root, const char *prefix)
{
  char buffer[MAX_NUM];
  int depth = 0;
  buffer[depth++] = *prefix;
  TrieNode *current = root;

  while (*prefix)
  {
    if (current == NULL)
      return;
    current = current->child[*prefix];
    buffer[depth++] = *prefix++;
  }

  if (current != NULL && current->isWord)
  {
    buffer[depth] = '\0';
    printf("%s\n", buffer);
  }

  for (int i = 0; i < MAX_NUM; i++)
  {
    if (current->child[i] != NULL)
    {
      printTrie(current->child[i], buffer, depth);
    }
  }
}

int exists(TrieNode *root, const char *word)
{
  TrieNode *current = root;
  while (*word)
  {
    if (current == NULL || current->child[*word] == NULL)
      return 0;
    current = current->child[*word];
    word++;
  }
  return current != NULL && current->isWord;
}

int main()
{
  TrieNode *root = NULL;

  insertTrie(&root, "shan", "Descript");
  insertTrie(&root, "shana", "Descript");
  insertTrie(&root, "shand", "Descript");

  puts("Print all without prefix");
  searchPref(root, "shan");

  return 0;
}