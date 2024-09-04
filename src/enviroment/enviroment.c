/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enviroment.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 16:50:31 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/30 14:40:29 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int add_to_env_list(char *env, t_env **head);
//core function where the environment list gets build
t_env	*init_env(char **env)
{
	t_env	*list;
	int 	i;

	if (env == NULL)
		return (NULL);
	list = NULL;
	i = 0;
	while (env[i])
	{
		if (add_to_env_list(env[i], &list) != 0)
		{
			if (list)
			{
				free_list(&list);
				return (NULL);
			}
		}
		i++;
	}
	return (list);
}
static int add_to_env_list(char *env_var, t_env **head)
{
	char 	*name;
	char 	*value;
	t_env 	*new_var;
	
	name = get_name(env_var);
	if (name == NULL)
		return (1);
	else
	{
		value = get_value(env_var);
		if (value == NULL)
			value = ft_calloc(1, 1);
		new_var = var_union(name, value);
		if (!new_var)
			return(free(name), free(value), 1);
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
char *get_name(char *var)
{
	int 		i;
	char 		*name;
	const int	name_len = ft_strlen(var);

	i = 0;
	if (name_len == 0)
		return (NULL);
	while (var[i] && var[i] != '=')
		i++;
	if (i == 0)
		return(NULL);
	if (i == name_len)
		return (NULL);
	name = ft_substr(var, 0, i);
	if (!name)
		return (NULL);
	return(name);
}
char *get_value(char *var)
{
	int 		i;
	char 		*value;
	const int	len = ft_strlen(var);

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	if (i == len)
		return (NULL);
	if (var[i] && var[i + 1])
	{
		value = ft_substr(var, i + 1, len - 1 - i);
		return (value);
	}
	return(NULL);
}

// int main(int argc, char **argv, char **envp) 
// {
// 	(void)argc;
// 	(void)argv;
//     t_env *env_list;

//     // Initialize environment linked list
//     env_list = init_env(envp);

//     // Print the linked list to check if everything is loaded correctly
//     print_env_linked_list(env_list);

//     // Free the environment list to check if memory is managed correctly
//     free_list(&env_list);

//     // Optionally, you can check if the list was correctly freed
//     if (env_list == NULL)
//         printf("Environment list successfully freed!\n");
//     else
//         printf("Failed to free environment list.\n");

//     return 0;
// }
