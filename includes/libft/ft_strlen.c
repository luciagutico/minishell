/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:29:54 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/24 15:38:47 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: string length calculation
**
** DESCRIPTION:
**      The strlen() function calculates the length of a null-terminated string 'str'.
**      It counts the number of characters in 'str' from the beginning (including the first character) until it encounters the null-terminator ('\0').
**      The return value of strlen() is the number of characters in 'str' up to, but not including, the null-terminator.
**
**      The strlen() function is a fundamental string manipulation function in C and is commonly used to determine the length of strings for various purposes.
*/

#include "libft.h"

size_t ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return(i);
}

// int main(void)
// {
//     char *str;

//     str = "Hola";

//     printf("Longitud de la cadena: %zu\n",ft_strlen(str));
// // %zu: especificador de formato utilizado para imprimir valores de tipo size_t
//     return(0);


