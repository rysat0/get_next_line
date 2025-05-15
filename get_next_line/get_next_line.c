/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:39 by rysato            #+#    #+#             */
/*   Updated: 2025/05/15 19:31:40 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// char	*get_next_line(int fd)
// {
// 	static char	*joined;
// 	char		*buf;
// 	ssize_t		read_bytes;
// 	char		*oneline;

// 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (buf == NULL)
// 		return (NULL);
// 	while ((joined == NULL || !newline_detect(joined)))
// 	{
// 		read_bytes = read(fd, buf, BUFFER_SIZE);
// 		if (read_bytes <= 0)
// 			break ;
// 		buf[read_bytes] = '\0';
// 		if (joined == NULL)
// 			joined = ft_strndup(buf, (size_t)read_bytes);
// 		else
// 			joined = ft_strjoin_free(joined, buf, read_bytes);
// 		if (joined == NULL)
// 			return (free(buf), NULL);
// 	}
// 	if (read_bytes < 0)
// 		return (free(joined), joined = NULL, free(buf), NULL);
// 	if (joined == NULL || *joined == '\0')
// 		return (free(buf), NULL);
// 	oneline = extract_line(joined);
// 	joined = make_next_joined(joined);
// 	return (free(buf), oneline);
// }
