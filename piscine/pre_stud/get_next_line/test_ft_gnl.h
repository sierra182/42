#ifndef TEST_FT_GNL_H
#define TEST_FT_GNL_H

int ft_search_i_newline(char *buffer);
int	ft_extract_firstline(char *buffer, char **line, int newline_index);
int ft_get_next_line(const int fd, char **line);

#endif