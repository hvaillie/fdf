/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:32:36 by hvaillie          #+#    #+#             */
/*   Updated: 2018/02/01 15:32:41 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"

static int		check_file(char *line, t_fdf *tf)
{
	char	**tl;
	char	**pt;
	int		i;

	tl = ft_strsplit(line, ' ');
	i = 0;
	while (tl[i])
	{
		pt = ft_strsplit(tl[i], ',');
		PROTECT(ft_isinteger(pt[0]), KO);
		if (pt[1])
			PROTECT(ft_strnequ(pt[1], "0x", 2), KO);
		i++;
	}
	if (tf->nbpt && tf->nbpt != i)
		return (KO);
	tf->nbpt = i;
	return (OK);
}

static int		copy_file(int ifd, int ofd, t_fdf *tf)
{
	char	*line;
	int		lg;

	while ((lg = get_next_line(ifd, &line)) > 0)
	{
		tf->nbrow++;
		ft_putendl_fd(line, ofd);
		PROTECT(check_file(line, tf), KO);
	}
	if (lg < 0)
		return (KO);
	return (OK);
}

int				copy_check_file(int argc, char **argv, t_fdf *tf)
{
	int		ifd;
	int		ofd;

	if (argc == 1)
		ifd = STDIN_FILENO;
	else
		PROTECT(((ifd = open(argv[1], O_RDONLY)) >= 0), KO);
	PROTECT(((ofd = creat(TEMPFILE, S_IRWXU)) >= 0), KO);
	PROTECT(copy_file(ifd, ofd, tf), KO);
	close(ifd);
	close(ofd);
	return (OK);
}
