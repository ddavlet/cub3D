/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddavlety <ddavlety@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:16:43 by mrizakov          #+#    #+#             */
/*   Updated: 2024/05/16 20:29:49 by ddavlety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		load_textures(t_game *game_data)
{
    game_data->textures[NO] = mlx_load_png(game_data->texture_filename[NO]);
    game_data->textures[SO] = mlx_load_png(game_data->texture_filename[SO]);
    game_data->textures[WE] = mlx_load_png(game_data->texture_filename[WE]);
	game_data->textures[EA] = mlx_load_png(game_data->texture_filename[EA]);
	if (!game_data->textures[NO] || !game_data->textures[SO]
		|| !game_data->textures[WE] || !game_data->textures[EA])
		return (free_textures(game_data), 1);
	return (0);
}
