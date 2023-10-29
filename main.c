#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd;
	int	lines;
	char *line;

	lines = 1;
	fd = open("test2.txt", O_RDONLY | O_CREAT);
	if (fd < 0)
		printf("Error opening file");
	while ((line = get_next_line(fd)))
		printf("%d -> %s\n", lines++, line);
	free(line);
	close(fd);
}