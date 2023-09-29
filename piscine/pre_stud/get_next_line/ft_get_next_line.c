/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:39:50 by seblin            #+#    #+#             */
/*   Updated: 2023/09/29 18:07:51 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_ft_gnl.h"
#include "ft_get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/*
int resize_buffer(char **line, size_t buff_size)
{
    char    *tmp_line;

    tmp_line = (char *) malloc(sizeof (char) * buff_size); // +1 ?
    if (!tmp_line)
        return (1);
    ft_memcpy(*line, tmp_line);        
    free(*line);
    *line = tmp_line;
    return (0);    
}
*/
/*
** verif si buffer null ?
** mesurer taille buffer
** multiplier cette taille par deux
** creer un nouveau buffer
** verifier malloc
** copier le contenu du buffer vers le nouveau buffer
** faire en sorte que le pointeur buffer se trouve a l'emplacement de l'ancien char '\0' 
** liberer le buffer
** affecter le nouveau buffer au pointeur buffer 
** return 0 si ok sinon 1
*/
/*
int    ft_expand_buffer(char **buffer) 
{
    char    *new_buffer;
    int i;

    i = 0;
    while ((*buffer)[i])
        i++; // minimum 1024
    new_buffer = (char *) malloc (sizeof (char) * i * 2);
    if (!new_buffer)
    {
        write(1, "error buffer allocation", 24);
        return (-1);        
    }   
    while (**buffer)    
        *new_buffer++ = *(*buffer++);
    free(*buffer);
    *buffer = new_buffer;
    return (0); 
}

int ft_save_remainingline(char **buffer, int newline_index)
{
    char *new_buffer;   
    int i;

    i = 0;
    while ((*buffer)[newline_index + 1 + i])
        i++;
    if (i > 0)
    {
        new_buffer = (char *) malloc(sizeof (char) * (i + 1));
        if (!new_buffer)
        {
            write(1, "error buffer allocation", 24);
            return (-1);        
        }
        i = 0;
        while ((*buffer)[newline_index + 1 + i])
            new_buffer[i] = (*buffer)[newline_index + 1 + i++];
        new_buffer[i] = '\0';
    }
    else
        new_buffer = NULL; 
    free(*buffer);
    *buffer = new_buffer; 
    return (0);
}
*/

int ft_extract_firstline(char *buffer, char **line, int newline_index) //buffer null ? strndup!!
{
    int i;

    if (*line)
        free(*line);
    *line = (char *) malloc(sizeof (char) * newline_index + 1); // si n est au debut ?
    if (!*line)
    {
        write(1, "error buffer allocation", 24);
        return (1);        
    }
    i = -1;
    while (++i < newline_index)	
        (*line)[i] = buffer[i];	
    (*line)[i] = '\0';
    return (0);   
}

int ft_search_i_newline(char *buffer)
{
    int i;

    i = -1;
    while (buffer[++i])
        if (buffer[i] == '\n')
            return (i);               
    return (-1);
}

int	ft_get_next_line(const int fd, char **line)
{
	static char	*buffer;
	ssize_t 	read_size;
	int			i_newline;
	
	//printf("in gnl\n");
	if (!buffer)
	{//	printf("BUFFER");	
		buffer = (char *) malloc (sizeof (char) * BUFF_SIZE);
		if (!buffer)
			return (-1);	
	}
	i_newline = -1;
	i_newline = ft_search_i_newline(buffer); printf("i:%d, %s", i_newline, buffer);
	while (i_newline < 0)
	{	//printf("while\n");
		char	*temp = ft_strdup(buffer);
		read_size = read(fd, buffer, BUFF_SIZE - 1); 	
			
		if (read_size > 0)
		{
			buffer[read_size] = '\0';
			buffer = ft_strjoin(temp, buffer); // free temp & buffer
			i_newline = ft_search_i_newline(buffer);//printf("i:%d\n", i_newline);
		}
		else if (read_size == 0)
		{			
			if (*buffer) 
			{
				*line = ft_strdup(buffer);
				*buffer = '\0';			
				return (1);	
			}
			free(buffer); 
			return (0);
		}
		else 
			return (-1);
	}//printf("af\n");
	*line = ft_strndup(buffer, i_newline);	
	ft_memmove(buffer, buffer + i_newline + 1, ft_strlen(buffer + i_newline + 1) + 1);	
	return (1);
}

/*
int ft_get_next_line(const int fd, char **line) // entré std ou redirection ?
{
    static char *buffer;
    ssize_t read_size;
    int buff_mult;
    int newline_index;
    
    if (!buffer)
    {
        buffer = (char *) (sizeof (char) * BUFF_SIZE);
        if (!buffer)
        {
            write(1, "error buffer allocation", 24);
            return (-1);        
        }
        buffer[0] = '\0';
    }
    newline_index = -1;
    while (newline_index < 0)
    {
        if (buffer[0] == '\0')// si le buffer est alloué mais vide
            read_size = read(fd, buffer, BUFF_SIZE - 1);
        if (read_size > 0)
        {               
            buffer[read_size] = '\0'; 
            newline_index = ft_search_newline_index(buffer);
            if (newline_index >= 0)
            {
                ft_extract_firstline(buffer, newline_index, line);  
                ft_save_remainingline(&buffer, newline_index);
                return (1);
            }
            else
                ft_expand_buffer(buffer);
        }
        else if (read_size == 0)
        {
            newline_index = //fin du buffer
            ft_extract_firstline(buffer, newline_index, line);   // si il est plein 
            free(buffer);
            buffer = NULL;
        }
        else
            ;//error read new_line 1 (sortie boucle) free ret -1
    }
    free(buffer);
    if (read_size < 0)
        return (-1);
    else if (read_size == 0) // send remain ?
        return (0);       
 // 0 plus de ligne, 1 une ligne lue, -1 erreur
}
*/