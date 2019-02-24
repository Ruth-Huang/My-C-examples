#define word_len  1024

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


void insert_fn(struct link_fn *head, char fname[]);

void insert_wd(struct link_wd *head, char word[], char fname[]);

