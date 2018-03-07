/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:56:51 by hvaillie          #+#    #+#             */
/*   Updated: 2018/03/05 17:56:57 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void		display_line(t_fdf *tf, int i)
{
	int		j;

	j = 0;
	while (j < tf->nbpt)
	{
		if (j > 0)
			ft_putstr("; ");
		ft_putnbr(tf->tp[i][j].x);
		ft_putchar(',');
		ft_putnbr(tf->tp[i][j].y);
		ft_putchar(',');
		ft_putnbr(tf->tp[i][j].z);
		ft_putchar(',');
		ft_putnbr(tf->tp[i][j].rgb);
		j++;
	}
}

void			display_map(t_fdf *tf)
{
	int		i;

	i = 0;
	while (i < tf->nbrow)
	{
		ft_putstr("Elem (");
		ft_putnbr(i);
		ft_putstr(") , '");
		display_line(tf, i);
		ft_putendl("'");
		i++;
	}
	ft_putstr("Map nbpt=");
	ft_putnbr(tf->nbpt);
	ft_putstr(" , nbrow=");
	ft_putnbr(tf->nbrow);
	ft_putstr(" , Zmin=");
	ft_putnbr(tf->zmin);
	ft_putstr(" , Zmax=");
	ft_putnbr(tf->zmax);
	ft_putchar('\n');
}
