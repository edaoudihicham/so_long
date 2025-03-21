/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:42:29 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/21 00:52:58 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_map(data->map);
		error("couldn't connect to x server.");
		exit(EXIT_FAILURE);
	}
	data->window = mlx_new_window(data->mlx,
			data->map.colums * 64,
			data->map.rows * 64, "so_long");
	if (!data->window)
	{
		free_map(data->map);
		free(data->mlx);
		error("couldn't create a new window");
		exit(EXIT_FAILURE);
	}
}

void	draw_tile(char tile, t_data *data, int x, int y)
{
	if (tile == 'C')
	{
		data->coin_count++;
		mlx_put_image_to_window(data->mlx, data->window, data->imgs.coin, x, y);
	}
	else if (tile == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->imgs.wall, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(data->mlx, data->window, data->imgs.floor, x, y
			);
	else if (tile == 'P')
	{
		data->player_x = x / 64;
		data->player_y = y / 64;
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs.player, x, y);
	}
	else if (tile == 'E')
	{
		data->map.exit_x = x / 64;
		data->map.exit_y = y / 64;
		mlx_put_image_to_window(data->mlx, data->window, data->imgs.exit, x, y);
	}
}

void	draw_tiles(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->coin_count = 0;
	data->coin_collected = 0;
	data->moves_count = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			draw_tile(data->map.map[y][x], data, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	*create_image(t_data *data, char *path)
{
	int		x;
	int		y;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &x, &y);
	if (!img)
	{
		error("Some images are missing!");
		close_game(data);
	}
	return (img);
}

void	init_imgs(t_data *data)
{
	data->imgs.coin = create_image(data,
			"textures/coin.xpm");
	data->imgs.wall = create_image(data,
			"textures/wall.xpm");
	data->imgs.player = create_image(data,
			"textures/player.xpm");
	data->imgs.floor = create_image(data,
			"textures/floor.xpm");
	data->imgs.exit = create_image(data,
			"textures/exit.xpm");
}
