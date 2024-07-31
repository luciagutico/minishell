/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/31 19:05:56 by anagutie      #+#    #+#                 */
/*   Updated: 2024/07/31 19:13:40 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return(dest);
}