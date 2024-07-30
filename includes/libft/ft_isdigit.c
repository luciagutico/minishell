/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:16:56 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/18 20:18:23 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: decimal-digit character test
**
** DESCRIPTION:
** 		The isdigit() function tests for a decimal digit character.
*/
//#include<stdio.h>

int ft_isdigit(int i)
{
    while( '0' <= i  && '9' >= i)
        return(1);
    return(0);
}

/*int main(void)
{
    char *str;
    int i;

    str = "4774HAOLLA  KMOW///";
    i = 0;

    while(str[i] != '\0')
    
    {
        if(ft_isdigit(str[i]) == 1)
            {

            printf("%c is a digit\n", str[i]);

            }
            else{
            printf("%c is not a digit\n", str[i]);
            }
        i++;
    }
    return(0);
}*/