/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:01:46 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/16 22:51:33 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	empty_add(t_game *game)
{
	int	i;
	int	j;

	game->empty = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/empty.xpm", &i, &j);
}

void	empty(t_game *game, int i, int j)
{
	empty_add(game);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->empty, j * 64, i * 64);
}
