/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enviroment_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 16:50:26 by anagutie      #+#    #+#                 */
/*   Updated: 2024/07/30 19:23:44 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

//CREATE FUNCTION OT FREE IN CASE OF FAILURE
t_env *create_node(char *name, char *value)
{
	t_env *new_node;
	
	new_node = malloc(sizeof(t_env));
	//FREE FUNCTION PENDING
	if (!new_node)
		return(NULL);
	new_node->var_name = name;
	new_node->var_value = value;
	new_node->next = NULL;
	return(new_node);
}
