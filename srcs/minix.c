/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:49:20 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/13 16:49:23 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include "libft.h"

static void		legende_val(t_mlx *tm, char *str)
{
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 800, 1, GREEN, "Valeurs");
	str = concat_legend(str, "shift=", tm->shift, &ft_itoa);
	str = concat_legend(str, " szX=", tm->szx, &ft_itoa);
	str = concat_legend(str, " szY=", tm->szy, &ft_itoa);
	str = concat_legend(str, " szZ=", tm->szz, &ft_itoa);
	str = concat_legend(str, " roX=", tm->rox, &ft_itoa);
	str = concat_legend(str, " roY=", tm->roy, &ft_itoa);
	str = concat_legend(str, " roZ=", tm->roz, &ft_itoa);
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 800, 20, WHITE, str);
	ft_bzero((void*)str, 100);
	str = concat_legend(str, "minRGB=", tm->minrgb, &ft_itoa_base_16);
	str = concat_legend(str, " maxRGB=", tm->maxrgb, &ft_itoa_base_16);
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 800, 40, WHITE, str);
}

static void		legende(t_mlx *tm)
{
	char	*str;

	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 1, 1, GREEN, "Pave Num");
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 1, 20, WHITE,
		"2=y--  4=x--  5=reset  6=x++  7=z--  8=y++  9=z++");
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 1, 40, GREEN, "Arrows");
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 1, 60, WHITE,
		"<=left  >=rigth  V=Down  ^=UP");
	str = ft_strnew(100);
	legende_val(tm, str);
	free(str);
}

void			display_window(t_mlx *tm)
{
	draw_map(tm);
	mlx_clear_window(tm->mlx_ptr, tm->win_ptr);
	legende(tm);
	mlx_put_image_to_window(tm->mlx_ptr, tm->win_ptr, tm->img_ptr, 10, 100);
	mlx_destroy_image(tm->mlx_ptr, tm->img_ptr);
}

void			setvar(t_mlx *tm)
{
	tm->wszh = WINDOW_SIZE_H;
	tm->wszv = WINDOW_SIZE_V;
	tm->iszh = IMAGE_SIZE_H;
	tm->iszv = IMAGE_SIZE_V;
	tm->shift = DEFSHIFT;
	tm->szx = IMAGE_SIZE_H / tm->tf->nbpt;
	if (tm->szx == 0)
		tm->szx = 1;
	if (tm->szx > DEFSZX)
		tm->szx = DEFSZX;
	tm->szy = IMAGE_SIZE_V / tm->tf->nbrow;
	if (tm->szy == 0)
		tm->szy = 1;
	if (tm->szy > DEFSZY)
		tm->szy = DEFSZY;
	tm->szz = DEFSZZ;
	tm->rox = DEFROX;
	tm->roy = DEFROY;
	tm->roz = DEFROZ;
	tm->minrgb = DEF_MIN_PALETTE;
	tm->maxrgb = DEF_MAX_PALETTE;
	tm->proj = PROJISO;
}

void			setmlx(t_fdf *tf)
{
	t_mlx			tm;

	tm.mlx_ptr = mlx_init();
	tm.tf = tf;
	setvar(&tm);
	tm.win_ptr = mlx_new_window(tm.mlx_ptr, tm.wszh, tm.wszv, "Fil De Fer");
	mlx_hook(tm.win_ptr, 2, 1L << 0, key_hook, &tm);
	mlx_hook(tm.win_ptr, 4, 1L << 0, mouse_hook, &tm);
	mlx_expose_hook(tm.win_ptr, expose_hook, &tm);
	mlx_loop_hook(tm.mlx_ptr, loop_hook, &tm);
	legende(&tm);
	mlx_loop(tm.mlx_ptr);
}
