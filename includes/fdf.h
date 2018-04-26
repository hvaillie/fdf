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
# define NUM3_KEY 85
# define NUM2_KEY 84
# define NUM1_KEY 83
# define NUM0_KEY 82
# define ARROW_LEFT_KEY 123
# define ARROW_RIGHT_KEY 124
# define ARROW_DOWN_KEY 125
# define ARROW_UP_KEY 126
# define A_KEY 0
# define S_KEY 1
# define Z_KEY 6
# define X_KEY 7
# define Q_KEY 12
# define W_KEY 13
# define I_KEY 34
# define P_KEY 35
# define BUT_1 1
# define BUT_2 2
# define BUT_3 3
# define BUT_4 4
# define BUT_5 5
# define BUT_6 6
# define BUT_7 7
# define WINDOW_SIZE_H 2000
# define WINDOW_SIZE_V 1200
# define IMAGE_SIZE_H 1980
# define IMAGE_SIZE_V 1090
# define DEFSZX 20
# define DEFSZY 20
# define DEFSZZ -2
# define DEFSHIFT -1
# define DEFROX 0
# define DEFROY 0
# define DEFROZ 0
# define KP 0.75
# define KI1 0.66
# define KI2 0.66
# define BLACK 0x000000
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define DEF_MIN_PALETTE 0x808080
# define DEF_MAX_PALETTE 0xFFFFFF
# define INC_PALETTE 0x50
# define PROJPAR 'P'
# define PROJISO 'I'

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
	int		nbpt;
	int		nbrow;
	int		zmax;
	int		zmin;
	t_point	**tp;
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
	int		bpp;
	int		szl;
	int		endian;
	t_point	po;
	t_point	pd;
	int		rgb;
	int		shift;
	int		arrow;
	int		pszx;
	int		pszy;
	int		max;
	int		szx;
	int		szy;
	int		szz;
	int		rox;
	int		roy;
	int		roz;
	int		minrgb;
	int		maxrgb;
	char	proj;
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
void			free_split(char **c);
int				load_file(t_fdf *tf);
void			setmlx(t_fdf *tf);
void			setvar(t_mlx *tm);
int				key_hook(int key, void *param);
int				key_hook_arrow(int key, t_mlx *tm);
int				key_hook_num(int key, t_mlx *tm);
int				key_hook_alpha(int key, t_mlx *tm);
int				mouse_hook(int button, int x, int y, void *param);
int				expose_hook(void *param);
int				loop_hook(void *param);
void			draw_map(t_mlx *tm);
void			display_window(t_mlx *tm);
void			projo(t_mlx *tm, t_point *tp);
void			projd(t_mlx *tm, t_point *tp);
void			rotxyz(t_mlx *tm, t_point *tp, int i, int j);
void			setcolor(t_mlx *tm, int i, int j);
int				compute_shift(t_mlx *tm);
int				check_pos(t_mlx *tm, t_draw *td, int *k, int i);
char			*concat_legend(char *str, char *l, int v, char *(*f)(int v));
int				min4(int i[4]);
int				max4(int i[4]);

#endif
