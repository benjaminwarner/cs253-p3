#include "delete.h"

void delete_lines(int starting, int ending) {
	char buffer[1024];
	int i = 1;
	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		if (i > ending || i < starting)
			printf("%s", buffer);
		i++;
	}
}
