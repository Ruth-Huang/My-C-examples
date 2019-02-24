#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define word_len 1024

struct link {
char word[word_len];
int count;
struct link *next;
};

void insert(struct link *head, struct link *ptr)
{
	struct link *tail;

	tail = head;
	while (tail->next != NULL) tail = tail->next;
	tail->next = ptr;
	return;

}


int main(int argc, char *argv[])
{
struct link *ptr, *head, *tail;

head = NULL;

ptr = malloc(sizeof(struct link));

strcpy(ptr->word, "cat");
ptr->count = 1;
ptr->next = NULL;

head = ptr;

ptr = malloc(sizeof(struct link));
strcpy(ptr->word, "cow");
ptr->count = 2;
ptr->next = NULL;

insert(head, ptr);

ptr = malloc(sizeof(struct link));
strcpy(ptr->word, "sheep");
ptr->count = 3;
ptr->next = NULL;

insert(head, ptr);

ptr = head;
do {
printf("%s  %d \n", ptr->word, ptr->count);
ptr = ptr->next;
} while(ptr != NULL);

}
