/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indirect_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:05:21 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/06 15:43:14 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_load_indirect(t_info *info, t_proc *proc)
{
	int val1;
	int val2;
	int reg_idx;

	ft_putstr("Je commence LOAD INDEX\n");
	val1 = ft_get_param(info, proc, 0, info->board[ft_mod_memsize(proc->pc - 1)]);
	val2 = ft_get_param(info, proc, 1, info->board[ft_mod_memsize(proc->pc - 1)]);
	reg_idx = ft_ptr_to_uint(info, ((proc->pc + P_SIZE[0] + P_SIZE[1])
				% MEM_SIZE), P_SIZE[2]);
	if (reg_idx < 1 || reg_idx > 16 || proc->error == 1)
		return (0);
	ft_putstr("val1 :\t");
	ft_putnbr(val1);
	ft_putstr("\tval2 :\t");
	ft_putnbr(val2);
	ft_putstr("\n");
	proc->reg[reg_idx - 1] = ft_ptr_to_uint(info, proc->pc - 2 +
			ft_idx_mod(proc, val1 + val2), REG_SIZE);
	ft_putstr("reg_value :\t");
	ft_putnbr(proc->reg[reg_idx - 1]);
	ft_putstr("\n");
	(proc->reg[reg_idx - 1] == 0) ? ft_modif_carry(proc, 1) :
		ft_modif_carry(proc, 0);
	ft_putstr("\n");
	ft_putstr("I'm Loaded indexed\n");
	return (0);
}

int	ft_store_indirect(t_info *info, t_proc *proc)
{
	long val1;
	long val2;
	int reg_idx;

	val1 = 0;
	val2 = 0;
	ft_putstr("Je commence STORE INDEX\n");
	reg_idx = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	val1 = ft_get_param(info, proc, 1, info->board[ft_mod_memsize(proc->pc - 1)]);
	val2 = ft_get_param(info, proc, 2, info->board[ft_mod_memsize(proc->pc - 1)]);
	if (reg_idx < 1 || reg_idx > 16 || proc->error == 1)
		return (0);
	ft_uint_to_ptr(info, proc->pc - 2 + ft_idx_mod(proc, val1 + val2), REG_SIZE, proc->reg[reg_idx - 1]);
	ft_putstr("val1 :\t");
	ft_putnbr(val1);
	ft_putstr("\tval2 :\t");
	ft_putnbr(val2);
	ft_putstr("\n");
	(proc->reg[reg_idx - 1] == 0) ? ft_modif_carry(proc, 1) :
		ft_modif_carry(proc, 0);
	ft_putstr("\n");
	ft_putstr("I'm store indexed\n");
	return (0);
}
