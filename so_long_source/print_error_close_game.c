/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_close_game.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:41:54 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/20 21:54:20 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

void	destroy_image(void *mlx, void *data_img)
{
	if (data_img)
		mlx_destroy_image(mlx, data_img);
}

void	free_imgs(t_data *data)
{
	destroy_image(data->mlx, data->imgs.coin);
	destroy_image(data->mlx, data->imgs.exit);
	destroy_image(data->mlx, data->imgs.floor);
	destroy_image(data->mlx, data->imgs.player);
	destroy_image(data->mlx, data->imgs.wall);
}

int	close_game(t_data *data)
{
	if (data)
	{
		free_imgs(data);
		if (data->mlx && data->window)
		{
			mlx_destroy_window(data->mlx, data->window);
			mlx_destroy_display(data->mlx);
			free(data->mlx);
			free_map(data->map);
		}
	}
	exit(EXIT_SUCCESS);
	return (0);
}
