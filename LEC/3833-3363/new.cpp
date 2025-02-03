#include <stdio.h>  // di include untuk ....
#include <string.h> // di include untuk ....
#include <stdlib.h> // di include untuk ....

#define MAX_CHAR 128 // ....
struct TrieNode
{
  char character;
  char description[MAX_CHAR];
  struct TrieNode *child[MAX_CHAR];
  int isWord;
};

TrieNode *createNode(char chara)
{
  TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
  node->character = chara;
  node->isWord = 0;

  memset(node->child, 0, sizeof(node->child));
  return node;
}

void insertWord(TrieNode **root, char word[], char desc[])
{
  if (*root == NULL)
  {
    *root = createNode('*');
  }

  TrieNode *current = *root;
  while (*word)
  {
    if (current->child[*word] == NULL)
    {
      current->child[*word] = createNode(*word);
    }
    current = current->child[*word];
    word++;
  }
  current->isWord = 1;
  strcpy(current->description, desc);
}

int cekExisting(TrieNode *root, char word[])
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

void printContent(TrieNode *node, char *buffer, int depth, int *counter)
{
  if (node == NULL)
    return;

  buffer[depth] = node->character;
  if (node->isWord)
  {
    buffer[depth + 1] = '\0';
    printf("%d. %s\n", ++(*counter), buffer);
  }

  for (int i = 0; i < MAX_CHAR; i++)
  {
    if (node->child[i] != NULL)
    {
      printContent(node->child[i], buffer, depth + 1, counter);
    }
  }
}

void searchPref(TrieNode *root, const char *prefix)
{
  if (root == NULL)
  {

    printf("\nThere is no prefix \"%s\" in the dictionary.\n", prefix);
    return;
  }

  TrieNode *current = root;
  char buffer[MAX_CHAR];
  int depth = 0;
  int counter = 0;
  const char *tempC = prefix;

  while (*prefix)
  {
    if (current->child[*prefix] == NULL)
    {
      printf("\nThere is no prefix \"%s\" in the dictionary.\n", prefix);
      return;
    }
    buffer[depth++] = *prefix;
    current = current->child[*prefix++];
  }
  printf("\nWords starting with \"%s\":\n", tempC);
  printContent(current, buffer, depth - 1, &counter);
}

void printAll(TrieNode *root)
{
  if (root == NULL)
  {
    printf("\nThere is no slang word yet in the dictionary.\n");
    return;
  }
  char buffer[MAX_CHAR];
  int counter = 0;
  printf("\nList of all slang words in the dictionary:\n");
  printContent(root, buffer + 1, -1, &counter);
  puts(" ");
}

void searchSlang(TrieNode *root, char word[])
{
  const char *tempC = word;
  if (root == NULL)
  {

    printf("\nThere is no word \"%s\" in the dictionary.\n", tempC);
    return;
  }

  TrieNode *current = root;
  char buffer[MAX_CHAR] = "";
  while (*word)
  {
    if (current == NULL || current->child[*word] == NULL)
    {
      printf("\nThere is no word \"%s\" in the dictionary.\n", tempC);
      return;
    }
    current = current->child[*word];
    buffer[strlen(buffer)] = *word;
    word++;
  }

  if (current != NULL && current->isWord)
  {
    printf("\nSlang word  : %s\n", buffer);
    printf("Description : %s\n\n", current->description);
  }
  else
  {
    printf("\nThere is no word \"%s\" in the dictionary.\n", tempC);
    return;
  }
}

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

int main()
{
  TrieNode *root = NULL;
  char word[MAX_CHAR];
  char description[MAX_CHAR];
  int choice;

  do
  {
    clear_screen();
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
    {
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

      int isExist = cekExisting(root, word);

      insertWord(&root, word, description);

      if (isExist)
      {
        printf("\nSuccessfully updated a slang word.\n");
      }
      else
      {
        printf("\nSuccessfully released new slang word.\n");
      }
      enter_line();
    }
    break;
    case 2:
    {
      do
      {
        printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
        scanf(" %[^\n]", word);
        getchar();
      } while (strlen(word) <= 1 || strchr(word, ' ') != NULL);
      searchSlang(root, word);

      enter_line();
    }
    break;
    case 3:
    {
      do
      {
        printf("Input a prefix to be searched: ");
        scanf(" %[^\n]", word);
        getchar();
      } while (strlen(word) < 1 || strchr(word, ' ') != NULL);
      searchPref(root, word);
      puts(" ");
      enter_line();
    }
    break;

    case 4:
    {
      printAll(root);
      getchar();
      enter_line();
    }
    break;
    case 5:
    {
      printf("Thank you... Have a nice day :)\n");
    }
    break;
    }
  } while (choice != 5);

  return 0;
}