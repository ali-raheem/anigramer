#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "anigramer.h"

// #define __DEBUG

char *trim (char *in_string) {
	char *string = strdup(in_string);
	int i;
	for (i = 0; i <strlen(string); i++) {
		if('\n' == string[i] || '\r' == string[i])
			string[i] = 0;
	}
	return string;
}
int compare_char (const void *a, const void *b) {
  const char *da = (const char *) a;
  const char *db = (const char *) b;

  return (*da > *db) - (*da < *db);
}

char *hash(char *word){
	char *hword = strdup(word);
	int i;
	int j = 0;
	for(i = 0; i < strlen(hword); i++){
		if(hword[i] >= 'A' && hword[i] <= 'Z') {
			hword[i] -= 'A';
			hword[i] += 'a';
		}
		if(hword[i] < 'a' || hword[i] > 'z') {
			hword[i] = '~';
			j++;
		}
	}
	qsort(hword, strlen(word), sizeof(char), compare_char);
	int len = strlen(hword) - j;
	hword[len] = 0;
	char *hashed = (char *) malloc(len + 1);
	strncpy(hashed, hword, len + 1);
	free(hword);
	#ifdef __DEBUG
	printf("hash(%s)=\"%s\"\n", word, hashed);
	#endif
	return hashed;
}

word_list *word_list_new(char *word) {
	#ifdef __DEBUG
	puts("word_list_new");
	#endif
	word_list *list = (word_list *) malloc(sizeof(word_list));
	assert(NULL != list);
	list->word = word;
	list->next = NULL;
	return list;
}

int word_list_add(word_list *self, char *word) {
	#ifdef __DEBUG
	printf("word_list_add(self: %p, word: %s)\n", self, word);
	#endif
	if(0 == strcmp(word, self->word)){
		free(word);
		return 0;
	}
	while (NULL != self->next) {
		if(0 == strcmp(word, self->word)){
			free(word);
			return 0;
		}
		self = self->next;
	}
	word_list *new = word_list_new(word);
	self->next = new;
	return 1;
}

void word_list_print(word_list *self) {
	while(NULL != self){
		#ifdef __DEBUG
		printf("word_list_print(self: %p, word: %s)\n", self, self->word);
		#else
		printf("->%s", self->word);
		#endif
		self = self->next;
	}
	puts(".");
}

bin_tree *bin_tree_new(char *key, char *word) {
	#ifdef __DEBUG
	printf("bin_tree_new(word: %s)\n", word);
	#endif
	bin_tree *tree = (bin_tree *) malloc(sizeof(bin_tree));
	assert(NULL != tree);
	tree->key = key;
	tree->left = NULL;
	tree->right = NULL;
	tree->next = word_list_new(word);
	return tree;
}

int bin_tree_add(bin_tree *self, char *word) {
	#ifdef __DEBUG
	printf("bin_tree_add(self: %p, word: %s)\n", self, word);
	#endif
	char *hword = hash(word);
	while(NULL != self) {
		int rv = strcmp(hword, self->key);
		if (rv < 0){
			if(NULL == self->left){
				bin_tree *node = bin_tree_new(hword, word);
				self->left = node;
				return 1;
			}
			self = self->left;
			continue;
		}
		if (rv > 0){
			if(NULL == self->right){
				bin_tree *node = bin_tree_new(hword, word);
				self->right = node;
				return 1;
			}
			self = self->right;
			continue;
		}
		free(hword);
		word_list_add(self->next, word);
		return 0;
	}
}

word_list *bin_tree_find(bin_tree *self, char *word) {
	#ifdef __DEBUG
	printf("bin_tree_find(self: %p, word: %s)\n", self, word);
	#endif
	char *hword = hash(word);
	while(NULL != self) {
		int rv = strcmp(hword, self->key);
		if (rv < 0){
			if(NULL == self->left){
				free(hword);
				return NULL;
			}
			self = self->left;
			continue;
		}
		if (rv > 0){
			if(NULL == self->right){
				free(hword);
				return NULL;
			}
			self = self->right;
			continue;
		}
		free(hword);
		return self->next;
	}
}

void bin_tree_print(bin_tree *self) {
	printf("bin_tree_node(self: %p, key: %s, left: %p, right: %p, next: %p)\n", \
	self, self->key, self->left, self->right, self->next);
}