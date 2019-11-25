#include "get_next_line.h"

int	main(void)
{
	int fd;
	char	**line;

	if(!(line = malloc(sizeof(char**))))
	{
		printf("error alocating\n");
		return (-1);
	}
	fd = open("txt", O_RDONLY);
	printf("Open file\n");
	get_next_line(fd, line);
	printf("RESULT: %s\n", *line);
	free(line);
	line = malloc(sizeof(char**));
	get_next_line(fd, line);
	printf("RESULT: %s\n", *line);
	free(line);
	close(fd);
}
