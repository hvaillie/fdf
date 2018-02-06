/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfdf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:21:01 by hvaillie          #+#    #+#             */
/*   Updated: 2018/01/23 20:21:06 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTFDF_H
# define TESTFDF_H

# define ESCAPE_KEY 53
# define RED 	0xFF0000
# define GREEN 	0x00FF00
# define BLUE 	0x0000FF
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define K_COEFPARA	0.75
# define K_COEFISO1	1
# define K_COEFISO2	0.66
# define K_SPACE 20
# define PROTECT(x,y) if(!x) return (y);

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		w;
	int		rgb;
}				t_point;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int 	bpp;
	int 	szl;
	int 	endian;
	t_point	po;
	t_point	pd;
	int		rgb;
	int		middle;
}				t_mlx;

typedef struct	s_draw
{
	int				diffx;
	int				diffy;
	float			incx;
	float			incy;
	unsigned int	color;
	unsigned char	octets[4];
	int				loops;
	t_point			p;
}				t_draw;

typedef struct	s_fdf_elem
{
	int		high;
	int		rgb;
}				t_fdf_elem;

#endif

typedef struct	s_fdf
{
	int				x;
	int				y;
	t_fdf_elem		*tfe;
}				t_fdf;
