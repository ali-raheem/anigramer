#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <readline/readline.h>

#include "anigramer.h"

#define __DEBUG

int main(int argc, char **argv){
	if(2 > argc){
		printf("Usage:\n\t%s word-file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *fp = NULL;
	fp = fopen(argv[1], "r");
	assert(NULL != fp);
	char *line;
	size_t n = 0;
	bin_tree *tree = bin_tree_new(hash(""), "");
	while( -1 != getline(&line, &n, fp)) {
		bin_tree_add(tree, trim(line));
	}
	puts("Ctrl+C to quit.");
	for(;;){
		line = readline("Enter search word: ");
	// 	line = strdup("Ali");
		if(NULL == line)
			break;
		// assert(NULL != line);
		printf("%s", line);
		word_list *list = bin_tree_find(tree, line);
		if(NULL != list) {
			word_list_print(list);
		}else{
			puts(": No matches.");
		}
	}
	exit(EXIT_SUCCESS);
}