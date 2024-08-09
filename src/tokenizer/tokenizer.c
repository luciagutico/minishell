#include "../../includes/minishell.h"

int	get_token_hint(char c)
{
	char	set_type[] = {'-', '|', '\'', '\"', '<', '>' };
	
	int value = 0;
	while (value < 6) 
	{
		if (c == set_type[value])
			break;
		value++;
	}
	if (value == 6) // if c is not in set_type[] will return 7
		value += 1;
	return (value);
}

void	fill_token_info(int *current_pos, char *input_str, t_token **new_token)
{
	int	start_pos;
	int	token_hint;

	start_pos = *current_pos;
	token_hint = get_token_hint(input_str[*current_pos]);
	void (*get_full_token[])(int *, char *, char, t_token **) =
	{
		[TOKEN] = NULL,
		[PIPE] = pipe_token,
		[S_QUOTE] = NULL,
		[D_QUOTE] = NULL,
		[REDIRECT_IN] = NULL,
		[REDIRECT_OUT] = NULL,
		[REDIRECT_OUT_APPEND] = NULL, // TODO: int this function set token_id 
		[WORD] = NULL
	};
	get_full_token[token_hint](&current_pos, input_str[*current_pos], &new_token) // TODO: Do i send input_str in total or just at a certain position
	(*new_token)->str = ft_substr(input_str, start_pos, ((*current_pos - start_pos) + 1));
	printf("%s", (*new_token)->str);

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

