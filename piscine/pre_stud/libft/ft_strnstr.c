/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:42:26 by seblin            #+#    #+#             */
/*   Updated: 2023/09/22 22:44:52 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	i;
	int	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *) haystack);
	while (*haystack && n--)
	{
		if (*haystack == *needle)
		{
			i = 1;
			while (needle[i] && (n - i))
			{
				if (haystack[i] != needle[i])
					break ;
				i++;
			}
			if (i == needle_len)
				return ((char *) haystack);
		}
		haystack++;
	}
	return (NULL);
}
/*
int main (void)
{//lorem ipsum dolor sit amet", "", 10
	char	*haystack = "bonjour";
	char	*needle = "";
	char	*find;
	
	find = ft_strnstr(haystack, needle, 10);
	printf("%s", find);
}
*/
