/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:53:46 by mdelforg          #+#    #+#             */
/*   Updated: 2022/04/09 16:01:58 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_my_env(t_env *env)
{
	int	i;

	i = 0;
	while (i <= env->e_last)
	{
		printf("%s\n", env->e_tab[i]);
		i++;
	}
	return ;
}

void	ft_remove_var(int i, t_env *env)
{
	while (env->e_tab[i] && env->e_tab[i + 1])
	{
		free(env->e_tab[i]);
		env->e_tab[i] = env->e_tab[i + 1];
		env->e_tab[i + 1] = NULL;
		i++;
	}
	env->e_last--;
	return ;
}

int	ft_var_index(char *str, char **e_tab, int fct)
{
	int	i;
	int	j;

	i = 0;
	while (e_tab[i])
	{
		j = 0;
		while (e_tab[i][j] && e_tab[i][j] != '=')
			j++;
		if (!fct)
		{	
			if (!ft_strncmp(e_tab[i], str, j) && !str[j])
				return (i);
		}
		else
		{
			if (!ft_strncmp(e_tab[i], str, j))
				return (i);
		}
		i++;
	}
	return (-1);
}

void	ft_my_unset(char **args, t_env *env)
{
	int	i;
	int	a;

	a = 0;
	while (args[a])
	{
		i = ft_var_index(args[a], env->e_tab, 0);
		if (i >= 0)
			ft_remove_var(i, env);
		a++;
	}
	return ;
}
