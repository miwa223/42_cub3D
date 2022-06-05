/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:56:21 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/05 19:08:09 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "cub3d.h"
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*save[FD_MAX];
	ssize_t		status;

	*line = NULL;
	if (fd < 0 || fd > FD_MAX || !line)
		exit_program(OPEN_FAIL);
	if (save[fd] && find_newline_in_save(&save[fd], line))
		return (1);
	status = get_line(&save[fd], line, fd);
	if (status == EOF_READ && *line == NULL)
	{
		*line = (char *)malloc(1);
		if (!*line)
			exit_program(MALLOC_FAIL);
		**line = '\0';
	}
	return (status);
}

bool	find_newline_in_save(char **save, char **line)
{
	char	*after_newline;
	char	*tmp;

	after_newline = ft_strchr_return_next_char(*save, '\n');
	if (!after_newline)
	{
		*line = *save;
		*save = NULL;
		return (false);
	}
	*line = ft_substr(*save, 0, after_newline - *save - 1);
	if (!*line)
	{
		free_buf((void **)save);
		exit_program(MALLOC_FAIL);
	}
	tmp = *save;
	*save = ft_strdup(after_newline);
	if (!*save)
		exit_program(MALLOC_FAIL);
	free_buf((void **)&tmp);
	return (true);
}

int	get_line(char **save, char **line, int fd)
{
	char	*buf;
	ssize_t	bytes;

	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		exit_program(MALLOC_FAIL);
	while (!*save)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == ERROR)
			exit_program(READ_FAIL);
		if (bytes == EOF_READ)
			return (0);
		buf[bytes] = '\0';
		store_nextline_in_save(save, buf);
		buf_to_line(line, buf, save);
	}
	free_buf((void **)&buf);
	return (1);
}

void	store_nextline_in_save(char **save, char *buf)
{
	char	*after_newline;

	after_newline = ft_strchr_return_next_char(buf, '\n');
	if (after_newline)
	{
		*save = ft_strdup(after_newline);
		if (!*save)
			exit_program(MALLOC_FAIL);
		buf[ft_strlen(buf) - ft_strlen(after_newline) - 1] = '\0';
	}
}

void	buf_to_line(char **line, char *buf, char **save)
{
	char	*tmp;

	if (!*line)
		*line = ft_strdup(buf);
	else
	{
		tmp = *line;
		*line = ft_strjoin_new_line(*line, buf);
		free_buf((void **)&tmp);
	}
	if (!*line)
	{
		free_buf((void **)save);
		exit_program(MALLOC_FAIL);
	}
}
