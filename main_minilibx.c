#include "mlx.h"
#include "mlx_int.h"

#define WIDTH 1600
#define HEIGHT 900
#define APP_NAME "minilibx"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;


// close function
int	mlx_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}


// inputs functions
int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		mlx_close(mlx);
	return (0);
}


int	main(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, APP_NAME);
	mlx_hook(mlx.win, DestroyNotify, StructureNotifyMask, mlx_close, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
}
