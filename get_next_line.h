/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngambi <wngambi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:50:55 by wngambi           #+#    #+#             */
/*   Updated: 2025/11/08 18:18:21 by wngambi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strdup(char *str); // Fonctionnelle
char	*ft_strndup(char *str, int n); // Fonctionnelle
int		ft_strlen(char *str); // Fonctionnelle
char	*ft_strjoin(char *s1, char *s2); // Fonctionnelle
char	*ft_strchr(char *str, char c); // Fonctionnelle

char	*extract_line(char *stash);
char	*update_clean_stash(char *stash);
char	*get_next_line(int fd);

#endif