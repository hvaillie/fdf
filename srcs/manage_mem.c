/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:28:45 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/13 11:28:48 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

int				alloc_map(t_fdf *tf)
{
	int		i;

	PROTECT((tf->tp = (t_point**)ft_memalloc(sizeof(t_point*) * tf->nbrow)),
					KO);
	i = 0;
	while (i < tf->nbrow)
	{
		PROTECT((tf->tp[i] = (t_point*)ft_memalloc(sizeof(t_point) * tf->nbpt)),
						KO);
		i++;
	}
	return (OK);
}

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

void			free_map(t_fdf *tf)
{
	int		i;

	i = 0;
	while (i < tf->nbrow)
	{
		free(tf->tp[i]);
		i++;
	}
	free(tf->tp);
}
