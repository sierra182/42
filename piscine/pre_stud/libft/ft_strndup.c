/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:30:08 by seblin            #+#    #+#             */
/*   Updated: 2023/09/28 21:59:41 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*s_dup;
	size_t	s_len;
	size_t	s_dup_len;

	s_len = ft_strlen(s);
	if (s_len > n)
		s_dup_len = n;
	else
		s_dup_len = s_len;
	s_dup = (char *) malloc(sizeof (char) * (s_dup_len + 1));
	if (!s_dup)
		return (NULL);
	ft_strlcpy(s_dup, s, s_dup_len + 1);
	return (s_dup);
}
