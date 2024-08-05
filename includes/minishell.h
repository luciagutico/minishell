/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 14:46:57 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/02 19:36:31 by anagutie      ########   odam.nl         */
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

typedef struct s_shell
{
	char 	**env;
	t_env	*own_env;
}	t_shell;
//ENVIROMENT
/*Enviroment functions*/
t_env		*init_env(char **env);
char 		*get_var(char *name, t_env	*env);
char 		*get_var_name(char *env_var);
char 		*get_var_content(char *env_var);
/*Enviroment utils*/
t_env 		*create_node(char *name, char *value);
void 		append_env_list(t_env **head, t_env *new_node);
void 		free_env_list(t_env **env_list);
void 		free_node(t_env *node);

//minishell
t_shell *set_up_shell(char **envp);

#endif