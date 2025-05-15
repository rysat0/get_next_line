/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:37 by rysato            #+#    #+#             */
/*   Updated: 2025/05/15 17:09:56 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	newline_detect(const char *str)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin_free(char *joined, char *buf, size_t read_bytes)
{
	size_t	len;
	char	*new_joined;
	char	*tmp;
	char	*str_return;

	len = 0;
	tmp = joined;
	if (joined == NULL)
		return (ft_strndup(buf, read_bytes));
	while (joined[len] != '\0')
		len++;
	new_joined = malloc(sizeof(char) * (len + read_bytes + 1));
	if (new_joined == NULL)
		return (free(joined), joined = NULL, NULL);
	str_return = new_joined;
	while (*joined != '\0')
		*new_joined++ = *joined++;
	while (*buf != '\0')
		*new_joined++ = *buf++;
	*new_joined = '\0';
	free(tmp);
	return (str_return);
}

char	*extract_line(char *joined)
{
	char	*line;
	size_t	len;

	len = 0;
	if (joined == NULL || *joined == '\0')
		return (NULL);
	while (joined[len] != '\0' && joined[len] != '\n')
		len++;
	if (joined[len] == '\n')
		len++;
	line = ft_strndup(joined, len);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*make_next_joined(char *joined)
{
	char	*dst;
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = joined;
	if (joined == NULL)
		return (NULL);
	while (*joined != '\0' && *joined != '\n')
		joined++;
	if (*joined == '\n')
		joined++;
	while (joined[len] != '\0')
		len++;
	if (len == 0)
		return (free(tmp), NULL);
	dst = ft_strndup(joined, len);
	free(tmp);
	return (dst);
}
