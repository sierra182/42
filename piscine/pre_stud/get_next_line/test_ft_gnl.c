/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:39:45 by seblin            #+#    #+#             */
/*   Updated: 2023/09/28 21:59:09 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_gnl.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	test_search_i_newline(void) // 3, 0, 29, 2, 0, -1
{
	char	**buf;
	char	*buffer[] = {
							"tu \ncherche la nouvelle ligne.", 
							"\ntu cherche la nouvelle ligne.",
							"tu cherche la nouvelle ligne.\n",
							"tu\n\n cherche la nouvelle ligne.\n",
							"\n\n",
							"",
							NULL
						};
	buf = buffer;
	printf("search_i_newline:\n\n");	
	while (*buf)	
		printf("%d\n", ft_search_i_newline(*buf++));	
	printf("\n");
}

void	test_extract_firstline(void)
{	
	int		ret;
	int		*newl;
	char	*line;
	char	**buf;
	char	*buffer[] = {
							"tu veux\n extraire la premiere ligne.",
							"tu veux extraire\n la premiere ligne.",
							
							NULL
						};
	int		newl_i[] = {
							2,
							16, 							
						};						
	line = NULL;
	buf = buffer;
	newl = newl_i;
	printf("extract_firstline:\n\n");
	while (*buf)
	{
		ret = ft_extract_firstline(*buf++, &line, *newl++);
		printf("%s\n", line); 
		printf("return :%d\n\n", ret);
	}
}

int	test_gnl(void)
{	
    char	*file_path;
    char	*line;
    int		fd;
    int		rslt;
	int		i;
	
	printf("gnl\n\n");
	rslt = 1;
   	file_path = "./test.txt";
	fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        write(1, "error file\n", 11);
        return (1);
    }
	i = 0;
    while (rslt > 0)
	{
		rslt = ft_get_next_line(fd, &line);
		if (rslt > 0)
		{
    		printf("res:%s\n", line);
			free(line);			
		}			
	}		
    close(fd);
    if (rslt == 0)
        write(1, "end file\n", 9);
    else if (rslt == -1)
    {
        write(1, "error line\n", 10);
        return (1);
    }
    return (0);
}

int main (void)
{ 
	//test_extract_firstline();
	test_search_i_newline();
	test_gnl();	
	return (0);
}