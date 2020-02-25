#include "copy.h"

void copy() {
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
		printf("%s", buffer);
}
