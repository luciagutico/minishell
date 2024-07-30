/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 15:55:53 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/24 15:20:40 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


/*
** LIBRARY: <string.h>
** SYNOPSIS: string copy with size limit
**
** DESCRIPTION:
**      The strlcpy() function copies a string from source 'src' to destination 'dest' while ensuring that the resulting string is null-terminated.
**      It copies at most 'size-1' characters from 'src' to 'dest' and null-terminates 'dest'.
**      If the length of 'src' is greater than or equal to 'size', only 'size-1' characters are copied, and 'dest' is null-terminated.
**      The return value of strlcpy() is the length of 'src' (not including the null-terminator) that would have been copied if 'dest' had been large enough.
**
**      The strlcpy() function is commonly used in Unix-based systems and provides a safer way to copy strings by avoiding buffer overflows.
*/
#include"libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t i;

    i = 0;
    if(size == 0)
    {
        while(src[i])
            i++;
        return(i);
    }
    while(i < size -1 && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    if(i < size)
        dest[i] = '\0';
    while (src[i] != '\0')
        i++;
    return(i);

}

/*int main(void)
{
    size_t copy;
    char  dest[20];
    const char *src = "Txt mf30399..//p..yyeu4444444444444444";

    copy = ft_strlcpy(dest, src, sizeof(dest));

    printf("String copied:%s\n", dest);
    printf("Legth of the source: %zu\n", ft_strlen(src));
    printf("Characteres copied from the source str: %zu\n", copy);

}*/