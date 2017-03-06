/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:21:31 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/03 17:21:33 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include <stdio.h>

int		get_player(t_info *inf)
{
	char	*s;

	s = NULL;
	if (!get_next_line(0, &s))
		return (1);
	if (s[10] == '1')
		inf->player = 'O';
	else if (s[10] == '2')
		inf->player = 'X';
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
	get_next_line(0, &line);
	inf->field = ft_strnew(inf->width * inf->lines);
	split = (char **)malloc(3 * sizeof(split));
	i = 0;
	while (i != inf->lines - 1)
	{
		get_next_line(0, &line);

		split = ft_strsplit(line, ' ');
		inf->field = ft_strjoin(inf->field, split[1]); 
		inf->field = ft_strjoin(inf->field, "\n");
		i++;
	}
	free(split);

}

void	get_fig(t_info *inf)
{
	char	*line;
	int		lines;
	int		width;
	char	**split;

	line = NULL;
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	lines = ft_atoi(split[1]);
	width = ft_atoi(split[2]);
	free(split);
	inf->fig = ft_strnew(lines * width);
	while (lines != 0)
	{
		get_next_line(0, &line);
		inf->fig = ft_strjoin(inf->fig, line);
		inf->fig = ft_strjoin(inf->fig, "\n");
		lines--;	
	}
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

void	filler(t_info *inf)
{
	int		i;
	int		k;

	i = 0;
	k = 0;

	ft_putstr_fd("1 1\n", 1);
	free(inf->fig);
	free(inf->field);
}

int		main()
{
	t_info		inf;

	if (get_player(&inf) == 1)
		return (0);
	while (get_data(&inf))
		filler(&inf);
//	printf("player = %c\n", inf.player);
//	printf("%i %i\n", inf.lines, inf.width);
//	printf("field:\n%s\n", inf.field);
//	printf("fig\n%s", inf.fig);
//	put_fig(&inf);
//	printf("%c\n", inf.player);
	return (0);
}