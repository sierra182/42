/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:52:11 by seblin            #+#    #+#             */
/*   Updated: 2023/09/18 11:08:05 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_parse_prefix(char const **s1, char const *set)
{
	int	n_set;
	int	j;

	n_set = 0;
	while (**s1)
	{
		j = -1;
		while (set[++j])
		{
			if (**s1 == set[j])
			{
				n_set++;
				break ;
			}
		}
		if (*(set + j) == '\0')
			break ;
		(*s1)++;
	}
	return (n_set);
}

static int	ft_parse_suffixe(char const *s1, char const *set, int s1_len)
{
	int	i;
	int	j;
	int	n_set;

	n_set = 0;
	i = s1_len;
	while (--i >= 0)
	{
		j = -1;
		while (set[++j])
		{
			if (s1[i] == set[j])
			{
				n_set++;
				break ;
			}
		}
		if (*(set + j) == '\0')
			break ;
	}
	return (n_set);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_s1;
	int		s1_len;
	int		n_set;
	int		i;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	n_set = ft_parse_suffixe(s1, set, s1_len);
	n_set += ft_parse_prefix(&s1, set);
	trim_s1 = (char *) malloc(sizeof (char) * (s1_len - n_set + 1));
	if (!trim_s1)
		return (NULL);
	i = 0;
	while (i < s1_len - n_set)
		trim_s1[i++] = *s1++;
	trim_s1[i] = '\0';
	return (trim_s1);
}
