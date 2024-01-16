/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:10:28 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/16 22:55:03 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	if (!s)
		return (0);
	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}
