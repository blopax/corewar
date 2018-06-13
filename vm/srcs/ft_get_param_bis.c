/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:53:02 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/13 16:54:40 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_param_164(t_info *info, t_proc *proc, int param)
{
	int reg;

	reg = 0;
	if (param == 0)
		return (ft_ptr_to_uint(info, proc->pc, proc->loaded_op.dir_size));
	if (param == 1)
	{
		return (ft_ptr_to_uint(info, proc->pc + P_SIZE[0],
				proc->loaded_op.dir_size));
	}
	reg = ft_ptr_to_uint(info, proc->pc + P_SIZE[0] + P_SIZE[1],
			T_REG);
	if (reg < 1 || reg > 16)
	{
		proc->error = 1;
		return (0);
	}
	return (proc->reg[reg - 1]);
}

int		ft_param_180(t_info *info, t_proc *proc, int param)
{
	int reg;

	reg = 0;
	if (param == 0)
		return (ft_ptr_to_uint(info, proc->pc, P_SIZE[0]));
	if (param == 1)
	{
		return (ft_ptr_to_uint(info, proc->pc - 2 +
			ft_idx_mod(proc, ft_ptr_to_uint(info, (proc->pc + P_SIZE[0])
				% MEM_SIZE, P_SIZE[1])), proc->loaded_op.dir_size));
	}
	reg = ft_ptr_to_uint(info, proc->pc + P_SIZE[0] + P_SIZE[1],
			T_REG);
	if (reg < 1 || reg > 16)
	{
		proc->error = 1;
		return (0);
	}
	return (proc->reg[reg - 1]);
}

int		ft_param_212(t_info *info, t_proc *proc, int param)
{
	int reg;

	reg = 0;
	if (param == 0)
	{
		return (ft_ptr_to_uint(info, proc->pc - 2 +
					ft_idx_mod(proc, ft_ptr_to_uint(info, proc->pc,
						P_SIZE[1])), proc->loaded_op.dir_size));
	}
	reg = ft_ptr_to_uint(info, proc->pc + P_SIZE[0] + (param - 1),
			T_REG);
	if (reg < 1 || reg > 16)
	{
		proc->error = 1;
		return (0);
	}
	return (proc->reg[reg - 1]);
}

int		ft_param_228(t_info *info, t_proc *proc, int param)
{
	int reg;

	reg = 0;
	if (param == 0)
	{
		return (ft_ptr_to_uint(info, proc->pc - 2 +
					ft_idx_mod(proc, ft_ptr_to_uint(info, proc->pc,
						P_SIZE[0])), proc->loaded_op.dir_size));
	}
	if (param == 1)
	{
		return (ft_ptr_to_uint(info, proc->pc + P_SIZE[0],
				P_SIZE[1]));
	}
	reg = ft_ptr_to_uint(info, proc->pc + P_SIZE[0] + P_SIZE[1], T_REG);
	if (reg < 1 || reg > 16)
	{
		proc->error = 1;
		return (0);
	}
	return (proc->reg[reg - 1]);
}

int		ft_param_244(t_info *info, t_proc *proc, int param)
{
	int reg;

	reg = 0;
	if (param == 0)
	{
		return (ft_ptr_to_uint(info, proc->pc - 2 +
					ft_idx_mod(proc, ft_ptr_to_uint(info, proc->pc,
						P_SIZE[0])), proc->loaded_op.dir_size));
	}
	if (param == 1)
	{
		return (ft_ptr_to_uint(info, proc->pc - 2 +
			ft_idx_mod(proc, ft_ptr_to_uint(info, proc->pc + P_SIZE[0],
					P_SIZE[1])), proc->loaded_op.dir_size));
	}
	reg = ft_ptr_to_uint(info, proc->pc + P_SIZE[0] + P_SIZE[1], T_REG);
	if (reg < 1 || reg > 16)
	{
		proc->error = 1;
		return (0);
	}
	return (proc->reg[reg - 1]);
}
