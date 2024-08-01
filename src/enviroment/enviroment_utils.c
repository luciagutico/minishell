/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enviroment_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 16:50:26 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/01 19:04:01 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

//CREATE FUNCTION OT FREE IN CASE OF FAILURE
t_env *create_node(char *name, char *value)
{
	t_env *new_node;
	
	if (!name)
		return (NULL);
	new_node = malloc(sizeof(t_env));
	//FREE FUNCTION PENDING
	if (!new_node)
		return(free(new_node), NULL);
	new_node->var_name = name;
	new_node->var_value = value;
	new_node->next = NULL;
	return(new_node);
}

void append_env_list(t_env **head, t_env *new_node)
{
	t_env *current_node;
	
	if (!new_node || head)
		return(NULL);
	if (!*head)
	{
		*head = new_node;
		return;
	}
	current_node = *head;
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = new_node;
}
void free_node(t_env *node)
{
	if (node)
	{
		free(node->var_value);
		free(node->var_name);
		free(node);
	}
}

void free_env_list(t_env **env_list)
{
	t_env *node;

	while (*env_list)
	{
		node = (*env_list)->next;
		free_node(*env_list);
		env_list = node;
	}
}



