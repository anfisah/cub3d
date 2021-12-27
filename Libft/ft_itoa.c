/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:57:51 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/26 08:29:22 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	i = ft_len(nb);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = 0;
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb >= 10)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	str[i] = 48 + (nb % 10);
	return (str);
}
