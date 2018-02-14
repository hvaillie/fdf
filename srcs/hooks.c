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
	if (key == NUM2_KEY && tm->szy)
		tm->szy--;
	else if (key == NUM4_KEY && tm->szx)
		tm->szx--;
	else if (key == NUM5_KEY)
	{
		tm->szx = DEFSZX;
		tm->szy = DEFSZY;
		tm->szz = DEFSZZ;
	}
	else if (key == NUM6_KEY)
		tm->szx++;
	else if (key == NUM7_KEY && tm->szz)
		tm->szz--;
	else if (key == NUM8_KEY)
		tm->szy++;
	else if (key == NUM9_KEY)
		tm->szz++;

	draw_map(tm);
	mlx_put_image_to_window(tm->mlx_ptr, tm->win_ptr,tm->img_ptr, 100, 100);
	mlx_destroy_image(tm->mlx_ptr, tm->img_ptr);
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
	draw_map(tm);
	mlx_put_image_to_window(tm->mlx_ptr, tm->win_ptr,tm->img_ptr, 100, 100);
	mlx_destroy_image(tm->mlx_ptr, tm->img_ptr);
	return (0);
}

int		loop_hook(void *param)
{
	t_mlx	*tm;

	tm = (t_mlx*)param;
	return (0);
}
