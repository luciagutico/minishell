/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/31 19:50:17 by anagutie      #+#    #+#                 */
/*   Updated: 2024/07/31 19:53:13 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcpy(char *dest, char *src)
{
	int 	i;
	char	*start;

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