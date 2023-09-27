/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:39:45 by seblin            #+#    #+#             */
/*   Updated: 2023/09/27 14:52:04 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_gnl.h"
#include <stdio.h>

void	test_search_newline_index(void) // 3, 0, 29, 2, 0, -1
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
	printf("search_new_line_index:\n\n");	
	while (*buf)	
		printf("%d\n", ft_search_newline_index(*buf++));	
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

int main (void)
{ 
	test_search_newline_index();
	test_extract_firstline();
	return (0);
}