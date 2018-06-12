/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:14:06 by pclement          #+#    #+#             */
/*   Updated: 2018/06/12 17:03:23 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_and(t_info *info, t_proc *proc)
{
	unsigned int	param0;
	unsigned int	param1;
	unsigned int	reg_idx;
	unsigned int	val;

	param0 = ft_get_param(info, proc, 0,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	param1 = ft_get_param(info, proc, 1,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	reg_idx = ft_ptr_to_uint(info,
			(proc->pc + P_SIZE[0] + P_SIZE[1]), P_SIZE[2]);
	val = 0;
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	val = param0 & param1;
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;
	return (0);
}

int	ft_or(t_info *info, t_proc *proc)
{
	unsigned int	param0;
	unsigned int	param1;
	unsigned int	reg_idx;
	unsigned int	val;

	param0 = ft_get_param(info, proc, 0,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	param1 = ft_get_param(info, proc, 1,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	reg_idx = ft_ptr_to_uint(info,
			(proc->pc + P_SIZE[0] + P_SIZE[1]) % MEM_SIZE, P_SIZE[2]);
	val = 0;
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	val = param0 | param1;
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;
	return (0);
}

int	ft_xor(t_info *info, t_proc *proc)
{
	unsigned int	param0;
	unsigned int	param1;
	unsigned int	reg_idx;
	unsigned int	val;

	param0 = ft_get_param(info, proc, 0,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	param1 = ft_get_param(info, proc, 1,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	reg_idx = ft_ptr_to_uint(info,
			(proc->pc + P_SIZE[0] + P_SIZE[1]) % MEM_SIZE, P_SIZE[2]);
	val = 0;
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	val = param0 ^ param1;
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;
	return (0);
}
