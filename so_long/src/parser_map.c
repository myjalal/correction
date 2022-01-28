/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:56:27 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/17 15:26:58 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	get_map_size_y(int fd)
{
	char	*line;
	int		y;

	y = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		y++;
	}
	return (y);
}*/

int	get_map_size_x(t_game *game, int y)
{
	int	i;
	int	x;
	int	compa;

	x = 0;
	i = 0;
	compa = 0;
	while (i < y)
	{
		x = ft_strlen(game->map[i]);
		if (compa != x && compa != 0)
		{
			error("Lines no iguales");
			return (0);
		}
		compa = x;
		i++;
	}	
	return (x);
}

char	*ft_join(char *line, char c, int gx)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * gx);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	while (i < gx -2)
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = c;
	tmp[++i] = '\0';
	free(line);
	line = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	c;
	int		lu;
	int		gx;

	gx = 1;
	line = malloc(sizeof(char) * gx);
	if (!line)
		return (NULL);
	line[0] = '\0';
	lu = read(fd, &c, 1);
	while (lu && c != '\n')
	{
		gx++;
		line = ft_join(line, c, gx);
		lu = read(fd, &c, 1);
	}
	if (line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}

/* POr si falla realloc -> hacer doble read
//game->map = malloc(sizeof(char *) * game->map_size.y); */
void	parse_map(int fd, t_game *game)
{
	char	*line;
	int		i;
	int		gx;

	i = 0;
	gx = 1;
	game->map = malloc(sizeof(char *) * gx);
	if (!game->map)
		game->map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		gx++;
		game->map = ft_realloc((void *)game->map, sizeof(char *) * gx);
		game->map[i] = line;
		line = NULL;
		line = get_next_line(fd);
		i++;
	}
	game->map_size.y = i;
	game->map[i] = NULL;
	game->map_size.x = get_map_size_x(game, i);
}
