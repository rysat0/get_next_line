/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:41:03 by rysato            #+#    #+#             */
/*   Updated: 2025/05/17 19:22:18 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	del_node(t_node *target, t_node **list)
{
	t_node	**scan;

	scan = list;
	while ((*scan) != NULL && (*scan) != target)
		scan = &(*scan)->next;
	if ((*scan) != NULL)
	{
		(*scan) = target->next;
		free(target->joined);
		free(target);
	}
}

static t_node	*find_get_node(int fd, t_node **list)
{
	t_node	*tmp;
	t_node	*newnode;

	tmp = *list;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	newnode = malloc(sizeof(t_node));
	if (newnode == NULL)
		return (NULL);
	newnode->fd = fd;
	newnode->joined = NULL;
	newnode->next = *list;
	*list = newnode;
	return (newnode);
}

static ssize_t	fill_joined(int fd, char **joined, char *buf)
{
	ssize_t	rb;

	rb = 1;
	while (*joined == NULL || !newline_detect(*joined))
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
	char			*buf;
	ssize_t			st;
	char			*line;
	static t_node	*list = NULL;
	t_node			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = find_get_node(fd, &list);
	if (tmp == NULL)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	st = fill_joined(fd, &(tmp->joined), buf);
	if (st == -2)
		return (free(buf), NULL);
	if (st < 0 || tmp->joined == NULL || *(tmp->joined) == '\0')
		return (free(buf), del_node(tmp, &list), NULL);
	line = extract_line(tmp->joined);
	tmp->joined = make_next_joined(tmp->joined);
	if (tmp->joined == NULL)
		del_node(tmp, &list);
	return (free(buf), line);
}
