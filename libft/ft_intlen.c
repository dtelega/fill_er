/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:47:36 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/08 14:03:35 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_intlen(int a)
{
	size_t		i;

	if (a == 0)
		return (1);
	i = 0;
	if (a < 0)
	{
		a *= -1;
		i++;
	}
	while (a)
	{
		a = a / 10;
		i++;
	}
	return (i);
}
