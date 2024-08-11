#include "../../include/minishell.h"

// TODO: should I add a syntax check at this stage, especially for quotes?
void	pipe_token(int *current_pos, char *input_str, char c)
{
	int i;
	if (!input_str)
		return ;
	i = 0;
	while (i < 2 && input_str[*current_pos] && input_str[*current_pos] == c)
	{
		(*current_pos)++;
		i++;
	}
}

void	redirect_token(int *current_pos, char *input_str, char c)
{
	int i;
	if (!input_str)
		return ;
	i = 0;
	while (i < 3 && input_str[*current_pos] && input_str[*current_pos] == c)
	{
		(*current_pos)++;
		i++;
	}
}

void	quote_token(int *current_pos, char *input_str, char c)
{
	if (!input_str)
		return ;
	(*current_pos)++;
	while (input_str[*current_pos] && input_str[*current_pos] != c)
		(*current_pos)++;
	if (input_str[*current_pos])
		(*current_pos)++;
}
// TODO: if i add a syntax checker here, what are the rules? should i check for unclosed quote herE?

void	word_token(int *current_pos, char *input_str, char c)
{
	while (input_str[*current_pos] && input_str[*current_pos] == get_token_hint(c))
		(*current_pos)++;
}
