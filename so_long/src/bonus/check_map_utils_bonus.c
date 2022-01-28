/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:26:31 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/20 15:08:48 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_collec(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->colle = 0;
	while (y < (game->map_size.y - 1))
	{
		x = 1;
		while (x < game->map_size.x -1)
		{
			if (game->map[y][x] == 'C')
				game->colle++;
			x++;
		}
		y++;
	}
	return (game->colle);
}

int	valid_point_p(t_game *game)
{
	int	i;
	int	x;

	i = 1;
	while (i < (game->map_size.y - 1))
	{
		x = (ft_strchrx(game->map[i], 'P'));
		if (x != '\0')
		{
			game->p_position.y = i * WIN_H;
			game->p_position.x = x * WIN_W;
			return (1);
		}
		i++;
	}
	return (0);
}

int	valid_point_e(t_game *game)
{
	int	i;
	int	x;

	i = 1;
	while (i < (game->map_size.y - 1))
	{
		x = (ft_strchrx(game->map[i], 'E'));
		if (x != '\0')
		{
			game->e_position.y = i * WIN_H;
			game->e_position.x = x * WIN_W;
			return (1);
		}
		i++;
	}
	return (0);
}

int	valid_wall_inter(char **str, int last)
{
	int	i;

	i = 1;
	while (i < (last - 1))
	{
		if (str[i][0] != 49 || str[i][ft_strlen(str[i]) - 1] != 49)
			return (0);
		i++;
	}
	return (1);
}

int	valid_wall(char **str, int last)
{
	int	i;

	i = 0;
	while (str[0][i] && str[last -1][i])
	{
		if (str[0][i] != 49 || str[last -1][i] != 49)
			return (0);
		i++;
	}
	return (1);
}
