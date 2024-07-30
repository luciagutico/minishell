/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 14:46:57 by anagutie      #+#    #+#                 */
/*   Updated: 2024/07/30 18:35:10 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

//struct to manage enviroment
typedef	struct s_env
{
	char 			*var_name;
	char 			*var_value;
	struct 	s_env 	*next;
}	t_env;

#endif