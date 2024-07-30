/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:34:51 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/11 20:00:47 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: string comparison with a limit
**
** DESCRIPTION:
**      The strncmp() function compares the first 'n' characters of two null-terminated strings 'str1' and 'str2'.
**      It returns an integer value that indicates their relationship:
**
**      - If 'str1' is less than 'str2', it returns a negative value.
**      - If 'str1' is greater than 'str2', it returns a positive value.
**      - If 'str1' is equal to 'str2', it returns zero.
**
**      The comparison is performed lexicographically. The function stops comparing after 'n' characters or when a null-terminator ('\0') is encountered in either 'str1' or 'str2'.
**
**      The strncmp() function is commonly used for comparing substrings of strings or for making limited-length string comparisons.
*/

#include"libft.h"
#include<string.h>

/*int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    for(unsigned int i = 0; (s1[i] != '\0' || s2[i] != '\0') && n > 0;i++, n--)
        {
        if(s1[i]!= s2[i])
            return(s1[i] - s2[i]);
        }
    return(0);
}*/

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    for(unsigned int i = 0; (s1[i] != '\0' || s2[i] != '\0') && n > 0; i++,n--)
    {
        if(s1[i] != s2[i])
            return(s1[i] - s2[i]);
    }
    return(0);
}

/*int main(void)
{
    const char *str1;
    const char *str2;
    int size;

    str1 = "Hola";
    str2 = "Hola";
    size = 3;

    int result = ft_strncmp(str1, str2, size);
    int result1= strncmp(str1, str2, size);
    
    if(result1 == 0)
        printf("(predetermined func)There is not difference\n");
    else
        printf("(predetermined func)The difference is: %d\n", result1);

    if(result == 0)
    {
        printf("There is not difference in the entered parameters\n");
    }

    else
    {
        printf("The difference in the stings according to the entered parameters is: %d\n", result);
    }
    return(0);
}*/
