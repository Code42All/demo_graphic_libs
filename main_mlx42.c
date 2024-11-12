#include "MLX42/MLX42.h"

#define WIDTH 1600
#define HEIGHT 900
#define APP_NAME "mlx42"

// inputs functions
void	app_loop(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}


int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, APP_NAME, false);
	mlx_loop_hook(mlx, app_loop, mlx);
	mlx_loop(mlx);

	mlx_terminate(mlx);
	return (0);
}
