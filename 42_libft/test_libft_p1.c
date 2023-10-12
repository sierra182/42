/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_p1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:06:02 by svidot            #+#    #+#             */
/*   Updated: 2023/10/09 19:08:31 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_sep.c"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int	ft_test_isalpha(void)
{
	int	res;
	int is_valid;
	
	is_valid = 1;	
	res = ft_isalpha('k');
	printf("is alpha: %d\n", res);	
	if (!res)
		is_valid = 0;
		
	res = ft_isalpha('8');
	printf("is alpha: %d\n\n", res);	
	if (res)
		is_valid = 0;
	return (is_valid);		
}

int	ft_test_isdigit(void)
{
	int	res;
	int is_valid;
	
	is_valid = 1;
	res = ft_isdigit('7');
	printf("is digit: %d\n", res);
	if (!res)
		is_valid = 0;
		
	res = ft_isdigit('l');
	printf("is digit: %d\n\n", res);
	if (res)
		is_valid = 0;
	return (is_valid);
}

int	ft_test_isalnum(void)
{
	int	res;	
	int is_valid;
	
	is_valid = 1;
	res = ft_isalnum('K');
	printf("is alnum: %d\n", res);
	if (!res)
		is_valid = 0;
		
	res = ft_isalnum(';');
	printf("is alnum: %d\n\n", res);
	if (res)
		is_valid = 0;
	return (is_valid);
}

int	ft_test_isascii(void)
{
	int	res;
	int is_valid;
	
	is_valid = 1;
	res = ft_isascii(127);
	printf("is ascii: %d\n", res);
	if (!res)
		is_valid = 0;
		
	res = ft_isascii(128);
	printf("is ascii: %d\n\n", res);
	if (res)
		is_valid = 0;
	return (is_valid);
}

int	ft_test_isprint(void)
{
	int	res;
	int is_valid;

	is_valid = 1;
	res = ft_isprint(' ');
	printf("is print: %d\n", res);
	if (!res)
		is_valid = 0;
		
	res = ft_isprint(127);
	printf("is print: %d\n", res);
	if (res)
		is_valid = 0;
	return (is_valid);
}

int	ft_test_toupper(void)
{
	int	res;
	int	is_valid;

	is_valid = 1;
	res = ft_toupper('a');
	printf("to upper: %c\n", res);
	if (res != 'A')
		is_valid = 0;
		
	res = ft_toupper('D');
	printf("to upper: %c\n", res);
	if (res != 'D')
		is_valid = 0;

	res = ft_toupper('7');
	printf("to upper: %c\n\n", res);
	if (res != '7')
		is_valid = 0;
	return (is_valid);
}

int	ft_test_tolower(void)
{
	int	res;
	int	is_valid;

	is_valid = 1;
	res = ft_tolower('A');
	printf("to lower: %c\n", res);
	if (res != 'a')
		is_valid = 0;
		
	res = ft_tolower('d');
	printf("to lower: %c\n", res);
	if (res != 'd')
		is_valid = 0;
		
	res = ft_tolower('7');
	printf("to lower: %c\n", res);
	if (res != '7')
		is_valid = 0;
	return (is_valid);
}

void	ft_test_strlen(void)
{
	char	*s;
	size_t	res;

	s = "";
	res = strlen(s);
	printf("strlen: %ld\n", res);
	res = ft_strlen(s);
	printf("ft_strlen: %ld\n\n", res);
	
	s = "bravo";
	res = strlen(s);
	printf("strlen: %ld\n", res);
	res = ft_strlen(s);
	printf("ft_strlen: %ld\n", res);

	/*
	s = NULL;
	res = strlen(s);
	printf("strlen: %ld\n", res);
	res = ft_strlen(s);
	printf("ft_strlen: %ld\n\n", res);
	*/
}

void	ft_test_memset(void)
{
	char	s[] = "bravo";
	char	s2[] = "bravo";
	char	s3[] = "bravo";
	char	s4[] = "bravo";
	int		c; 
	size_t	n;
	void	*res;
	
	c = 42;
	n = 0;
	while (n < 6)
	{
		res = memset(s, c, n++);	
		printf("memset: %s, %s\n", s, (char *) res);
	}
	printf("\n");
	n = 0;
	while (n < 6)
	{
		res = ft_memset(s2, c, n++);	
		printf("ft_memset: %s, %s\n", s2, (char *) res);
	}

	n = 3;
	res = memset(s3, c, n);	
	printf("\nmemset: %s, %s\n", s3, (char *) res);
	res = ft_memset(s4, c, n);
	printf("ft_memset: %s, %s\n", s4, (char *) res);
	/*
	** si n > buffer: stack smashing 
	** si n < 0: err / size_t
	** si s = NULL: seg fault
	*/
}

