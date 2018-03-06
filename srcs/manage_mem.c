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

void			free_split(char **c)
{
	int		i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}
