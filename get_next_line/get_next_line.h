/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:42 by rysato            #+#    #+#             */
/*   Updated: 2025/05/07 19:19:19 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <stdlib.h>
# include <unistd.h>

BUFFER_SIZE = 16;

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
int		newline_detect(const char *str);
char	*ft_strjoin_free(char *joined, char *buf, ssize_t read_bytes);
char	*extract_line(char *joined);
char	*make_next_joined(char *joined);

#endif
