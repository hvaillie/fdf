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
