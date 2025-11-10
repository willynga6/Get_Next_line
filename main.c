/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:57:52 by wngambi           #+#    #+#             */
/*   Updated: 2025/11/08 18:11:31 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("lyrics", O_RDONLY);
	if (!fd)
		return (-1);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (-1);
		printf("%s", line);
		free(line);
	}
	return (0);
}
