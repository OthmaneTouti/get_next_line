#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd;
	int	lines;
	char *line;

	// printf("TEST 1, simple test\n");
	// lines = 1;
	// fd = open("text_files/test1.txt", O_RDONLY | O_CREAT);
	// if (fd < 0)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%d -> %s\n", lines++, line);
	// 	free(line);
	// }
	// close(fd);
	// printf("---------------------------------------\n\n");

	// printf("TEST 2, multiple nl\n");
	// lines = 1;
	// fd = open("text_files/test2.txt", O_RDONLY | O_CREAT);
	// if (fd < 0)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%d -> %s\n", lines++, line);
	// 	free(line);
	// }
	// close(fd);

	// printf("---------------------------------------\n\n");

	// printf("TEST 3 - no nl, short\n");
	// lines = 1;
	// fd = open("text_files/test3.txt", O_RDONLY | O_CREAT);
	// if (fd < 0)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%d -> %s\n", lines++, line);
	// 	free(line);
	// }
	// close(fd);

	// printf("---------------------------------------\n\n");

	// printf("TEST 4 - no nl, long\n");
	// lines = 1;
	// fd = open("text_files/test4.txt", O_RDONLY | O_CREAT);
	// if (fd < 0)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%d -> %s\n", lines++, line);
	// 	free(line);
	// }
	// close(fd);
	// printf("---------------------------------------\n\n");

	// printf("TEST 5 - only newlines\n");
	// lines = 1;
	// fd = open("text_files/test5.txt", O_RDONLY | O_CREAT);
	// if (fd < 0)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%d -> %s\n", lines++, line);
	// 	free(line);
	// }
	// close(fd);
	// printf("---------------------------------------\n\n");
	// printf("TEST 6 - only one nl\n");
	// lines = 1;
	// fd = open("text_files/test6.txt", O_RDONLY | O_CREAT);
	// if (fd < 0)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%d -> %s\n", lines++, line);
	// 	free(line);
	// }
	// close(fd);

	// printf("TEST 7, lost of lines with nl\n");
	// lines = 1;
	// fd = open("text_files/test7.txt", O_RDONLY | O_CREAT);
	// if (fd < 0)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%d -> %s\n", lines++, line);
	// 	free(line);
	// }
	// close(fd);
	// printf("---------------------------------------\n\n");

	// printf("TEST 8, one char no nl\n");
	// lines = 1;
	// fd = open("text_files/test8.txt", O_RDONLY | O_CREAT);
	// if (fd < 0)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%d -> %s", lines++, line);
	// 	free(line);
	// }
	// close(fd);
	// printf("---------------------------------------\n\n");

	// printf("TEST 9, variable nl\n");
	// lines = 1;
	// fd = open("text_files/test9.txt", O_RDONLY | O_CREAT);
	// if (fd < 0)
	// {
	// 	printf("Error opening file");
	// 	return (1);
	// }
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%d -> %s", lines++, line);
	// 	free(line);
	// }
	// close(fd);
	// printf("---------------------------------------\n\n");

	printf("TEST 10, 2 lines, no nl\n");
	lines = 1;
	fd = open("text_files/test10.txt", O_RDONLY | O_CREAT);
	if (fd < 0)
	{
		printf("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%d -> %s", lines++, line);
		free(line);
	}
	close(fd);
	printf("---------------------------------------\n\n");
}