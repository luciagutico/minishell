/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 14:44:17 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/24 13:46:03 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// First  check if the 2 variables are set in non zero values, then declared a variable with the length of the haystack,
	//in this case s1. With the while loop and the strchr function I'm comparting if the first value of the haystack is the same as needle
	// position 0
char *ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	size_t source_length;
	
	source_length = 0;

	if(s1 != 0 && set != 0)
	{
		source_length = ft_strlen(s1);
		i = 0;
		while(s1[i] && ft_strchr(set, s1[i]))
			i++;
		while(s1[source_length -1] && ft_strchr(set, s1[source_length -1]))
			source_length--;
		return(ft_substr(s1, i, source_length - i));
	}
	return(NULL);

}

// int main(void)
// {
// 	char *s1 = "Pannekoeken";
// 	char *set = "";

// 	printf("%s\n",ft_strtrim(s1, set));
	
// }