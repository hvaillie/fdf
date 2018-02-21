/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:33:48 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/14 16:33:53 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include "libft.h"

int 	key_hook(int key, void *param) {
	t_mlx	*tm;

	tm = (t_mlx*)param;
		fprintf(stdout, "Key=%d\n", key);
	if (key == ESCAPE_KEY)
		exit(0);
	if (key == ARROW_UP_KEY && tm->shift >= tm->szl * 4)
		tm->shift -= tm->szl * 4;
	else if (key == ARROW_DOWN_KEY)
		tm->shift += tm->szl * 4;
	else if (key == ARROW_LEFT_KEY && tm->shift)
		tm->shift -= 16;
	else if (key == ARROW_RIGHT_KEY)
		tm->shift += 16;
	else if (key == NUM2_KEY && tm->szy)
		tm->szy--;
	else if (key == NUM4_KEY && tm->szx)
		tm->szx--;
	else if (key == NUM5_KEY)
	{
		tm->szx = DEFSZX;
		tm->szy = DEFSZY;
		tm->szz = DEFSZZ;
		tm->shift = DEFSHIFT;
		tm->rox = DEFROX;
		tm->roy = DEFROY;
		tm->roz = DEFROZ;
	}
	else if (key == NUM6_KEY)
		tm->szx++;
	else if (key == NUM7_KEY && tm->szz)
		tm->szz--;
	else if (key == NUM8_KEY)
		tm->szy++;
	else if (key == NUM9_KEY)
		tm->szz++;
	else if (key == Q_KEY)
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
	display_window(tm);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*tm;

	tm = (t_mlx*)param;
	fprintf(stdout, "Mouse Button=%d ,x=%d ,y=%d\n", button, x, y);
	return (0);
}

int		expose_hook(void *param)
{
	t_mlx	*tm;

	tm = (t_mlx*)param;
	fprintf(stdout, "Expose\n");
	display_window(tm);
	return (0);
}

int		loop_hook(void *param)
{
	t_mlx	*tm;

	tm = (t_mlx*)param;
	return (0);
}
