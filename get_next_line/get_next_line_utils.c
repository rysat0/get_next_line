/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:37 by rysato            #+#    #+#             */
/*   Updated: 2025/05/07 19:09:48 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*dst;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
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

char	*ft_strjoin_free(char *joined, char *buf, ssize_t read_bytes)
{
	ssize_t	len;
	char	*new_joined;
	int		len;

	len = 0;
	while (joined[len] != '\0')
		len++;
	new_joined = malloc(sizeof(char) * (len + read_bytes + 1));
	if (new_joined == NULL)
		return (NULL);
	while (*joined != '\0')
		*new_joined++ = *joined++;
	while (*buf != '\0')
		*new_joined++ = *buf++;
	*new_joined = '\0';
	free(joined);
	return (new_joined);
}

char	*extract_line(char *joined)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (joined == NULL)
		return (NULL);
	while (joined[len] != '\0')
	{
		if (joined[len] == '\n')
			break ;
		len++;
	}
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = joined[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*make_next_joined(char *joined)
{
	char	*dst;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (*joined != '\n')
		joined++;
	joined++;
	while (joined[len] != '\0')
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = joined[i];
		i++;
	}
	dst[i] = '\0';
	free(joined);
	return (dst);
}
