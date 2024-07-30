/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 15:45:16 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/24 16:09:34 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t length_1;
	size_t length_2;
	char *new_string;

	length_1 = ft_strlen(s1);
	length_2 = ft_strlen(s2);

	new_string = (char *)malloc(length_1 + length_2 + 1);
	if(new_string == NULL)
		return(NULL);
	ft_strlcpy(new_string, s1, length_1 + 1);
	ft_strlcat(new_string, s2, length_1 + length_2 + 1);
	
	return(new_string);
}