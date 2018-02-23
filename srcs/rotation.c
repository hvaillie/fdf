/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:05:18 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/23 17:05:20 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	rotx(t_mlx *tm, t_point *tp, int i, int j)
{
	double rad;

	rad = tm->rox * M_PI / 180;
	tp->x = tm->tf->tp[i][j].x;
	tp->y = (cos(rad) * tm->tf->tp[i][j].y)
			- (sin(rad) * tm->tf->tp[i][j].y);
	tp->z = (sin(rad) * tm->tf->tp[i][j].z)
			+ (cos(rad) * tm->tf->tp[i][j].z);
}

static void	roty(t_mlx *tm, t_point *tp, int i, int j)
{
	double rad;

	rad = tm->roy * M_PI / 180;
	tp->x = (cos(rad) * tm->tf->tp[i][j].x)
			+ (sin(rad) * tm->tf->tp[i][j].x);
	tp->y = tm->tf->tp[i][j].y;
	tp->z = -(sin(rad) * tm->tf->tp[i][j].z)
			+ (cos(rad) * tm->tf->tp[i][j].z);
}

static void	rotz(t_mlx *tm, t_point *tp, int i, int j)
{
	double rad;

	rad = tm->roz * M_PI / 180;
	tp->x = (cos(rad) * tm->tf->tp[i][j].x)
			- (sin(rad) * tm->tf->tp[i][j].x);
	tp->y = (sin(rad) * tm->tf->tp[i][j].y)
			+ (cos(rad) * tm->tf->tp[i][j].y);
	tp->z = tm->tf->tp[i][j].z;
}

void		rotxyz(t_mlx *tm, t_point *tp, int i, int j)
{
	rotx(tm, tp, i, j);
	roty(tm, tp, i, j);
	rotz(tm, tp, i, j);
}
