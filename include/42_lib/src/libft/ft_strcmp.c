/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/24 12:40:37 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/24 12:40:47 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return((unsigned char) *s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return((unsigned char) *s1 - (unsigned char)*s2);
}