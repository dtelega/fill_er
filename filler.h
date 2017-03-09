/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:24:02 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/03 17:24:03 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"
# include "libft/libft.h"

typedef struct 		s_info
{
	char		**fig;
	char		**field;
	int			lines;
	int			width;
	int			player;
	int			x_to_print;
	int			y_to_print;
	int			min_dist;
	int			put_true;
	int			x_enemy;
	int			y_enemy;
}							t_info;

#endif