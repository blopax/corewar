/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_cor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:30:50 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/06 17:16:50 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_init(int *i, long *result, int *sign)
{
	*i = 0;
	*result = 0;
	*sign = 1;
}

int				ft_atoi_cor(const char *str, t_info *info)
{
	int					i;
	int					start;
	long				result;
	int					sign;

	if (!str)
		return (0);
	ft_init(&i, &result, &sign);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
		if (result > 2147483648 || (result == 2147483648 && sign == 1))
			ft_error(3, info);
	}
	return (sign * result);
}
