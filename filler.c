/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:44:04 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/10 16:44:05 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(t_info *inf, int x, int y, int dist)
{
	inf->put_true = 0;
	inf->y_to_print = 0;
	get_position_centre(inf);
	inf->min_dist = 10000;
	while (inf->y_to_print < inf->lines)
	{
		inf->x_to_print = -1;
		while (++inf->x_to_print < inf->width)
			if (pick_traf(inf, 0, inf->y_to_print - 1, -1) == 1
				&& (inf->put_true = 1))
				if ((dist = (inf->x_to_print - inf->x_enemy) * (inf->x_to_print
					- inf->x_enemy) + (inf->y_to_print - inf->y_enemy) *
					(inf->y_to_print - inf->y_enemy)) <= inf->min_dist)
				{
					inf->min_dist = dist;
					y = inf->y_to_print;
					x = inf->x_to_print;
				}
		inf->y_to_print++;
	}
	inf->x_to_print = x;
	inf->y_to_print = y;
	print_res(inf);
}

int		pick_traf(t_info *inf, int zamena, int y, int i)
{
	int		x;
	int		l;

	while (inf->fig[++i] && inf->field[++y] && (l = -1))
	{
		x = inf->x_to_print;
		while (inf->fig[i][++l])
		{
			if (inf->fig[i][l] == '*' && inf->field[y][x] == inf->player)
				zamena++;
			if (inf->field[y][x] != '.' && inf->field[y][x] != 'X' &&
				inf->field[y][x] != 'x' && inf->field[y][x] != 'O' &&
				inf->field[y][x] != 'o')
				return (0);
			if (inf->fig[i][l] == '*' && inf->field[y][x] != inf->player &&
				inf->field[y][x] != '.')
				return (0);
			x++;
		}
		if (inf->fig[i][l] != '\0' || (inf->fig[i] && !inf->field[y]))
			return (0);
	}
	if (zamena != 1 || inf->fig[i])
		return (0);
	return (1);
}

void	get_position_enemy(t_info *inf)
{
	int		x_e;
	int		y_e;
	char	enemy;

	y_e = 0;
	if (inf->player == 'X')
		enemy = 'O';
	else
		enemy = 'X';
	while (y_e < inf->lines)
	{
		x_e = 0;
		while (x_e < inf->width)
		{
			if (inf->field[y_e][x_e] == enemy)
			{
				inf->x_enemy = x_e;
				inf->y_enemy = y_e;
				return ;
			}
			x_e++;
		}
		y_e++;
	}
}

int		where_enemy(t_info *inf, int first, int sec, int three)
{
	int		four;
	int		x;
	int		y;

	y = -1;
	while (++y < inf->lines / 2 && (x = -1))
		while (++x < inf->width / 2 && (four = 0) == 0)
		{
			if (inf->field[y][x] == inf->enemy)
				first++;
			if (inf->field[y][x] == inf->player)
				first--;
		}
	y = -1;
	while (++y < inf->lines / 2 && (x = inf->width / 2 - 1))
		while (++x < inf->width)
		{
			if (inf->field[y][x] == inf->enemy)
				sec++;
			if (inf->field[y][x] == inf->player)
				sec--;
		}
	y = inf->lines / 2 - 1;
	while (++y < inf->lines && (x = -1))
		while (++x < inf->width / 2)
		{
			if (inf->field[y][x] == inf->enemy)
				three++;
			if (inf->field[y][x] == inf->player)
				three--;
		}
	y = inf->lines / 2 - 1;
	while (++y < inf->lines && (x = inf->width / 2 - 1))
		while (++x < inf->width)
		{
			if (inf->field[y][x] == inf->enemy)
				four++;
			if (inf->field[y][x] == inf->player)
				four--;
		}
	return (fourth(first, sec, three, four));
}

void	get_position_centre(t_info *inf)
{
	if (where_enemy(inf, 0, 0, 0) == 1)
	{
		inf->x_enemy = 0;
		inf->y_enemy = inf->lines / 3;
	}
	else if (where_enemy(inf, 0, 0, 0) == 2)
	{
		inf->x_enemy = 3 * inf->width / 4;
		inf->y_enemy = 0;
	}
	else if (where_enemy(inf, 0, 0, 0) == 3)
	{
		inf->x_enemy = 0;
		inf->y_enemy = inf->lines / 2;
	}
	else if (where_enemy(inf, 0, 0, 0) == 4)
	{
		inf->x_enemy = inf->width - 1;
		inf->y_enemy = 4 * inf->lines / 5;
	}
}
