/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:19:23 by wngambi           #+#    #+#             */
/*   Updated: 2025/11/14 13:19:39 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strndup(char *s, int size);
char	*ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
char	*extract_line(char *stash);
char	*clean_update_stash(char *stash);

#endif