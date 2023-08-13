/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Cireated: 2023/07/29 17:45:30 by svidot            #+#    #+#             */
/*   Updated: 2023/07/30 16:03:49 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "array_manager.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_printarr(char *arr[])
{
	while (*arr)
	{
		ft_putstr(*arr++);
		write(1, "\n", 1);
	}		
}

ssize_t	ft_filelenght(char buffer[])
{
	ssize_t		i;
	
	i = 0;
	while (*buffer)
        {
        	if (*buffer == '\n')
                	i++;
                buffer++;
        }
	return (i);	
}
#include <stdio.h>
void	ift_rmempty(char buffer[])
{
	int	b;
		
	b = 0;
	while (*buffer)
	{
		if (*buffer == '\n' && b >= 1)
                {
                        *buffer = ' ';                   
                }
		if (*buffer == '\n')
			b++;
		
		if (*buffer >= 'a' && *buffer <= 'z')
			b = 0;
	 				
		buffer++;	
	}
}
void    ft_rmempty(char buffer[])
{
        int     b;
	int	c;
	int	d;
	int	i;

        b = 0;
	c = 0;
	d = 0;
	i = 0;
        while (*buffer)
        {
		if (*buffer >= 'a' && *buffer <= 'z') 
		{			
			b = 0;
		}		
		else if (*buffer == '\n' && b < 1 )
		{
			b = 1;		
		}	
		 
		else if (*buffer == '\n' && b >= 1)

                        *buffer = ' ';
		buffer++;
        }
	while (!(buffer[i] >= 'a' && buffer[i] <= 'z'))
	{
		if (buffer[i] == '\n')
			buffer[i] = ' ';
		i++;
	}
	while (i > 0)
	{
		if(buffer[i] == '\n')
			buffer[i] = ' ';
		i--;
	}
}
char**	ft_assigndict(char *dict[], char buffer[])
{
	int	i;
	int	j;
	int	k;
	int	b;

	i = 0;
	j = 0;
	k = 0;
	b = 0;
//	ft_rmempty(buffer);
	while (buffer[i])
	{
		if (buffer[i] >= 'a' && buffer[i] <= 'z') 
		{
			dict[j][k] = buffer[i];		 	
			k++;
		}
		
		if (buffer[i] == '\n')
		{	
			k = 0;
		        j++;
		}
		i++;
	}
	return (dict);
}

char**	ft_createdict(char *dict[], ssize_t size)
{	
	int	i;

	dict = (char**) malloc(size*256);
	i = 0;
	while (i < size)
	{
		dict[i] = (char*) malloc(256);
		i++;
	}
	return (dict);
}

char**	ft_getdict(const char *pathname)
{
	int	i;
	int	fd;
	ssize_t	rslt;
	char*	buffer;	
	char**	dict;
	ssize_t	dict_lenght;
		
	i = 0;
	fd = open(pathname, O_RDONLY);

	if (fd == -1) 
 	{
		ft_putstr("Dict Error\n");
		return (NULL);
	}

	while ((rslt = read(fd, buffer, 1) != -1 && rslt != 0))
		i++;
	if (rslt == -1 || rslt == 0)
        {
                close(fd);
                return (NULL);
        }
	while ((rslt = read(fd, buffer, i)) != -1 && rslt != 0)
	{
		buffer[rslt] = '\0';

		dict = ft_createdict(dict, rslt);
		ft_assigndict(dict, buffer);
		ft_printarr(dict);
	}
	if (rslt == -1 || rslt == 0)
	{	
		close(fd);
		return (NULL);
	}
	return (dict);
}
