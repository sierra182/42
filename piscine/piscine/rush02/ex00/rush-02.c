/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:31:45 by svidot            #+#    #+#             */
/*   Updated: 2023/07/30 06:14:19 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "array_manager.h"
#include <stdio.h>
int	main()
{
	char	**dict;
	const char	*pathname;
	int	i;

	i = 0;
	pathname = "test.dict";	
	dict = ft_getdict(pathname);
/*
	while (i < 32)
	{printf("n");
		free(dict[i]);
	        i++;
	}
	free(dict);	
*/
	return (0);
}
