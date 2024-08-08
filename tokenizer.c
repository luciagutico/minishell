#include "includes/minishell.h"

t_token	*extract_tokens(char *input_str)
{
	t_token	*token_list_head;
	t_token	*new_token;
	int	current_pos;

	token_list_head = NULL;
	current_pos = 0;
	while (input_str[current_pos] != '\0')
	{
		new_token = create_new_token();

	}
		


	token_list_add_back(token_list_head, new_token);
	return (token_list_head);
}

int main(void)
{
	char *input_str;
	t_token *test;
	char *prompt = "minishell > ";
	input_str = readline(prompt);
	test = extract_tokens(input_str);

	return (0);
}

