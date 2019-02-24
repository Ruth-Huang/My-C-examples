#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

struct word_count {
char key[word_len];
int count;
} wc[10000];

void bubble_sort_words(char word[][word_len], int n)
{
	int i, j;
	char temp[word_len];

	  for (j=0; j<n-1; j++){
	    for (i=n-1; i>j; i--)
	      if (strcmp(word[i], word[i-1]) < 0){
	         strcpy (temp, word[i]);
	         strcpy (word[i], word[i-1]);
	         strcpy (word[i-1], temp);
	      }
          }
}



void sort_words(char word[][word_len], int n)
{

int i, j, min;
char temp[word_len];

  for (j=0; j<n-1; j++){ 

  min = j;
    for (i=j+1; i<n; i++)
     if (strcmp(word[min], word[i]) > 0) min = i;
   strcpy (temp, word[min]);
   strcpy (word[min], word[j]);
   strcpy (word[j], temp);   


  }

}

char word[10000][word_len];

void word_curation(char word[][word_len], int n)
{
int i, last_char;

     for(i=0; i<n; i++) {
	 last_char = strlen(word[i]) - 1;
	 if(word[i][last_char] == ')' || word[i][last_char] == ',' || word[i][last_char] == ':' || word[i][last_char] == '.' || word[i][last_char] == ';') word[i][last_char] = '\0';
     }

     for(i=0; i<n; i++) {
	if(word[i][0] >= 'A' && word[i][0] <= 'Z')
	word[i][0] = word[i][0] + 32;
     }

}

int hash_func(char s[])
{
int len, i, sum;

sum = 0;
len = strlen(s);
for(i=0; i<len; i++){
sum = sum + s[i]*(i+1);
}
return sum % 10000;
}

struct link_wd *hash_table[10000];

int main(int argc, char *argv[])
{
int x,i,j,min,n, last_char, h, k;
char temp[word_len];
struct link_wd *ptr;
struct link_fn *fn_head, *ptr_1;

FILE *f;

     if(argc < 2) {
	printf("Usage: %s <filename>\n", argv[0]);
	exit(1);
     }

     for(i=0; i<10000; i++) hash_table[i] = NULL;

for(k=1; k<argc; k++){
     f = fopen(argv[k], "r");
     i = 0;
     // assumes no word exceeds length of 1023
     while (fscanf(f, " %1023s", word[i]) == 1) {
	i=i+1;
	if(i>10000) {
		printf("The file is too large\n");
		exit(0);
	}
     }
     n = i;
     for(i=0; i<n; i++) printf("%s ", word[i]);
     printf("\n");

     word_curation(word, n);

/*     for(i=0; i<n; i++) printf("%s %d\n", word[i], hash_func(word[i]));
               printf("\n");
*/

//     for(i=0; i<10000; i++) hash_table[i] = NULL;

     for(i=0; i<n; i++) {
	h = hash_func(word[i]);
	if(hash_table[h] == NULL) {
	    ptr = malloc(sizeof(struct link_wd));
	    strcpy(ptr->word, word[i]);
	    ptr->fnll_head = malloc(sizeof(struct link_fn));
	    fn_head = ptr->fnll_head;
	    strcpy(fn_head->fname, argv[k]);
	    fn_head->count = 1;
	    fn_head->next = NULL;
	    ptr->next = NULL;
	    hash_table[h] = ptr;
	} else insert_wd(hash_table[h], word[i], argv[k]);
     }
}

while(1)
{
fgets(temp, 100, stdin);
temp[strlen(temp)-1] = '\0';
h = hash_func(temp);
if(hash_table[h] == NULL) {
    printf("No such word: %s\n", temp);
    continue;
}

ptr = hash_table[h];

do {
  if(strcmp(ptr->word, temp) == 0) {
    ptr_1 = ptr->fnll_head;
    do {
	printf("%s: %d\n", ptr_1->fname, ptr_1->count);
	ptr_1 = ptr_1->next;
    } while(ptr_1 != NULL);
    break;
  }
  ptr = ptr->next;
} while(ptr != NULL);
if(ptr == NULL) printf("No such word: %s\n", temp);
}

/*
     for(i=0; i<10000; i++) {
	if(hash_table[i] == NULL) continue;
	ptr = hash_table[i];
	while (ptr != NULL) {
	    printf("%s  %d\n", ptr->word, ptr->count);
	    ptr = ptr->next;
	}
     }*/

exit(0);


/*     bubble_sort_words(word, n);

     for(i=0; i<n; i++) printf("%s ", word[i]);
          printf("\n");
*/
     sort_words(word, n);
     for(i=0; i<n; i++) printf("%s ", word[i]);
	printf("\n");

     for(i=0; i<10000; i++){
	wc[i].key[0] = 0;
	wc[i].count = 0;
     }

     j = -1;
     for(i=0; i<n; i++) {
	if(strcmp(word[i], wc[j].key)!=0) {
	    j = j + 1;
	    strcpy(wc[j].key, word[i]);
    	    wc[j].count = 1;
	} else {
	    wc[j].count ++;
	}
     }
     for(i=0; i<j+1; i++) {
	printf("%s  %d\n", wc[i].key, wc[i].count);
     }

     exit(0);



strcpy(word[0], "the");
strcpy(word[1], "google");
strcpy(word[2], "search");
strcpy(word[3], "is");
strcpy(word[4], "cool");
strcpy(word[5], "willow");
strcpy(word[6], "levy");
strcpy(word[7], "ethan");
strcpy(word[8], "melee");
strcpy(word[9], "ruth");
n = 10;
bubble_sort_words(word, n);

for(i=0;i<n;i++) printf("%s ", word[i]);
printf("\n");

exit(0);

}

