/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:49:52 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/15 15:09:25 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int	ft_mod_memsize(int val)
{
	if (val < 0)
		return (4096 + val);
	else
		return (val % MEM_SIZE);
}

int				ft_idx_mod(t_proc *proc, unsigned int val)
{
	int		flag;

	flag = 0;
	if (val > 2147483647)
		flag = 1;
	val = val % 65536;
	if (proc->loaded_op.opcode == 13 || proc->loaded_op.opcode == 14)
	{
		if (flag == 0)
			return (val % MEM_SIZE);
		return (-(-(val % MEM_SIZE) % IDX_MOD));
	}
	if (val > (65535 / 2) || flag == 1)
		return (-(-(val % MEM_SIZE) % IDX_MOD));
	return ((val % MEM_SIZE) % IDX_MOD);
}

void			ft_uint_to_ptr(t_info *info, unsigned int ptr,
		int size, unsigned int value)
{
	int				i;
	int				k;

	i = 0;
	k = size - 1;
	ptr = ft_mod_memsize(ptr);
	while (i < size)
	{
		info->board[ptr] = value / ft_power(256, k);
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
	ptr = ft_mod_memsize(ptr);
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
