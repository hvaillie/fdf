/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:21:01 by hvaillie          #+#    #+#             */
/*   Updated: 2018/01/23 20:21:06 by hvaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define PROTECT(x,y) if(!x) return (y);
# define OK 1
# define KO 0
# define OK_MAIN 0
# define KO_MAIN -1
# define TEMPFILE "temp.fdf"
# define ESCAPE_KEY 53
# define NUM9_KEY 92
# define NUM8_KEY 91
# define NUM7_KEY 89
# define NUM6_KEY 88
# define NUM5_KEY 87
# define NUM4_KEY 86
# define NUM2_KEY 84
# define DEFSZX 20
# define DEFSZY 20
# define DEFSZZ 2
# define DEFROX 30
# define DEFROY 30
# define DEFROZ 30
# define KP 0.75
# define WHITE 0xFFFFFF

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		w;
	int		rgb;
}				t_point;

typedef struct	s_fdf
{
	int				nbpt;
	int				nbrow;
	t_point			**tp;
}				t_fdf;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		wszh;
	int		wszv;
	int		iszh;
	int		iszv;
	int 	bpp;
	int 	szl;
	int 	endian;
	t_point	po;
	t_point	pd;
	int		rgb;
	int		middle;
	int		szx;
	int		szy;
	int		szz;
	int		rox;
	int		roy;
	int		roz;
	t_fdf	*tf;
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

int				copy_check_file(int argc, char **argv, t_fdf *tf);
int				alloc_map(t_fdf *tf);
void			display_map(t_fdf *tf);
void			free_map(t_fdf *tf);
int				load_file(t_fdf *tf);
void			setmlx(t_fdf *tf);
int 			key_hook(int key, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				expose_hook(void *param);
int				loop_hook(void *param);
void 			draw_map(t_mlx *tm);


#endif
