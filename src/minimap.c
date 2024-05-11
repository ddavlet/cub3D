/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:54:27 by mrizakov          #+#    #+#             */
/*   Updated: 2024/05/11 18:01:01 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_close(char maze[40][40], int y, int x, char map_tok)
{
	if (maze[y][x + 1] == map_tok)
		return (1);
	if (maze[y + 1]
		&& (maze[y + 1][x] == map_tok || maze[y + 1][x + 1] == map_tok))
		return (1);
	if (y > 0)
	{
		if (maze[y - 1][x] == map_tok)
			return (1);
		if (x > 0 && maze[y - 1][x - 1] == map_tok)
			return (1);
	}
	if (x > 0)
	{
		if (maze[y][x - 1] == map_tok)
			return (1);
		if (maze[y + 1]
			&& maze[y + 1][x - 1] == map_tok)
			return (1);
	}
	return (0);
}

int maze_check_closed(t_game *game_data)
{
	int	i;
	int	j;
	int	player;

	j = 0;
	player = 0;
	while(j < MAZE_DIMENSION)
	{
		i = 0;
		while(i < MAZE_DIMENSION)
		{
			if (game_data->maze.g[j][i++] == 'X')
				if (check_close(game_data->maze.g, j ,i - 1, '0')
					|| check_close(game_data->maze.g, j ,i - 1, 'N'))
						return (ft_putendl_fd("Error\nWall not closed", 2), 1);
		}
		j++;
	}
	game_data->maze_closed = 1;
	if (!game_data->player_init_dir)
		return(ft_putendl_fd("Error\nWrong number of players", 2), 1);
	return (0);
}

