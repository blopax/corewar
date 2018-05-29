/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indirect_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:05:21 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/29 20:08:08 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_load_indirect(t_info *info, t_proc *proc)
{
	int val1;
	int val1_bis;
	int val2;
	int reg_idx;

	ft_putstr("Je commence LOAD INDEX\n");
	val1 = ft_ptr_to_uint(info, ((proc->pc - proc->op_size + 2)
					% MEM_SIZE), proc->loaded_op.param_size[0]);
	val1_bis = ft_ptr_to_uint(info, ((2 + proc->pc - proc->op_size +
					ft_idx_mod(val1)) % MEM_SIZE), proc->loaded_op.param_size[0]);
	val2 = ft_ptr_to_uint(info, ((proc->pc - proc->op_size + 2 +
					proc->loaded_op.param_size[0]) % MEM_SIZE),
			proc->loaded_op.param_size[1]);
	reg_idx = ft_ptr_to_uint(info, ((2 + proc->pc - proc->op_size +
			proc->loaded_op.param_size[0] + proc->loaded_op.param_size[1])
				% MEM_SIZE), proc->loaded_op.param_size[2]);
	ft_putstr("val1 :\t");
	ft_putnbr(val1);
	ft_putstr("\n");
	ft_putstr("val1_bis :\t");
	ft_putnbr(val1_bis);
	ft_putstr("\n");
	ft_putstr("val2 :\t");
	ft_putnbr(val2);
	ft_putstr("\n");
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	if (info->board[1 + proc->pc - proc->op_size] == 228)
	{
		proc->reg[reg_idx - 1] = ft_ptr_to_uint(info,
				(proc->pc - proc->op_size +
				  ft_idx_mod(val1_bis + val2)) % MEM_SIZE, REG_SIZE);
	}
	if (info->board[1 + proc->pc - proc->op_size] == 164)
	{
		proc->reg[reg_idx - 1] = ft_ptr_to_uint(info, (proc->pc - proc->op_size + val1 + val2) % MEM_SIZE, REG_SIZE);
	}
	(proc->reg[reg_idx - 1] == 0) ? ft_modif_carry(proc, 1) :
		ft_modif_carry(proc, 0);
	ft_putstr("\n");
	ft_putstr("I'm Loaded indexed\n");
	return (0);
}

int	ft_store_indirect(t_info *info, t_proc *proc)
{
	int val1;
	int val1_bis;
	int val2;
	int reg_idx;

	ft_putstr("Je commence STORE INDEX\n");
	val1 = ft_ptr_to_uint(info, ((proc->pc - proc->op_size + 2)
					% MEM_SIZE), proc->loaded_op.param_size[0]);
	val1_bis = ft_ptr_to_uint(info, ((2 + proc->pc - proc->op_size +
					ft_idx_mod(val1)) % MEM_SIZE), proc->loaded_op.param_size[0]);
	val2 = ft_ptr_to_uint(info, ((proc->pc - proc->op_size + 2 +
					proc->loaded_op.param_size[0]) % MEM_SIZE),
			proc->loaded_op.param_size[1]);
	reg_idx = ft_ptr_to_uint(info, (2 + proc->pc - proc->op_size)
				% MEM_SIZE, proc->loaded_op.param_size[0]);
	ft_putstr("val1 :\t");
	ft_putnbr(val1);
	ft_putstr("\n");
	ft_putstr("val1_bis :\t");
	ft_putnbr(val1_bis);
	ft_putstr("\n");
	ft_putstr("val2 :\t");
	ft_putnbr(val2);
	ft_putstr("\n");
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	if (info->board[1 + proc->pc - proc->op_size] == 228)
	{
		proc->reg[reg_idx - 1] = ft_ptr_to_uint(info,
				(proc->pc - proc->op_size +
				  ft_idx_mod(val1_bis + val2)) % MEM_SIZE, REG_SIZE);
	}
	if (info->board[1 + proc->pc - proc->op_size] == 164)
	{
		proc->reg[reg_idx - 1] = ft_ptr_to_uint(info, (proc->pc - proc->op_size + val1 + val2) % MEM_SIZE, REG_SIZE);
	}
	(proc->reg[reg_idx - 1] == 0) ? ft_modif_carry(proc, 1) :
		ft_modif_carry(proc, 0);
	ft_putstr("\n");
	ft_putstr("I'm Loaded indexed\n");
	return (0);
}
