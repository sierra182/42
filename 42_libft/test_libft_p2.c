/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:09:19 by svidot            #+#    #+#             */
/*   Updated: 2023/10/11 11:37:36 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_sep.c"
#include "libft.h"
#include <stdio.h>
#include <limits.h>

int	ft_test_substr(void)
{
	int				is_valid;
	char			*s; 
	char			*sub_s;
	unsigned int	start;	
	size_t			len;
	
	is_valid = 1;
	s = "la fonction premiere de l'elu est de retourner a la source";
	start = 3;
	len = 8;
	sub_s = NULL;
	sub_s = ft_substr(s, start, len);
	printf("1 ft_substr: %s\n", sub_s);
	
	s = "la fonction premiere de l'elu est de retourner a la source";
	start = 1;
	len = 1;
	sub_s = NULL;
	sub_s = ft_substr(s, start, len);
	printf("2 ft_substr: %s\n", sub_s);
	
	s = "la fonction premiere de l'elu est de retourner a la source";
	start = 0;
	len = 1;
	sub_s = ft_substr(s, start, len);
	printf("3 ft_substr: %s\n", sub_s);

	s = "la fonction premiere de l'elu est de retourner a la source";
	start = 0;
	len = 0;
	sub_s = NULL;
	sub_s = ft_substr(s, start, len);
	printf("4 ft_substr: %s\n", sub_s);
		
	s = "la source";
	start = 3;
	len = 42;
	sub_s = NULL;
	sub_s = ft_substr(s, start, len);
	printf("5 ft_substr: %s\n", sub_s);
	
	s = "";
	start = 10;
	len = 10;
	sub_s = NULL;
	sub_s = ft_substr(s, start, len);
	printf("6 ft_substr: %s\n", sub_s);
	
	s = "la source";
	start = 22;
	len = 10;
	sub_s = NULL;
	sub_s = ft_substr(s, start, len);
	printf("7 ft_substr: %s\n", sub_s);
	
	s = "la source";
	start = 9;
	len = 10;
	sub_s = NULL;
	sub_s = ft_substr(s, start, len);
	printf("8 ft_substr: %s\n", sub_s);
	
	s = NULL;
	start = 3;
	len = 42;
	sub_s = NULL;
	sub_s = ft_substr(s, start, len);
	printf("9 ft_substr: %s\n", sub_s);
	return (is_valid);
	/*
	** faut il gerer le cas ou start commence apres la string, s null ?
	*/
}

int	ft_test_strjoin(void)
{
	int		is_valid;
	char	*s1;
	char	*s2;
	char	*s3;
	
	is_valid = 1;
	s1 = "bravo";
	s2 = " mon dodo";
	s3 = NULL;
	s3 = ft_strjoin(s1, s2);
	printf("1 ft_strjoin : %s\n", s3);
	
	s1 = "";
	s2 = " mon dodo";
	s3 = NULL;
	s3 = ft_strjoin(s1, s2);
	printf("2 ft_strjoin : %s\n", s3);
		
	s1 = "bravo";
	s2 = "";
	s3 = NULL;
	s3 = ft_strjoin(s1, s2);
	printf("3 ft_strjoin : %s\n", s3);
	
	s1 = "";
	s2 = "";
	s3 = NULL;
	s3 = ft_strjoin(s1, s2);
	printf("4 ft_strjoin : %s\n", s3);
	return (is_valid);
	/*
	** verif si besoin de verifier les pointeurs null.
	*/	
}

int	ft_test_strtrim(void)
{
	int		is_valid;
	char	*s;
	char	*set;
	char	*res;
	
	is_valid = 1;
	s = " yxx xthe matrix has youy yyyx  xy  ";
	set = " yx";
	res = NULL;
	res = ft_strtrim(s, set);
	printf("1 ft_strtrim: %s\n", res);

	s = " yxx xthe matrix has youy yyyx  xy  ";
	set = "";
	res = NULL;
	res = ft_strtrim(s, set);
	printf("2 ft_strtrim: %s\n", res);
	
s = " yxx xthe matrix has you";
	set = " yx";
	res = NULL;
	res = ft_strtrim(s, set);
	printf("3 ft_strtrim: %s\n", res);
	
	s = "";
	set = "";
	res = NULL;
	res = ft_strtrim(s, set);
	printf("4 ft_strtrim: %s\n", res);

	s = "";
	set = " xy";
	res = NULL;
	res = ft_strtrim(s, set);
	printf("5 ft_strtrim: %s\n", res);
	return (is_valid);
}

