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

int		getcolor(t_mlx *tm, int z)
{
	double		pas;

	pas = (tm->maxrgb - tm->minrgb) / (tm->tf->zmax - tm->tf->zmin);
	return (tm->minrgb + pas * (z - tm->tf->zmin));
}

void 	rotx(t_mlx *tm, t_point *tp, int i, int j)
{
	double rad;

	rad = tm->rox * M_PI / 180;
	tp->x = tm->tf->tp[i][j].x;
	tp->y = (cos(rad) * tm->tf->tp[i][j].y)
	 		- (sin(rad) * tm->tf->tp[i][j].y);
	tp->z = (sin(rad) * tm->tf->tp[i][j].z)
	 		+ (cos(rad) * tm->tf->tp[i][j].z);
}

void 	roty(t_mlx *tm, t_point *tp, int i, int j)
{
	double rad;

	rad = tm->roy * M_PI / 180;
	tp->x = (cos(rad) * tm->tf->tp[i][j].x)
	 		+ (sin(rad) * tm->tf->tp[i][j].x);
	tp->y = tm->tf->tp[i][j].y;
	tp->z = -(sin(rad) * tm->tf->tp[i][j].z)
	 		+ (cos(rad) * tm->tf->tp[i][j].z);
}

void 	rotz(t_mlx *tm, t_point *tp, int i, int j)
{
	double rad;

	rad = tm->roz * M_PI / 180;
	tp->x = (cos(rad) * tm->tf->tp[i][j].x)
	 		- (sin(rad) * tm->tf->tp[i][j].x);
	tp->y = (sin(rad) * tm->tf->tp[i][j].y)
	 		+ (cos(rad) * tm->tf->tp[i][j].y);
	tp->z = tm->tf->tp[i][j].z;
}

void 	rotxyz(t_mlx *tm, t_point *tp, int i, int j)
{
	rotx(tm, tp, i, j);
	roty(tm, tp, i, j);
	rotz(tm, tp, i, j);
}

int 	draw_line(t_mlx *tm)
{
	t_draw			td;
	int				i;
	int				j;
	int				k;

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
		j = 0;
		k = (tm->szl * td.p.y) + (tm->bpp / 8 * td.p.x) + tm->shift;
		//fprintf(stdout, "point %d=(%d,%d) color=%d, k=%d\n", i, td.p.x, td.p.y, td.color, k);
		while(j < tm->bpp / 8 && k >= 0 && k < tm->max)
		{
			tm->img_data[k + j] = td.octets[j];
			j++;
		}
		i++;
	}
	return (td.loops);
}

void 	draw_map(t_mlx *tm)
{
	int				i;
	int				j;
	t_point			tp;

	tm->img_ptr = mlx_new_image(tm->mlx_ptr, tm->iszh, tm->iszv);
	tm->img_data = mlx_get_data_addr(tm->img_ptr, &tm->bpp, &tm->szl, &tm->endian);
	tm->max = tm->iszh * tm->iszv * tm->bpp / 8;
	if (tm->shift == DEFSHIFT)
		tm->shift = ft_abs(tm->tf->zmin * tm->szl) + ft_abs(tm->tf->zmax * tm->bpp / 8 * tm->szz);
	//fprintf(stdout, "shift=%d, max=%d\n", tm->shift,tm->max);
	//fprintf(stdout, "bpp=%d, szl=%d, endian=%d\n", tm->bpp, tm->szl, tm->endian);
	i = 0;
	while (i < tm->tf->nbrow)
	{
		j = 0;
		while (j < tm->tf->nbpt)
		{
			if (j < tm->tf->nbpt  - 1)
			{
				rotxyz(tm, &tp, i, j);
				//fprintf(stdout, "x=%d,y=%d,z=%d\n", tp.x,tp.y,tp.z);
				tm->po.x = (tp.x * tm->szx) + (tp.z * tm->szz * KP);
				tm->po.y = (tp.y * tm->szy) + (tp.z * tm->szz * KP / 2);
				rotxyz(tm, &tp, i, j + 1);
				//fprintf(stdout, "x=%d,y=%d,z=%d\n", tp.x,tp.y,tp.z);
				tm->pd.x = (tp.x * tm->szx) + (tp.z * tm->szz * KP);
				tm->pd.y = (tp.y * tm->szy) + (tp.z * tm->szz * KP / 2);
				//fprintf(stdout, "o=(%d,%d) d=(%d,%d)\n", tm->po.x,tm->po.y,tm->pd.x,tm->pd.y);
				if (tm->tf->tp[i][j + 1].rgb == -1)
					tm->rgb = getcolor(tm, tm->tf->tp[i][j + 1].z);
				else
					tm->rgb = tm->tf->tp[i][j + 1].rgb;
				draw_line(tm);
			}
			if (i < tm->tf->nbrow - 1)
			{
				rotxyz(tm, &tp, i, j);
				//fprintf(stdout, "x=%d,y=%d,z=%d\n", tp.x,tp.y,tp.z);
				tm->po.x = (tp.x * tm->szx) + (tp.z * tm->szz * KP);
				tm->po.y = (tp.y * tm->szy) + (tp.z * tm->szz * KP / 2);
				rotxyz(tm, &tp, i + 1, j);
				//fprintf(stdout, "x=%d,y=%d,z=%d\n", tp.x,tp.y,tp.z);
				tm->pd.x = (tp.x * tm->szx) + (tp.z * tm->szz * KP);
				tm->pd.y = (tp.y * tm->szy) + (tp.z * tm->szz * KP / 2);
				if (tm->tf->tp[i + 1][j].rgb == -1)
					tm->rgb = getcolor(tm, tm->tf->tp[i + 1][j].z);
				else
					tm->rgb = tm->tf->tp[i + 1][j].rgb;
				draw_line(tm);
			}
			j++;
		}
		i++;
	}
}
