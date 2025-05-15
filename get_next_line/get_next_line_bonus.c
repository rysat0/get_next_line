/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:41:03 by rysato            #+#    #+#             */
/*   Updated: 2025/05/15 20:19:48 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static ssize_t	fill_joined(int fd, char **joined, char *buf)
{
	ssize_t	rb;

	rb = 1;
	while (!newline_detect(*joined))
	{
		rb = read(fd, buf, BUFFER_SIZE);
		if (rb <= 0)
			break ;
		buf[rb] = '\0';
		if (*joined == NULL)
			*joined = ft_strndup(buf, (size_t)rb);
		else
			*joined = ft_strjoin_free(*joined, buf, rb);
		if (*joined == NULL)
			return (-2);
	}
	return (rb);
}

char	*get_next_line(int fd)
{
	static char	*joined;
	char		*buf;
	ssize_t		st;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	st = fill_joined(fd, &joined, buf);
	if (st == -2)
		return (free(buf), NULL);
	if (st < 0)
		return (free(buf), free(joined), joined = NULL, NULL);
	if (joined == NULL || *joined == '\0')
		return (free(buf), NULL);
	line = extract_line(joined);
	joined = make_next_joined(joined);
	return (free(buf), line);
}
