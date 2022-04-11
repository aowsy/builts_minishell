/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:48:59 by mdelforg          #+#    #+#             */
/*   Updated: 2022/04/11 16:32:21 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_my_pwd(void)
{
	char	*path;								// choisir un buffer

	path = getcwd(NULL, 0);								// return err
	printf("%s\n", path);
	return ;
}

char	*ft_find_inenv(char *var, t_env *env)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (env->e_tab[i] && !ft_strstr(env->e_tab[i], var))
		i++;
	j = 0;
	while (env->e_tab[i][j] && env->e_tab[i][j] != '/')
		j++;
	str = &env->e_tab[i][j];
	return (str);
}

void	ft_my_cd(char **args, t_env *env)
{
	char s[100];

    printf("%s\n", getcwd(s, 100));
	if (!*args)
		chdir(ft_find_inenv("HOME", env));						// return err
	else if (!ft_strncmp(args[0], "-", 2))
		chdir(ft_find_inenv("OLDPWD", env));					// return err
	else
		chdir(args[0]);											// return err
    printf("%s\n", getcwd(s, 100));
	return ;
}
