/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:24:40 by anagutie      #+#    #+#                 */
/*   Updated: 2023/10/28 23:43:10 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
//Functions from <ctype.h>
int ft_isdigit(int i);
int ft_isalpha(int c);
int ft_isalnum(char c);
int ft_isascii(int i);
int ft_isprint(int c);
int ft_tolower(char c);
int ft_toupper(char c);
//Functions from <string.h>
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memset(void *b, int c, size_t len);
void *ft_memchr(const void *s, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
char *ft_strnstr(const char *big, const char *little, size_t len);
char *ft_strdup(const char *src);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//Functions from <stdlib.h>
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
//Functions second page
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

#endif