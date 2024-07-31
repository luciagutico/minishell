/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enviroment.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 16:50:31 by anagutie      #+#    #+#                 */
/*   Updated: 2024/07/31 19:55:44 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	init_env(char **env)
{
	t_env	*env_list;
	int 	i;

	if (!env)
		return ;
	env_list = NULL;
	return (*env_list);
}

static int add_to_env_list(char *env_var, t_env **head)
{
	char *var_name;
	
	var_name = 
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

// figure out a way to free in case of malloc failure
char *get_var_name(char *env_var)
{
	int 	i;
	char 	*name;

	i = 0;

	while (env_var[i] && env_var[i] != '=')
		i++;
	if (i == 0 || env_var[i] != '=')
		return(NULL);
	name = malloc(i + 1);
	if (!name)
		return(NULL);
	ft_strncpy(name, env_var, i);
	name[i] = '\0';
	return(name);
}
char *get_var_content(char *env_var)
{
	int 	i;
	char 	*content;

	i = 0;

	while (env_var[i] && env_var[i] != '=')
		i++;
	if (env_var[i] == '=')
		i++;
	content = malloc(ft_strlen(env_var + i) + 1);
	if (content == NULL)
		return (NULL);
	ft_strcpy(content, env_var + i);
	return (content);
}