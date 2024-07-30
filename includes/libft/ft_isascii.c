/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:17:05 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/12 12:29:14 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: test for ASCII character
**
** DESCRIPTION:
**      The isascii() function tests whether the given integer 'c' represents a valid ASCII character (in the range 0 to 127, inclusive).
**      It returns a non-zero value if 'c' is an ASCII character, and 0 otherwise.
**
**      The isascii() function is part of the C Standard Library's <ctype.h> header and is typically used to ensure that a character is within the ASCII character set before performing further operations on it.
*/
#include"libft.h"

int ft_isascii(int i)
{
    if(i >= 0 && i <= 127)
        return(1);
    return(0);
}

/*int main(void)
{
    char *str;
    int i;

    str = "hola097*-1$$€";

    while(str[i] != '\0')
    {
        if(ft_isascii(str[i]) == 1)
        {
            printf("Este es un valor ascii: %c\n",str[i]);
        }
        else
        {
            printf("Este no es un valor ascci: %c\n",str[i]);
        }
        i++;
    }
}*/