void	ft_test_bzero(void)
{
	char	s[] = "bravo";
	char	s2[] = "bravo";	
	char	s3[] = "bravo";
	char	s4[] = "bravo";
	size_t	n;		
	int offset;

	offset = 3;
	n = 1;
	bzero(s + offset, n);
	printf("bzero: %s\n", s);
	ft_bzero(s2 + offset, n);
	printf("ft_bzero: %s\n\n", s2);
	offset = 5;
	while (offset-- > 0)
	{
		bzero(s3 + offset, n); 
		printf("bzero: %s\n", s3);
	}
	printf("\n");
	offset = 5;
	while (offset-- > 0)
	{
		ft_bzero(s4 + offset, n); 
		printf("ft_bzero: %s\n", s4);
	}
	/*
	** si n > buffer: stack smashing 
	** si n < 0: err / size_t
	** si s = NULL: seg fault
	*/
}

int	ft_test_memcpy(void)
{
	char	*src;
	char	dest[16] = {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', '\0'}; 
	char	dest2[16] = {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', '\0'}; 
	void	*res;
	size_t	n;
	int		is_valid;

	is_valid = 1;
	src = "la dodo le la";
	n = 14;
	res = memcpy(dest, src, n);
	printf("memcpy: %s, %s\n", dest, (char *) res);	
	res = ft_memcpy(dest2, src, n);
	printf("ft_memcpy: %s, %s\n", dest2, (char *) res);
	printf("\n");
	if (strcmp((char *) res, dest2) || strcmp(dest2, dest))
		is_valid = 0;
		
	src = "le gros dodo le la";
	n = 2;
	res = memcpy(dest, src, n);
	printf("memcpy: %s, %s\n", dest, (char *) res);
	res = ft_memcpy(dest2, src, n);
	printf("ft_memcpy: %s, %s\n", dest2, (char *) res);	
	if (strcmp((char *) res, dest2) || strcmp((char *) res, dest))
		is_valid = 0;
	return (is_valid);
	/*
	** memcpy ne contient pas de verification sur les pointeurs
	** itere seulement sur n
	*/
}

int	ft_test_memmove(void)
{
	char	*src;
	char	dest[] = "\0\0\0\0\0\0\0\0\0\0";
	char	dest2[] = "\0\0\0\0\0\0\0\0\0\0";
	void	*res;
	size_t	n;
	int		is_valid;

	is_valid = 1;
	n = 5; // modif
	src = "bravo mon dodo"; 
	res = memmove(dest, src, n);
	printf("memmove: %s, %s\n", dest, (char *) res);
	res = ft_memmove(dest2, src, n);
	printf("ft_memmove: %s, %s\n", dest2, (char *) res);
	printf("\n");
	
	if (strcmp(res, dest2) || strcmp(res, dest))
		is_valid = 0;
			
	char	src2[] = "bravo la famillia"; 
	char	*dest3;
	dest3 = src2 + 2;
	res = memmove(dest3, src2, n);
	printf("memmove: %s, %s\n", dest3, (char *) res);
	
	char	src3[] = "bravo la famillia"; 
	char	*dest4;
	dest4 = src3 + 2;
	res = ft_memmove(dest4, src3, n);
	printf("ft_memmove: %s, %s\n", dest4, (char *) res);
	printf("\n");
	
	if (strcmp(res, dest4) || strcmp(res, dest3))
		is_valid = 0;

	char	src4[] = "bravo la famillia"; 
	char	*src5;
	char	*dest5;	
	src5 = src4 + 5;
	dest5 = src5 - 2;
	res = memmove(dest5, src5, n);
	printf("memmove: %s, %s\n", dest5, (char *) res);

	char	src6[] = "bravo la famillia"; 
	char	*src7;
	char	*dest6;	
	src7 = src6 + 5;
	dest6 = src7 - 2;
	res = ft_memmove(dest6, src7, n);
	printf("ft_memmove: %s, %s\n", dest6, (char *) res);
	
	if (strcmp(res, dest6) || strcmp(res, dest5))
		is_valid = 0;
	return (is_valid);
	
	/*
	** pas de verif sur taille de buffer dest
	** pas de verif sur nullite des pointeurs
	*/
}

int	ft_test_strlcpy(void)
{
	char	*src;
	size_t	size;
	size_t	res;
	int		is_valid;

	is_valid = 1;	
	char	dst[42];
	size = 42;
	src = "hello world!";
	res = ft_strlcpy(dst, src, size);
	printf("ft_strlcpy: %s, %ld\n", dst, res);
	if (strcmp(dst, "hello world!") || res != 12)
		is_valid = 0;
	
	char	dst2[10];
	size = 10;	
	res = ft_strlcpy(dst2, src, size);
	printf("ft_strlcpy: %s, %ld\n", dst2, res);
	if (strcmp(dst2, "hello wor") || res != 12)
		is_valid = 0;
		
	char	dst3[10];
	size = 0;	
	res = ft_strlcpy(dst3, src, size);
	printf("ft_strlcpy: %s, %ld\n", dst3, res);
	if (strcmp(dst3, "") || res != 12)
		is_valid = 0;
	return (is_valid);
	/*
	** pas de gestion des pointeurs null 
	** si size est neg, il est converti en un tres grand entier pos
	*/
}

int	ft_test_strlcat(void)
{
	int		is_valid;
	char	*src;
	
	size_t	size;
	size_t res;
	
	is_valid = 1;
	size =  60;
	src = "mon dodo!";
	char dst[20] = "bravo ";
	res = ft_strlcat(dst, src, size);	
	printf("ft_strlcat: %s, %ld\n", dst, res);
	if (strcmp(dst, "bravo mon dodo!") || res != 15)
		is_valid = 0;
		
	size =  0;
	char dst2[20] = "bravo ";
	res = ft_strlcat(dst2, src, size);	
	printf("ft_strlcat: %s, %ld\n", dst2, res);
	if (strcmp(dst2, "bravo ") || res != 9)
		is_valid = 0;
		
	size =  2;
	char dst3[20] = "bravo ";
	res = ft_strlcat(dst3, src, size);	
	printf("ft_strlcat: %s, %ld\n", dst3, res);
	if (strcmp(dst3, "bravo ") || res != 11)
		is_valid = 0;
	
	size =  10;
	char dst4[20] = "bravo ";
	res = ft_strlcat(dst4, src, size);	
	printf("ft_strlcat: %s, %ld\n", dst4, res);
	if (strcmp(dst4, "bravo mon") || res != 15)
		is_valid = 0;
	return (is_valid);
	
	/*
	** verif terminateur et arret aussi a *src
	** pas de gestion de nullite des pointeurs ni size
	*/
}

void	ft_test_strchr(void)
{
	char	*s;
	char	*res;
	char	c;

	s = "whaou";
	c = '\0';
	res = strchr(s, c);
	if (!res)
		printf("strchr: 1er: null!\n");
	else
		printf("strchr: 1er: %s\n", res);
	res = ft_strchr(s, c);
	if (!res)
		printf("ft_strchr: 1er: null!\n");
	else
		printf("ft_strchr: 1er: %s\n", res);	
	printf("\n");

	s = "je veux le x";
	c = 'x';	
	res = strchr(s, c);
	if (!res)
		printf("strchr: 2nd: null!\n");
	else
		printf("strchr: 2nd: %s\n", res);	
	res = ft_strchr(s, c);
	if (!res)
		printf("ft_strchr: 2nd: null!\n");
	else
		printf("ft_strchr: 2nd: %s\n", res);	
	printf("\n");
	
	s = "je veux le x"; 
	c = 'z';	
	res = strchr(s, c);
	if (!res)
		printf("strchr: 3eme: null!\n");
	else
		printf("strchr: 3eme: %s\n", res);
	res = ft_strchr(s, c);
	if (!res)
		printf("ft_strchr: 3eme: null!\n");
	else
		printf("ft_strchr: 3eme: %s\n", res);
	printf("\n");
	
	s = "";
	c = 'x';	
	res = strchr(s, c);
	if (!res)
		printf("strchr: 4eme: null!\n");
	else
		printf("strchr: 4eme: %s\n", res);
	res = ft_strchr(s, c);
	if (!res)
		printf("ft_strchr: 4eme: null!\n");
	else
		printf("ft_strchr: 4eme: %s\n", res);
		
	/*
	s = NULL;
	c = 'x';
	res = strchr(s, c);
	if (!res)
		printf("strchr: 5eme: null!\n");
	else
		printf("strchr: 5eme: %s\n", res);
	res = ft_strchr(s, c);
	if (!res)
		printf("ft_strchr: 5eme: null!\n\n");
	else
		printf("ft_strchr: 5eme: %s\n\n", res);		
	*/
}

void	ft_test_strrchr(void)
{
	char	*s;
	char	*res;
	char	c;

	s = "whaou";
	c = '\0';
	res = strrchr(s, c);
	if (!res)
		printf("strrchr: 1er: null!\n");
	else
		printf("strrchr: 1er: %s\n", res);
	res = ft_strrchr(s, c);
	if (!res)
		printf("ft_strrchr: 1er: null!\n");
	else
		printf("ft_strrchr: 1er: %s\n", res);
	printf("\n");
	
	s = "je veux le x";
	c = 'x';	
	res = strrchr(s, c);
	if (!res)
		printf("strrchr: 2nd: null!\n");
	else
		printf("strrchr: 2nd: %s\n", res);
	res = ft_strrchr(s, c);
	if (!res)
		printf("ft_strrchr: 2nd: null!\n");
	else
		printf("ft_strrchr: 2nd: %s\n", res);
	printf("\n");
	
	s = "je veux le x";
	c = 'z';
	res = strrchr(s, c);
	if (!res)
		printf("strrchr: 3eme: null!\n");
	else
		printf("strrchr: 3eme: %s\n", res);
	res = ft_strrchr(s, c);
	if (!res)
		printf("ft_strrchr: 3eme: null!\n");
	else
		printf("ft_strrchr: 3eme: %s\n", res);
	printf("\n");
	
	s = "";
	c = 'x';
	res = strrchr(s, c);
	if (!res)
		printf("strrchr: 4eme: null!\n");
	else
		printf("strrchr: 4eme: %s\n", res);
	res = ft_strrchr(s, c);
	if (!res)
		printf("ft_strrchr: 4eme: null!\n");
	else
		printf("ft_strrchr: 4eme: %s\n", res);
	printf("\n");
	
	s = "je veux le x";
	c = 'j';
	res = strrchr(s, c);
	if (!res)
		printf("strrchr: 4eme: null!\n");
	else
		printf("strrchr: 4eme: %s\n", res);
	res = ft_strrchr(s, c);
	if (!res)
		printf("ft_strrchr: 4eme: null!\n");
	else
		printf("ft_strrchr: 4eme: %s\n", res);

	/*
	s = NULL;
	c = 'x';
	res = strrchr(s, c);
	if (!res)
		printf("strrchr: 5eme: null!\n");
	else
		printf("strrchr: 5eme: %s\n", res);
	res = ft_strrchr(s, c);
	if (!res)
		printf("ft_strrchr: 5eme: null!\n");
	else
		printf("ft_strrchr: 5eme: %s\n", res);
	*/
}

void	ft_test_strncmp(void)
{
	char	*s1;
	char	*s2;
	int		res;
	size_t	n;

	n = 42; // try neg pos norm
	s1 = "abcezfder";
	s2 = "abcezfderhj";	
	res = strncmp(s1, s2, n);
	printf("strncmp: %d\n", res);
	res = ft_strncmp(s1, s2, n);
	printf("ft_strncmp: %d\n", res);
	printf("\n");
	
	s1 = "abcdzfderhhe";
	s2 = "abcdzfderh";
	res = strncmp(s1, s2, n);
	printf("strncmp: %d\n", res);
	res = ft_strncmp(s1, s2, n);
	printf("ft_strncmp: %d\n", res);
	printf("\n");
	
	s1 = "abcdzfderhhe";
	s2 = "akcdzfderh";
	res = strncmp(s1, s2, n);
	printf("strncmp: %d\n", res);
	res = ft_strncmp(s1, s2, n);
	printf("ft_strncmp: %d\n", res);
	printf("\n");
	
	s1 = "abcdzfderh";
	s2 = "abcdzfderh";
	res = strncmp(s1, s2, n);
	printf("strncmp: %d\n", res);
	res = ft_strncmp(s1, s2, n);
	printf("ft_strncmp: %d\n", res);
	/*
	s1 = NULL;
	s2 = NULL;
	res = strncmp(s1, s2, 6);
	printf("strncmp: %d\n", res);
	res = ft_strncmp(s1, s2, 6);
	printf("ft_strncmp: %d\n", res);
	*/
}

int	ft_test_memchr(void)
{
	char	*s;
	void	*res;
	size_t	n;
	int		c;
	int		is_valid;
		
	is_valid = 1;
	n = 4;
	c = 'v';
	res = NULL;	
	s = "je veux trouver le v";
	res = memchr(s, c, n);
	if (!res)
		printf("memchr: null\n");
	else
		printf("memchr: %s\n", res);
		
	n = 4;
	c = 'v';
	res = NULL;	
	s = "je veux trouver le v";
	res = ft_memchr(s, c, n);
	if (!res)
		printf("ft_memchr: null\n\n");
	else
		printf("ft_memchr: %s\n\n", res);	
	if (strcmp(res, "veux trouver le v"))
		is_valid = 0;	

	n = 10;
	c = 'z';
	res = NULL;	
	s = "je veux trouver le v";
	res = memchr(s, c, n);
	if (!res)
		printf("memchr: 2nd: null\n");
	else
		printf("memchr: 2nd: %s\n", res);

	n = 10;
	c = 'z';
	res = NULL;	
	s = "je veux trouver le v";
	res = ft_memchr(s, c, n);
	if (!res)
		printf("ft_memchr: 2nd: null\n\n");
	else
		printf("ft_memchr: 2nd: %s\n\n", res);
	if (res)
		is_valid = 0;
		
	n = 3;
	c = 'v';
	res = NULL;	
	s = "je veux trouver le v";
	res = memchr(s, c, n);
	if (!res)
		printf("memchr: 3eme: null\n");
	else
		printf("memchr: 3eme: %s\n", res);
		
	n = 3;
	c = 'z';
	res = NULL;	
	s = "je veux trouver le v";
	res = ft_memchr(s, c, n);
	if (!res)
		printf("ft_memchr: 3eme: null\n");
	else
		printf("ft_memchr: 3eme: %s\n", res);
	if (res)
		is_valid = 0;
	return (is_valid);
		
	/*
	** pas de verification de nullite de pointeur
	** si c est vide avert compilateur puis retour null
	** pas de verif sur n
	** l'iteration doit se faire sur n uniquement
	*/		
}

int	ft_test_memcmp(void)
{
	int		is_valid;
	char 	*s1;
	char	*s2;
	int 	res;
	int		res2;
	size_t	n;
	
	is_valid = 1;   
	/*			//gerer nmax
	res = 0;
	n = -10;
	s1 = "houla";
	s2 = "houla";	
	res = ft_memcmp(s1, s2, n);
	printf("ft_memcmp: %d\n", res);
	
	res = 0;
	n = -10;
	s1 = "houla";
	s2 = "houla";
	res = memcmp(s1, s2, n);
	printf("memcmp: %d\n", res);
	printf("\n");
	*/
	
	res = 0;
	n = 0;
	s1 = "aoula";
	s2 = "houla";	
	res = ft_memcmp(s1, s2, n);
	printf("ft_memcmp: %d\n", res);
	
	res2 = 0;
	n = 0;
	s1 = "aoula";
	s2 = "houla";
	res2 = memcmp(s1, s2, n);
	printf("memcmp: %d\n", res2);
	printf("\n");
	if (res != res2)
		is_valid = 0;
		
	res = 0;
	n = 6;
	s1 = "houlaa";
	s2 = "houla";	
	res = ft_memcmp(s1, s2, n);
	printf("ft_memcmp: %d\n", res);
	
	res2 = 0;
	n = 6;
	s1 = "houlaa";
	s2 = "houla";
	res2 = memcmp(s1, s2, n);
	printf("memcmp: %d\n", res2);
	printf("\n");
	if (res != res2)
		is_valid = 0;
		
	res = 0;
	n = 6;
	s1 = "houla";
	s2 = "houlaa";	
	res = ft_memcmp(s1, s2, n);
	printf("ft_memcmp: %d\n", res);
	
	res2 = 0;
	n = 6;
	s1 = "houla";
	s2 = "houlaa";
	res2 = memcmp(s1, s2, n);
	printf("memcmp: %d\n", res2);
	printf("\n");
	if (res != res2)
		is_valid = 0;
		
	res = 0;
	n = 3;
	s1 = "hogla";
	s2 = "houlaa";	
	res = ft_memcmp(s1, s2, n);
	printf("ft_memcmp: %d\n", res);
	
	res2 = 0;
	n = 3;
	s1 = "hogla";
	s2 = "houlaa";
	res2 = memcmp(s1, s2, n);
	printf("memcmp: %d\n", res2);
	if (res != res2)
		is_valid = 0;
	return (is_valid);

	/*
	** pas de gestion des pointeurs null
	** attention n ne dois pas depasser LONG_MAX
	*/
}

int	ft_test_strnstr(void)
{
	int		is_valid;
	char	*big;
	char	*little;
	char	*res;
	size_t 	len;
	
	is_valid = 1;
	/*
	res = NULL;
	big = "crois tu etre en train de respirer de l'air?";
	little = "train";
	len = 5;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: %s\n", res);
		
	res = NULL;    
	big = "crois tu etre en train de respirer de l'air?";
	little = "train"; //
	len = 2;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: %s\n", res);
	
	res = NULL;    
	big = "crois tu etre en train de respirer de l'air?";
	little = ""; //
	len = 5;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: %s\n", res);
	
	res = NULL;    
	big = "crois tu etre en train de respirer de l'air?";
	little = "air? "; //
	len = 4;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: %s\n", res);
	
	res = NULL;    // return null , normal ?
	big = "";
	little = "train";
	len = 5;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: %s\n", res);	
	
	res = NULL; // return null , normal ?
	big = "crois tu etre en train de respirer de l'air?";
	little = "train";
	len = 6;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: %s\n", res);
	*/

	res = NULL;
	big = "crois tu etre en train de respirer de l'air?";
	little = "train";
	len = 45;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: %s\n", res);
	if (strcmp(res,"train de respirer de l'air?"))
		is_valid = 0;
	
	res = NULL;    
	big = "crois tu etre en train de respirer de l'air?"; // verif libft war
	little = "train"; 
	len = 22; 
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: 2nd: %s\n", res);
	if (strcmp(res,"train de respirer de l'air?"))
		is_valid = 0;
		
	res = NULL;    
	big = "crois tu etre en train de respirer de l'air?";
	little = "train"; 
	len = 21; 
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: 3eme: %s\n", res);
	if (res)
		is_valid = 0;
		
	res = NULL;    
	big = "crois tu etre en train de respirer de l'air?";
	little = "c"; 
	len = 1;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: 4eme: %s\n", res);
	if (strcmp(res,"crois tu etre en train de respirer de l'air?"))
		is_valid = 0;
		
	res = NULL;    
	big = "crois tu etre en train de respirer de l'air?";
	little = ""; 
	len = 5;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: 5eme: %s\n", res);
	if (strcmp(res,"crois tu etre en train de respirer de l'air?"))
		is_valid = 0;
		
	res = NULL;    
	big = "crois tu etre en train de respirer de l'air?";
	little = "air? "; 
	len = 43;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: 6eme: %s\n", res);
	if (res)
		is_valid = 0;
		
	res = NULL;    
	big = "";
	little = "train";
	len = 5;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: 7eme: %s\n", res);	
	if (res)
		is_valid = 0;
		
	res = NULL; 
	big = "crois tu etre en train de respirer de l'air?";
	little = "train";
	len = 50;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: 8eme: %s\n", res);
	if (strcmp(res,"train de respirer de l'air?"))
		is_valid = 0;
		
	res = NULL; 
	big = "crois tu etre en train de respirer de l'air?";
	little = "c";
	len = -10;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: 9eme: %s\n", res);
	if (strcmp(res,"crois tu etre en train de respirer de l'air?"))
		is_valid = 0;
		
	res = NULL; 
	big = "crois tu etre en train de respirer de l'air?";
	little = "tr";
	len = -10;
	res = ft_strnstr(big, little, len);
	printf("ft_strnstr: 10eme: %s\n", res);
	if (strcmp(res,"tre en train de respirer de l'air?"))
		is_valid = 0;
	return (is_valid);
	
	/*
	** accent ? si len depasse la taille reele de little > null et la vraie ?
	*/
}

int	ft_test_atoi()
{
	int		is_valid;
	char	*nptr;
	int 	res;
	int 	res2;
	
	is_valid = 1;
	
	nptr = "420";
	res = -42;
	res = atoi(nptr);
	printf("1: atoi: %d\n", res);	
	
	nptr = "420";
	res2 = -42;
	res2 = ft_atoi(nptr);
	printf("1: ft_atoi: %d\n\n", res2);
	if (res != res2)
		is_valid = 0;
	
	nptr = "42k";
	res = -42;
	res = atoi(nptr);
	printf("2: atoi: %d\n", res);	
	
	nptr = "42k";
	res2 = -42;
	res2 = ft_atoi(nptr);
	printf("2: ft_atoi: %d\n\n", res2);	
	if (res != res2)
		is_valid = 0;
		
	nptr = "  +  42";
	res = -42;
	res = atoi(nptr);
	printf("3: atoi: %d\n", res);
	
	nptr = "  +  42";
	res2 = -42;
	res2 = ft_atoi(nptr);
	printf("3: ft_atoi: %d\n\n", res2);
	if (res != res2)
		is_valid = 0;
		
	nptr = "  -  42";
	res = -42;
	res = atoi(nptr);
	printf("4: atoi: %d\n", res);
	
	nptr = "  -  42";
	res2 = -42;
	res2 = ft_atoi(nptr);
	printf("4: ft_atoi: %d\n\n", res2);
	if (res != res2)
		is_valid = 0;
		
	nptr = "   \t \n \v \f \r  4224";
	res = -42;
	res = atoi(nptr);
	printf("5: atoi: %d\n", res);
	
	nptr = "   \t \n \v \f \r  4224";
	res2 = -42;
	res2 = ft_atoi(nptr);
	printf("5: ft_atoi: %d\n\n", res2);
	if (res != res2)
		is_valid = 0;
		
	nptr = "42\th24";
	res = -42;
	res = atoi(nptr);
	printf("6: atoi: %d\n", res);
	
	nptr = "42\th24";
	res2 = -42;
	res2 = ft_atoi(nptr);
	printf("6: ft_atoi: %d\n\n", res2);
	if (res != res2)
		is_valid = 0;
		
	nptr = "+42\th24";
	res = -42;
	res = atoi(nptr);
	printf("7: atoi: %d\n", res);
	
	nptr = "+42\th24";
	res2 = -42;
	res2 = ft_atoi(nptr);
	printf("7: ft_atoi: %d\n\n", res2);
	if (res != res2)
		is_valid = 0;
		
	nptr = "-42\th24";
	res = -42;
	res = atoi(nptr);
	printf("8: atoi: %d\n", res);
	
	nptr = "-42\th24";
	res2 = -42;
	res2 = ft_atoi(nptr);
	printf("8: ft_atoi: %d\n", res2);
	if (res != res2)
		is_valid = 0;
	return (is_valid);
}

int	ft_test_calloc(void)
{
	char	*ptr;	
	size_t 	nmemb;
	size_t	size;
	int		is_valid;
	int		count;

	is_valid = 1;
	size = 0;
	nmemb = 0;
	ptr = NULL;
	ptr = (char *) ft_calloc(nmemb, size);
	if (!ptr)
		is_valid = 0;
	
	size = SIZE_MAX;
	nmemb = 2;
	ptr = NULL;
	ptr = (char *) ft_calloc(nmemb, size);
	if (ptr)
		is_valid = 0;
	
	size = 2;
	nmemb = SIZE_MAX;
	ptr = NULL;
	ptr = (char *) ft_calloc(nmemb, size);
	if (ptr)
		is_valid = 0;
	
	size = SIZE_MAX;
	nmemb = SIZE_MAX;
	ptr = NULL;
	ptr = (char *) ft_calloc(nmemb, size);
	if (ptr)
		is_valid = 0;
	
	count = 0;
	size = sizeof(char);
	nmemb = 1024;	
	ptr = NULL;
	ptr = (char *) ft_calloc(nmemb, size);
	if (!ptr)
		is_valid = 0;	
	while (!*ptr++)		
		count++;
	printf("ft_calloc: %d\n", count);
	if (count < nmemb)
		is_valid = 0;		
	return (is_valid);
}

int	ft_test_strdup(void)
{
	int		is_valid;

	is_valid = 1;
	char	*s;	
	char	*s_dup;
	size_t	s_dup_len;	
	s_dup_len = 0;
	s = "tank, charge le programme de saut";
	s_dup = NULL;
	s_dup = strdup(s);
	s_dup_len = strlen(s_dup);
	printf("strdup: %s\n", s_dup);	
	printf("ft_strdup: %s, %ld\n", s_dup, s_dup_len);
	
	char	*s2;
	char	*s_dup2;
	size_t	s_dup_len2;
	s2 = "tank, charge le programme de saut";
	s_dup2 = NULL;
	s_dup_len2 = 0;
	s_dup2 = ft_strdup(s2);
	s_dup_len2 = strlen(s_dup2);
	printf("ft_strdup: %s, %ld\n", s_dup2, s_dup_len2);
	
	if (strcmp(s_dup, s_dup2) || strlen(s_dup) != strlen(s_dup2))
		is_valid = 0;	
		
	s = "";
	s_dup = NULL;
	s_dup_len = 42;
	s_dup = strdup(s);
	s_dup_len = strlen(s_dup);		
	printf("ft_strdup: %s, %ld\n", s_dup, s_dup_len);	
		
	s2 = "";
	s_dup2 = NULL;
	s_dup_len2 = 42;
	s_dup2 = strdup(s2);
	s_dup_len2 = strlen(s_dup2);		
	printf("ft_strdup: %s, %ld\n", s_dup2, s_dup_len2);
	
	if (strcmp(s_dup, s_dup2) || strlen(s_dup) != strlen(s_dup2))
		is_valid = 0;
	return (is_valid);
	
	/*
	s = NULL;
	s_dup = NULL;
	s_dup = strdup(s);
	printf("strdup: %s\n", s_dup);	
		
	s2 = NULL;
	s_dup2 = NULL;
	s_dup2 = ft_strdup(s2);
	printf("ft_strdup: %s\n", s_dup2);
	printf("\n");
	if (strcmp(s_dup, s_dup2))
		is_valid = 0;
	*/
	 	
	/* 
	** pas de gestion de nullite de pointeur
	*/
}

void	ft_test_strcmp(void)
{
	char	*s1;
	char	*s2;
	int		res;

	s1 = "abcdzfder";
	s2 = "abcdzfderh";
	res = strcmp(s1, s2);
	printf("strcmp: %d\n", res);
	res = ft_strcmp(s1, s2);
	printf("ft_strcmp: %d\n", res);
	printf("\n");
	
	s1 = "abcdzfderhh";
	s2 = "abcdzfderh";
	res = strcmp(s1, s2);
	printf("strcmp: %d\n", res);
	res = ft_strcmp(s1, s2);
	printf("ft_strcmp: %d\n", res);
	printf("\n");
	
	s1 = "abcdzfderh";
	s2 = "abcdzfderh";
	res = strcmp(s1, s2);
	printf("strcmp: %d\n", res);
	res = ft_strcmp(s1, s2);
	printf("ft_strcmp: %d\n", res);
	printf("\n");
	
	s1 = "abczzfderh";
	s2 = "abcdzfderh";
	res = strcmp(s1, s2);
	printf("strcmp: %d\n", res);
	res = ft_strcmp(s1, s2);
	printf("ft_strcmp: %d\n", res);
	
	/*
	s1 = NULL;
	s2 = NULL;
	res = strcmp(s1, s2);
	printf("strcmp: %d\n", res);
	res = ft_strcmp(s1, s2);  
	printf("ft_strcmp: %d\n", res);
	*/
}

int	ft_test_isspace(void)
{
	int	is_valid;
	int	res;
	int	c;
	
	is_valid = 1;
	res = 42;
	c = 32;		
	res = ft_isspace(c);
	printf("ft_isspace: c: %d, %d\n", c, res);
	if(!res)
		is_valid = 0;
	c = 9;
	while (c <= 13)
	{
		res = 42;			
		res = ft_isspace(c);
		printf("ft_isspace: c: %d, %d\n", c, res);
		if (!res)
			is_valid = 0;
		c++;		
	}
	
	c = 2;
	while (c <= 8)
	{
		res = 42;			
		res = ft_isspace(c);
		printf("ft_isspace: c: %d, %d\n", c, res);
		if (res)
			is_valid = 0;
		c++;		
	}
	
	c = 14;
	while (c <= 16)
	{
		res = 42;			
		res = ft_isspace(c);
		printf("ft_isspace: c: %d, %d\n", c, res);
		if (res)
			is_valid = 0;
		c++;		
	}
	return (is_valid);	
}

int	main(void)
{
	displayTestSeparator("Is ?", 33);
	if (ft_test_isalpha() && ft_test_isdigit() && ft_test_isalnum()
			&& ft_test_isascii() && ft_test_isprint())
		display_valid();
	else 
		display_novalid();
		
	displayTestSeparator("To", 33);
	if (ft_test_toupper() && ft_test_tolower())
		display_valid();
	else 
		display_novalid();		
	
	displayTestSeparator("strlen", 36);
	ft_test_strlen();
	displayTestSeparator("memset", 36);
	ft_test_memset();
	displayTestSeparator("bzero", 36);
	ft_test_bzero();
	
	displayTestSeparator("memcpy", 36);
	if(ft_test_memcpy())
		display_valid();
	else 
		display_novalid();
	
	displayTestSeparator("memmove", 36);
	if(ft_test_memmove())
		display_valid();
	else 
		display_novalid();
		
	displayTestSeparator("strlcpy", 36);
	if(ft_test_strlcpy())
		display_valid();
	else 
		display_novalid();
		
	displayTestSeparator("strchr", 36);
	ft_test_strchr();
	displayTestSeparator("strrchr", 36);
	ft_test_strrchr();
	displayTestSeparator("strncmp", 36);
	ft_test_strncmp();
	displayTestSeparator("strcmp", 35);
	ft_test_strcmp();
	
	displayTestSeparator("strlcat", 36);
	if(ft_test_strlcat())
		display_valid();
	else 
		display_novalid();	
		
	displayTestSeparator("memchr", 36);
	if(ft_test_memchr())
		display_valid();
	else 
		display_novalid();
		
	displayTestSeparator("memcmp", 36);	
	if(ft_test_memcmp())
		display_valid();
	else 
		display_novalid();
	
		displayTestSeparator("atoi", 36);	
	if(ft_test_atoi())
		display_valid();
	else 
		display_novalid();
		
	displayTestSeparator("strnstr", 36);	
	if(ft_test_strnstr())
		display_valid();
	else 
		display_novalid();
		
	displayTestSeparator("calloc", 36);	
	if(ft_test_calloc())
		display_valid();
	else 
		display_novalid();
		
	displayTestSeparator("strdup", 36);	
	if(ft_test_strdup())
		display_valid();
	else 
		display_novalid();		
	
	displayTestSeparator("isspace", 35);	
	if(ft_test_isspace())
		display_valid();
	else 
		display_novalid();		
		
	displayTestSeparator("end", 35);	
	return (0);
}
