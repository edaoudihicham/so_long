/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:42:47 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/21 01:38:02 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *data)
{
	if (data->map.map[data->player_y][data->player_x + 1] == '1')
		return ;
	data->player_x++;
	data->moves_count++;
	if (data->map.map[data->player_y][data->player_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->player_y][data->player_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->window, data->imgs.player,
		data->player_x * 64, data->player_y * 64);
	mlx_put_image_to_window(data->mlx, data->window, data->imgs.floor,
		(data->player_x - 1) * 64, data->player_y * 64);
	ft_putstr_fd("\nCount: ", 1);
	ft_putnbr_fd(data->moves_count, 1);
}

void	move_left(t_data *data)
{
	if (data->map.map[data->player_y][data->player_x - 1] == '1')
		return ;
	data->player_x--;
	data->moves_count++;
	if (data->map.map[data->player_y][data->player_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->player_y][data->player_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->window, data->imgs.player,
		data->player_x * 64, data->player_y * 64);
	mlx_put_image_to_window(data->mlx, data->window, data->imgs.floor,
		(data->player_x + 1) * 64, data->player_y * 64);
	ft_putstr_fd("\nCount: ", 1);
	ft_putnbr_fd(data->moves_count, 1);
}

void	move_up(t_data *data)
{
	if (data->map.map[data->player_y - 1][data->player_x] == '1')
		return ;
	data->player_y--;
	data->moves_count++;
	if (data->map.map[data->player_y][data->player_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->player_y][data->player_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->window, data->imgs.player,
		data->player_x * 64, data->player_y * 64);
	mlx_put_image_to_window(data->mlx, data->window, data->imgs.floor,
		data->player_x * 64, (data->player_y + 1) * 64);
	ft_putstr_fd("\nCount: ", 1);
	ft_putnbr_fd(data->moves_count, 1);
}

void	move_down(t_data *data)
{
	if (data->map.map[data->player_y + 1][data->player_x] == '1')
		return ;
	data->player_y++;
	data->moves_count++;
	if (data->map.map[data->player_y][data->player_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->player_y][data->player_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->window, data->imgs.player,
		data->player_x * 64, data->player_y * 64);
	mlx_put_image_to_window(data->mlx, data->window, data->imgs.floor,
		data->player_x * 64, (data->player_y - 1) * 64);
	ft_putstr_fd("\nCount: ", 1);
	ft_putnbr_fd(data->moves_count, 1);
}

int	handle_keys(int key, t_data *data)
{
	if (key == ESC_KEY)
		close_game(data);
	else if (key == RIGHT_KEY || key == D_KEY)
		move_right(data);
	else if (key == LEFT_KEY || key == A_KEY)
		move_left(data);
	else if (key == UP_KEY || key == W_KEY)
		move_up(data);
	else if (key == DOWN_KEY || key == S_KEY)
		move_down(data);
	if (data->player_x == data->map.exit_x && data->player_y
		== data->map.exit_y)
		check_win(data);
	if (data->player_x != data->map.exit_x || data->player_y
		!= data->map.exit_y)
		mlx_put_image_to_window(data->mlx, data->window, data->imgs.exit,
			data->map.exit_x * 64, data->map.exit_y * 64);
	return (0);
}
