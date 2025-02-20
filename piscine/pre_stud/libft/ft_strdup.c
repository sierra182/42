/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:54:44 by seblin            #+#    #+#             */
/*   Updated: 2023/09/23 09:38:45 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_dup;	
	size_t	s_len;

	s_len = ft_strlen(s);
	s_dup = (char *) malloc(sizeof (char) * (s_len + 1));
	while (*s)
		*s_dup++ = (char) *s++;
	*s_dup = '\0';
	return (s_dup - s_len);
}
/*
#include <stdio.h>
if (!s_len)
		return (NULL);
int main(void)
{
	char *s = "";
	char *res;
	res = ft_strdup(s);
	printf("%s", res);
	return (0);
}
*/
