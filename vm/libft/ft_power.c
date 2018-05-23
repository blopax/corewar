/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:03:55 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/23 17:42:23 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int base, int power)
{
	int	result;

	result = 1;
	if (power == 0)
		return (result);
	result = base;
	while (power >= 2)
	{
		result = result * base;
		power--;
	}
	return (result);
}
