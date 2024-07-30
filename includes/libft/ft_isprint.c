/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:22:59 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/18 20:38:35 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: test for a printable character
**
** DESCRIPTION:
**      The isprint() function tests whether the given integer 'c' represents a printable character.
**      A printable character is any character that can be visualized or printed, such as letters, digits, punctuation, and other graphical characters.
**      It returns a non-zero value if 'c' is a printable character, and 0 otherwise.
**
**      The isprint() function is part of the C Standard Library's <ctype.h> header and is commonly used for character classification to check if a character can be displayed.
*/

#include"libft.h"

int ft_isprint(int c)
{
    if(c >= 32 && c <= 126)
        return(1);
    return(0);
}

/*int main(void)
{
    char *str;
    int i;

    i = 1;
    str = "  9u388h$$$$,orm *//*r--";

    while(str[i] != '\0')
    {
        if(ft_isprint(str[i]) == 1)
        {
            printf("This is printable: %c\n", str[i]);
        }

        else
        {
            printf("This is not printable: %c\n", str[i]);
        }
        i++;
    }

}*/