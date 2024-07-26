/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marechalolivier <marechalolivier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:09:46 by abolor-e          #+#    #+#             */
/*   Updated: 2024/07/25 01:27:28 by marechaloli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_token		*input;
	char		*inp;
	t_tree		*tree;
	t_table		**parsingtable;
	t_toolkit	*toolkit;
	t_envb		*env;
	char **test;
	char *good;
	int	i;
	int	fd[2];

	while (1)
	{
		inp = readline("FCKG_HELL ");
		fd[0] = dup(0);
		fd[1] = dup(1);
		add_history((char *)inp);
		input = ft_lexer(inp);
		parsingtable = ft_init_parsing_table();
		tree = syntax_analysis(input, parsingtable);
		env = env_init(envp);
		if (!tree)
			printf("Tree is NULL\n");
		else
			ast_executor(tree, env);
		fd[0] = dup2(fd[0], 0);
		fd[1] = dup2(fd[1], 1);
		printf("\nex_status : %d\n", env->exstatus);
		//return (1);
	}
	// inp = readline("");
	// input = ft_lexer(inp);
	// parsingtable = ft_init_parsing_table();
	// tree = syntax_analysis(input, parsingtable);
	// env = env_init(envp);
	// if (!tree)
	// 	printf("Tree is NULL\n");
	// else
	// 	ast_executor(tree, env);
	// return (1);
}
