/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 18:36:43 by anagutie      #+#    #+#                 */
/*   Updated: 2024/07/30 18:44:56 by anagutie      ########   odam.nl         */
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