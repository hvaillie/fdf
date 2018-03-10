/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:30:25 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/23 16:30:31 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		projo(t_mlx *tm, t_point *tp)
{
	int		x;
	int		y;
	int		z;

	x = tp->x * tm->szx;
	y = tp->y * tm->szy;
	z = tp->z * tm->szz;
	if (tm->proj == PROJPAR)
	{
		tm->po.x = x + (z * KP);
		tm->po.y = y + (z * KP / 2);
	}
	else
	{
		tm->po.x = (x * KI1) - (y * KI2);
		tm->po.y = (x * KI1 / 2) + (y * KI2 / 2) + z;
	}
}

void		projd(t_mlx *tm, t_point *tp)
{
	int		x;
	int		y;
	int		z;

	x = tp->x * tm->szx;
	y = tp->y * tm->szy;
	z = tp->z * tm->szz;
	if (tm->proj == PROJPAR)
	{
		tm->pd.x = x + (z * KP);
		tm->pd.y = y + (z * KP / 2);
	}
	else
	{
		tm->pd.x = (x * KI1) - (y * KI2);
		tm->pd.y = (x * KI1 / 2) + (y * KI2 / 2) + z;
	}
}

static void	map_xy(t_mlx *tm, int x[4], int y[4], int i)
{
	y[0 + i] = tm->po.y;
	y[1 + i] = tm->pd.y;
	x[0 + i] = tm->po.x;
	x[1 + i] = tm->pd.x;
}

int			compute_shift(t_mlx *tm)
{
	t_point			tp;
	int				x[4];
	int				y[4];

	if (tm->proj == PROJPAR)
		return ((((tm->iszv - ((tm->tf->nbrow - 1) * tm->szy)) / 2) * tm->szl)
		+ (((tm->iszh - ((tm->tf->nbpt - 1) * tm->szx)) / 2) * (tm->bpp / 8)));
	else
	{
		rotxyz(tm, &tp, 0, 0);
		projo(tm, &tp);
		rotxyz(tm, &tp, tm->tf->nbrow - 1, tm->tf->nbpt - 1);
		projd(tm, &tp);
		map_xy(tm, x, y, 0);
		rotxyz(tm, &tp, 0, tm->tf->nbpt - 1);
		projo(tm, &tp);
		rotxyz(tm, &tp, tm->tf->nbrow - 1, 0);
		projd(tm, &tp);
		map_xy(tm, x, y, 2);
		return ((((tm->iszv - (max4(y) - min4(y))) / 2) * tm->szl)
				- ((min4(y) < 0) ? min4(y) * tm->szl : 0)
				+ (((tm->iszh - (max4(x) - min4(x))) / 2) * (tm->bpp / 8))
				- ((min4(x) < 0) ? min4(x) * (tm->bpp / 8) : 0));
	}
}

int			check_pos(t_mlx *tm, t_draw *td, int *k, int i)
{
	td->p.x = tm->po.x + (td->incx * i);
	td->p.y = tm->po.y + (td->incy * i);
	*k = (tm->szl * td->p.y) + (tm->bpp / 8 * td->p.x) + tm->shift;
	if (*k < 0 || *k >= tm->max)
		return (KO);
	return (OK);
}
