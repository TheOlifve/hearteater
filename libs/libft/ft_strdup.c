/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:10:53 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/16 22:55:45 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*mem;

	if (!s1)
		return (NULL);
	i = 0;
	size = ft_strlen(s1);
	mem = (char *) malloc(size + 1);
	if (!mem)
		return (NULL);
	while (i <= size)
	{
		mem[i] = s1[i];
		i++;
	}
	return (mem);
}
