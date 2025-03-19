/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:41:54 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/19 03:14:14 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx, data->images.coin);
	mlx_destroy_image(data->mlx, data->images.exit);
	mlx_destroy_image(data->mlx, data->images.floor);
	mlx_destroy_image(data->mlx, data->images.player);
	mlx_destroy_image(data->mlx, data->images.wall);
}

int	close_game(t_data *data)
{
	free_imgs(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	exit(EXIT_SUCCESS);
	return (0);
}
