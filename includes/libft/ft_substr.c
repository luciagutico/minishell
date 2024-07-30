/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 15:56:44 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/28 21:53:12 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ** LIBRARY: <string.h>
// ** SYNOPSIS: Extract a substring from a given string.
// **
// ** DESCRIPTION:
// **    The substr() function extracts a substring from the source string (str) based on the starting index (start) and length (length) provided.
// **
// ** RETURN VALUE:
// **    Returns the extracted substring as a dynamically allocated string.
// **
#include "libft.h"
#include "string.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
    size_t s_len;
    char *ret;

    if(s == NULL)
        return(NULL);
    s_len = ft_strlen(s);
    if(start >= s_len)
        return(ft_strdup(""));
    if(len > s_len - start)
        len = s_len - start;
    ret = (char *)malloc(sizeof(char) * (len + 1));
    if (ret == NULL)
        return (NULL);
    ft_strlcpy(ret, s + start, len + 1);
    return(ret);
    
}
/*int main()
{
    char *str = "Como estas";
    char *substr = ft_substr(str, 2, 8);
    printf("%s\n",substr);
    return(0);
}*/