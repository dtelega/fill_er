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

 // \e[5;32mDEBUG:\e[0m

int		main(void)
{
	char	*s;
	int		i;

	s = NULL;
	get_next_line(0, &s);
	while (1)
	{
		get_next_line(0, &s);
		get_next_line(0, &s);
		while (s[i])
		{
			ft_putstr("\e[5;32m");
			ft_putchar(s[i]);
			ft_putstr("\e[0m");
		}
		return (0);
	}
}
