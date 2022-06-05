#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>

# define FD_MAX 8192
# define BUFFER_SIZE 16
# define EOF_READ 0
# define ERROR -1

int		get_next_line(int fd, char **line);
bool	find_newline_in_save(char **save, char **line);
int		get_line(char **save, char **line, int fd);
void	store_nextline_in_save(char **save, char *buf);
void	buf_to_line(char **line, char *buf, char **save);

#endif
