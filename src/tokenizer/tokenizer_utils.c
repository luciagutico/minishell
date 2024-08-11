#include "../../includes/minishell.h"

void	pipe_token(int *current_pos, char *input_str, char c, t_token *new_token)
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
	new_token->type = PIPE;
}
//
// void	redirect_in_token(int *current_pos, char *input_str, char token_hint, t_token **new_token)
// {
// 	int i;
// 	if (!input_str)
// 		return ;
// 	i = 0;
// 	while (i < 2 && input_str[*current_pos] && input_str[*current_pos] == token_hint)
// 	{
// 		(*current_pos)++;
// 		i++;
// 	}
// 	(*new_token)->type = REDIRECT_IN;
// } //TODO : what about << ? what does it mean? if i handle it, should i create a separate token id for it?
//
void	single_quote_token(int *current_pos, char *input_str, char token_hint, t_token **new_token)
{
	int i;
	if (!input_str)
		return ;
	i = 0;
	while (input_str[*current_pos] && input_str[*current_pos] != token_hint) // TODO: replace token hint (interger value) with character at that posiiton in the stirng!
	{
		(*current_pos)++;
		i++;
	}
	new_token->type = S_QUOTE;
}
