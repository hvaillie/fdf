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

#include <stdio.h> // TO REMOVE
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

int		check_file(char *line, int *x, int *y)
{
	char	**tl;
	char	**pt;
	int		i;

	*x = 0;
	*y = 0;
	tl = ft_strsplit(line, ' ');
	i = 0;
	while (tl[i])
	{
		pt = ft_strsplit(tl[i], ',');
		if (!ft_isinteger(pt[0]))
			return (0);
		//printf("point %d, value=%s,%s\n",i,pt[0],pt[1]);
		i++;
	}
	return (1);
}

int		copy_file(ifd, ofd)
{
	char 	*line;
	int		lg;
	int		x;
	int		y;

	while ((lg = get_next_line(ifd, &line)) > 0)
	{
		ft_putstr_fd(line, ofd);
		PROTECT(check_file(line, &x, &y), 0)
		ft_putchar_fd('\n', ofd);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		ifd;
	int		ofd;

	if (argc == 1)
		ifd = STDIN_FILENO;
	else
		PROTECT(((ifd = open(argv[1], O_RDONLY)) >= 0), -1);
	PROTECT(((ofd = creat("temp.fdf", S_IRWXU)) >= 0), -1);
	if (!copy_file(ifd, ofd))
	{
		ft_putstr("Invalid file\n");
	}
	close(ifd);
	close(ofd);
	return (0);
}
