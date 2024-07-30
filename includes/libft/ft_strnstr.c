/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:35:16 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/20 20:21:24 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: substring search with size limit
**
** DESCRIPTION:
**      The strnstr() function searches for the first occurrence of the substring 'needle' within the string 'haystack', limited to 'len' characters.
**      It returns a pointer to the first occurrence of 'needle' within 'haystack', or a null pointer if 'needle' is not found within the first 'len' characters of 'haystack'.
**
**      The 'haystack' and 'needle' parameters should be null-terminated strings.
**      The 'len' parameter specifies the maximum number of characters to search within 'haystack'.
**/

#include "libft.h"

// other way to do it
/*int ft_strncmp2(const char *s1, const char *s2, size_t n)
{
    if (!n)
        return (0);
    while (*s1 == *s2++ && --n > 0)
        if (!*s1++)
            return (0);
    return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}*/

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  i;
    size_t  length;
    char    *small;
    char    *large;

    if(*little =='\0')
        return((char *)big);


    large = (char *)big;
    small = (char *)little;

    i = 0;
    length = ft_strlen(small);

    while (large[i] && (i + length) <= len)
    {
        if (ft_strncmp((large + i), small, length) == 0)
            return (large + i);
        i++;
    }
    return(NULL);
}

/*int main(void)
{
    const char str1[] = "Hola como estas";
    const char str2[] = "";

    printf("This is the result: %s\n", ft_strnstr(str1, str2, 20));
    return(0);
}

char    *h;

h = "hello";

h = 0x103;

i = 3

0
'\0' -> null terminator -> 0 on ascii
NULL -> 0x0
*/