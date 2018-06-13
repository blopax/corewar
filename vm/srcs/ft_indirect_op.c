/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indirect_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:05:21 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/12 16:20:58 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_load_indirect(t_info *info, t_proc *proc)
{
	int val1;
	int val2;
	int reg_idx;

	val1 = ft_get_param(info, proc, 0,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	val2 = ft_get_param(info, proc, 1,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	reg_idx = ft_ptr_to_uint(info, ((proc->pc + P_SIZE[0] + P_SIZE[1])
				% MEM_SIZE), P_SIZE[2]);
	if (reg_idx < 1 || reg_idx > 16 || proc->error == 1)
		return (0);
	proc->reg[reg_idx - 1] = ft_ptr_to_uint(info, proc->pc - 2 +
			ft_idx_mod(proc, val1 + val2), REG_SIZE);
	(proc->reg[reg_idx - 1] == 0) ? ft_modif_carry(proc, 1) :
		ft_modif_carry(proc, 0);
	return (0);
}

int	ft_store_indirect(t_info *info, t_proc *proc)
{
	long	val1;
	long	val2;
	int		reg_idx;

	val1 = 0;
	val2 = 0;
	reg_idx = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	val1 = ft_get_param(info, proc, 1,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	val2 = ft_get_param(info, proc, 2,
			info->board[ft_mod_memsize(proc->pc - 1)]);
	if (reg_idx < 1 || reg_idx > 16 || proc->error == 1)
		return (0);
	ft_uint_to_ptr(info, proc->pc - 2 + ft_idx_mod(proc, val1 + val2),
			REG_SIZE, proc->reg[reg_idx - 1]);
	(proc->reg[reg_idx - 1] == 0) ? ft_modif_carry(proc, 1) :
		ft_modif_carry(proc, 0);
	return (0);
}
