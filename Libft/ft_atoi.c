/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:53:48 by ccoto             #+#    #+#             */
/*   Updated: 2021/02/15 11:56:41 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		condition(int count, int sign, int nb)
{
	if (count > 20 && sign < 0)
		return (0);
	else if (count > 20 && sign > 0)
		return (-1);
	else
		return (sign * nb);
}

int		ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;
	int	count;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	count = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		count++;
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (condition(count, sign, nb));
}
