/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <hvaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:08:11 by hvaillie          #+#    #+#             */
/*   Updated: 2017/12/04 19:26:31 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct	s_reader
{
	int			fd;
	char		*lines_first;
	char		*lines;
}				t_reader;

# define BUFF_SIZE 20
# define PROTECT(x,y) if(!x) return (y);

int				get_next_line(const int fd, char **line);

#endif
