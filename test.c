#include <mlx.h>
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft/includes/libft.h"


int 	key_hook(int key, void *param) {
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == ESCAPE_KEY)
		exit(0);
	return (0);
}


int main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*str;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Window Test");
	mlx_key_hook(win_ptr, key_hook, str);
	mlx_loop(mlx_ptr);


	return (0);
}
