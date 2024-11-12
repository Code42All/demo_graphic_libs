#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 1600
#define HEIGHT 900
#define APP_NAME "macrolibx"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;


// inputs functions
int	key_hook(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (keycode == 41) // Escape
		mlx_loop_end(mlx->mlx);
	return (0);
}


// window event
int window_hook(int event, void* param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if(event == 0) // Cross
		mlx_loop_end(mlx->mlx);
	return 0;
}


int	main(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, APP_NAME);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);

	mlx_loop(mlx.mlx);

	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
}
