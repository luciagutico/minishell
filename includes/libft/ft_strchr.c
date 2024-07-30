/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:33:19 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/23 14:37:02 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: find first occurrence of a character in a string
**
** DESCRIPTION:
**      The strchr() function searches for the first occurrence of the character 'c' (un `int` interpretado como un carácter sin signo) in the null-terminated string 'str'.
**      It returns a pointer to the first occurrence of 'c' within 'str', or a null pointer if 'c' is not found.
**
**      The search starts from the beginning of the string 'str' and moves towards the end.
**
**      The strchr() function is commonly used to find the first occurrence of a specific character in a string, such as locating a particular character in a text input or parsing a string for a delimiter.
*/

#include"libft.h"
//#include <string.h>
//#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == (char)c)
            return((char *)s + i);
        i++;
    }
    if(s[i] == '\0' && c == '\0')
    {
        return((char *)s + i); 
    }
    return(NULL);
}

// int main(void)
// {
//     int i;
//     char *str;
//     char *result;
//     char *result2;

//     i = 'z';
//     str = "tripouille";

//     printf("i = %c | %d\n\n", i, i);
//     result = (ft_strchr(str, i));
//     result2 = (strchr(str, i));

//     printf("The function returns: %s\n",result);
//     printf("The function returns: %s\n",result2);
// }