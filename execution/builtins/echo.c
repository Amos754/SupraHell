/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marechalolivier <marechalolivier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:12:06 by abolor-e          #+#    #+#             */
/*   Updated: 2024/07/25 01:34:55 by marechaloli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_echo(char **av, int nbr, t_envb *env)
{
	char	*str;
	int		i;

	if (nbr == 0)
		i = 1;
	else
		i = 2;
	while (av[i])
	{
		// if (!ft_strncmp(av[i], "$?", 2))
		// 	printf("%d", env->exstatus);
		printf("%s", av[i++]);
		if (av[i])
			printf(" ");
	}
	if (nbr == 0)
		printf("\n");
	return (0);
}

int	main_echo(int ac, char **av, t_envb *env)
{
	int	nbr;

	nbr = 0;
	if (ac > 1 && !ft_strncmp(av[0], "echo", 4))
	{
		if (!ft_strncmp(av[1], "-n", 2))
		{
			nbr = 1;
			if (!av[2])
				return (0);
		}
		if (ft_echo(av, nbr, env) == 127)
			return (127);
		return (0);
	}
	else
		printf("\n");
	return (127);
}
