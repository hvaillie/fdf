/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:06:16 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/13 12:06:20 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"

static void		load_map(char *line, t_fdf *tf, int *i)
{
	char	**tl;
	char	**pt;
	int		j;

	tl = ft_strsplit(line, ' ');
	j = 0;
	while (tl[j])
	{
		tf->tp[*i][j].x = j;
		tf->tp[*i][j].y = *i;
		pt = ft_strsplit(tl[j], ',');
		tf->tp[*i][j].z = ft_atoi(pt[0]);
		if (pt[1])
			tf->tp[*i][j].rgb = ft_atoi_base(pt[1], 16);
		else
			tf->tp[*i][j].rgb = -1;
		j++;
	}
}

int				load_file(t_fdf *tf)
{
	char	*line;
	int		ifd;
	int		lg;
	int		i;

	PROTECT(((ifd = open(TEMPFILE, O_RDONLY)) >= 0), KO);
	i = 0;
	while ((lg = get_next_line(ifd, &line)) > 0)
	{
		load_map(line, tf, &i);
		i++;
	}
	if (lg < 0)
		return (KO);
	close(ifd);
	return (OK);
}
