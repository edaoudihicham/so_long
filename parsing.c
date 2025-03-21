/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:42:56 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/21 00:52:58 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_file(char *filename)
{
	char	*ext;
	int		fd;

	ext = ft_strrchr(filename, '.');
	if (ext == NULL)
	{
		error("the map should have .ber extention.");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(ext, ".ber", 4) || *(ext + 4) != '\0')
	{
		error("the map should have .ber extention.");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(filename, ".ber", 4) == 0 || *(ext - 1) == '/')
	{
		error("invalid extention");
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error("could open the map."), exit(EXIT_FAILURE), 1);
	return (fd);
}

static char	*load_map_from_file(int fd)
{
	char	*line;
	char	*tmp;
	char	*new_line;

	line = NULL;
	new_line = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		new_line = ft_strjoin(line, tmp);
		if (!new_line)
			error("something went wrong.");
		free(line);
		line = new_line;
		if (tmp[0] == '\n')
		{
			free(tmp);
			free(new_line);
			return (get_next_line(-1), error("Invalid map, Empty lines exist."),
				exit(EXIT_FAILURE), NULL);
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (line);
}

static t_map	create_map_from_string(char *line)
{
	t_map	map;

	map.map = ft_split(line, '\n');
	if (!map.map)
	{
		error("something wrong happened, couldn't split str.");
		exit(EXIT_FAILURE);
	}
	map.rows = 0;
	while (map.map[map.rows])
		map.rows++;
	map.colums = ft_strlen(map.map[0]);
	return (map);
}

t_map	load_map(char *filename)
{
	t_map	map;
	int		fd;
	char	*line;

	fd = open_file(filename);
	line = load_map_from_file(fd);
	map = create_map_from_string(line);
	free(line);
	return (map);
}

void	free_map(t_map map)
{
	int	y;

	y = 0;
	while (map.map[y])
		free(map.map[y++]);
	free(map.map);
	get_next_line(-1);
}
