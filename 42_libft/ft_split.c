/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:24 by svidot            #+#    #+#             */
/*   Updated: 2023/10/12 18:38:24 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>

static char	**ft_assign_words(char const *s, char c,
								char **s_split, size_t n_words)
{
	char	*s_trim;
	char	*s2;
	
	//s2 = ft_strdup(s);
	s_trim = NULL;
	s2 = "a";
	while (s2)
	{
		s_trim = ft_strtrim(s, &c);
		if (!s_trim)
			return (NULL);
		s2 = ft_strchr(s_trim, c);
		if (s2)
			*s_split = ft_substr(s_trim, 0, s2 - s_trim);
		else
			*s_split = ft_substr(s_trim, 0, ft_strlen(s_trim));
		if (!*s_split)
			return (NULL);
		s = s2;
		s_split++;
		//free(s_trim);
	}
	
	free(s_trim);
	//free(s2);
	return (s_split - n_words);
}

char	**ft_split(char const *s, char c)
{
	char		**s_split;
	char		*s_trim;
	char const	*s1;
	size_t			n_words;

	s1 = s;
	n_words = 0;
	//if(!s)
	//	return (NULL);
	if (!*s)
	{
		s_split = (char **) malloc(sizeof (char *));
		*s_split = NULL;
		return (s_split);
	}
	while (s1)
	{
		s_trim = ft_strtrim(s1, &c);
		if (!s_trim)
			return (NULL);
		s1 = ft_strchr(s_trim, c);
		if(*s_trim)
			n_words++;
	}
	if (!n_words)
	{
		s_split = (char **) malloc(sizeof (char *) * (1));
		*s_split = NULL;
		free(s_trim);
		return (s_split);
	}
	free(s_trim);
	s_split = (char **) malloc(sizeof (char *) * (n_words + 1));
	if (!s_split)
		return (NULL);
	s_split[n_words] = NULL;
	return (ft_assign_words(s, c, s_split, n_words));
}
