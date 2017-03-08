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

int		pick_traf(t_info *inf)
{
	int		zamena;
	int		x;
	int		y;
	int		i;
	int		l;

	zamena = 0;
	y = inf->y_to_print;
	i = 0;
	l = 0;
	zamena = 0;
	while (inf->fig[i] && inf->field[y])
	{
		x = inf->x_to_print;
		l = 0;
		while (inf->fig[i][l])
		{
			if (inf->fig[i][l] == '*' && inf->field[y][x] == inf->player)
				zamena++;
			if (inf->field[y][x] != '.' && inf->field[y][x] != 'X' && inf->field[y][x] != 'x' && inf->field[y][x] != 'O' && inf->field[y][x] != 'o')
				return (0);
			if (inf->fig[i][l] == '*' && inf->field[y][x] != inf->player && inf->field[y][x] != '.')
				return (0);
			l++;
			x++;
		}
		if (inf->fig[i][l] != '\0' || (inf->fig[i] && !inf->field[y]))
			return (0);
		i++;
		y++;
	}
	if (zamena != 1 || inf->fig[i])
		return (0);
	
	return (1);
}

void	print_res(t_info *inf)
{
	ft_putnbr_fd(inf->y_to_print, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(inf->x_to_print, 1);
	ft_putstr_fd("\n", 1);
	free(inf->fig);
	free(inf->field);
}

void	filler(t_info *inf)
{

	inf->y_to_print = 0;
//	printf("START FILLER\n");
	while (inf->y_to_print < inf->lines)
	{
//		printf("Y = %d\n", inf->y_to_print);
		inf->x_to_print = 0;
		while (inf->x_to_print < inf->width)
		{
//			printf("Y = %d | ", inf->y_to_print);
//			printf("X = %d\n", inf->x_to_print);
			if (pick_traf(inf) == 1)
			{
//				printf("/////////////////////////////////////////FINISH");
//				printf("hato to printf y = %d, x =%d\n", inf->y_to_print, inf->x_to_print);
				print_res(inf);
				return ;
			}
			inf->x_to_print++;
		}
		inf->y_to_print++;
	}
	inf->x_to_print = 0;
	inf->y_to_print = 0;
	print_res(inf);
}

int		main()
{
	t_info		inf;

	if (get_player(&inf) == 1)
		return (0);
	while (get_data(&inf))
		filler(&inf);
	return (0);
}