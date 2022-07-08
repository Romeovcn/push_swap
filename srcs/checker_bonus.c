#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>


// get stack 1 2 3 4 || "1 2 3 4"
// do op
// check if stack is sorted
int main()
{
	int fd = 0;
	char *line;
	line = get_next_line(fd);
	while (line)
	{
		printf("line=%s", line);
		line = get_next_line(fd);
	}
	free(line);
}