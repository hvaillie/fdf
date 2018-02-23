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

void	projo(t_mlx *tm, t_point *tp)
{
	if (tm->proj == PROJPAR)
	{
		tm->po.x = (tp->x * tm->szx) + (tp->z * tm->szz * KP);
		tm->po.y = (tp->y * tm->szy) + (tp->z * tm->szz * KP / 2);
	}
}

void	projd(t_mlx *tm, t_point *tp)
{
	if (tm->proj == PROJPAR)
	{
		tm->pd.x = (tp->x * tm->szx) + (tp->z * tm->szz * KP);
		tm->pd.y = (tp->y * tm->szy) + (tp->z * tm->szz * KP / 2);
	}
}
