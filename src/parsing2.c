#include "../cub3d.h"

int	parse_texture_file(t_direct direction, t_game *game_data, char *link)
{
	int		texture_fd;
	char	*file_name;

	if (!link || !link[0])
		return (ft_putendl_fd("Empty file name for texture", 2), 1);
	file_name = ft_strtrim(link, "\n");
	texture_fd = open(file_name, O_RDONLY);
	if (!texture_fd)
		return(perror("Error opening texture files"), 2);
	if (check_file_extension(file_name, ".png") || check_read_file(texture_fd))
		return (close(texture_fd), ft_putendl_fd("Error reading png file", 2), 2);
	game_data->texture_filename[direction] = file_name;
	game_data->texture_count[direction] += 1;
	return (0);
}

int parse_color_data(t_colors color, t_game *game_data, char *data)
{
	char	**colors;
	t_rgb	rgb;
	ssize_t	i;
	size_t	j;

	data = ft_strtrim(data, "\n");
	colors = ft_split(data, ',');
	free(data);
	i = 0;
	while (colors[i])
	{
		j = 0;
		while(colors[i][j])
			if (!ft_isdigit(colors[i][j++]))
				return (free_char_arr(colors), rgb.valid_rgb = -1, 1);
		if (i >= 3)
			return (free_char_arr(colors), rgb.valid_rgb = -1, 1);
		rgb.color[i] = ft_atoi(colors[i]);
		i++;
	}
	if (i < 3)
		return (free_char_arr(colors), rgb.valid_rgb = -1, 1);
	i = -1;
	while (rgb.color[++i])
		if (rgb.color[i] < 0 || rgb.color[i] > 255)
			return (free_char_arr(colors), rgb.valid_rgb = -1, 1);
	free_char_arr(colors);
	game_data->color[color] = rgb;
	game_data->color_count[color]++;
	game_data->color[color].valid_rgb = 1;
	return (0);
}

int	router_parse_data(char *line, t_game *game_data)
{
	char	**tokens;
	char	*token_texture[] = {"NO", "SO", "WE", "EA", NULL};
	char	*token_color[] = {"F", "C", NULL};
	size_t	i;
	size_t	j;

	i = 0;
	tokens = ft_split(line, ' ');
	while (tokens[i])
	{
		j = 0;
		while (token_texture[j])
			if (!ft_strncmp(tokens[i], token_texture[j++], ft_strlen(tokens[i]))
				&& parse_texture_file(j - 1, game_data, tokens[i + 1]))
					return (free_char_arr(tokens), 1); // free memory
		j = 0;
		while (token_color[j])
			if (!ft_strncmp(tokens[i], token_color[j++], ft_strlen(tokens[i]))
				&& parse_color_data(j - 1, game_data, tokens[i + 1]))
					return (free_char_arr(tokens), 1); //free memory
		i++;
	}
	free_char_arr(tokens);
	return (0);
}
