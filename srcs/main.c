/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:08:01 by mdelforg          #+#    #+#             */
/*   Updated: 2022/04/07 15:22:02 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int ac, char **av, char **envp)
{
	t_env	env;

	ft_create_env(&env, envp);
	envp = env.e_tab;				//pas oublier
	if (ac)
		ft_dispatcher(av[1], av + 2, &env);
	return (0);
}
