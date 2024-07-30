/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:23:33 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/22 20:35:18 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: copy memory block with overlapping areas
**
** DESCRIPTION:
**      The memmove() function copies 'n' bytes from the memory area 'src' to the memory area 'dest'.
**      The copying is done in a way that can handle overlapping memory regions, ensuring that the data is correctly copied regardless of the overlap.
**
**      The memmove() function is commonly used when copying data between memory areas that may overlap, as it provides reliable results in such cases.
**
**      The return value of memmove() is a pointer to the destination memory area 'dest'.
*/

#include"libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dest1;
	const unsigned char *src1;
	size_t i;

	dest1 = (unsigned char *)dest;
	src1 =(const unsigned char *)src;
	i = 0;
	if(src1 < dest1)
	{
		while(n > 0)
		{
			dest1[n - 1] = src1[n -1];
			n--;
		}
	}
	else
	{
		while(i < n)
		{
			dest1[i] = src1[i];
			i++;  
		}
	}
	return(dest1);
}

// int main()
// {
//     char dest[] = "Hola hhuh how are you?";
//     // char *src;
//     size_t n;

//     // dest = "Hola hhuh";
//     // src = "Como estas";
//     n = 7;
//     printf("This is dest: %s\n", dest);

//     char *result = ft_memmove(dest + 1, dest + 5, n);
//     printf("this is the result: %s\n", result);

// }