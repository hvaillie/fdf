/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:09:44 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/23 17:09:46 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	getcolor(t_mlx *tm, int z)
{
	double		pas;

	pas = (tm->maxrgb - tm->minrgb) / (tm->tf->zmax - tm->tf->zmin);
	return (tm->minrgb + pas * (z - tm->tf->zmin));
}

void		setcolor(t_mlx *tm, int i, int j)
{
	if (tm->tf->tp[i][j].rgb == -1)
		tm->rgb = getcolor(tm, tm->tf->tp[i][j].z);
	else
		tm->rgb = tm->tf->tp[i][j].rgb;
}
