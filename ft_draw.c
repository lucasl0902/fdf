/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluiz-de <lluiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:28:48 by lluiz-de          #+#    #+#             */
/*   Updated: 2024/01/05 18:08:42 by lluiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int32_t	ft_get(int32_t x, int32_t y, t_fdf *data)
{
	return (data->coords[y * data->map_width + x].height);
}

static void	ft_drawlines(int32_t x, int32_t y, t_fdf *data)
{
	if (x != data->map_width - 1)
		ft_draw_line(data->canvas, ft_project(x, y, ft_get(x, y, data),
				&data->camera), ft_project(x + 1, y, ft_get(x + 1, y, data),
				&data->camera));
	if (y != data->map_height - 1)
		ft_draw_line(data->canvas, ft_project(x, y, ft_get(x, y, data),
				&data->camera), ft_project(x, y + 1, ft_get(x, y + 1, data),
				&data->camera));
}

void	ft_draw(t_fdf *data)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	y = 0;
	ft_bzero(data->canvas->pixels, WIDTH * HEIGHT * sizeof(int32_t));
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			ft_drawlines(x, y, data);
			x++;
		}
		y++;
	}
}
