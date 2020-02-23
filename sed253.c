#include "copy.h"
#include "delete.h"
#include "substitute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace = 0;
int delete = 0;

void usage() {
	fprintf(stderr, "usage: sed253 [-s pattern string] [-d line1 line2]\n");
	exit(2);
}

void parse_args(int argc, char *argv[]) {
	if (argc != 4 && argc != 1)
		usage();
	if (argc == 4) {
		if (strcmp(argv[1], "-s") == 0)
			replace = 1;
		else if (strcmp(argv[1], "-d") == 0)
			delete = 1;
		else {
			usage();
		}
	}
}

void replace_occurrences() {
	printf("this would replace stuff eventually\n");
}

void delete_lines() {
	printf("this will delete stuff eventually\n");
}

void copy() {
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
		printf("%s", buffer);
}

int main(int argc, char *argv[]) {
	parse_args(argc, argv);
	if (replace)
		replace_occurrences();
	else if (delete)
		delete_lines();
	else
		copy();
	return 0;
}

