/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:41:38 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/20 06:41:46 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	dfs(t_map map, int y, int x, char **visited)
{
	if (x < 0 || x >= map.colums || y < 0 || y >= map.rows
		|| map.map[y][x] == '1' || visited[y][x] == 'f')
		return ;
	visited[y][x] = 'f';
	dfs(map, y + 1, x, visited);
	dfs(map, y - 1, x, visited);
	dfs(map, y, x + 1, visited);
	dfs(map, y, x - 1, visited);
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
	dfs(map, y, x, visited);
	if (check_char(visited, 'E') || check_char(visited, 'C'))
	{
		free_map(map);
		error("Error: Invalid map, exit unreachable or coins uncollectible.\n");
	}
	free_arr(visited);
}
