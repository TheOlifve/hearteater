/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:04:20 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/16 22:51:33 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	win_size(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->map;
	i = 0;
	j = 0;
	while (map[i][j])
		j++;
	while (map[i])
		i++;
	game->win_height = i;
	game->win_width = j;
}
