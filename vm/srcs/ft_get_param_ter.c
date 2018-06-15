/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param_ter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:55:35 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/15 14:34:53 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_param_116(t_info *info, t_proc *proc, int param)
{
	int reg;

	reg = 0;
	if (param == 0 || param == 2)
	{
		reg = ft_ptr_to_uint(info, proc->pc + P_SIZE[0] + P_SIZE[1], T_REG);
		if (param == 0)
			reg = ft_ptr_to_uint(info, proc->pc, T_REG);
		if (reg < 1 || reg > 16)
		{
			proc->error = 1;
			return (0);
		}
		return (proc->reg[reg - 1]);
	}
	if (param == 1)
	{
		return (ft_ptr_to_uint(info, proc->pc - 2 +
			ft_idx_mod(proc, ft_ptr_to_uint(info, proc->pc + P_SIZE[0],
				P_SIZE[1])), proc->loaded_op.dir_size));
	}
	return (0);
}

int		ft_param_120(t_info *info, t_proc *proc, int param)
{
	int reg;

	reg = 0;
	if (param == 0)
	{
		reg = ft_ptr_to_uint(info, proc->pc, T_REG);
		if (reg < 1 || reg > 16)
		{
			proc->error = 1;
			return (0);
		}
		return (proc->reg[reg - 1]);
	}
	if (param == 1)
	{
		return (ft_ptr_to_uint(info, proc->pc - 2 +
					ft_idx_mod(proc, ft_ptr_to_uint(info, proc->pc + P_SIZE[0],
						P_SIZE[1])), 4));
	}
	if (param == 2)
	{
		return (ft_ptr_to_uint(info, proc->pc + P_SIZE[0]
						+ P_SIZE[1], proc->loaded_op.dir_size));
	}
	return (0);
}

int		ft_param_148(t_info *info, t_proc *proc, int param)
{
	int reg;

	reg = 0;
	if (param == 0)
		return (ft_ptr_to_uint(info, proc->pc, proc->loaded_op.dir_size));
	reg = ft_ptr_to_uint(info, proc->pc + P_SIZE[0] + (param - 1),
			T_REG);
	if (reg < 1 || reg > 16)
	{
		proc->error = 1;
		return (0);
	}
	return (proc->reg[reg - 1]);
}
