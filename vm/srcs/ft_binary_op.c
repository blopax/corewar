/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:14:06 by pclement          #+#    #+#             */
/*   Updated: 2018/06/01 15:32:54 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_and(t_info *info, t_proc *proc)
{
	unsigned int	param0;
	unsigned int	param1;
	unsigned int	reg_idx;
	unsigned int	val;

	ft_putnbr(proc->reg[0]);
	ft_putstr("____________________________________________________________________________________________________________________________________________Je commence AND\n");
	param0 = ft_get_param(info, proc, 0, info->board[(proc->pc -1 ) % MEM_SIZE]);
	param1 = ft_get_param(info, proc, 1, info->board[(proc->pc -1 ) % MEM_SIZE]);
	
	reg_idx = ft_ptr_to_uint(info, (proc->pc + P_SIZE[0] + P_SIZE[1]) % MEM_SIZE, P_SIZE[2]);
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	val = param0 & param1;
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[reg_idx - 1] = val;

	ft_putstr("param1\n");
	ft_putnbr(param0);
	ft_putstr("param2\n");
	ft_putnbr(param1);
	ft_putnbr(val);
	ft_putstr("\n");
	ft_putnbr(proc->reg[reg_idx - 1]);
	ft_putstr("\n");
	ft_putstr("I'm ANDED\n");

	return (0);
}

int	ft_or(t_info *info, t_proc *proc)
{
	unsigned int	param0;
	unsigned int	param1;
	unsigned int	reg_idx;
	unsigned int	val;

	ft_putnbr(proc->reg[0]);
	ft_putstr("____________________________________________________________________________________________________________________________________________Je commence OR\n");
	param0 = ft_get_param(info, proc, 0, info->board[(proc->pc -1 ) % MEM_SIZE]);
	param1 = ft_get_param(info, proc, 1, info->board[(proc->pc -1 ) % MEM_SIZE]);
	
	reg_idx = ft_ptr_to_uint(info, (proc->pc + P_SIZE[0] + P_SIZE[1]) % MEM_SIZE, P_SIZE[2]);
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

	ft_putnbr(proc->reg[0]);
	ft_putstr("____________________________________________________________________________________________________________________________________________Je commence XOR\n");
	param0 = ft_get_param(info, proc, 0, info->board[(proc->pc -1 ) % MEM_SIZE]);
	param1 = ft_get_param(info, proc, 1, info->board[(proc->pc -1 ) % MEM_SIZE]);
	
	reg_idx = ft_ptr_to_uint(info, (proc->pc + P_SIZE[0] + P_SIZE[1]) % MEM_SIZE, P_SIZE[2]);
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
