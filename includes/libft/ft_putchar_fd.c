/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 17:54:11 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/22 15:37:38 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void)
// {
//     int fd;
//     int fd2;
//     fd = open("test.txt", O_CREAT | O_RDWR | O_APPEND);
//     fd2 = open("print.txt", O_CREAT | O_RDWR | O_APPEND);
//     printf("%d\n", fd);
//     printf("%d\n", fd2);
//     ft_putchar_fd('h', fd);
//     ft_putchar_fd('a', fd);
//     ft_putchar_fd('e', fd2);
//     close(fd);
//     close(fd2);
//     return (0);
// }

// int main(void)
// {
//     int fd;
//     fd = open("Myfile.txt", O_CREAT | O_RDWR |0777);
//     if(fd == -1)
//         return(1);
//     printf("fd = %d\n", fd);
//     ft_putchar_fd('f', fd);
//     close(fd);
//     return(0);
// }