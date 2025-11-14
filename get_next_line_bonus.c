/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:14:42 by wngambi           #+#    #+#             */
/*   Updated: 2025/11/14 13:20:09 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	char	*line;
	char	*nl;

	if (!stash)
		return (NULL);
	nl = ft_strchr(stash, '\n');
	if (!nl)
	{
		line = ft_strdup(stash);
		return (line);
	}
	else
	{
		line = ft_strndup(stash, (nl - stash + 1));
		return (line);
	}
}

/*=============================================================*/

char	*clean_update_stash(char *stash)
{
	char	*new_stash;
	char	*new_line;

	if (!stash)
		return (NULL);
	new_line = ft_strchr(stash, '\n');
	if (!new_line)
	{
		free(stash);
		stash = NULL;
		return (stash);
	}
	if (*(new_line + 1) == '\0')
		return (free(stash), NULL);
	new_stash = ft_strdup(new_line + 1);
	free(stash);
	return (new_stash);
}

/*=============================================================*/

char	*get_next_line(int fd)
{	
	static char	*stash[1024];
	char		*buffer;
	int			lecture;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash[fd], '\n'))
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		if (lecture == -1)
			return (free(buffer), NULL);
		buffer[lecture] = '\0';
		if (lecture == 0)
			break ;
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	line = extract_line(stash[fd]);
	stash[fd] = clean_update_stash(stash[fd]);
	free(buffer);
	return (line);
}

/*
int	main(void)
{
	int			fd;
	char		*lecture;

	fd = open("txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erreur ouverture fichier\n");
		return (-1);
	}
	lecture = "go";
	while (lecture)
	{
		lecture = get_next_line(fd);
		printf("%s", lecture);
		free(lecture);
	}
	return (0);
}
*/