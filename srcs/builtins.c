/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:16:23 by mdelforg          #+#    #+#             */
/*   Updated: 2022/04/11 16:36:49 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_my_echo(char **args)
{
	int	i;
	int	n_option;

	i = -1;
	n_option = 0;
	while (args[++i] && !ft_strncmp(args[i], "-n", 3))
		n_option++;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[++i])
			printf(" ");
	}
	if (!n_option)
		printf("\n");
	return ;
}

//	reutrn int
//	exit -1
void	ft_dispatcher(char *cmd, char **args, t_env *env)
{
	if (!ft_strncmp(cmd, "env", 4))
		ft_my_env(env);
	else if (!ft_strncmp(cmd, "export", 7))
		ft_my_export(args, env);
	else if (!ft_strncmp(cmd, "unset", 6))
		ft_my_unset(args, env);
	else if (!ft_strncmp(cmd, "echo", 5))
		ft_my_echo(args);
	else if (!ft_strncmp(cmd, "cd", 3))
		ft_my_cd(args, env);
	else if (!ft_strncmp(cmd, "pwd", 4))
		ft_my_pwd();
//	ft_my_env(env);
	return ;
}
