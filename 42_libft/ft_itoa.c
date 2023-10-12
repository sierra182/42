/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:55:51 by svidot            #+#    #+#             */
/*   Updated: 2023/10/12 06:20:34 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_digitlen(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		is_neg;
	int		i;

	is_neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		is_neg++;
		n = -n;
	}
	i = ft_digitlen(n);
	s = (char *) malloc(sizeof (char) * (i + is_neg + 1));
	if (!s)
		return (NULL);
	s += i + is_neg;
	*s = '\0';
	while (i-- + is_neg)
	{
		*--s = n % 10 + 48;
		n /= 10;
	}
	if (is_neg)
		*s = '-';
	return (s);
}
