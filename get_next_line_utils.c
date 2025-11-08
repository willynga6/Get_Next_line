/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:55:17 by wngambi           #+#    #+#             */
/*   Updated: 2025/11/08 17:10:01 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*============================================*/

char	*ft_strdup(char *str)
{
	char	*copy;
	int		i;
	int		size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*============================================*/

char	*ft_strndup(char *str, int n)
{
	char	*copy;
	int		i;
	int		size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (n > size)
		n = size;
	copy = malloc(sizeof(char) * (n + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*============================================*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*copy;

	int (i) = 0;
	int (j) = 0;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (s1);
	copy = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		copy[i++] = s2[j++];
	copy[i] = '\0';
	free(s1);
	return (copy);
}
/*============================================*/

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
