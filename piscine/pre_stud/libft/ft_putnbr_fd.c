/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:42:37 by seblin            #+#    #+#             */
/*   Updated: 2023/09/20 14:37:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;

	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	div = n / 10;
	mod = n % 10;
	if (n > 9)
		ft_putnbr_fd(div, fd);
	ft_putchar_fd((char) mod + 48, fd);
}
/*
int	main(void)
{
	ft_putnbr_fd(INT_MAX, 1);
	return (0);
}
*/
