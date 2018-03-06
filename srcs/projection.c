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
	int				sz;
	int				x;
	int				y;

	if (tm->proj == PROJPAR)
		shift = (((tm->iszv - ((tm->tf->nbrow - 1) * tm->szy)) / 2) * tm->szl)
		+ (((tm->iszh - ((tm->tf->nbpt - 1) * tm->szx)) / 2) * (tm->bpp / 8));
	else
	{
		rotxyz(tm, &tp, 0, 0);
		projo(tm, &tp);
		rotxyz(tm, &tp, tm->tf->nbrow-1, tm->tf->nbpt-1);
		projd(tm, &tp);
		sz = ft_abs(tm->pd.y - tm->po.y);
		shift = ((tm->iszv - sz) / 2) * tm->szl;
		rotxyz(tm, &tp, 0, tm->tf->nbpt-1);
		projo(tm, &tp);
		rotxyz(tm, &tp, tm->tf->nbrow-1, 0);
		projd(tm, &tp);
		sz = ft_abs(tm->po.x - tm->pd.x);
		shift += ((tm->iszh - sz) / 2) * (tm->bpp / 8);
		shift += (tm->pd.x > 0) ? 0 : ft_abs(tm->pd.x) * (tm->bpp / 8);
	}
	y = shift / tm->szl;
	x = shift % tm->szl;
	printf("col=%d, lig=%d, szl=%d\n",x,y,tm->szl);
	return (shift);
}

int		check_pos(t_mlx *tm, t_draw *td, int *k)
{
	*k = (tm->szl * td->p.y) + (tm->bpp / 8 * td->p.x) + tm->shift;
	if (*k < 0 || *k >= tm->max)
		return (KO);
	return (OK);
}
