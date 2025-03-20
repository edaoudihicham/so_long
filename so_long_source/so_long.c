/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:43:05 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/20 06:16:34 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_win(t_data *data)
{
	if (data->coin_collected == data->coin_count)
	{
		ft_putstr_fd("\nYou Won!\n", 1);
		close_game(data);
	}
	ft_putstr_fd("\nYou have to collect all the coins first\n", 1);
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

	if (ac != 2)
		error("usage: ./so_long <MAP.ber>");
	data.map = load_map(av[1]);
	check_if_map_is_vaid(data.map);
	run_game(data);
}
