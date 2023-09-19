/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:52:04 by seblin            #+#    #+#             */
/*   Updated: 2023/09/18 11:58:35 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_s;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	join_s = (char *) malloc(sizeof (char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	temp = join_s;
	while (*s1)
		*join_s++ = *s1++;
	while (*s2)
		*join_s++ = *s2++;
	*join_s = '\0';
	return (temp);
}
/*
int main(void)
{
    char    *s1 = "je mange ";
    char    *s2 = "des patates.";
    char    *join_s;

    join_s = ft_strjoin(s1, s2);
    printf("%s\n", join_s);
    free(join_s);
    return (0);
}
*/