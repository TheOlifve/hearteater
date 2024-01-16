/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:05:38 by hrahovha          #+#    #+#             */
/*   Updated: 2024/01/16 22:55:45 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_p_string(const char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_type(va_list arg, const char type)
{
	int	len;

	len = 0;
	if (type == 's')
		len = len + ft_p_string(va_arg(arg, char *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	arg;
	int		len;

	if (!str)
		return (0);
	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i] && i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			len = len + ft_type(arg, str[i + 1]);
			i++;
		}
		else
			len = len + ft_p_char(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
