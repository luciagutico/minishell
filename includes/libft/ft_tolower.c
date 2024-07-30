/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:33:36 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/18 17:59:23 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: convert character to lowercase
**
** DESCRIPTION:
**      The tolower() function takes an integer representing an unsigned character as an argument and converts it to its lowercase equivalent if it is an uppercase letter (A-Z).
**      If the argument is not an uppercase letter, it returns the same value unchanged.
**
**      The tolower() function is part of the C Standard Library's <ctype.h> header and is commonly used for performing case-insensitive comparisons or transformations on characters.
*/
#include"libft.h"

int ft_tolower(char c)
{
    if( c >= 'A' && c <= 'Z')
    {
        return(c += 32);
    }
    else
    {
        return(c);
    }
}

/*int main(void)
{
    char *str;
    int i;

    i = 0;
    str = "DEspierto y agARADEZCO, SoY FELIZ CON lo que TengOOOO, Y AMANECI pa DisfrutAR <3";

    while(str[i] != '\0')
    {
        printf("%c", ft_tolower(str[i]));
        i++;
    }
}*/
