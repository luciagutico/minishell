/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enviroment_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 16:50:26 by anagutie      #+#    #+#                 */
/*   Updated: 2024/08/24 21:56:49 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env *var_union(char *name, char *value)
{
	t_env *mix;
	
	if (!name)
		return (NULL);
	mix = malloc(sizeof(t_env));
	if (!mix)
		return (NULL);
	mix->var_name = name;
	if (!mix->var_name)
		return(free(mix), NULL);
	mix->var_value = value;
	if (!mix->var_value)
		return (free(mix->var_name), free(mix), NULL);
	return(mix);
}

void append_env_list(t_env **head, t_env *element_to_add)
{
	t_env *current_node;
	
	if (element_to_add == NULL || head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = element_to_add;
		return ;
	}
	current_node = *head;
	while (current_node->next)
		current_node = current_node->next;
	current_node->next = element_to_add;
}
void free_element(t_env *element)
{
	if (element != NULL)
	{
		if (element->var_value)
			free(element->var_value);
		if (element->var_name)
			free(element->var_name);
		free(element);
	}
}

void free_list(t_env **list)
{
	t_env *node;

	if (list == NULL)
		return ;
	while (*list)
	{
		node = (*list)->next;
		free_element(*list);
		*list = node;
	}
}

void print_env_linked_list(t_env *list)
{
	printf("ENVP:");
	while(list != NULL)
	{
		printf("%s", list->var_name);
		printf("=");
		printf("%s\n", list->var_value);
		list = list->next;
	}
}


