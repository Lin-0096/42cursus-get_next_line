/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:54:54 by linliu            #+#    #+#             */
/*   Updated: 2025/05/23 11:19:25 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*copy_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_strndup(stash, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*left;
	char	*new_string;

	if (!stash)
		return (NULL);
	left = ft_strchr(stash, '\n');
	if (!left)
		return (free(stash), NULL);
	left++;
	if (*left == '\0')
		return (free(stash), NULL);
	new_string = ft_strndup(left, ft_strlen(left));
	if (!new_string)
		return (free(stash), NULL);
	free (stash);
	return (new_string);
}

static	char	*join_stash(char *stash, int fd)
{
	char		*buf;
	ssize_t		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), stash = NULL, NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free (buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash[MAX_FD];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	stash[fd] = join_stash(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = copy_line(stash[fd]);
	if (!line)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
