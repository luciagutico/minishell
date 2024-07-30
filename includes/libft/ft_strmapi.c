/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 17:01:28 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/23 18:55:35 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length_s;
	char *new_string;
	int i;
	
	i = 0;
	length_s = ft_strlen(s);
	new_string = (char *)malloc(sizeof(char) * length_s + 1);
	if(new_string == NULL)
		return(NULL);
	while(s[i] != '\0')
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';	
	return(new_string);
}
