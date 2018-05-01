/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:06:29 by atourner          #+#    #+#             */
/*   Updated: 2018/01/12 17:19:01 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, (int)ft_strlen((char*)s));
}

void			ft_putnstr_fd(char const *s, int fd, int nb)
{
	write(fd, s, nb);
}