int	ft_test_split(void)
{
	int		is_valid;
	char	*s;
	char	**s_split;
		
	is_valid = 1;
	
	s = "xxsplitxmoixlaxfacexxx";		
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("%s\n", *s_split++);
	printf("\n");

	s = "xxsplitxxxmoixlaxxfacexxx";		
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("%s\n", *s_split++);
	printf("\n");
	
	s = "splitxmoixlaxface";
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("%s\n", *s_split++);
	printf("\n");

	s = "splitxmoixlaxfacex";
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("%s\n", *s_split++);
	printf("\n");
	
	s = "xsplitxmoixlaxface";
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("%s\n", *s_split++);
	printf("\n");	
	
	s = "xsplitxmoi";
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("%s\n", *s_split++);
	printf("\n");
		
	s = "splitmoilaface";
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("%s\n", *s_split++);
	printf("\n");
	
	s = "splitmoixxx";
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("%s\n", *s_split++);
	printf("\n");
	
	s = "xxsplitmoi";
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("%s\n", *s_split++);
	printf("\n");

	s = "";
	s_split = ft_split(s, 'x');
	while (*s_split)
		printf("l%s\n", *s_split++);
	printf("\n");
	
	return (is_valid);
}

int	ft_test_itoa(void)
{
	int		is_valid;
	char	*res;
	int		n;

	is_valid = 1;
	n = 428475;
	res = NULL;
	res = ft_itoa(n);
	printf("%s\n", res);
	
	n = -428475;
	res = NULL;
	res = ft_itoa(n);
	printf("%s\n", res);
	
	n = -0;
	res = NULL;
	res = ft_itoa(n);
	printf("%s\n", res);
	
	n = 2;
	res = NULL;
	res = ft_itoa(n);
	printf("%s\n", res);
	return (is_valid);
}

char	ft_mapi(unsigned int i, char c)
{
	return (c + i);
}

int	ft_test_ft_strmapi(void)
{
	int		is_valid;
	char	*s;
	char	*res;
	
	is_valid = 1;
	s = "bravo";
	res = NULL;	
	res = ft_strmapi(s, ft_mapi);	
	printf("%s\n", res);
	if (!res || strlen(res) != strlen(s) || strcmp(res, "bscys"))
		is_valid = 0;
	return (is_valid);	
}

void	ft_iteri(unsigned int i, char *c)
{
	*c = ft_mapi(i, *c);	
}

int	ft_test_striteri(void)
{
	int		is_valid;
	char	s[] = {'b', 'r', 'a', 'v', 'o', '\0'};
	
	is_valid = 1;
	ft_striteri(s, ft_iteri);
	printf("%s\n", s);
	if (strcmp(s, "bscys"))
		is_valid = 0;	
	return (is_valid);
}

int	ft_test_putendl_fd(void)
{
	int		is_valid;
	char	*s;
	int		fd;
	
	is_valid = 1;
	fd = 1;
	s = "encore bravo";
	ft_putendl_fd(s, fd);
	return (is_valid);
	/*
	** pour mon cas teste a la fois, putstr_fd et putchar_fd
	*/
}

int	ft_test_putnbr_fd(void)
{
	int	is_valid;
	int	n;
	int fd;
	
	is_valid = 1;
	n = INT_MIN; 
	fd = 1;
	ft_putnbr_fd(n, fd);
	printf("\n");
	
	n = 428475; 
	fd = 1;
	ft_putnbr_fd(n, fd);
	printf("\n");

	n = -428475; 
	fd = 1;
	ft_putnbr_fd(n, fd);
	printf("\n");

	n = 0; 
	fd = 1;
	ft_putnbr_fd(n, fd);
	printf("\n");

	n = INT_MAX; 
	fd = 1;
	ft_putnbr_fd(n, fd);
	printf("\n");
	
	n = 7; 
	fd = 1;
	ft_putnbr_fd(n, fd);
	printf("\n");
	return (is_valid);
}

int	main(void)
{
	displayTestSeparator("substr", 36);
	ft_test_substr();	
	displayTestSeparator("strjoin", 36);
	ft_test_strjoin();
	displayTestSeparator("strtrim", 36);
	ft_test_strtrim();
	displayTestSeparator("itoa", 36);
	ft_test_itoa();
	displayTestSeparator("strmapi", 36);
	if(ft_test_ft_strmapi())
		display_valid();
	else 
		display_novalid();
		
	displayTestSeparator("striteri", 36);
	if(ft_test_striteri())
		display_valid();
	else 
		display_novalid();
			
	displayTestSeparator("putendl_fd", 36);
	ft_test_putendl_fd();
	displayTestSeparator("putnbr_fd", 36);
	ft_test_putnbr_fd();
	displayTestSeparator("split", 36);
	ft_test_split();
}