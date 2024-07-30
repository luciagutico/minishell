/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:22:44 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/15 15:29:05 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <strings.h>
** SYNOPSIS: zero out a block of memory
**
** DESCRIPTION:
**    The bzero() function is used to set a block of memory to zero.
**    It takes two arguments, a pointer to the memory block (s) and the size (n) in bytes to be set to zero.
**    The function is commonly used to clear out sensitive information stored in memory or to initialize a block of memory to zero.
*/

#include"libft.h"

void ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

/*int main(void)
{

    char str[5];
    
    ft_bzero(str, 20);
    printf("This is the result: %s\n", str);
    
}*/



