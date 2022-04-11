/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:13:28 by mdelforg          #+#    #+#             */
/*   Updated: 2022/04/09 16:02:44 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_env
{
	int		size;
	int		e_last;
	char	**e_tab;
}	t_env;

void	ft_dispatcher(char *cmd, char **args, t_env *env);
void	ft_my_echo(char **args);
void	ft_create_env(t_env *env, char **envp);
void	ft_bigger_env(t_env *env, char **past_e);
void	ft_my_export(char **args, t_env *env);
void	ft_my_pwd(void);
void	ft_my_cd(char **args, t_env *env);
void	ft_my_unset(char **args, t_env *env);
void	ft_my_env(t_env *env);
int		ft_var_index(char *str, char **e_tab, int fct);
void	ft_remove_var(int i, t_env *env);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
