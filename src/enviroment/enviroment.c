/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enviroment.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 16:50:31 by anagutie      #+#    #+#                 */
/*   Updated: 2024/07/30 19:19:43 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	init_env(char **env)
{
	t_env	*env_list;
	int 	i;

	if (!env)
		return (NULL);
	env_list = NULL;
	return (env_list);
}

char *get_var(char *name, t_env	*env)
{
	if (!name || !env)
		return(NULL);
	while (env)
	{
		if (ft_strcmp(env->var_name, name) == 0)
			return(env->var_value);
		env = env->next;
	}
	return(NULL);
}