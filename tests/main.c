#include "test.h"

int main()
{
	t_data	img;
	t_mlx_data data;
	data.mlxptr = 0;
	data.mlxwin = 0;
	int		x = 0;
	int		y = 0;

	data.mlxptr = mlx_init();
	if (!data.mlxptr)
		return 0;
	data.mlxwin = mlx_new_window(data.mlxptr, 1600, 900, "Hello world!");
	if (!data.mlxwin)
	{
		mlx_destroy_display(data.mlxptr);
		free(data.mlxptr);
		return 0;
	}
	mlx_key_hook(data.mlxwin, handle_input, &data);
	img.img = mlx_new_image(data.mlxptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	
	while (y < 500)
	{	
		while (x < 500)
		{
			_mlx_pixel_put(&img, x, y, rand()%0x100000);
			//mlx_pixel_put(mlxptr, mlxwin,x, y, rand()%0x10000);
			x++;
		}
		x = 0;
		y++;
	}

	mlx_put_image_to_window(data.mlxptr, data.mlxwin, img.img, 0, 0);
	mlx_loop(data.mlxptr);
	
	/* The init makes use of a malloc so it's very important to free it 
	 * No matter, as we don't reach this part due to Ctrl-c we need events 
	 * handling
	 * */
	mlx_destroy_window(data.mlxptr, data.mlxwin);
	mlx_destroy_display(data.mlxptr);
	free(data.mlxwin);
	free(data.mlxptr);
	return (0);
}
