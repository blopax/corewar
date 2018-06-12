/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_n_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:08:45 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/12 16:24:04 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_check_proc_alive(t_info *info)
{
	t_proc	*proc_tmp;
	int		proc_alive;

	proc_alive = 0;
	proc_tmp = info->first_processus;
	while (proc_tmp)
	{
		if (proc_tmp->alive != -1)
			proc_alive++;
		proc_tmp = proc_tmp->next;
	}
	return (proc_alive);
}

void	ft_kill_proc(t_info *info)
{
	t_proc *proc_tmp;

	proc_tmp = info->first_processus;
	while (proc_tmp)
	{
		if (proc_tmp->alive <= 0)
			proc_tmp->alive = -1;
		else
			proc_tmp->alive = 0;
		proc_tmp = proc_tmp->next;
	}
}

void	ft_add_new_proc(t_info *info, t_proc *proc, int fork_val)
{
	t_proc	*new;
	t_proc	*proc_tmp;
	int		i;

	i = 0;
	proc_tmp = ft_last(info->first_processus);
	new = ft_init_proc(proc->pc - 1 + fork_val);
	proc_tmp->next = new;
	new->prev = proc_tmp;
	new->carry = proc->carry;
	new->alive = proc->alive;
	while (i < 16)
	{
		new->reg[i] = proc->reg[i];
		i++;
	}
}

int		ft_fork(t_info *info, t_proc *proc)
{
	int	fork_val;

	fork_val = 0;
	fork_val = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	ft_add_new_proc(info, proc, ft_idx_mod(proc, fork_val));
	return (0);
}

int		ft_long_fork(t_info *info, t_proc *proc)
{
	int	fork_val;

	fork_val = 0;
	fork_val = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	ft_add_new_proc(info, proc, fork_val);
	return (0);
}

int		ft_zjump(t_info *info, t_proc *proc)
{
	int jmp_val;

	jmp_val = 0;
	if (proc->carry != 1)
		return (0);
	jmp_val = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	proc->pc = ft_mod_memsize(proc->pc - 1 - proc->op_size + jmp_val);
	return (0);
}
