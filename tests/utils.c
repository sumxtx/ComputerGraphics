#include "test.h"

void _mlx_pixel_put(t_data *data, int x, int y, int color)
{
	/* This function buffers the content to be printed making the performance */
	/* better than the original pixel_put                                     */

	char *dt;

	dt = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dt = color;
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if(keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlxptr, data->mlxwin);
		mlx_destroy_display(data->mlxptr);
		free(data->mlxptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}
