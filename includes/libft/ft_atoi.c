/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:35:30 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/20 20:19:23 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdlib.h>
** SYNOPSIS: convert ASCII string to integer
**
** DESCRIPTION:
**      The atoi() function takes a null-terminated string 'str' as an argument and converts it to an integer representation.
**      It reads characters from 'str' until a non-digit character is encountered or until the end of the string is reached.
**      The function stops at the first non-digit character or at the null-terminator ('\0') and converts the numeric part of 'str' to an integer.
**      If 'str' does not contain a valid integer representation, the behavior is undefined.
**      The function returns the converted integer value.
**
**      The atoi() function is commonly used for converting string representations of numbers to integers, but it does not handle error checking, so it's important to ensure that the input string is a valid integer representation.
*/

#include"libft.h"
//#include<stdlib.h>

int ft_atoi(const char *str)
{
    int r;
    int i;
    int sign;
    
    r = 0;
    i = 0;
    sign = 1;
    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        r = (10 * r )+ (str[i] -'0');
        i++;
    }
    return(r * sign);
}

/*int main(void)
{
    int result;
    int result1;
    
    char str[] = "336744ASD 4";
    result = ft_atoi(str);
    result1 = atoi(str);
    
    printf("This is the result of implementing ATOI: %d\n",result);
    printf("This is the result of implementing ATOI: %d\n",result1);
}*/