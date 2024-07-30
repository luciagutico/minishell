/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:17:02 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/12 12:28:35 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: alphanumeric character test
**
** DESCRIPTION:
** 		The isalnum() function tests for an alphanumeric character.
** 		It checks if the given character is either a decimal digit (0-9) or an uppercase letter (A-Z) or a lowercase letter (a-z).
** 		If the character is alphanumeric, the function returns a non-zero value (true).
** 		Otherwise, it returns 0 (false).
*/
#include "libft.h"

int ft_isalnum(char c)
{
    if((ft_isalpha(c)) == 1 || (ft_isdigit(c)) == 1)
            return(1);
    return(0);
}

/*int main(void)
{
    char *str;
    int i;

    i = 0;

    str = "HOLA99 3IMRK]--=300";

    while(str[i] != '\0')
    {
        printf("%c is: %d\n", str[i], ft_isalnum(str[i]));
        // if(ft_isalnum(str[i]) == 1)
        //     printf("This is a letter or a numbers\n");
        // else
        //     printf("The string doesn't contain letters or numbers\n ");
        i++;
    }
    
}*/

