/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:45:55 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/14 17:45:58 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft.h"

static t_draw	set_td(t_mlx *tm)
{
	t_draw			td;

	td.diffx = tm->pd.x - tm->po.x;
	td.diffy = tm->pd.y - tm->po.y;
	td.loops = ft_max(ft_abs(td.diffx), ft_abs(td.diffy));
	td.incx = (float)td.diffx / td.loops;
	td.incy = (float)td.diffy / td.loops;
	td.color = mlx_get_color_value(tm->mlx_ptr, tm->rgb);
	td.octets[0] = td.color >> 0;
	td.octets[1] = td.color >> 8;
	td.octets[2] = td.color >> 16;
	td.octets[3] = td.color >> 24;
	return (td);
}

static void		draw_line(t_mlx *tm)
{
	t_draw			td;
	int				i;
	int				j;
	int				k;

	td = set_td(tm);
	i = 0;
	while (i <= td.loops)
	{
		if (check_pos(tm, &td, &k, i))
		{
			j = 0;
			while (j < tm->bpp / 8)
			{
				tm->img_data[k + j] = td.octets[j];
				j++;
			}
		}
		i++;
	}
}

static void		draw_h(t_mlx *tm, t_point *tp, int i, int j)
{
	rotxyz(tm, tp, i, j);
	projo(tm, tp);
	rotxyz(tm, tp, i, j + 1);
	projd(tm, tp);
	setcolor(tm, i, j + 1);
	draw_line(tm);
}

static void		draw_v(t_mlx *tm, t_point *tp, int i, int j)
{
	rotxyz(tm, tp, i, j);
	projo(tm, tp);
	rotxyz(tm, tp, i + 1, j);
	projd(tm, tp);
	setcolor(tm, i + 1, j);
	draw_line(tm);
}

void			draw_map(t_mlx *tm)
{
	int				i;
	int				j;
	t_point			tp;

	tm->img_ptr = mlx_new_image(tm->mlx_ptr, tm->iszh, tm->iszv);
	tm->img_data = mlx_get_data_addr(tm->img_ptr, &tm->bpp,
									&tm->szl, &tm->endian);
	tm->max = tm->iszh * tm->iszv * (tm->bpp / 8);
	tm->shift = compute_shift(tm) + tm->arrow;
	i = 0;
	while (i < tm->tf->nbrow)
	{
		j = 0;
		while (j < tm->tf->nbpt)
		{
			if (j < tm->tf->nbpt - 1)
				draw_h(tm, &tp, i, j);
			if (i < tm->tf->nbrow - 1)
				draw_v(tm, &tp, i, j);
			j++;
		}
		i++;
	}
}
