#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
int	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);

#endif
