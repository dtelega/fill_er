/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:34:02 by dtelega           #+#    #+#             */
/*   Updated: 2017/01/19 13:03:31 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_more_memory(char *line, int size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(line) + size + 1)))
		return (0);
	ft_strcpy(tmp, line);
	free(line);
	return (tmp);
}

static char		*ft_af(char *buffer)
{
	int		i;
	int		k;
	char	*save;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	save = ft_strnew(ft_strlen(buffer) - i);
	k = 0;
	if (buffer[i] != '\0' && buffer[i + 1] != '\0')
	{
		i++;
		while (buffer[i] != '\0')
		{
			save[k] = buffer[i];
			k++;
			i++;
		}
		save[k] = '\0';
		return (save);
	}
	free(save);
	return (NULL);
}

static char		*ft_make_line(char *str, char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			if (!(str = ft_more_memory(str, i + (int)ft_strlen(str))))
				return (0);
			return (str = ft_strncat(str, buf, i));
		}
		i++;
	}
	return (str);
}

static char		*ft_find_line(int fd, char *str, char **s, int *i)
{
	char		buf[BUFF_SIZE + 1];
	int			k;

	if (*s != NULL && (*i = 1) && ft_strchr(*s, '\n') != 0)
		if ((str = ft_make_line(str, *s)))
		{
			*s = ft_af(*s);
			return (str);
		}
	if (*s != NULL && (str = ft_strcat(str, *s)))
		*s = NULL;
	while ((k = read(fd, buf, BUFF_SIZE)) && k >= 0)
	{
		buf[k] = '\0';
		if ((*i = 1) && ft_strchr(buf, '\n') != 0)
		{
			*s = ft_af(buf);
			return (ft_make_line(str, buf));
		}
		else if (!(str = ft_more_memory(str, BUFF_SIZE)))
			return (0);
		str = ft_strncat(str, buf, BUFF_SIZE);
	}
	k < 0 ? *i = -1 : 0;
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*save[4000];
	char			*str;
	int				res;

	if (fd < 0 || fd > 4000 || !line || BUFF_SIZE <= 0 || BUFF_SIZE > MAX_BUFF)
		return (-1);
	if (read(fd, 0, 0))
	{
		save[fd] = NULL;
		*line = NULL;
		return (-1);
	}
	res = 0;
	if (!(str = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!(str = ft_find_line(fd, str, &save[fd], &res)))
		return (-1);
	if (res <= 0)
	{
		save[fd] = NULL;
		*line = NULL;
		return (res);
	}
	*line = str;
	return (1);
}
