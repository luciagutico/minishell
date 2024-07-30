/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:24:33 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/24 15:20:29 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**=======================================================================================================================
**                                                    STRLCAT
 * *LIBRARY: <string.h>
** SYNOPSIS: string concatenation with size limit
**
** DESCRIPTION:
**      The strlcat() function concatenates two strings, ensuring that the resulting string is null-terminated.
**      It appends the source string 'src' to the destination string 'dest', but limits the total number of characters copied to 'size'.
**      If the length of 'dest' plus the length of 'src' is less than 'size', the entire 'src' string is appended to 'dest'.
**      If the combined length exceeds 'size', only a portion of 'src' is appended to 'dest', and the resulting string is null-terminated.
**      The return value of strlcat() is the total length of the concatenated strings, not including the null-terminator.
**
**      The strlcat() function is commonly used in Unix-based systems and provides a safer way to concatenate strings by avoiding buffer overflows.

 *=======================================================================================================================**/

#include"libft.h"
// #include<bsd/string.h>

size_t ft_strlcat(char *dst, const char *src, size_t n)
{
    size_t dst_length;
    size_t src_length;
    size_t i;    

    dst_length = ft_strlen(dst);
    src_length = ft_strlen((char *)src);
    i = 0;
    if(n == 0 || dst_length >= n)
        return(n + src_length);
    while((dst_length + i) < (n -1) && src[i] != '\0')
    {
        dst[dst_length + i] = src[i];
            i++;
    }
    dst[i + dst_length] = '\0';
    
    return(dst_length + src_length);
}

/*int main()
{
    char destination[100] = "Here is where the source string will be copied: \n";
    char source[]= "This string will be copied in the destination";
    // size_t result;
    size_t result_myfunc;

    // result = strlcat(destination, source, 90);
    result_myfunc = ft_strlcat(destination, source, 90);
    
    // printf("This is de result: %lu\n", result);
    printf("This is de result: %lu\n", result_myfunc);
    
}*/