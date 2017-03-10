/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:40:52 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/10 16:40:53 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(t_info *inf)
{
	char	*s;

	s = NULL;
	if (!get_next_line(0, &s))
		return (1);
	if (s[10] == '1')
	{
		inf->player = 'O';
		inf->enemy = 'X';
	}
	else if (s[10] == '2')
	{
		inf->player = 'X';
		inf->enemy = 'O';
	}
	else
		return (1);
	return (0);
}

int		get_size(t_info *inf)
{
	char	**split;
	char	*line;

	line = NULL;
	if (!get_next_line(0, &line))
		return (1);
	split = (char **)malloc(3);
	split = ft_strsplit(line, ' ');
	inf->lines = ft_atoi(split[1]);
	inf->width = ft_atoi(split[2]);
	free(split);
	return (0);
}

void	get_field(t_info *inf)
{
	char	*line;
	int		i;
	char	**split;

	line = NULL;
	inf->field = (char **)malloc((inf->lines + 1) * sizeof(inf->field));
	split = (char **)malloc(3 * sizeof(split));
	i = 0;
	while (i != inf->lines)
	{
		get_next_line(0, &line);
		split = ft_strsplit(line, ' ');
		inf->field[i] = ft_strnew(ft_strlen(split[1]));
		inf->field[i] = ft_strjoin(inf->field[i], split[1]);
		i++;
	}
	inf->field[i] = NULL;
	free(split);
}

void	get_fig(t_info *inf)
{
	char	*line;
	int		lines;
	int		width;
	char	**split;
	int		i;

	line = NULL;
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	lines = ft_atoi(split[1]);
	width = ft_atoi(split[2]);
	free(split);
	inf->fig = (char **)malloc((lines + 1) * sizeof(inf->fig));
	i = 0;
	while (lines != 0)
	{
		get_next_line(0, &line);
		inf->fig[i] = ft_strnew(ft_strlen(line));
		inf->fig[i] = ft_strjoin(inf->fig[i], line);
		lines--;
		i++;
	}
	inf->fig[i] = NULL;
}

int		get_data(t_info *inf)
{
	char	*line;

	line = NULL;
	if (get_size(inf) == 1)
		return (0);
	if (get_next_line(0, &line))
	{
		get_field(inf);
		get_fig(inf);
	}
	else
		return (0);
	return (1);
}
