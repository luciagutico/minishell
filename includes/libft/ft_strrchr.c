/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 22:03:28 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/20 20:21:34 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: find last occurrence of a character in a string
**
** DESCRIPTION:
**      The strrchr() function searches for the last occurrence of the character 'c' (un `int` interpretado como un carácter sin signo) in the null-terminated string 'str'.
**      It returns a pointer to the last occurrence of 'c' within 'str', or a null pointer if 'c' is not found.
**
**      The search starts from the end of the string 'str' and moves towards the beginning.
**
**      The strrchr() function is commonly used to find the last occurrence of a specific character in a string, such as locating the file extension in a file path or searching for a delimiter in a string.
*/

#include "libft.h"
#include "string.h"

char *ft_strrchr(const char *s, int c)
{
    size_t i;
    char *str;

    str = (char *)s;
    i = ft_strlen(s);
    if(c == '\0')
        return(str + i);
    while(i != 0)
    {
        if(str[i] == (char)c)
            return(str + i);
        i--;
    }
    if(s[0] == (char) c)
        return(str);
    return(0);    
}


/*int main(void)
{
    const char *str;
    int c;
    char *result;
    char *function_result;

    str = "   .";
    c = '....';
    result = ft_strrchr(str, c);
    function_result = strrchr(str,c);

    printf("Este es el resultado: %s\n",result);
    printf("Este es el resultado de la funcion orginal: %s\n", function_result);

    
}*/
