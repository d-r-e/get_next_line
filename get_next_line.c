/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:58:19 by darodrig          #+#    #+#             */
/*   Updated: 2019/11/26 16:20:48 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(int fd, char **s, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	*line = ft_substr(s[fd], 0, i);
	if (s[fd][i] == '\0')
		return (0);
	tmp = ft_strdup(s[fd] + i + 1);
	free(s[fd]);
	s[fd] = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*s[4096];
	int			rd;
	char		*temp;

	if (!line || fd < 1 || fd > 4095 || (rd = read(fd, buff, 0)) == -1)
		return (-1);
	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (rd == -1)
			return (-1);
		buff[rd] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup("");
		temp = ft_strjoin(s[fd], buff);
		if (s[fd])
			free(s[fd]);
		s[fd] = temp;
		if (ft_strchr(s[fd], '\n') != NULL)
			break ;
	}
	rd = get_line(fd, s, line);
	if (rd < 0)
		return (-1);
	return (rd);
}
