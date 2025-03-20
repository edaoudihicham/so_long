/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:42:38 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/20 06:49:52 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_for_alien_chars(t_map map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			c = map.map[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
			{
				free_map(map);
				error("Invalid map, alien char exists.");
			}
			x++;
		}
		y++;
	}
}

static void	check_rectangle(t_map map)
{
	int	i;

	i = 0;
	while (i < map.rows)
	{
		if (map.colums != (int)ft_strlen(map.map[i]))
		{
			free_map(map);
			error("Inalid map, not a rectangle.");
		}
		i++;
	}
}

static void	check_walls(t_map map)
{
	int	i;

	i = 0;
	while (i < map.colums)
	{
		if (map.map[0][i] != '1' || map.map[map.rows - 1][i] != '1')
		{
			free_map(map);
			error("Ivalid map, check your walls.");
		}
		i++;
	}
	i = 1;
	while (i < map.rows - 1)
	{
		if (map.map[i][0] != '1' || map.map[i][map.colums - 1] != '1')
		{
			free_map(map);
			error("Ivalid map, check your walls.");
		}
		i++;
	}
}

static void	check_flags(t_map map)
{
	static int	coin;
	int			player;
	int			exit;
	int			x;

	exit = 0;
	player = 0;
	while (--map.rows)
	{
		x = 0;
		while (*(map.map[map.rows] + x++))
		{
			if (*(map.map[map.rows] + x - 1) == 'C')
				coin = 1;
			else if (*(map.map[map.rows] + x - 1) == 'P')
				player++;
			else if (*(map.map[map.rows] + x - 1) == 'E')
				exit++;
		}
	}
	if ((coin * player * exit) != 1)
	{
		free_map(map);
		error("Invalid map: 1P, min 1C, and 1E allowed.");
	}
}

void	check_if_map_is_vaid(t_map map)
{
	check_for_alien_chars(map);
	check_rectangle(map);
	check_walls(map);
	check_flags(map);
	is_map_playable(map);
	if (map.rows > 32 || map.colums > 60)
	{
		free_map(map);
		error("Map is too big.");
	}
}
