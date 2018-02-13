/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <hvaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:07:15 by hvaillie          #+#    #+#             */
/*   Updated: 2017/12/04 21:45:13 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static t_list			*get_maillon(t_list **first, int fd)
{
	t_list				*tmp;
	t_reader			*reader;

	tmp = *first;
	while (tmp)
	{
		reader = (t_reader*)tmp->content;
		if (reader->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_reader			*get_reader(t_list **first, int fd)
{
	t_list				*tmp;
	t_reader			*reader;

	if (!(tmp = get_maillon(first, fd)))
	{
		PROTECT((reader = ft_memalloc(sizeof(t_reader))), NULL);
		reader->fd = fd;
		reader->lines = ft_strnew(0);
		reader->lines_first = reader->lines;
		tmp = ft_lstnew(reader, sizeof(t_reader));
		free(reader);
		ft_lstadd(first, tmp);
	}
	return ((t_reader*)tmp->content);
}

static int				load_lines(t_reader *reader)
{
	char				buf[BUFF_SIZE + 1];
	int					lg;

	while (((lg = read(reader->fd, buf, BUFF_SIZE)) > 0))
	{
		buf[lg] = '\0';
		PROTECT((reader->lines = ft_strjoin(reader->lines, buf)), -1);
		free(reader->lines_first);
		reader->lines_first = reader->lines;
		if (ft_strchrx(buf, '\n') >= 0)
			break ;
	}
	return (lg);
}

int						get_next_line(const int fd, char **line)
{
	static t_list		*first = NULL;
	t_reader			*reader;
	int					i;
	int					lg;
	char				buf[0];

	PROTECT((fd >= 0 && line && read(fd, buf, 0) >= 0 && BUFF_SIZE > 0), -1);
	lg = 0;
	PROTECT((reader = get_reader(&first, fd)), -1);
	if (ft_strchrx(reader->lines, '\n') == -1)
		PROTECT(((lg = load_lines(reader)) >= 0), -1);
	if (lg == 0 && !ft_strlen(reader->lines))
	{
		free(reader->lines_first);
		ft_lstdelmaillon(&first, get_maillon(&first, fd));
		return (0);
	}
	lg = ft_strchrx(reader->lines, '\n');
	i = ((lg == -1) ? ft_strlen(reader->lines) : lg);
	PROTECT((*line = ft_strnew(i + 1)), -1);
	ft_strncpy(*line, reader->lines, i);
	reader->lines += (i + ((lg == -1) ? 0 : 1));
	return (i);
}
