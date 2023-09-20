/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:06:41 by seblin            #+#    #+#             */
/*   Updated: 2023/09/20 11:39:13 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_map;
	size_t	s_size;
	int		i;

	s_size = ft_strlen(s);
	s_map = (char *) malloc(sizeof (char) * (s_size + 1));
	if (!s_map)
		return (NULL);
	i = -1;
	while (s[++i])
		s_map[i] = f(i, s[i]);
	s_map[i] = '\0';
	return (s_map);
}
/*
static char	ft_f(unsigned int i, char c)
{
	c -= i;
	return (c);
}
#include <stdio.h>
int	main(void)
{
	const char	*s = "bravo";
	char	*s_map;

	s_map = ft_strmapi(s, ft_f);
	printf("%s\n", s_map);
	free(s_map);
	return (0);
}
*/