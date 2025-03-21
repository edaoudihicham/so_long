/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:43:05 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/21 01:12:48 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win(t_data *data)
{
	if (data->coin_collected == data->coin_count)
	{
		ft_putstr_fd("\nYou Won!\n", 1);
		close_game(data);
	}
	ft_putstr_fd("\nYou have to collect all the coins first", 1);
}

void	run_game(t_data data)
{
	init_window(&data);
	init_imgs(&data);
	draw_tiles(&data);
	mlx_hook(data.window, KeyPress, KeyPressMask, handle_keys, &data);
	mlx_hook(data.window, DestroyNotify, StructureNotifyMask, close_game,
		&data);
	mlx_loop(data.mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ac != 2)
		return (error("usage: ./so_long <MAP.ber>"), 1);
	data.map = load_map(av[1]);
	check_if_map_is_vaid(data.map);
	run_game(data);
}
