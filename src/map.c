/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:31:53 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/18 19:54:00 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_r(char *file, t_list *game)
{
	char	*temp;
	char	*temp1;
	int		fd;
	char	*temp3;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	temp = ft_strdup("");
	temp1 = ft_strdup("");
	while (temp1)
	{	
		free(temp1);
		temp1 = get_next_line(fd);
		temp3 = temp;
		free(temp);
		temp = NULL;
		temp = ft_strjoin(temp3, temp1);
	}
	game->map3 = ft_strjoin(temp3, temp1);
	game->map = ft_split(temp, '\n');
	game->map2 = ft_split(temp, '\n');
	free(temp);
	close(fd);
	return (1);
}
