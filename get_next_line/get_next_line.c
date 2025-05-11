/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:07:39 by rysato            #+#    #+#             */
/*   Updated: 2025/05/09 11:55:45 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*joined;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_bytes;
	char		*oneline;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
	while (!newline_detect(joined))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			break;
		buf[read_bytes] = '\0';
		if (joined == NULL)
			joined = ft_strdup(buf);
		else
			joined = ft_strjoin_free(joined, buf, read_bytes);
        if(joined == NULL)
            return(NULL);
	}
    if(joined == NULL || *joined == '\0')
        return(NULL);
	oneline = extract_line(joined);
	joined = make_next_joined(joined);
	return (oneline);
}

static void	print_fd(int fd, const char *label)
{
    char    *line;
    int     n = 1;

    printf("\n---- %s ----\n", label);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%03d: %s", n++, line);
        free(line);
    }
    printf("---- EOF %s ----\n", label);
}

int	main(int argc, char **argv)
{
    if (argc == 1)
    {
        /* 引数無し: 標準入力をそのままテスト */
        print_fd(STDIN_FILENO, "STDIN");
    }
    else
    {
        int i = 1;
        while (i < argc)
        {
            int fd = open(argv[i], O_RDONLY);
            if (fd < 0)
            {
                perror(argv[i]);
                ++i;
                continue;
            }
            print_fd(fd, argv[i]);
            close(fd);
            ++i;
        }
    }
    return (0);
}
