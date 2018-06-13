/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:37:08 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/13 16:56:08 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_get_param.h"

int		ft_get_param(t_info *info, t_proc *proc, int param, int ocp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 12)
	{
		if (ocp == tab_ocp[i].ocp)
			return (tab_ocp[i].f_op(info, proc, param));
		i++;
	}
	proc->error = 1;
	return (0);
}

int		ft_param_84(t_info *info, t_proc *proc, int param)
{
	int	reg;

	reg = 0;
	reg = ft_ptr_to_uint(info, proc->pc + param, T_REG);
	if (reg < 1 || reg > 16)
	{
		proc->error = 1;
		return (0);
	}
	return (proc->reg[reg - 1]);
}

int		ft_param_88(t_info *info, t_proc *proc, int param)
{
	int reg;

	reg = 0;
	if (param == 0 || param == 1)
	{
		reg = ft_ptr_to_uint(info, proc->pc + param, T_REG);
		if (reg < 1 || reg > 16)
		{
			proc->error = 1;
			return (0);
		}
		return (proc->reg[reg - 1]);
	}
	if (param == 2)
	{
		return (ft_ptr_to_uint(info, proc->pc + P_SIZE[0]
						+ P_SIZE[1], proc->loaded_op.dir_size));
	}
	return (0);
}

int		ft_param_100(t_info *info, t_proc *proc, int param)
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
		return (ft_ptr_to_uint(info, proc->pc + P_SIZE[0],
					proc->loaded_op.dir_size));
	}
	return (0);
}

int		ft_param_104(t_info *info, t_proc *proc, int param)
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
		return (ft_ptr_to_uint(info, proc->pc + P_SIZE[0],
					proc->loaded_op.dir_size));
	}
	if (param == 2)
	{
		return (ft_ptr_to_uint(info, proc->pc + P_SIZE[0]
						+ P_SIZE[1], proc->loaded_op.dir_size));
	}
	return (0);
}
