#include "copy.h"
#include "delete.h"
#include "substitute.h"
#include <stdlib.h>
#include <string.h>

int replace = 0;
char *pattern;
char *replacement;

int delete = 0;
int starting_line;
int ending_line;

void usage() {
	fprintf(stderr, "usage: sed253 [-s pattern string] [-d line1 line2]\n");
	exit(2);
}

void parse_args(int argc, char *argv[]) {
	if (argc != 4 && argc != 1)
		usage();
	if (argc == 4) {
		if (strcmp(argv[1], "-s") == 0) {
			replace = 1;
			pattern = argv[2];
			replacement = argv[3];
		}
		else if (strcmp(argv[1], "-d") == 0) {
			delete = 1;
			starting_line = atoi(argv[2]);
			ending_line = atoi(argv[3]);
		} else {
			usage();
		}
	}
}

int main(int argc, char *argv[]) {
	parse_args(argc, argv);
	if (replace)
		replace_occurrences(pattern, replacement);
	else if (delete)
		delete_lines(starting_line, ending_line);
	else
		copy();
	return 0;
}

