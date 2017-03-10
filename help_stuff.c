/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:57:37 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/10 16:57:38 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fourth(int first, int sec, int three, int four)
{
	int		res;

	res = first;
	if (res < sec)
		res = sec;
	if (res < three)
		res = three;
	if (res < four)
		res = four;
	if (res == first)
		return (1);
	else if (res == sec)
		return (2);
	else if (res == three)
		return (3);
	else if (res == four)
		return (4);
	return (0);
}
