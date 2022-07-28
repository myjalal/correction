/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:26:31 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/20 15:07:57 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchrx(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	check_condicions(t_game *game)
{
	if (!valid_collec(game))
	{
		error("There must be at least one 'C'");
		return (0);
	}
	if (!valid_point_p(game))
	{
		error("There must be at least one 'P'");
		return (0);
	}
	if (!valid_point_e(game))
	{
		error("There must be at least one Point 'E' Exit");
		return (0);
	}
	if (game->map_size.x == game->map_size.y)
	{
		error("The map must be rectangular");
		return (0);
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!valid_wall(game->map, game->map_size.y))
	{
		error("Wall not Valid");
		return (0);
	}
	if (!valid_wall_inter(game->map, game->map_size.y))
	{
		error("Wall not Valid");
		return (0);
	}
	if (!check_condicions(game))
		return (0);
	return (1);
}
