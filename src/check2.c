/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:34:24 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/17 17:43:27 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_line_len(char **map, int len)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map && map[++i])
	{
		while (map[i][j])
			j++;
		if (j != len)
			return (0);
		j = 0;
	}
	return (1);
}

int	map_cut(char *map)
{
	int	i;
	int	checker;

	i = -1;
	checker = 0;
	while (map[++i] && map[i] == '\n')
		;
	while (map[++i])
	{
		if (i > 0 && map[i] == '\n' && map[i - 1] == '\n')
			checker = 1;
		if (checker == 1 && (map[i] != '\n' || map[i] != '\0'))
			return (0);
	}
	return (1);
}
