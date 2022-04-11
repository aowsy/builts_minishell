/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:37:48 by mdelforg          #+#    #+#             */
/*   Updated: 2022/04/06 16:38:21 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != 0 && s1[i] == s2[i] && i < n)
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] && haystack[i] != needle[j])
			i++;
		while ((haystack[i + j] == needle[j]) && (j < ft_strlen(&needle[0])))
		{
			if (j == ft_strlen(&needle[0]) - 1)
				return ((char *)&haystack[i]);
			j++;
		}
		if (haystack[i])
			i++;
		else
			return (NULL);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}
