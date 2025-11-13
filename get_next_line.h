#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_strndup(char *str, int size);
char	*ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*extract_line(char *stash);
char	*clean_upgrade(char *stash);

#endif
