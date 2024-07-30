/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 15:43:41 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/25 14:32:03 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static unsigned int ft_number_length(int number)
{
	unsigned int length;

	length = 0;
	
	if(number == 0)
		return(1);
	if(number < 0)
		length += 1;
	while(number != 0)
	{
		number /= 10;
		length++;
	}
	return(length);

}

char *ft_itoa(int n)
{
	char *ret;
	int length;
	long int better_num;
	
	better_num = n;
	length = ft_number_length(better_num);
	if(length == 0)
		return(NULL);
	ret = (char *)malloc(sizeof(char) * length + 1);
	ret[length] = '\0';
	if(better_num == 0)
		ret[--length] = 0 + 48;
	if(better_num < 0)
	{
		ret[0] = '-';
		better_num *= -1;
	}
	while(better_num > 0)
		{
			length--;
			ret[length] = better_num % 10 + 48;
			better_num /= 10;	
		}
	return(ret);
}
