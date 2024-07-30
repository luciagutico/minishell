/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:34:40 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/18 20:10:56 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: search for a byte in a memory block
**
** DESCRIPTION:
**      The memchr() function searches for the first occurrence of the byte 'c' in the first 'n' bytes of the memory block pointed to by 's'.
**      It returns a pointer to the byte found or a null pointer if 'c' is not found within the specified memory block.
**
**      The function is often used to search for a specific character or byte in a memory buffer.
*/
#include"libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *block;
    unsigned char needle;
    size_t i;
    
    block = (unsigned char *)s;
    needle = (unsigned char)c;
    i = 0;
    while(i < n)
    {
        if(block[i] == needle)
            return(block + i);
        i++;
    }
    return(NULL);
}

// int main(void)
// {
//     char *str;
//     int c;
//     size_t n;
//     char *result1;
//     char *result2;
    
//     str = "66776";
//     c = 'b';
//     n = 6;
    
//     result1 = memchr(str, c, n);
//     result2 = ft_memchr(str, c, n);
    
//     printf("This is the original result:\t%s\n", result1);
//     printf("This is the my result:\t\t%s\n", result2);
// }


