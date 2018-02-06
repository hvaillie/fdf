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

static int		check_file(char *line, int *nbpoint)
{
	char	**tl;
	char	**pt;
	int		i;

	tl = ft_strsplit(line, ' ');
	i = 0;
	while (tl[i])
	{
		pt = ft_strsplit(tl[i], ',');
		if (!ft_isinteger(pt[0]))
			return (0);
		if (pt[1])
		{
			if (!ft_strnequ(pt[1], "0x", 2))
				return (0);
		}
		i++;
	}
	if (*nbpoint && *nbpoint != i)
		return (0);
	*nbpoint = i;
	return (i);
}

static int		copy_file(ifd, ofd)
{
	char 	*line;
	int		lg;
	int		nbpoint;

	nbpoint = 0;
	while ((lg = get_next_line(ifd, &line)) > 0)
	{
		ft_putstr_fd(line, ofd);
		PROTECT(check_file(line, &nbpoint), 0)
		ft_putchar_fd('\n', ofd);
	}
	return (nbpoint);
}

int		copy_check_file(int argc, char **argv)
{
	int		ifd;
	int		ofd;
	int		nbpoint;

	if (argc == 1)
		ifd = STDIN_FILENO;
	else
		PROTECT(((ifd = open(argv[1], O_RDONLY)) >= 0), 0);
	PROTECT(((ofd = creat("temp.fdf", S_IRWXU)) >= 0), 0);
	PROTECT(((nbpoint = copy_file(ifd, ofd)) > 0), 0);
	close(ifd);
	close(ofd);
	return (nbpoint);
}
