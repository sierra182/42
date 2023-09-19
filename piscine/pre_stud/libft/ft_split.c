/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:52:15 by seblin            #+#    #+#             */
/*   Updated: 2023/09/19 15:46:31 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_transition_toggle(char const *s, char c, int rst)
{
	static int	match_transition = 1;
	static int	no_match_transition = 1;

	if (rst)
	{
		match_transition = 1;
		no_match_transition = 1;
		return (0);
	}
	if (*s == c)
	{
		if (match_transition)
		{
			match_transition = 0;
			no_match_transition = 1;
		}
	}
	else if (no_match_transition)
	{
		no_match_transition = 0;
		match_transition = 1;
		return (1);
	}
	return (0);
}

static char	**assign_word(char const *s, char c, char **split_s)
{
	char	*temp_split_s;
	int		n_letter;

	n_letter = 0;
	while (s[n_letter] != c && s[n_letter])
		n_letter++;
	*split_s = (char *) malloc(sizeof (char) * (n_letter + 1));
	if (!*split_s)
		return (NULL);
	temp_split_s = *split_s;
	n_letter = 0;
	while (s[n_letter] != c && s[n_letter])
	{
		**split_s = s[n_letter];
		n_letter++;
		(*split_s)++;
	}
	**split_s = '\0';
	*split_s = temp_split_s;
	return (split_s);
}

char	**ft_split(char const *s, char c)
{
	char const	*temp_s;	
	char		**split_s;
	char		**temp_splits_s;
	int			n_word;

	temp_s = s;
	n_word = 0;
	while (*s)
		n_word += ft_transition_toggle(s++, c, 0);
	split_s = (char **) malloc(sizeof(char *) * (n_word + 1));
	if (!split_s)
		return (NULL);
	temp_splits_s = split_s;
	ft_transition_toggle(s, c, 1);
	s = temp_s;
	while (*s)
	{
		if (ft_transition_toggle(s, c, 0))
			if (!assign_word(s, c, split_s++))
				return (NULL);
		s++;
	}
	*split_s = NULL;
	return (temp_splits_s);
}
/*
#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	char	*s = " un grand pouvoir implique de  grandes responsabilites!";
	char	c = ' ';
	char	**split_s;	
	char **temp_s;	
	
	split_s = NULL;
	split_s = ft_split(s, c);	
	temp_s = split_s;
	while (*split_s)
	{	
		printf("%s\n", *split_s);
		split_s++;
	}	
	split_s = temp_s;
	while (*split_s)
	{
		free(*split_s);
		*split_s = NULL;
		split_s++;
	}
	split_s = temp_s;
	free(split_s);
	split_s = NULL;

	//printf("w: %s\n", tt);//printf("w: %d\n", n_letter);//split_s[n_letter]);
	return (0);
}
*/
/*
static int	ft_transition_toggle(char const *s, char c, int	rst)
{
	static int	match_transition = 1;
	static int	no_match_transition = 1;
	
	if (rst)
	{
		match_transition = 1;
		no_match_transition = 1;	
		return (0);	
	}
	if (*s == c)
	{
		if (match_transition)
		{
			match_transition = 0;
			no_match_transition = 1; 
		}
	}
	else if (no_match_transition)
	{
		no_match_transition = 0;
		match_transition = 1; 
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char const	*temp_s;	
	char		**split_s;
	int			n_word;
	int			n_letter;
	
	temp_s = (char const *) s;
	n_word = 0;
	while (*s)
		n_word += ft_transition_toggle(s++, c, 0);
	split_s = (char **) malloc(sizeof(char *) * (n_word + 1));
	if (!split_s)
		return (NULL);
	char **ret = split_s;
	ft_transition_toggle(s, c, 1);
	s = temp_s;	
	while (*s)
	{
		if (ft_transition_toggle(s, c, 0))
		{
			n_letter = 0;
			while (s[n_letter] != c && s[n_letter])				
				n_letter++;					
			*split_s = (char *) malloc(sizeof (char) * (n_letter + 1));
			if (!*split_s)
				return (NULL);
			char *tt = *split_s;
			n_letter = 0;
			while (s[n_letter] != c && s[n_letter])			
			{
				**split_s = s[n_letter];
				n_letter++;
				(*split_s)++;
			}
			**split_s = '\0';         
			*split_s = tt;				
			split_s++;	
		}	
		s++;
	}	
	*split_s = NULL;
	return (ret);
}
*/