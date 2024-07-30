
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 16:41:45 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/17 16:41:54 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    size_t m;

    void *a;
    if (nmemb == 0 || size == 0)
    {
        nmemb = 1;
        size = 1;
    }
    if ((nmemb * size) / size != nmemb)
        return(NULL);
    
    m = nmemb * size;
    a = malloc(m);
    if(a == NULL)
        return(NULL);
    ft_bzero(a,m);
    return(a);
}

