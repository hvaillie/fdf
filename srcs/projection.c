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

#include <stdio.h>

#include <math.h>
#include "fdf.h"
#include "libft.h"

void	projo(t_mlx *tm, t_point *tp)
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

void	projd(t_mlx *tm, t_point *tp)
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

int		compute_shift(t_mlx *tm)
{
	t_point			tp;
	int				shift;
	int				x[4];
	int				y[4];

	if (tm->proj == PROJPAR)
		shift = (((tm->iszv - ((tm->tf->nbrow - 1) * tm->szy)) / 2) * tm->szl)
		+ (((tm->iszh - ((tm->tf->nbpt - 1) * tm->szx)) / 2) * (tm->bpp / 8));
	else
	{
		rotxyz(tm, &tp, 0, 0);
		projo(tm, &tp);
		rotxyz(tm, &tp, tm->tf->nbrow - 1, tm->tf->nbpt - 1);
		projd(tm, &tp);
		y[0] = tm->po.y;
		y[1] = tm->pd.y;
		x[0] = tm->po.x;
		x[1] = tm->pd.x;
		rotxyz(tm, &tp, 0, tm->tf->nbpt - 1);
		projo(tm, &tp);
		rotxyz(tm, &tp, tm->tf->nbrow - 1, 0);
		projd(tm, &tp);
		y[2] = tm->po.y;
		y[3] = tm->pd.y;
		x[2] = tm->po.x;
		x[3] = tm->pd.x;
		printf("x0=%d, x1=%d, x2=%d, x3=%d, ",x[0],x[1],x[2],x[3]);
		printf("y0=%d, y1=%d, y2=%d, y3=%d\n",y[0],y[1],y[2],y[3]);
		shift = round((tm->iszv - (max4(y) - min4(y))) / 2) * tm->szl;
		shift -= (min4(y) < 0) ? min4(y) * tm->szl : 0;
		printf("shift1=%d, ", shift);
		shift += ((tm->iszh - (max4(x) - min4(x))) / 2) * (tm->bpp / 8);
		shift -= (min4(x) < 0) ? min4(x) * (tm->bpp / 8) : 0;
		printf("shift2=%d, ", shift);
	}
	printf("col=%d, lig=%d, szl=%d\n",(shift%tm->szl)/4,shift/tm->szl,tm->szl);
	return (shift);
}

int		check_pos(t_mlx *tm, t_draw *td, int *k, int i)
{
	td->p.x = tm->po.x + (td->incx * i);
	td->p.y = tm->po.y + (td->incy * i);
	*k = (tm->szl * td->p.y) + (tm->bpp / 8 * td->p.x) + tm->shift;
	if (*k < 0 || *k >= tm->max)
		return (KO);
	// if (i > 0)
	// 	i = 0;
	// {
	// 	//if (td->incx > 0 && (((*k % tm->szl) / 4 < ((*k - 4) % tm->szl) / 4)))
	// 	if (td->incx > 0 && tm->midx > 0
	// 	&& (*k%tm->szl)/4 < 1980/2)
	// 	{
	// 		printf("debord droite k=%d, kprev=%d, td->p.x=%d, shiftX=%d\n",
	// 		(*k%tm->szl)/4,((*k-4)%tm->szl)/4,td->p.x,((tm->shift)%tm->szl)/4);
	// 		return (KO);
	// 	}
		//if (td->incx < 0 && (((*k % tm->szl) / 4 > ((*k + 4) % tm->szl) / 4)))
		// if (td->incx < 0 && (td->p.x + (((tm->shift)%tm->szl)/4)) <= 10)
		// {
		// 	printf("debord gauche k=%d, kprev=%d, td->p.x=%d, shiftX=%d\n",
		// 	(*k%tm->szl)/4,((*k-4)%tm->szl)/4,td->p.x,((tm->shift)%tm->szl)/4);
		// 	return (KO);
		// }
	//}
	return (OK);
}
