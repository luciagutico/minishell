#include "../../include/minishell.h"

// send current token,
// go through the token list while is still an argument
// update token list so that it's updated in both
// 

void	fill_command_info(t_command *new_command, t_token **current_token)
{
	// TODO: build while loop
	void (*get_full_command[])(t_command *, t_token	**) =
	{
		[PIPE] = NULL,
		[S_QUOTE] = NULL,
		[D_QUOTE] = NULL,
		[REDIRECT_IN] = NULL,
		[REDIRECT_OUT] = NULL,
		[WORD] = command_args,
	};
	if (get_full_command[(*current_token)->type] != NULL)
		get_full_command[(*current_token)->type](new_command, current_token);
	// go through the token list, while its a word or quote, fill args
}

t_command *parser(t_token *token_list_head)
{
	t_command	*command_list_head;
	t_token		*current_token;
	t_command	*new_command;

	current_token = token_list_head;
	command_list_head = NULL;
	new_command = create_new_command();
	fill_command_info(new_command, &current_token);
	command_list_add_back(&command_list_head, new_command);
	// while (current_token != NULL)
	// {
	// 	new_command = create_new_command();
	// 	fill_command_info(new_command, &current_token);
	// 	// command_list_add_back(); 
	// 	current_token = current_token->next;
	// }
	return (command_list_head);
}

int main(void)
{
	t_token *list_token_head;
	t_token *new;
	t_token *two;
	t_command *test_command;
	test_command = create_new_command();
	list_token_head = NULL;
	new = create_new_token();
	new->type = WORD;
	new->str = "hello ";
	token_list_add_back(&list_token_head, new);
	two = create_new_token();
	two->type = WORD;
	two->str = "world";
	token_list_add_back(&list_token_head, two);
	test_command = parser(list_token_head);
	int i = 0;
	while (test_command->command_args != NULL && test_command->command_args[i] != NULL)
	{
		printf("%s\n", test_command->command_args[i]);
		i++;
	}


	return (0);
}
