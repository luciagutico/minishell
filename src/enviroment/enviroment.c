/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enviroment.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 16:50:31 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/01 21:23:25 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_env(char **env)
{
	t_env	*env_list;
	int 	i;

	if (!env)
		return (NULL);
	env_list = NULL;
	i = 0;
	
	while (env[i])
	{
		if (add_to_env_list(env[i], &env_list) != 0)
		{
			if (env_list)
				free_env_list(&env_list);
				return (NULL);
		}
		i++;
	}
	return (env_list);
}
static int add_to_env_list(char *env_var, t_env **head)
{
	char 	*name;
	char 	*content;
	t_env 	*new_var;
	
	name = get_var_name(env_var);
	if (!name)
		return (1);
	else
	{
		content = get_var_content(env_var);
		if (!content)
			content = ft_calloc(1, 1);
		new_var = create_node(name, content);
		if (!new_var)
			return(free(name), free(content), NULL);
		append_env_list(head, new_var);
	}
	return (0);
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


//main to test

int main(int ac, char**av, char **envp)
{
	t_env *env;
	
	(void) ac;
	(void) av;

	env = init_env(envp);
	if (env)
		printf("envp set up was sucessfull");
	else
		printf("envp couldnt be intialized");
	free_env_list(envp);
	if (!env)
		printf("envp set up and freeing went sucesfull");
}