/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:46:55 by hvaillie          #+#    #+#             */
/*   Updated: 2018/03/16 15:46:59 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"
#include "libft.h"

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

	// if (tm->proj == PROJPAR)
	// 	return ((((tm->iszv - ((tm->tf->nbrow - 1) * tm->szy)) / 2) * tm->szl)
	// 	+ (((tm->iszh - ((tm->tf->nbpt - 1) * tm->szx)) / 2) * (tm->bpp / 8)));
	// else
	// {
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
		tm->pszx = max4(x) - min4(x);
		tm->pszy = max4(y) - min4(y);
		printf("minX=%d, maxX=%d, minY=%d, maxY=%d",min4(x),max4(x),min4(y),max4(y));
		printf(", Piece X=%d, Y=%d\n",tm->pszx,tm->pszy);
		// printf("x0=%d, x1=%d, x2=%d, x3=%d",x[0],x[1],x[2],x[3]);
		// printf(", y0=%d, y1=%d, y2=%d, y3=%d\n",y[0],y[1],y[2],y[3]);
		return ((((tm->iszv - tm->pszy) / 2) * tm->szl)
				- ((min4(y) < 0) ? min4(y) * tm->szl : 0)
				+ (((tm->iszh - tm->pszx) / 2) * (tm->bpp / 8))
				- ((min4(x) < 0) ? min4(x) * (tm->bpp / 8) : 0));
	// }
}

int			check_pos(t_mlx *tm, t_draw *td, int *k, int i)
{
	int		pos;

	td->p.x = tm->po.x + (td->incx * i);
	td->p.y = tm->po.y + (td->incy * i);
	*k = (tm->szl * td->p.y) + (tm->bpp / 8 * td->p.x) + tm->shift;
	if (*k < 0 || *k >= tm->max)
		return (KO);
	pos = (ft_modulo(tm->shift, tm->szl) / (tm->bpp / 8)) + td->p.x;
	if (pos >= tm->iszh || pos <= 0)
	{
		//printf("td->p.x=%d, pos=%d\n",td->p.x,pos);
		return (KO);
	}

	return (OK);
}
