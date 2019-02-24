#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define word_len 1024

struct link_fn {
char fname[word_len];
int count;
struct link_fn *next;
};

struct link_wd {
char word[word_len];
struct link_fn *fnll_head;
struct link_wd *next;
};


void insert_fn(struct link_fn *head, char fname[])
{
	struct link_fn *tail, *ptr;

	tail = head;
	if(strcmp(tail->fname, fname) == 0) {
	    tail->count ++;
	    return;
	}
	while (tail->next != NULL) {
		tail = tail->next;
		if(strcmp(tail->fname, fname) == 0) {
		    tail->count ++;
		    return;
		}
	}
	ptr = malloc(sizeof(struct link_fn));
	strcpy(ptr->fname, fname);
	ptr->count = 1;
	ptr->next = NULL;

	tail->next = ptr;
	return;

}

void insert_wd(struct link_wd *head, char word[], char fname[])
{
	struct link_wd *tail, *ptr;
	struct link_fn *fn_head;

	tail = head;
	if(strcmp(tail->word, word) == 0) {
	    insert_fn(tail->fnll_head, fname);
	    return;
	}
	while (tail->next != NULL) {
		tail = tail->next;
		if(strcmp(tail->word, word) == 0) {
		    insert_fn(tail->fnll_head, fname);
		    return;
		}
	}
	ptr = malloc(sizeof(struct link_wd));
	strcpy(ptr->word, word);
	ptr->fnll_head = malloc(sizeof(struct link_fn));
	fn_head = ptr->fnll_head;
	strcpy(fn_head->fname, fname);
	fn_head->count = 1;
	fn_head->next = NULL;
	ptr->next = NULL;

	tail->next = ptr;
	return;

}

