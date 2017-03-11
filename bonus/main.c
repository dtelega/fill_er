/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:38:22 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/10 17:38:23 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	o_win(void)
{
	ft_putstr("\e[33;31m    OOOO      OO          OO  OO  OO       OO\e[0m\n");
	ft_putstr("\e[33;31m   OO  OO     OO          OO  OO  OOOO     OO\e[0m\n");
	ft_putstr("\e[33;31m OO      OO   OO          OO  OO  OO OO    OO\e[0m\n");
	ft_putstr("\e[33;31mOO        OO  OO          OO  OO  OO  OO   OO\e[0m\n");
	ft_putstr("\e[33;31mOO        OO  OO    oo    OO  OO  OO  OO   OO\e[0m\n");
	ft_putstr("\e[33;31mOO        OO   OO   OO   OO   OO  OO   OO  OO\e[0m\n");
	ft_putstr("\e[33;31m OO      OO     OO  OO  OO    OO  OO    OO OO\e[0m\n");
	ft_putstr("\e[33;31m  OO    OO       OOOOOOOO     OO  OO     OOOO\e[0m\n");
	ft_putstr("\e[33;31m    OOOO          OO  OO      OO  OO       OO\e[0m\n");
	ft_putstr("\n");
}

void	x_win(void)
{
	ft_putstr("\e[32;32m XX      XX   XX          XX  XX  XX       XX\e[0m\n");
	ft_putstr("\e[32;32m  XX    XX    XX          XX  XX  XXXX     XX\e[0m\n");
	ft_putstr("\e[32;32m   XX  XX     XX          XX  XX  XX XX    XX\e[0m\n");
	ft_putstr("\e[32;32m    XXXX      XX          XX  XX  XX  XX   XX\e[0m\n");
	ft_putstr("\e[32;32m     XX       XX    xx    XX  XX  XX  XX   XX\e[0m\n");
	ft_putstr("\e[32;32m    XXXX       XX   XX   XX   XX  XX   XX  XX\e[0m\n");
	ft_putstr("\e[32;32m   XX  XX       XX  XX  XX    XX  XX    XX XX\e[0m\n");
	ft_putstr("\e[32;32m  XX    XX       XXXXXXXX     XX  XX     XXXX\e[0m\n");
	ft_putstr("\e[32;32m XX      XX       XX  XX      XX  XX       XX\e[0m\n");
	ft_putstr("\n");
}

int		finish(char *s)
{
	char	**split;
	int		x;
	int		o;

	split = (char **)malloc(5 * sizeof(split));
	split = ft_strsplit(s, ' ');
	o = ft_atoi(split[3]);
	get_next_line(0, &s);
	split = ft_strsplit(s, ' ');
	x = ft_atoi(split[3]);
	if (o > x)
		o_win();
	else if (o < x)
		x_win();
	else
		ft_putstr("no winner\n");
	return (1);
}

void	print_map(int lines)
{
	char	*s;
	int		i;

	s = NULL;
	ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n");
	while (lines-- != 0)
	{
		get_next_line(0, &s);
		i = 0;
		while (s[i])
		{
			if (s[i] == '.')
				ft_putstr(" ");
			if (s[i] == 'X')
				ft_putstr("\e[32;32mX\e[0m");
			if (s[i] == 'O')
				ft_putstr("\e[33;31mO\e[0m");
			if (s[i] == 'x')
				ft_putstr("\e[1;42mx\e[0m");
			if (s[i] == 'o')
				ft_putstr("\e[1;41mo\e[0m");
			i++;
		}
		ft_putchar('\n');
	}
	ft_putstr("\n\n");
}

int		main(void)
{
	char	*s;
	char	**split;
	int		lines;

	s = NULL;
	while (1)
	{
		get_next_line(0, &s);
		if (s[1] == 'l')
		{
			split = (char **)malloc(3 * sizeof(split));
			split = ft_strsplit(s, ' ');
			lines = ft_atoi(split[1]);
			free(split);
			get_next_line(0, &s);
			print_map(lines);
		}
		if (s[1] == '=')
		{
			finish(s);
			return (0);
		}
	}
	return (0);
}
