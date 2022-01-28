/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:42:43 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/16 10:46:13 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game = init_map(argv[1]);
		if (game.map == NULL)
			return (0);
		game_init(&game);
	}
	else
		error("Invalid number of arguments");
	return (0);
}
