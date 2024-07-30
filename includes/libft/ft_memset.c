/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:22:41 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/22 16:13:07 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: fill memory with a constant byte
**
** DESCRIPTION:
**      The memset() function fills the first 'n' bytes of the memory area pointed to by 's' with the constant byte 'c'.
**
**      It is commonly used to initialize or reset memory areas, including arrays, structures, or other data structures.
**
**      The return value of memset() is the pointer to the memory area 's'.
*/

#include"libft.h"
//#include<string.h>

void	*ft_memset(void *b, int c, size_t len)
{
    char *p;
    
    p = (char *)b;

    while(len > 0)
    {
        p[len -1] = c;
        len--;
    }
    return b;
}

/*int main(void)
{
    char str[30];
    int c = 'H';
    ft_memset(str, c, 45);
    //memset(str, c, 45);
    printf("This is the result %s\n", str);
}*/