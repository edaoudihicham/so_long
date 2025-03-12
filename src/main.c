#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"

#define TILESIZE 64

char *tmp_map[] =
{
	"1111111111111111111",
	"100000000000000C001",
	"1000000000000000001",
	"10E0000000000000001",
	"1000000000000000001",
	"1000000000000P00001",
	"1111111111111111111"
};

typedef struct s_map
{
	int width;
	int height;
	char **map;
} t_map;

typedef struct s_player
{
	int x;
	int y;
	// void *texture;
}	t_player;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_game
{
	t_map map_info;
	t_player player_info;
	t_window window_info;
} t_game;

t_game game;

void	init_window()
{
	game.window_info.mlx = mlx_init();
	game.window_info.win = mlx_new_window(game.window_info.mlx, game.map_info.width * TILESIZE, game.map_info.height * TILESIZE, "hicham");
}

void	init_map()
{
	// todo: load map from a file
	// game.map_info = load_map(path);
	game.map_info.map = tmp_map;
	game.map_info.height = 9;
	game.map_info.width = 19;
}

void	init_game()
{
	init_map();
	init_window();
}

void	run_game()
{
	mlx_loop(game.window_info.mlx);
}
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("usage: ./so_long <MAP_PATH>\n");
		return (EXIT_FAILURE);
	}
	init_game();
	run_game();
}	
