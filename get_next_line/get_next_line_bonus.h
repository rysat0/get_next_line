/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:41:05 by rysato            #+#    #+#             */
/*   Updated: 2025/05/15 20:19:09 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int		fd;
	char	*joined;
	t_node	*next;
}			t_node;

char		*get_next_line(int fd);
char		*ft_strndup(const char *str, size_t len);
int			newline_detect(const char *str);
char		*ft_strjoin_free(char *joined, char *buf, size_t read_bytes);
char		*extract_line(char *joined);
char		*make_next_joined(char *joined);

#endif
