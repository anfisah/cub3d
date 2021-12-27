/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:57:52 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/03 11:39:21 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#define BUFFER_SIZE 1

int		ft_findchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr_free(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	index = 0;
	while (index < len && ((index + start) < size))
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	free((char *)s);
	return (str);
}

char	*read_line(int fd, char *str, int *res)
{
	char	buf[BUFFER_SIZE + 1];

	if (ft_findchr(str, '\n') == 1)
		return (str);
	while ((*res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*res] = '\0';
		str = ft_strjoin(str, buf);
		if ((ft_findchr(str, '\n') == 1))
			break ;
	}
	return (str);
}

char	*fill_str(char *str, int *fd, int *res)
{
	if (str == NULL)
		str = ft_calloc(1, 1);
	str = read_line(*fd, str, res);
	if (str[0] == '\n')
	{
		str[0] = ' ';
		str[1] = '\n';
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	int			i;
	static char	*str;

	i = 0;
	res = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL || (read(fd, 0, 0) < 0))
		return (-1);
	if (res == -1)
		return (-1);
	str = fill_str(str, &fd, &res);
	while (str[i] && str[i] != '\n')
		i++;
	(*line) = ft_substr(str, 0, i);
	str = ft_substr_free(str, i + 1, (ft_strlen(str) - i) - 1);
	if (*str == 0 && res == 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	return (1);
}
