#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <readline/readline.h>

#include "anigramer.h"

int main(int argc, char **argv){
	if(2 > argc || 3 < argc){
		printf("Usage:\n\t%s word-file [OPTIONS]\n\nOptions:\n\t-b\tBroken keyboard mode.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *fp = NULL;
	fp = fopen(argv[1], "r");
	if(NULL == fp) {
	  printf("Failed to open file: \"%s\", is it really a wordlist?\n", argv[1]);
	  exit(EXIT_FAILURE);
	}
	char *line = NULL;

	int flags = 0;
	if(3 == argc)
		if(0 == strcmp(argv[2], "-b"))
			flags |= BROKEN_KEYBOARD_MODE;
	set_flags(flags);
	size_t n = 0;
	bin_tree *tree = bin_tree_new(hash(""), "");
	while( EOF != fscanf(fp, "%ms", &line)) {
		bin_tree_add(tree, trim(line));
		free(line);
	}
	fclose(fp);
	fp = NULL;
	puts("Ctrl+D to quit.");
	for(;;){
		printf("Enter search word: ");
		free(line);
		scanf("%ms", &line);
		if(NULL == line)
			break;
		//		puts(line);
		word_list *list = bin_tree_find(tree, line);
		if(NULL != list)
			word_list_print(list);
		else
			puts("No matches.");
	}
	exit(EXIT_SUCCESS);
}
