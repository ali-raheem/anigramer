#ifndef __ANIGRAMMER_H
#define _ANIGRAMMER_H

enum {
	BROKEN_KEYBOARD_MODE = 1 << 0,
};
int __flags;
void set_flags(int);
int get_flags(void);

struct linked_list_s {
	char *word;
	struct linked_list_s *next;
};
typedef struct linked_list_s word_list;

struct binary_tree_s {
	char *key;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
	word_list *next;
};
typedef struct binary_tree_s bin_tree;

word_list *word_list_new(char *);
int word_list_add(word_list *, char *);
void word_list_print(word_list *);

bin_tree *bin_tree_new(char *, char *);
int bin_tree_add(bin_tree *, char *);
void bin_tree_print(bin_tree *);
word_list *bin_tree_find(bin_tree *, char *);

char *trim (char *);
char *hash(char *);
int compare_char(const void *, const void *);

#endif
