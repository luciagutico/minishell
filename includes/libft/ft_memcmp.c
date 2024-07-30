/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 18:20:52 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/20 20:19:53 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include"libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1;
    unsigned char *str2;
    size_t i;

    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    i = 0;
    while(i < n)
    {
        if(str1[i] != str2[i])
        {
            printf("%d %d\n", str1[i], str2[i]);
            return(str1[i] - str2[i]);
        }
            i++;
    }
    return(0);
}

// int main(void)
// {
//     char *str1;
//     char *str2;
//     int n;
//     int result;

//     str1 = "Pinapple";
//     str2 = "apple";
//     n = 4;
//     result = ft_memcmp(str1, str2, n);
    
    
//     printf("This is the result: %d\n", result);
// }
