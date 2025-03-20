/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:50 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/20 01:52:49 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

enum		e_keys
{
	ESC_KEY = 65307,
	UP_KEY = 65362,
	DOWN_KEY = 65364,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
};

typedef struct s_imgs
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*floor;
	void	*exit;
}			t_imgs;

typedef struct s_map
{
	char	**map;
	int		colums;
	int		rows;
	int		exit_x;
	int		exit_y;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_imgs	images;
	t_map	map;
	int		p_x;
	int		p_y;
	int		moves_count;
	int		coin_count;
	int		coin_collected;
}			t_data;

void		free_map(t_map map);
t_map		load_map(char *filename);
void		check_if_map_is_vaid(t_map map);
void		is_map_beatable(t_map map);
void		error(char *msg);

int			close_game(t_data *data);
void		init_window(t_data *data);
void		draw_tail(char taile, t_data *data, int x, int y);
void		draw_tails(t_data *data);
void		*create_img(t_data *data, char *path);
void		init_imgs(t_data *data);

void		move_right(t_data *data);
void		move_left(t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);
int			handle_keys(int key, t_data *data);
void		check_win(t_data *data);

#endif
