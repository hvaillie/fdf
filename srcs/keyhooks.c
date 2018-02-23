/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:35:50 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/23 16:35:53 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook_arrow(int key, t_mlx *tm)
{
	PROTECT((key == ARROW_UP_KEY || key == ARROW_DOWN_KEY ||
		key == ARROW_LEFT_KEY || key == ARROW_RIGHT_KEY), KO);
	if (key == ARROW_UP_KEY && tm->shift >= tm->szl * 4)
		tm->shift -= tm->szl * 8;
	else if (key == ARROW_DOWN_KEY)
		tm->shift += tm->szl * 8;
	else if (key == ARROW_LEFT_KEY && tm->shift)
		tm->shift -= 32;
	else if (key == ARROW_RIGHT_KEY)
		tm->shift += 32;
	return (OK);
}

int		key_hook_num(int key, t_mlx *tm)
{
	PROTECT((key == NUM2_KEY || key == NUM4_KEY || key == NUM5_KEY || key ==
	NUM6_KEY || key == NUM7_KEY || key == NUM8_KEY || key == NUM9_KEY), KO);
	if (key == NUM2_KEY && tm->szy)
		tm->szy--;
	else if (key == NUM4_KEY && tm->szx)
		tm->szx--;
	else if (key == NUM5_KEY)
		setvar(tm);
	else if (key == NUM6_KEY)
		tm->szx++;
	else if (key == NUM7_KEY && tm->szz)
		tm->szz--;
	else if (key == NUM8_KEY)
		tm->szy++;
	else if (key == NUM9_KEY)
		tm->szz++;
	return (OK);
}

int		key_hook_alpha(int key, t_mlx *tm)
{
	PROTECT((key == Q_KEY || key == W_KEY || key == A_KEY || key == S_KEY ||
	key == Z_KEY || key == X_KEY), KO);
	if (key == Q_KEY)
		tm->roz--;
	else if (key == W_KEY)
		tm->roz++;
	else if (key == A_KEY)
		tm->rox--;
	else if (key == S_KEY)
		tm->rox++;
	else if (key == Z_KEY)
		tm->roy--;
	else if (key == X_KEY)
		tm->roy++;
	return (OK);
}
