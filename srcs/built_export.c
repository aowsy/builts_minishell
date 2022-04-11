/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:45:03 by mdelforg          #+#    #+#             */
/*   Updated: 2022/04/11 16:27:04 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_var(char *str)
{
	int	i;
	int eq;

	if (str[0] == '=' || ft_isdigit((int)str[0]))
		return (0);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (ft_strchr("!@#$%^&*()-+[]{}\\|;:\'\",.<>/?˜`", str[i]))
			return (0);
		i++;
	}
	i = 0;
	eq = 0;
	while (str[i])
	{
		if (!ft_isalnum((int)str[i]) && !ft_strchr("@#$%^*-_=+[]{}\\|:,./?˜", str[i]))
			return (0);
		if (str[i] == '=')
			eq++;
		i++;
	}
	if (!eq)
		return (0);
	return (1);
}

// export +=
//	free le tableau
int	*ft_env_index(char **env)
{
	int max;
	int	a;
	int	i;
	int	*index;

	max = 0;
	while (env[max])
		max++;
	index = (int *)malloc(sizeof(int) * (max + 1));
	a = 0;
	while (a < max)
	{
		index[a] = 0;
		i = 0;
		while (env[i])
		{
			if (ft_strncmp(env[a], env[i], ft_strlen(env[a])) > 0)
				index[a]++;
			i++;
		}
		a++;
	}
	index[a] = -1;
	return (index);
}

//	guillemets
void	ft_env_sorted(char **env)
{
	int	i;
	int	nb;
	int	max;
	int	*index;

	index = ft_env_index(env);
	max = 0;
	while (env[max])
		max++;
	nb = 0;
	while (nb < max)
	{
		i = 0;
		while (env[i])
		{
			if ((index[i] == nb) && !(env[i][0] == '_' && env[i][1] == '='))
				printf("%s\n", env[i]);
			i++;
		}
		nb++;
	}
	free(index);
	return ;
}

void	ft_my_export(char **args, t_env *env)
{
	int	a;
	int	i;
	int j;

	j = 0;
	if (!args || !*args)				// verifier pour !*args et mettre un else
		ft_env_sorted(env->e_tab);
	while (args[j])
	{
		i = env->e_last + 1;
		if (ft_check_var(args[j]))
		{
			a = ft_var_index(args[j], env->e_tab, 1);
			if (a >= 0)
			{
				free(env->e_tab[a]);
				env->e_tab[a] = ft_strdup(args[j]);
			}
			else
			{
			env->e_tab[i] = ft_strdup(args[j]);
			env->e_last++;
			}
		}
		j++;
		if (env->e_last == env->size -1)
			ft_bigger_env(env, env->e_tab);
	}
	return ;
}
