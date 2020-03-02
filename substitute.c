#include "substitute.h"

void replace_occurrences(char *pattern, char *replacement) {
	if (pattern == NULL) {
		printf("the pattern string string were NULL pointers\n");
		exit(2);
	}
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		char *new_string = str_replace(buffer, pattern, replacement);
		if (new_string == NULL) {
			printf("failed to replace %s with %s in %s\n", pattern, replacement, buffer);
			exit(2);
		}
		printf("%s", new_string);
		free(new_string);
	}
}

char *str_replace(char *str, char *pattern, char *replacement) {
	if (!str)
		return NULL;

	char *result;
	char *insertion;
	char *tmp;
	int len_pattern = strlen(pattern);
	int len_replacement; 

	if (len_pattern == 0)
		return NULL;
	if (!replacement)
		replacement = "";
	len_replacement = strlen(replacement);

	insertion = str;
	int i = 0;
	while ((tmp = strstr(insertion, pattern)) != NULL) {
		i++;
		insertion = tmp + len_pattern;
	}
	
	tmp = result = malloc(strlen(str) + (len_replacement - len_pattern) * 1 + 1);

	if (!result)
		return NULL;

	int len_front;
	while (i--) {
		insertion = strstr(str, pattern);
		len_front = insertion - str;
		tmp = strncpy(tmp, str, len_front) + len_front;
		tmp = strcpy(tmp, replacement) + len_replacement;
		str += len_front + len_pattern;
	}
	strcpy(tmp, str);
	return result;
}
