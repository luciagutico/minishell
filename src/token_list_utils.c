#include "../includes/minishell.h"

// This function creates a new node
t_token	*create_new_token(void)
{
	t_token *new = malloc(sizeof(t_token) * 1);
	if (!new)
		return (NULL);
	new->type = TOKEN;
	new->str = NULL;
	new->next = NULL;
	return (new);
}

t_token	*token_list_add_back(t_token *token_list_head, t_token *new_token)
{
	if (token_list_head == NULL)
		token_list_head = new_token;
	else
	
	

	return (token_list_head);
}

t_token *token_list_find_last(t_token *token_list_node)
{
	if (token_list_node == NULL)
		return (NULL);
	while (token_list_node->next != NULL)
		token_list_node = token_list_node->next;
	return (token_list_node);
}
