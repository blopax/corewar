/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:49:52 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/30 16:40:29 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_idx_mod(int val)
{
	if (val < 0)
		return (val % -MEM_SIZE);
	return (val % MEM_SIZE);
}

void			ft_modif_carry(t_proc *proc, int carry_value)
{
	proc->carry = carry_value;
}

void			ft_uint_to_ptr(t_info *info, unsigned int ptr, int size, unsigned int value)
{
	int				i;
	int				k;

	i = 0;
	k = size - 1;
	while (i < size)
	{
		info->board[ptr] = value / ft_power(256, k);
		ft_putstr("ptr[i] :\t");
		ft_putnbr(info->board[ptr]);
		ft_putstr("\n");
		ptr = (ptr + 1) % MEM_SIZE;
		i++;
		k--;
	}
}

unsigned int	ft_ptr_to_uint(t_info *info, unsigned int ptr, int size)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (i < size)
	{
		result = result * 256 + info->board[ptr];
		i++;
		ptr = (ptr + 1) % MEM_SIZE;
	}
	return (result);
}

unsigned int	ft_ptr_to_uint_parsing(unsigned char *ptr, int size)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (i < size)
	{
		result = result * 256 + ptr[i];
		i++;
	}
	return (result);
}
