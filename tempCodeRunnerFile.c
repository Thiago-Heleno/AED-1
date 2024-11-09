/*
  Author: Thiago Heleno
  Date: 08/11/2024
  Data Structure: Linked List
  https://judge.beecrowd.com/en/problems/view/3160
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░▄▄▀▀▀▀▀▀▀▀▀▀▄▄█▄░░░░▄░░░░█░░░░░░░
░░░░░░█▀░░░░░░░░░░░░░▀▀█▄░░░▀░░░░░░░░░▄░
░░░░▄▀░░░░░░░░░░░░░░░░░▀██░░░▄▀▀▀▄▄░░▀░░
░░▄█▀▄█▀▀▀▀▄░░░░░░▄▀▀█▄░▀█▄░░█▄░░░▀█░░░░
░▄█░▄▀░░▄▄▄░█░░░▄▀▄█▄░▀█░░█▄░░▀█░░░░█░░░
▄█░░█░░░▀▀▀░█░░▄█░▀▀▀░░█░░░█▄░░█░░░░█░░░
██░░░▀▄░░░▄█▀░░░▀▄▄▄▄▄█▀░░░▀█░░█▄░░░█░░░
██░░░░░▀▀▀░░░░░░░░░░░░░░░░░░█░▄█░░░░█░░░
██░░░░░░░░░░░░░░░░░░░░░█░░░░██▀░░░░█▄░░░
██░░░░░░░░░░░░░░░░░░░░░█░░░░█░░░░░░░▀▀█▄
██░░░░░░░░░░░░░░░░░░░░█░░░░░█░░░░░░░▄▄██
░██░░░░░░░░░░░░░░░░░░▄▀░░░░░█░░░░░░░▀▀█▄
░▀█░░░░░░█░░░░░░░░░▄█▀░░░░░░█░░░░░░░▄▄██
░▄██▄░░░░░▀▀▀▄▄▄▄▀▀░░░░░░░░░█░░░░░░░▀▀█▄
░░▀▀▀▀░░░░░░░░░░░░░░░░░░░░░░█▄▄▄▄▄▄▄▄▄██
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░⠀⠀
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct item
{
  char name[21];
  struct item *next;
};

struct item *add_new_item(char name[21])
{
  struct item *new_item = malloc(sizeof(struct item));
  strncpy(new_item->name, name, 20);
  new_item->next = NULL;
  return new_item;
}

struct item *find_last_item(struct item *head)
{
  struct item *last_item = head;
  while (last_item->next != NULL)
  {
    last_item = last_item->next;
  }
  return last_item;
}

void remove_item(struct item *head, struct item *trash)
{
  struct item *item_that_points_to_trash = head;
  while (item_that_points_to_trash->next != trash)
  {
    item_that_points_to_trash = item_that_points_to_trash->next;
  }
  item_that_points_to_trash->next = trash->next;
  free(trash);
}

void remove_list(struct item *head)
{
  struct item *current = head->next;
  while (current != NULL)
  {
    struct item *temp = current;
    current = current->next;
    free(temp);
  }
  head->next = NULL;
}

void print_items(struct item *head)
{
  struct item *current_item = head->next;
  bool isFirst = true;
  while (current_item != NULL)
  {
    if (!isFirst)
      printf(" ");
    printf("%s", current_item->name);
    isFirst = false;
    current_item = current_item->next;
  }
  printf("\n");
}

bool check_if_is_unique(struct item *head, char name[21])
{
  struct item *current = head;
  while (current != NULL)
  {
    if (strcmp(current->name, name) == 0)
      return false;
    current = current->next;
  }
  return true;
}

void combine_list(struct item *head, struct item *head2, char friend_to_connect[51])
{
  if (head == NULL || head->next == NULL)
    return;
  if (head2 == NULL || head2->next == NULL)
    return;

  struct item *current = head->next;
  struct item *tail = head;
  while (current != NULL)
  {
    if (strcmp(current->name, friend_to_connect) == 0)
    {
      // Copy other List
      struct item *temp = current->next;
      current->next = head2->next;
      struct item *last_item2 = find_last_item(head2);
      last_item2->next = temp;
      break;
    }
    else
    {
      current = current->next;
      tail = tail->next;
    }
  }
  // struct item *last_item = find_last_item(head);
  // last_item->next = head2->next;
  tail->next = head2->next;
}

void extract_words(struct item *pHead, char line_text[21000], int line_text_size)
{
  int word_count = 0;
  struct item *last_item = find_last_item(pHead);
  for (int j = 0; j < line_text_size; j++)
  {
    if (line_text[j] == ' ' || line_text[j] == '\0' || line_text[j] == '\n')
    {
      if (word_count > 0)
      {
        char word[21] = {0};
        for (int z = 0; z < word_count; z++)
        {
          word[z] = line_text[j - word_count + z];
        }
        word[word_count] = '\0';

        struct item *new_item = add_new_item(word);
        last_item->next = new_item;
        last_item = last_item->next;

        word_count = 0;
      }
    }
    else
    {
      word_count++;
    }
  }
}

int main()
{
  int n;

  struct item head;
  strcpy(head.name, "Head");
  head.next = NULL;
  struct item *pHead = &head;

  struct item head2;
  strcpy(head2.name, "Head2");
  head2.next = NULL;
  struct item *pHead2 = &head2;

  char line_text[21000] = {0};
  fgets(line_text, sizeof(line_text) - 1, stdin);
  int line_text_size = strlen(line_text);

  char line_text2[21000] = {0};
  fgets(line_text2, sizeof(line_text2) - 1, stdin);
  int line_text_size2 = strlen(line_text2);

  char friend_to_connect[51] = {0};
  fgets(friend_to_connect, sizeof(friend_to_connect) - 1, stdin);
  friend_to_connect[strcspn(friend_to_connect, "\n")] = '\0';

  extract_words(pHead, line_text, line_text_size);
  extract_words(pHead2, line_text2, line_text_size2);
  combine_list(pHead, pHead2, friend_to_connect);

  print_items(pHead);

  return 0;
}