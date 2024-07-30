/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 19:34:46 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/18 20:10:13 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: alphabetic character test
**
** DESCRIPTION:
** 		The isalpha() function tests for an alphabetic character.
** 		It checks if the given character is an uppercase letter (A-Z) or a lowercase letter (a-z).
** 		If the character is alphabetic, the function returns a non-zero value (true).
** 		Otherwise, it returns 0 (false).
*/

//#include <stdio.h>
#include"libft.h"

int     ft_isalpha (int c)
{
    if  (('a' <= c && 'z' >= c) || ('A' <= c && 'Z' >= c)) // aqui estamos checando si la variable h esta dentro de los valores de a a z o A a Z 
        return(1);
    return(0); 
}

// int main(void)
// {
//     char *str;
//     int i;

//     i = 0;
//     str = "Octu 1 ___ bre*";
    
//     while (str[i] != '\0')
//     {
//         if(ft_isalpha(str[i]) == 1 )
//         {
//             printf("%c is an alphabetic character.\n", str[i]);
//         }
//         else
//         {
//             printf("%c is not an alphabetich character.\n", str[i]);
//         }

//         i++;
//     }
//     return(0);
// }


