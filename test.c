#include <mlx.h>
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./libft/libft/includes/libft.h"


int 	key_hook(int key, void *param) {
	ft_putstr("Key=");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == ESCAPE_KEY)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	ft_putstr("Mouse Button=");
	ft_putnbr(button);
	ft_putstr(" ,x=");
	ft_putnbr(x);
	ft_putstr(" ,y=");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int		expose_hook(void *param)
{
	ft_putstr("Expose");
	ft_putchar('\n');
	return (0);
}

int loop_hook(void *param)
{
	t_mlx		*tm;
	int			x;
	int			y;
	int			c;

	c = BLUE;
	x = rand() % 500;
	y = rand() % 500;

	tm = (t_mlx*)param;
	mlx_pixel_put(tm->mlx_ptr, tm->win_ptr, x, y, c);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx		tm;
	char		*str;

	tm.mlx_ptr = mlx_init();
	tm.win_ptr = mlx_new_window(tm.mlx_ptr, 500, 500, "Window Test");
	mlx_key_hook(tm.win_ptr, key_hook, &tm);
	mlx_mouse_hook(tm.win_ptr, mouse_hook, &tm);
	mlx_expose_hook(tm.win_ptr, expose_hook, &tm);
	mlx_loop_hook(tm.mlx_ptr, loop_hook, &tm);
	mlx_loop(tm.mlx_ptr);


	return (0);
}
