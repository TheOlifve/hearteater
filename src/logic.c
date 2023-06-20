/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:37:20 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/27 19:37:24 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_list *game, char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'N' || x < 1 || y < 1
		|| y > game->win_width || x > game->win_height)
		return ;
	map[x][y] = '1';
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x, y - 1);
	flood_fill(game, map, x, y + 1);
}

int	logic(t_list *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = game->p_x;
	y = game->p_y;
	i = -1;
	flood_fill(game, game->map2, x, y);
	while (game->map2[++i])
	{
		j = -1;
		while (game->map2[i][++j])
		{
			if (game->map2[i][j] == 'E' || game->map2[i][j] == 'C')
				return (0);
		}
	}
	return (1);
}
