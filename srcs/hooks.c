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

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include "libft.h"

int		key_hook(int key, void *param)
{
	t_mlx	*tm;
	int		ret;

	tm = (t_mlx*)param;
	if (key == ESCAPE_KEY)
	{
		free_map(tm->tf);
		mlx_destroy_window(tm->mlx_ptr, tm->win_ptr);
		exit(0);
	}
	if (!(ret = key_hook_arrow(key, tm)))
		if (!(ret = key_hook_num(key, tm)))
			ret = key_hook_alpha(key, tm);
	if (ret)
		display_window(tm);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*tm;

	tm = (t_mlx*)param;
	(void)x;
	(void)y;
	if ((button == BUT_1 || button == BUT_4) && tm->minrgb > BLACK)
		tm->minrgb -= INC_PALETTE;
	else if ((button == BUT_2 || button == BUT_5) && tm->minrgb < WHITE)
		tm->minrgb += INC_PALETTE;
	else if (button == BUT_6 && tm->maxrgb < WHITE)
		tm->maxrgb += INC_PALETTE;
	else if (button == BUT_7 && tm->maxrgb > BLACK)
		tm->maxrgb -= INC_PALETTE;
	display_window(tm);
	return (0);
}

int		expose_hook(void *param)
{
	t_mlx	*tm;

	tm = (t_mlx*)param;
	display_window(tm);
	return (0);
}

int		loop_hook(void *param)
{
	t_mlx	*tm;

	tm = (t_mlx*)param;
	return (0);
}
