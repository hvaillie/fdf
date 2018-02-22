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

#include <stdio.h>

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include "libft.h"

static void	legende_val(t_mlx *tm)
{
	char 	*str;

	str = ft_strnew(100);
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 800, 1, GREEN, "Valeurs");
	str = ft_strcat(str, "shift=");
	str = ft_strcat(str, ft_itoa(tm->shift));
	str = ft_strcat(str, " szX=");
	str = ft_strcat(str, ft_itoa(tm->szx));
	str = ft_strcat(str, " szY=");
	str = ft_strcat(str, ft_itoa(tm->szy));
	str = ft_strcat(str, " szZ=");
	str = ft_strcat(str, ft_itoa(tm->szz));
	str = ft_strcat(str, " roX=");
	str = ft_strcat(str, ft_itoa(tm->rox));
	str = ft_strcat(str, " roY=");
	str = ft_strcat(str, ft_itoa(tm->roy));
	str = ft_strcat(str, " roZ=");
	str = ft_strcat(str, ft_itoa(tm->roz));
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 800, 20, WHITE, str);
	free(str);
}

static void	legende(t_mlx *tm)
{
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 1, 1, GREEN, "Pave Num");
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 1, 20, WHITE,
		"0=rien  1=rien  2=y--  3=rien  4=x--  5=reset  6=x++  7=z--  8=y++  9=z++" );
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 1, 40, GREEN, "Arrows");
	mlx_string_put(tm->mlx_ptr, tm->win_ptr, 1, 60, WHITE,
		"<=left  >=rigth  V=Down  ^=UP" );
	legende_val(tm);

}

void 		display_window(t_mlx *tm)
{
	draw_map(tm);
	mlx_clear_window(tm->mlx_ptr, tm->win_ptr);
	legende(tm);
	mlx_put_image_to_window(tm->mlx_ptr, tm->win_ptr,tm->img_ptr, 100, 100);
	mlx_destroy_image(tm->mlx_ptr, tm->img_ptr);
}

void		setmlx(t_fdf *tf)
{
	t_mlx			tm;

	tm.mlx_ptr = mlx_init();
	tm.tf = tf;
	tm.wszh = WINDOW_SIZE_H;
	tm.wszv = WINDOW_SIZE_V;
	tm.iszh = IMAGE_SIZE_H;
	tm.iszv = IMAGE_SIZE_V;
	tm.win_ptr = mlx_new_window(tm.mlx_ptr, tm.wszh, tm.wszv, "Fil De Fer");
	// tm.img_ptr = mlx_new_image(tm.mlx_ptr, tm.iszh, tm.iszv);
	// tm.img_data = mlx_get_data_addr(tm.img_ptr, &tm.bpp, &tm.szl, &tm.endian);
	tm.shift = DEFSHIFT;
	tm.szx = DEFSZX;
	tm.szy = DEFSZY;
	tm.szz = DEFSZZ;
	tm.rox = DEFROX;
	tm.roy = DEFROY;
	tm.roz = DEFROZ;
	tm.minrgb = DEF_MIN_PALETTE;
	tm.maxrgb = DEF_MAX_PALETTE;
	// fprintf(stdout, "middle=%d\n", tm.middle);
	// fprintf(stdout, "bpp=%d, szl=%d, endian=%d\n", tm.bpp, tm.szl, tm.endian);
	mlx_key_hook(tm.win_ptr, key_hook, &tm);
	mlx_mouse_hook(tm.win_ptr, mouse_hook, &tm);
	mlx_expose_hook(tm.win_ptr, expose_hook, &tm);
	mlx_loop_hook(tm.mlx_ptr, loop_hook, &tm);
	legende(&tm);
	mlx_loop(tm.mlx_ptr);
}
