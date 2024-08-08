#include "../../includes/minishell.h"

void	get_token_type(char c)
{
	char	*set_type[] = {'-', '|', '\'', '"', '<', '>', '>>'};



}

void	fill_token_info(int *current_pos, char *input_str, t_token **new_token)
{
	int	start_pos;

	start_pos = *current_pos;
	get_token_type(input_str[*current_pos]);
}

// This function extracts the tokens from the input string.
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
		fill_token_info(&current_pos, input_str, &new_token);
		token_list_add_back(&token_list_head, new_token);
		current_pos++;
	}
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

// int main(void)
// {
// 	int i = 0;
// 	t_token	*head;
// 	t_token *new;
// 	head = NULL;
//
// 	while (i < 5)
// 	{
// 		new = create_new_token();
// 		new->str = "hehe\n";
// 		printf("token %d created\n", i);
// 		token_list_add_back(&head, new);
// 		i++;
// 	} 
// 	t_token *temp;
// 	temp = head;
// 	while (temp->next != NULL)
// 	{
// 		printf("%s\n", new->str);
// 		temp = temp->next;
// 	}
// 	return (0);
// }

