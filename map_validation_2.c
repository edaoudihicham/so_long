/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:41:38 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/21 03:39:44 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	depth_first_check(t_map map, int y, int x, char **visited)
{
	if (x < 0 || x >= map.colums || y < 0 || y >= map.rows
		|| map.map[y][x] == '1' || visited[y][x] == 'f')
		return ;
	visited[y][x] = 'f';
	depth_first_check(map, y + 1, x, visited);
	depth_first_check(map, y - 1, x, visited);
	depth_first_check(map, y, x + 1, visited);
	depth_first_check(map, y, x - 1, visited);
}

static char	**tmp_map(t_map map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (map.rows + 1));
	while (i < map.rows)
	{
		tmp[i] = malloc(sizeof(char) * (map.colums + 1));
		ft_strcpy(tmp[i], map.map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

static void	free_arr(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

static int	check_char(char **tmp, char c)
{
	int	y;
	int	x;

	y = 0;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x])
		{
			if (tmp[y][x] == c)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	is_map_playable(t_map map)
{
	char	**visited;
	int		x;
	int		y;

	y = 0;
	while (y < map.rows)
	{
		x = -1;
		while (++x < map.colums)
		{
			if (map.map[y][x] == 'P')
				break ;
		}
		if (map.map[y][x] == 'P')
			break ;
		y++;
	}
	visited = tmp_map(map);
	depth_first_check(map, y, x, visited);
	if (check_char(visited, 'E') || check_char(visited, 'C'))
	{
		error("Invalid map, exit unreachable or coins uncollectible.");
		return (free_map(map), free_arr(visited), exit(EXIT_FAILURE));
	}
	free_arr(visited);
}
