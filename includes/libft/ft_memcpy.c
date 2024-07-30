/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:23:05 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/20 20:20:01 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h> 
** SYNOPSIS: copy memory from source to destination
**
** DESCRIPTION:
**    The ft_memcpy() function copies a block of memory from the source location (src) to the destination location (dst).
**    It takes three arguments: a pointer to the destination memory (dst), a pointer to the source memory (src), and the number of bytes (n) to copy from src to dst.
*/

#include"libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *dest_c;
    unsigned char *src_c;
    size_t i;
    
    i = 0;
    dest_c = (unsigned char *)dest;
    src_c = (unsigned char *) src;
    while(n > 0)
    {
        dest_c[i] = src_c[i];
            i++;
            n--;
    }
    return(dest);
}

// int main(void)
// {
//     char dest[3];
//     const char *src = "Hola, como estas";
//     size_t i;
    
//     i = ft_strlen(src);
//     ft_memcpy(dest, src, i);

//     printf("This is the result: %s\n", dest);  
// }
