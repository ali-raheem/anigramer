#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#include "anigramer.h"

int main(int argc, char **argv){
	if(2 > argc){
		printf("Usage:\n\t%s word-file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *fp = NULL;
	fp = fopen(argv[1], "r");
	if(NULL == fp) {
	  printf("Failed to open file: \"%s\", is it really a wordlist?\n", argv[1]);
	  exit(EXIT_FAILURE);
	}
	char *line;
	size_t n = 0;
	bin_tree *tree = bin_tree_new(hash(""), "");
	while( -1 != getline(&line, &n, fp)) {
		bin_tree_add(tree, trim(line));
	}
	puts("Ctrl+D to quit.");
	for(;;){
		line = readline("Enter search word: ");
		if(NULL == line)
			break;
		printf("%s", line);
		word_list *list = bin_tree_find(tree, line);
		if(NULL != list)
			word_list_print(list);
		else
			puts(": No matches.");
	}
	exit(EXIT_SUCCESS);
}
