#include "copy.h"
#include "delete.h"
#include "substitute.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		printf("%s", buffer);
	}
	return 0;
}
