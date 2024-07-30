/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 19:02:26 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/20 15:41:48 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strdup(const char *src)
{
    char *dst;
    size_t len;
	
    len = ft_strlen(src);
    dst = malloc(len + 1);
	if(dst == NULL)
		return(NULL);
	ft_strlcpy(dst, src, ( len + 1));
    return(dst);
}

// int main(void)
// {
// 	char	*str;
// 	char	*result;
	
//     str = "Hope this is working";
// 	result = ft_strdup(str);
// 	printf("%s\n", result); 
// }
