/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/24 12:46:45 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/24 12:46:48 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strcpy(char *dest, char *src)
{
	int 	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		dest++;
		src++;
	}
	dest[i] = '\0';
	return(dest);
}