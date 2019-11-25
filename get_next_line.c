#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int	i;
	int	j;

	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i+ j] = '\0';
	return (new);
}

int	get_next_line(int fd, char **line)
{
	char	*tmp;
	char	buff[4096][BUFFER_SIZE + 1];
	int	rd;

	while ((rd = read(fd, buff[fd], BUFFER_SIZE)) > 0)
	{
		buff[fd][BUFFER_SIZE] = '\0';
		tmp = buff[fd];
		*line = tmp;
		printf("RD: %d, LINE: %s\n",rd, *line);
	}
	return (1);
}
