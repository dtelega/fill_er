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

void	print_res(t_info *inf)
{
	ft_putnbr_fd(inf->y_to_print, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(inf->x_to_print, 1);
	ft_putstr_fd("\n", 1);
	free(inf->fig);
	free(inf->field);
}

int		main(void)
{
	t_info		inf;

	if (get_player(&inf) == 1)
		return (0);
	while (get_data(&inf))
		filler(&inf, 0, 0, 0);
	return (0);
}
