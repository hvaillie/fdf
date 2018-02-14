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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"

int 	draw_line(t_mlx *tm)
{
	t_draw			td;
	int				i;
	int				j;

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
	i = 0;
	while (i <= td.loops)
	{
		td.p.x = tm->po.x + (td.incx * i);
		td.p.y = tm->po.y + (td.incy * i);
		fprintf(stdout, "point %d=(%d,%d) color=%d\n", i, td.p.x, td.p.y, td.color);
		j = 0;
		while(j < tm->bpp / 8)
		{
			tm->img_data[(tm->szl * td.p.y) + (tm->bpp / 8 * td.p.x) + j]
			 	= td.octets[j];
			j++;
		}
		i++;
	}
	fprintf(stdout, "ici\n");
	return (td.loops);
}

void 	draw_map(t_mlx *tm)
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				z;

	tm->img_ptr = mlx_new_image(tm->mlx_ptr, tm->iszh, tm->iszv);
	tm->img_data = mlx_get_data_addr(tm->img_ptr, &tm->bpp, &tm->szl, &tm->endian);
	tm->middle = (tm->iszh*tm->iszv*tm->bpp/8/2);
	fprintf(stdout, "middle=%d\n", tm->middle);
	fprintf(stdout, "bpp=%d, szl=%d, endian=%d\n", tm->bpp, tm->szl, tm->endian);
	i = 0;
	while (i < tm->tf->nbrow)
	{
		j = 0;
		while (j < tm->tf->nbpt)
		{
			if (j < tm->tf->nbpt  - 1)
			{
				x = (cos(tm->roz) * tm->tf->tp[i][j].x) - (sin(tm->roz) * tm->tf->tp[i][j].x);
				y = (sin(tm->roz) * tm->tf->tp[i][j].y) + (cos(tm->roz) * tm->tf->tp[i][j].y);
				z = tm->tf->tp[i][j].z;
				fprintf(stdout, "x=%d,y=%d,z=%d\n", x,y,z);
				tm->po.x = (x * tm->szx) + (z * tm->szz * KP) + tm->middle;
				tm->po.y = (y * tm->szy) + (z * tm->szz * KP / 2) + tm->middle;
				x = (cos(tm->roz) * tm->tf->tp[i][j + 1].x) - (sin(tm->roz) * tm->tf->tp[i][j + 1].x);
				y = (sin(tm->roz) * tm->tf->tp[i][j + 1].y) + (cos(tm->roz) * tm->tf->tp[i][j + 1].y);
				z = tm->tf->tp[i][j + 1].z;
				fprintf(stdout, "x=%d,y=%d,z=%d\n", x,y,z);
				tm->pd.x = (x * tm->szx) + (z * tm->szz * KP)  + tm->middle;
				tm->pd.y = (y * tm->szy) + (z * tm->szz * KP / 2) + tm->middle;
//				fprintf(stdout, "o=(%d,%d) d=(%d,%d)\n", tm->po.x,tm->po.y,tm->pd.x,tm->pd.y);
				if (tm->tf->tp[i][j + 1].rgb == -1)
					tm->rgb = WHITE;
				else
					tm->rgb = tm->tf->tp[i][j + 1].rgb;
				draw_line(tm);
			}
			if (i < tm->tf->nbrow - 1)
			{
				x = (cos(tm->roz) * tm->tf->tp[i][j].x) - (sin(tm->roz) * tm->tf->tp[i][j].x);
				y = (sin(tm->roz) * tm->tf->tp[i][j].y) + (cos(tm->roz) * tm->tf->tp[i][j].y);
				z = tm->tf->tp[i][j].z;
				fprintf(stdout, "x=%d,y=%d,z=%d\n", x,y,z);
				tm->po.x = (x * tm->szx) + (z * tm->szz * KP) + tm->middle;
				tm->po.y = (y * tm->szy) + (z * tm->szz * KP / 2) + tm->middle;
				x = (cos(tm->roz) * tm->tf->tp[i + 1][j].x) - (sin(tm->roz) * tm->tf->tp[i + 1][j].x);
				y = (sin(tm->roz) * tm->tf->tp[i + 1][j].y) + (cos(tm->roz) * tm->tf->tp[i + 1][j].y);
				z = tm->tf->tp[i + 1][j].z;
				fprintf(stdout, "x=%d,y=%d,z=%d\n", x,y,z);
				tm->pd.x = (x * tm->szx) + (z * tm->szz * KP) + tm->middle;
				tm->pd.y = (y * tm->szy) + (z * tm->szz * KP / 2) + tm->middle;
				if (tm->tf->tp[i + 1][j].rgb == -1)
					tm->rgb = WHITE;
				else
					tm->rgb = tm->tf->tp[i + 1][j].rgb;
				draw_line(tm);
			}
			j++;
		}
		i++;
	}
}
