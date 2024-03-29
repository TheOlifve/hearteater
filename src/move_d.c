/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:39:25 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/16 22:51:33 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	loot_dcoin_d(t_game *game, int i, int j)
{
	empty(game, i - 1, j);
	game->map[i][j] = '7';
	game->coins -= 1;
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->hb, j * 64, i * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->hb, j * 64, (i - 1) * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->g_front2, j * 64, i * 64);
}

void	loot_coin_d(t_game *game, int i, int j)
{
	game->p_x = i;
	if (game->map[i - 1][j] == '7' && game->map[i][j] == 'C')
		loot_dcoin_d(game, i, j);
	else if (game->map[i][j] == 'C')
	{
		game->map[i][j] = '7';
		game->coins -= 1;
		empty(game, i - 1, j);
		empty(game, i, j);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->hb, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->g_front2, j * 64, i * 64);
	}
	else if (game->map[i - 1][j] == '7')
	{
		empty(game, (i - 1), j);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->hb, j * 64, (i - 1) * 64);
		if (game->map[i][j] == '7')
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->hb, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->g_front2, j * 64, i * 64);
	}
}

void	move_down(t_game *game, int i, int j)
{
	i += 1;
	if (game->map[i][j] == 'N' || (game->map[i][j] == 'E'
		&& game->coins == 0))
		ft_exit(game);
	if (game->map[i][j] != '1' && (game->map[i][j] == 'C'
		|| game->map[i - 1][j] == '7'))
	{
		game->score += 1;
		empty(game, i, j);
		loot_coin_d(game, i, j);
	}
	else if (game->map[i][j] != '1')
	{
		game->score += 1;
		game->p_x = i;
		empty(game, i - 1, j);
		if (game->map[i - 1][j] == 'E' && game->coins > 0)
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->door, j * 64, (i - 1) * 64);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->g_front2, j * 64, i * 64);
	}
}
