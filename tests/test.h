#ifndef TEST_H
#define TEST_H


#include "mlx.h"
#include "unistd.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <stdio.h>

typedef struct s_data
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
}	
t_data;

typedef struct s_mlx_data
{
	void	*mlxptr;
	void	*mlxwin;
}
t_mlx_data;

void _mlx_pixel_put(t_data *data, int x, int y, int color);
int	handle_input(int keysym, t_mlx_data *data);

#endif
