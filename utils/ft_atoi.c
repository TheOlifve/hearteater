/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:20:26 by hrahovha          #+#    #+#             */
/*   Updated: 2023/01/31 14:11:50 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_ato(const char *str, int i, int num)
{
	int	is_neg;

	is_neg = 1;
	if (!str)
		return (0);
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		is_neg = is_neg * -1;
	if ((str[i] == 43) || (str && str[i] == 45))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + str[i] - 48;
			i++;
		}
		else
			return (0);
	}
	return (num * is_neg);
}

int	ft_atoi(const char *str)
{
	if (!str)
		return (0);
	return (ft_ato(str, 0, 0));
}
