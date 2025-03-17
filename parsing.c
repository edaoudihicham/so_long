#include "so_long.h"

// Function declarations
int has_ber_extension(const char *filename);
char **allocate_map(int line_count);
int count_lines(const char *file_path);
char **read_map(const char *file_path);
void flood_fill(char **map, int x, int y, int width, int height);
int is_map_valid(char **map, int width, int height);
int check_line_lengths(char **map);
int check_walls(char **map);
int check_map_elements(char **map, int *player_x, int *player_y);
char **copy_map(char **map, int height);
int validate_map(char **map);
void free_map(char **map);


// Check if the file has a .ber extension
int has_ber_extension(const char *filename)
{
    const char *ext = strrchr(filename, '.');
    return (ext && strcmp(ext, ".ber") == 0);
}

// Allocate memory for the map
char **allocate_map(int line_count)
{
    char **map = (char **)malloc((line_count + 1) * sizeof(char *));
    if (!map)
    {
        printf("Error\nMemory allocation failed\n");
        return NULL;
    }
    return map;
}

// Count the number of lines in the map file
int count_lines(const char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\nFailed to open map file\n");
        return -1;
    }

    int line_count = 0;
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        free(line);  // Free the line after processing it
        line_count++;
    }
    close(fd);
    return line_count;
}

// Read the map from the file
char **read_map(const char *file_path)
{
    int line_count = count_lines(file_path);
    if (line_count < 0)
        return NULL;

    char **map = allocate_map(line_count);
    if (!map)
        return NULL;

    int fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\nFailed to open map file\n");
        free(map); // Free the map before returning NULL
        return NULL;
    }

    int i = 0;
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[i] = line;
        i++;
    }
    map[i] = NULL;
    close(fd);
    return map;
}

// Flood-fill algorithm to check reachability
void flood_fill(char **map, int x, int y, int width, int height)
{
    if (x < 0 || x >= width || y < 0 || y >= height || map[y][x] == '1' || map[y][x] == '#')
        return;
    
    map[y][x] = '#'; // Mark the position as visited

    // Debug: Print current state of the map during flood fill
    printf("Flood-fill at position (%d, %d)\n", x, y);

    flood_fill(map, x + 1, y, width, height); // Right
    flood_fill(map, x - 1, y, width, height); // Left
    flood_fill(map, x, y + 1, width, height); // Down
    flood_fill(map, x, y - 1, width, height); // Up
}

// Check if the map is valid after flood-fill
int is_map_valid(char **map, int width, int height)
{
    int i = 0;
    while (i < height)
    {
        int j = 0;
        while (j < width)
        {
            if (map[i][j] == 'C' || map[i][j] == 'E')
                return 0; // Unreachable collectible or exit
            j++;
        }
        i++;
    }
    return 1;
}

// Check if all lines in the map have the same length
int check_line_lengths(char **map)
{
    int i = 1;
    size_t line_length = strlen(map[0]);

    while (map[i])
    {
        if (strlen(map[i]) != line_length)
        {
            printf("Error\nAll lines in the map must have the same length\n");
            return 0;
        }
        i++;
    }
    return 1;
}

// Check if the map is enclosed by walls
int check_walls(char **map)
{
    int i = 0;
    size_t line_length = strlen(map[0]);

    // Check top and bottom walls
    while (i < (int)line_length) // Cast line_length to int to fix sign comparison
    {
        if (map[0][i] != '1' || map[line_length - 1][i] != '1')
        {
            printf("Error\nThe first and last lines must consist only of '1's\n");
            return 0;
        }
        i++;
    }

    // Check side walls
    i = 0;
    while (map[i])
    {
        if (map[i][0] != '1' || map[i][line_length - 1] != '1')
        {
            printf("Error\nEach line must start and end with '1'\n");
            return 0;
        }
        i++;
    }
    return 1;
}

// Check if the map contains valid elements
int check_map_elements(char **map, int *player_x, int *player_y)
{
    int i = 0, j;
    int collectibles = 0, exits = 0, players = 0;

    // Initialize player position to invalid values
    *player_x = -1;
    *player_y = -1;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                collectibles++;
            else if (map[i][j] == 'E')
                exits++;
            else if (map[i][j] == 'P')
            {
                players++;
                *player_x = j;
                *player_y = i;
            }
            j++;
        }
        i++;
    }

    if (collectibles == 0 || exits == 0 || players != 1)
    {
        printf("Error\nInvalid map elements\n");
        return 0;
    }
    return 1;
}

// Free the allocated memory for the map
void free_map(char **map)
{
    if (map)
    {
        int i = 0;
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
}

// Main validation function
int validate_map(char **map)
{
    int width = strlen(map[0]);
    int height = 0;
    while (map[height])
        height++;

    if (!check_line_lengths(map))
    {
        free_map(map); // Free map before returning failure
        return 0;
    }

    flood_fill(map, 0, 0, width, height);
    if (!is_map_valid(map, width, height))
    {
        // free_map(map); // Free map before returning failure
        printf("Error\nMap is not valid\n");
        return 0;
    }

    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./so_long map.ber\n");
        return 1;
    }

    if (!has_ber_extension(argv[1]))
    {
        printf("Error\nInvalid map file extension\n");
        return 1;
    }

    char **map = read_map(argv[1]);
    if (!map)
    {
        printf("Error\nFailed to read map\n");
        return 1;
    }

    if (!validate_map(map))
    {
        free_map(map);
        return 1;
    }

    printf("Map is valid!\n");

    // Free the map after validation
    free_map(map);
    return 0;
}
