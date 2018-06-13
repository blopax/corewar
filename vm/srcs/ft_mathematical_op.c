/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathematical_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:13:26 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/12 16:38:29 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_add(t_info *info, t_proc *proc)
{
	int	r1_idx;
	int	r2_idx;
	int	r3_idx;

	r1_idx = 0;
	r2_idx = 0;
	r3_idx = 0;
	r1_idx = info->board[(2 + proc->pc - proc->op_size) % MEM_SIZE];
	r2_idx = info->board[(2 + proc->pc - proc->op_size
			+ proc->loaded_op.param_size[0]) % MEM_SIZE];
	r3_idx = info->board[(2 + proc->pc - proc->op_size +
			proc->loaded_op.param_size[0] + proc->loaded_op.param_size[1])
		% MEM_SIZE];
	if (r1_idx <= 0 || r1_idx > 16 || r2_idx <= 0 || r2_idx > 16 ||
			r3_idx <= 0 || r3_idx > 16)
		return (0);
	proc->reg[r3_idx - 1] = proc->reg[r1_idx - 1] + proc->reg[r2_idx - 1];
	proc->carry = (proc->carry + 1) % 2;
	return (0);
}

int	ft_sub(t_info *info, t_proc *proc)
{
	int	r1_idx;
	int	r2_idx;
	int	r3_idx;

	r1_idx = 0;
	r2_idx = 0;
	r3_idx = 0;
	r1_idx = info->board[(2 + proc->pc - proc->op_size) % MEM_SIZE];
	r2_idx = info->board[(2 + proc->pc - proc->op_size +
			proc->loaded_op.param_size[0]) % MEM_SIZE];
	r3_idx = info->board[(2 + proc->pc - proc->op_size +
			proc->loaded_op.param_size[0] + proc->loaded_op.param_size[1])
		% MEM_SIZE];
	if (r1_idx <= 0 || r1_idx > 16 || r2_idx <= 0 || r2_idx > 16 ||
			r3_idx <= 0 || r3_idx > 16)
		return (0);
	proc->reg[r3_idx - 1] = proc->reg[r1_idx - 1] - proc->reg[r2_idx - 1];
	proc->carry = (proc->carry + 1) % 2;
	return (0);
}
