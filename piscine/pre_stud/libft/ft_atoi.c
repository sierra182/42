/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:58:19 by seblin            #+#    #+#             */
/*   Updated: 2023/09/22 22:41:12 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -sign;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
			res = res * 10 + (*nptr - 48);
		else
			break ;
		nptr++;
	}
	res *= sign;
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s = "+-54";
	int		res = 0;
	
	res = atoi(s);
	
	printf("%d", res);
	return (0);
}
*/
