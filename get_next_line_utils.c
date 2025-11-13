#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s && (*s != c))
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

char	*ft_strdup(char *str)
{
	int		size = ft_strlen(str);
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	copy = malloc(size + 1);
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

char	*ft_strndup(char *str, int size)
{
	int		i;
	char	*copy;

	if (!str || size < 0)
		return (NULL);
	copy = malloc(size + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size && str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*copy;
	int		i = 0;
	int		j = 0;

	if (!s2)
		return (s1);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	copy = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!copy)
		return (free(s1), NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	while (s2[j])
		copy[i++] = s2[j++];
	copy[i] = '\0';
	free(s1);
	return (copy);
}

char	*extract_line(char *stash)
{
	char	*nl;
	int		len;

	if (!stash || !stash[0])
		return (NULL);
	nl = ft_strchr(stash, '\n');
	if (nl)
	{
		len = nl - stash + 1;
		return (ft_strndup(stash, len));
	}
	return (ft_strdup(stash));
}

char	*clean_upgrade(char *stash)
{
	char	*nl;
	char	*new_stash;

	if (!stash)
		return (NULL);
	nl = ft_strchr(stash, '\n');
	if (!nl)
	{
		free(stash);
		return (NULL);
	}
	nl++; // avancer après '\n'
	if (!*nl)
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(nl);
	free(stash);
	return (new_stash);
}
