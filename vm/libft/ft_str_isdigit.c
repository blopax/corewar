/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:54:24 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/19 19:13:57 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != '-' && ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
