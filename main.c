/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluiz-de <lluiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:34:02 by lluiz-de          #+#    #+#             */
/*   Updated: 2024/01/05 18:09:26 by lluiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_IVec2	ft_point(int32_t x, int32_t y)
{
	t_IVec2	point;

	point.x = x;
	point.y = y;
	return (point);
}

static void	ft_new_camera(t_fdf *data)
{
	data->camera.pos.x = 0;
	data->camera.pos.y = -100;
	data->camera.x_rot = 0;
	data->camera.y_rot = 0;
	data->camera.z_rot = 0;
	data->camera.height = 50;
	data->camera.zoom = 20;
}

static void	ft_new_projection(t_fdf *data)
{
	data->camera.pos.x = 95;
	data->camera.pos.y = -265;
	data->camera.x_rot = 12.55;
	data->camera.y_rot = 0.95;
	data->camera.z_rot = 0.80;
	data->camera.height = 50;
	data->camera.zoom = 20;
}

void	ft_press(void *param)
{
	t_fdf	*data;

	data = (t_fdf *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		return ;
	}
	ft_move(data);
	ft_rotate(data);
	ft_height(data);
	ft_zoom(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_0))
		ft_new_camera(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_P))
		ft_new_projection(data);
	ft_draw(data);
}

int	main(int32_t argc, char **argv)
{
	mlx_t	*mlx;
	t_fdf	data;

	if (argc == 1 || argc > 2)
	{
		ft_putendl("USAGE: ./fdf <map_file>");
		exit(EXIT_SUCCESS);
	}
	data.coords = ft_parse_map(&data, argv[1]);
	mlx = mlx_init(WIDTH, HEIGHT, "lluiz-de FDF", true);
	if (mlx)
	{
		data.mlx = mlx;
		data.canvas = mlx_new_image(mlx, WIDTH, HEIGHT);
		mlx_image_to_window(mlx, data.canvas, 0, 0);
		ft_new_camera(&data);
		mlx_loop_hook(mlx, ft_press, &data);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		free(data.coords);
		exit(EXIT_SUCCESS);
	}
	ft_error("Error: Initilization failure!");
	return (EXIT_FAILURE);
}
