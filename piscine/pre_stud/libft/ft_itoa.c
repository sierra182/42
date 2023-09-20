/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:10 by seblin            #+#    #+#             */
/*   Updated: 2023/09/19 21:43:58 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*ft_alloc_on_rec_end(int is_neg, char *s, int *n_digit)
{
	if (!s)
	{
		if (is_neg)
		{
			s = (char *) malloc(sizeof(char) * (*n_digit + 2));
			if (!s)
				return (NULL);
			s[*n_digit + 1] = '\0';
			*n_digit = 0;
			s[*n_digit] = '-';
		}
		else
		{
			s = (char *) malloc(sizeof(char) * (*n_digit + 1));
			if (!s)
				return (NULL);
			s[*n_digit] = '\0';
			*n_digit = -1;
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	static int	is_neg = 0;	
	static int	n_digit = 0;
	char		*s;
	int			div;
	int			mod;

	s = NULL;
	n_digit++;
	if (n == -2147483648)
		return (s = "-2147483648");
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	div = n / 10;
	mod = n % 10;
	if (n > 9)
		s = ft_itoa(div);
	s = ft_alloc_on_rec_end(is_neg, s, &n_digit);
	if (!s)
		return (NULL);
	n_digit++;
	s[n_digit] = (char) mod + 48;
	return (s);
}
/*
#include <stdio.h>
int	main(void)
{  
	char	*s;
	int	pos = 422489;
	int neg = -2147483648;

	s = NULL;
	s = ft_itoa(neg); 
	printf("%s\n", s);
	free(s);	
	return (0);
}
*/