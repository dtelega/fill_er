/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:24:02 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/10 17:11:01 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"
# include "libft/libft.h"

typedef struct		s_info
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
	char		enemy;
}					t_info;

void				print_res(t_info *inf);
void				get_position_centre(t_info *inf);
void				get_position_enemy(t_info *inf);
int					fourth(int first, int sec, int three, int four);
int					pick_traf(t_info *inf, int zamena, int y, int i);
int					where_enemy(t_info *inf, int first, int sec, int three);
void				filler(t_info *inf, int x, int y, int dist);
int					get_player(t_info *inf);
int					get_size(t_info *inf);
void				get_field(t_info *inf);
void				get_fig(t_info *inf);
int					get_data(t_info *inf);

#endif
