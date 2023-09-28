/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:41:08 by seblin            #+#    #+#             */
/*   Updated: 2023/09/27 22:07:46 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strcpy
*/
#include <string.h> 

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_start;
	
	dest_start = dest;
	while (*src)
		*dest++ = (char) *src++;
	*dest = '\0';
	return (dest_start);
}

#include <stdio.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*dest_start;

	dest_start = dest;
	while (*src && n)
	{
		*dest++ = *src++;
		n--;
	}
	while (n--)
		*dest++ = '\0';
	return (dest_start);
}

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*s_dup;	
	size_t	s_len;

	s_len = strlen(s);
	s_dup = (char *) malloc(sizeof (char) * (s_len + 1));
	while (*s)
		*s_dup++ = (char) *s++;
	*s_dup = '\0';
	return (s_dup - s_len);
}

char	*ft_strdup2(const char *s)
{
	char	*s_dup;	
	size_t	s_len;

	s_len = strlen(s);
	s_dup = (char *) malloc(sizeof (char) * (s_len + 1));
	ft_strcpy(s_dup, s);
	return (s_dup);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*s_dup;
	size_t	s_len;
	size_t	s_dup_len;
	
	s_len = strlen(s);
	if (s_len > n)
		s_dup_len = n;
	else 
		s_dup_len = s_len + 1;	
	s_dup = (char *) malloc (sizeof (char) * s_dup_len);
	if (!s_dup)
		return NULL;
	ft_strncpy(s_dup, s, s_dup_len);
	return (s_dup);
}

int	main(void)
{
	char	*s = "lorem ipsum dolor sit amet";
	char	*d;	
	
	ft_strndup(s, 11);
	printf("%s", ft_strndup(s, 11));
	//printf("%s", s);
	return (0);
}