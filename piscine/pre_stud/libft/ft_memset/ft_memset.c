/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:02:41 by seblin            #+#    #+#             */
/*   Updated: 2023/09/15 10:31:41 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void    ft_print_mem(void *s, size_t n)
{
    int     *s_cast = (int *) s;
    
    while (n-- > 0)        
        write(1, &(char) {*s_cast++ + '0'}, 1);  
    write(1, "\n", 1);    
}

void    *ft_memsetgood(void *s, int c, size_t n)
{
    int     *s_cast = (int*) s;
    
    while (n-- > 0)    
        *s_cast++ = c; 
    return (s);
}

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *s_cast;
    
    s_cast = (unsigned char*) s;
   // c &= 0xFF; c = c & 0xFF;
    while (n-- > 0)    
        *s_cast++ = c; 
    return (s);
}

int     main(void)
{       
   // int test2[4] = {4, 2, 1, 6};
    int test3[2][4] = {{4, 2, 1, 6},
                       {8, 1, 7, 5}};                     
    //ft_print_mem(&test3[0][0], sizeof (test3) / sizeof (int));
    for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < 4; j++) 
            printf("before:%d", test3[i][j]);
    }
    printf("\n");
    memset(test3, 160, sizeof (test3));
    //int t5 = *t4;
    for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < 4; j++) 
        {
            printf("pf MEM:%d", (char) {test3[i][j]});
            write(1, &(char) {test3[i][j] + 48}, 1);
        }
    }
    write(1, "\n**\n", 4);
    printf("\n");
    ft_memset(test3, 160, sizeof (test3));// / sizeof (int));
        for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < 4; j++) 
        {
            printf("pf ft_mem:%d", (char) {test3[i][j]});
            write(1, &(char) {test3[i][j] + 48}, 1);
        }
    }
    //ft_print_mem(&test3[0][0], sizeof (test3) / sizeof (int));
    /*
    int num;
    int i = 0;
    while (i < 4)
    {
        num = test2[i] + 48;
        write(1, &num, 1);
        //printf("%d\n", test2[i]);
        i++;
    } 
    i = 0;
    while (i < 4)
     {
        num = test2[i] + 48;
        //write(1, &num, 1);
        printf("pf:%d\n", test2[i]);
        i++;
    }     */
    return (0);
}