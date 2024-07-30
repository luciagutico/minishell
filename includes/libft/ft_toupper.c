/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:32:31 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/07 16:53:54 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: convert character to uppercase
**
** DESCRIPTION:
**      The toupper() function takes an integer representing an unsigned character as an argument and converts it to its uppercase equivalent if it is a lowercase letter (a-z).
**      If the argument is not a lowercase letter, it returns the same value unchanged.
**
**      The toupper() function is part of the C Standard Library's <ctype.h> header and is commonly used for performing case-insensitive comparisons or transformations on characters.
*/

#include<stdio.h>

int ft_toupper(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return(c - 32);
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
    str = "HolaCOmoEStasESPERO QUE muy bien";

    while(str[i] != '\0')
    {
        printf("%c",ft_toupper(str[i]));
        i++;
    }
    return(0);
}*/