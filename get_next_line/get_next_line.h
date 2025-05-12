/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:42 by rysato            #+#    #+#             */
/*   Updated: 2025/05/12 19:25:08 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 16
#endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>



char	*get_next_line(int fd);
char	*ft_strndup(const char *str, size_t len);
int		newline_detect(const char *str);
char	*ft_strjoin_free(char *joined, char *buf, size_t read_bytes);
char	*extract_line(char *joined);
char	*make_next_joined(char *joined);

#endif
