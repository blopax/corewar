/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:37:08 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/30 18:46:00 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_get_param.h"

int		ft_get_param(t_info *info, t_proc *proc, int param, int ocp)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	while (i < 12)
	{
		if (ocp == tab_ocp[i].ocp)
			return (tab_ocp[i].f_op(info, proc, param, ocp));
		i++;
	}
	return (0);
}

int		ft_param_84(t_info *info, t_proc *proc, int param, int ocp)
{
	if (ocp == 84)
		{
			if (param == 0)
			{
				return (proc->reg[ft_ptr_to_uint(info, proc->pc % MEM_SIZE,
							P_SIZE[1]) - 1]);
			}
			if (param == 1)
			{
				return (proc->reg[ft_ptr_to_uint(info, (proc->pc + P_SIZE[0])
							% MEM_SIZE, P_SIZE[1]) - 1]);
			}
			if (param == 2)
			{
				return (proc->reg[ft_ptr_to_uint(info, (proc->pc + P_SIZE[0]
								+ P_SIZE[1]) % MEM_SIZE, P_SIZE[2]) - 1]);
			}
		}
	return (0);
}

int		ft_param_88(t_info *info, t_proc *proc, int param, int ocp)
{
	if (ocp == 88)
		{
			if (param == 0)
			{
				return (proc->reg[ft_ptr_to_uint(info, proc->pc % MEM_SIZE,
							P_SIZE[1]) - 1]);
			}
			if (param == 1)
			{
				return (proc->reg[ft_ptr_to_uint(info, (proc->pc + P_SIZE[0])
							% MEM_SIZE, P_SIZE[1]) - 1]);
			}
			if (param == 2)
			{
				return (ft_ptr_to_uint(info, (proc->pc + P_SIZE[0]
								+ P_SIZE[1]) % MEM_SIZE, P_SIZE[2]));
			}
		}
	return (0);
}

int		ft_param_100(t_info *info, t_proc *proc, int param, int ocp)
{
	if (ocp == 100)
		{
			if (param == 0)
			{
				return (proc->reg[ft_ptr_to_uint(info, proc->pc % MEM_SIZE,
							P_SIZE[1]) - 1]);
			}
			if (param == 1)
			{
				return (ft_ptr_to_uint(info, (proc->pc + P_SIZE[0])
							% MEM_SIZE, P_SIZE[1]));
			}
			if (param == 2)
			{
				return (proc->reg[ft_ptr_to_uint(info, (proc->pc + P_SIZE[0]
								+ P_SIZE[1]) % MEM_SIZE, P_SIZE[2]) - 1]);
			}
		}
	return (0);
}

int		ft_param_104(t_info *info, t_proc *proc, int param, int ocp)
{
	if (ocp == 104)
		{
			if (param == 0)
			{
				return (proc->reg[ft_ptr_to_uint(info, proc->pc % MEM_SIZE,
							P_SIZE[1]) - 1]);
			}
			if (param == 1)
			{
				return (ft_ptr_to_uint(info, (proc->pc + P_SIZE[0])
							% MEM_SIZE, P_SIZE[1]));
			}
			if (param == 2)
			{
				return (ft_ptr_to_uint(info, (proc->pc + P_SIZE[0]
								+ P_SIZE[1]) % MEM_SIZE, P_SIZE[2]));
			}
		}
	return (0);
}

int		ft_param_116(t_info *info, t_proc *proc, int param, int ocp)
{
	if (ocp == 116)
		{
			if (param == 0)
			{
				return (proc->reg[ft_ptr_to_uint(info, proc->pc % MEM_SIZE,
							P_SIZE[1]) - 1]);
			}
			if (param == 1)
			{
				return (ft_ptr_to_uint(info, (proc->pc + P_SIZE[0])
							% MEM_SIZE, P_SIZE[1]));
			}
			if (param == 2)
			{
				return (proc->reg[ft_ptr_to_uint(info, (proc->pc + P_SIZE[0]
								+ P_SIZE[1]) % MEM_SIZE, P_SIZE[2]) - 1]);
			}
		}
	return (0);
}
