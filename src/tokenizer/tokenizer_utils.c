#include "../../includes/minishell.h"

void	pipe_token(int *current_pos, char *input_str, char token_hint, t_token **new_token)
{
	int i;
	if (!input_str)
		return ;
	i = 0;
	while (i < 2 && input_str[*current_pos] && input_str[*current_pos] == token_hint)
	{
		(*current_pos)++;
		i++;
	}
	(*new_token)->type = PIPE;
}
