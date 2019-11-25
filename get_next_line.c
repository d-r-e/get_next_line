#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	if (!s2 || !s1)
		return (NULL);
	if (!(new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1)
	{
		new[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		new[i] = *s2;
		s2++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

int	get_line(int fd, char **s, char **line)
{
	int	i;
	char	*tmp;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	*line = ft_substr(s[fd], 0, i);
	if (s[fd][i] == '\0')
	{
		*line = s[fd];
		free(s[fd]);
		return (0);
	}
	tmp = ft_strdup(s[fd] + i + 1);
	free(s[fd]);
	s[fd] = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*s[4096];
	int	rd;
	char	*temp;

	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup("");
		temp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = temp;
		rd = get_line(fd, s, line);
	}
	printf("fuera del bucle\n\n");
	if (rd < 0)
		return (-1);
	return (rd);
}
