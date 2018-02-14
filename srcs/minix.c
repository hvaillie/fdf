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


void		setmlx(t_fdf *tf)
{
	t_mlx			tm;

	tm.mlx_ptr = mlx_init();
	tm.tf = tf;
	tm.wszh = 5000;
	tm.wszv = 4000;
	tm.iszh = 4000;
	tm.iszv = 3000;
	tm.win_ptr = mlx_new_window(tm.mlx_ptr, tm.wszh, tm.wszv, "Fil De Fer");
	// tm.img_ptr = mlx_new_image(tm.mlx_ptr, tm.iszh, tm.iszv);
	// tm.img_data = mlx_get_data_addr(tm.img_ptr, &tm.bpp, &tm.szl, &tm.endian);
	// tm.middle = (tm.iszh*tm.iszv*tm.bpp/8/2);
	tm.szx = DEFSZX;
	tm.szy = DEFSZY;
	tm.szz = DEFSZZ;
	tm.rox = DEFROX;
	tm.roy = DEFROY;
	tm.roz = DEFROZ;
	// fprintf(stdout, "middle=%d\n", tm.middle);
	// fprintf(stdout, "bpp=%d, szl=%d, endian=%d\n", tm.bpp, tm.szl, tm.endian);
	mlx_key_hook(tm.win_ptr, key_hook, &tm);
	mlx_mouse_hook(tm.win_ptr, mouse_hook, &tm);
	mlx_expose_hook(tm.win_ptr, expose_hook, &tm);
	mlx_loop_hook(tm.mlx_ptr, loop_hook, &tm);
	mlx_loop(tm.mlx_ptr);
}
