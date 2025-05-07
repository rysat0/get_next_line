/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:39 by rysato            #+#    #+#             */
/*   Updated: 2025/05/07 19:20:44 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*joined;
	char		*new_joined;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_bytes;
	char		*oneline;

	while (!newline_detect(joined))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == 0)
			return (joined);
		if (read_bytes == -1)
			return (NULL);
		buf[read_bytes] = '\0';
		if (joined == NULL)
			joined = ft_strdup(buf);
		else
			joined = ft_strjoin_free(joined, buf, read_bytes);
	}
	oneline = extract_line(joined);
	new_joined = make_next_joined(joined);
	joined = new_joined;
	return (oneline);
}
