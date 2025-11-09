/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:52:39 by wngambi           #+#    #+#             */
/*   Updated: 2025/11/09 22:56:02 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	char	*line;
	char	*newline_ptr;

	if (!stash || *stash == '\0')
		return (NULL);
	newline_ptr = ft_strchr(stash, '\n');
	if (newline_ptr)
		line = ft_strndup(stash, newline_ptr - stash + 1);
	else
		line = ft_strdup(stash);
	return (line);
}

char	*update_clean_stash(char *stash)
{
	char	*new_stash;
	char	*newline_ptr;

	if (!stash)
		return (NULL);
	newline_ptr = ft_strchr(stash, '\n');
	if (!newline_ptr)
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(newline_ptr + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	r = 1;
	while (r > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[r] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	if (!stash || !*stash)
		return (free(buf), free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	return (stash = update_clean_stash(stash), free(buf), line);
}
