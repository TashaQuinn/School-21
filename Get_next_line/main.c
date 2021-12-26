#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	//int		fd2;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	//fd2 = open("text2.txt", O_RDONLY);
	//line = get_next_line(fd2);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	//line = get_next_line(fd2);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	//line = get_next_line(fd2);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}
