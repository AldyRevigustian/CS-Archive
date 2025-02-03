#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Tries Code
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
void printTrieContents(TrieNode *node, char *buffer, int depth)
{
  if (node == NULL)
    return;

  if (node->isWord)
  {
    buffer[depth] = '\0';
    printf("%s\n", buffer);
  }

  for (int i = 0; i < MAX_NUM; i++)
  {
    if (node->child[i] != NULL)
    {
      buffer[depth] = node->child[i]->character;
      printTrieContents(node->child[i], buffer, depth + 1);
    }
  }
}

void searchPrefix(TrieNode *root, const char *prefix)
{
  char buffer[100];
  int depth = 0;
  buffer[depth++] = *prefix;
  TrieNode *current = root;
  while (*prefix)
  {
    if (current == NULL)
      return;
    current = current->child[*prefix];
    buffer[depth++] = *prefix;
    prefix++;
  }

  if (current != NULL && current->isWord)
  {
    buffer[depth] = '\0';
    printf("%s\n", buffer);
  }

  for (int i = 0; i < 128; i++)
  {
    if (current->child[i] != NULL)
    {
      printTrieContents(current->child[i], buffer, depth);
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

void searchSlang(TrieNode *root, const char *word)
{
  TrieNode *current = root;
  char buffer[MAX_NUM] = "";
  while (*word)
  {
    if (current == NULL || current->child[*word] == NULL)
    {
      printf("\nThere is no word \"%s\" in the dictionary.\n", word);
      return;
    }
    current = current->child[*word];
    buffer[strlen(buffer)] = *word;
    word++;
  }

  if (current != NULL && current->isWord)
  {
    printf("\nSlang word: %s\n", buffer);
    printf("Description: %s\n\n", current->desc);
  }
}

// Case Menu
void clear_screen()
{
  for (int i = 0; i < 100; i++)
    printf("\n");
}

void enter_line()
{
  printf("Press enter to continue...");
  getchar();
  clear_screen();
}

void caseOne(TrieNode **root)
{
  char word[100];
  char description[100];

  do
  {
    printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
    scanf(" %[^\n]", word);
    getchar();
  } while (strlen(word) <= 1 || strchr(word, ' ') != NULL);

  do
  {
    printf("Input a new slang word description [Must be more than 2 words]: ");
    scanf(" %[^\n]", description);
    getchar();
  } while (strlen(description) <= 1 || strchr(description, ' ') == NULL);

  insertTrie(root, word, description);

  printf("\nSuccessfully released new slang word.\n");
  enter_line();
}

void caseTwo(TrieNode *root)
{
  char word[100];

  do
  {
    printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
    scanf(" %[^\n]", word);
    getchar();
  } while (strlen(word) <= 1 || strchr(word, ' ') != NULL);
  searchSlang(root, word);

  enter_line();
}

void caseThree(TrieNode *root)
{
  char word[100];
  do
  {
    printf("Input a prefix to be searched: ");
    scanf(" %[^\n]", word);
    getchar();
  } while (strlen(word) <= 1 || strchr(word, ' ') != NULL);
  searchPrefix(root, word);

  enter_line();
}

int main()
{
  TrieNode *root = NULL;
  int choice;
  do
  {
    printf("Boogle\n");
    printf("1. Release a new slang word\n");
    printf("2. Search a slang word\n");
    printf("3. View all slang words starting with a certain prefix word\n");
    printf("4. View all slang words\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1 || choice > 5)
    {
      clear_screen();
      printf("\nInvalid input. Please enter a valid number.\n\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    switch (choice)
    {
    case 1:
      caseOne(&root);
      break;
    case 2:
      caseTwo(root);
      break;

    case 3:
      caseThree(root);
      break;

      // case 4:
      //   printf("List of all slang words in the dictionary:\n");
      //   printTrieContents(root, word, 0);
      //   break;

      // case 5:
      //   printf("Thank you... Have a nice day :)\n");
      //   break;

    case 5:
      printf("Thank you... Have a nice day :)\n");
      break;
    }
  } while (choice != 5);

  return 0;
}