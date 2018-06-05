/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_n_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:08:45 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/05 19:58:21 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_kill_proc(t_info *info)
{
	t_proc *proc_tmp;

	proc_tmp = info->first_processus;
	while (proc_tmp)
	{
		if (proc_tmp->alive == 0)
			proc_tmp->alive = -1;
		else
			proc_tmp->alive = 0;
		proc_tmp = proc_tmp->next;
	}
}

void	ft_add_new_proc(t_info *info, t_proc *proc, int fork_val)
{
	t_proc *new;
	t_proc *proc_tmp;
	int i;

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

int	ft_fork(t_info *info, t_proc *proc)
{
	int	fork_val;

	ft_putstr("Je commence FORK\n");
	fork_val = 0;
	fork_val = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	ft_putstr("fork_val :\t");
	ft_putnbr(ft_idx_mod(proc, fork_val));
	ft_putstr("\n");
	ft_add_new_proc(info, proc, ft_idx_mod(proc, fork_val));
	ft_putstr("J'ai FORKED\n");
	return (0);
}

int	ft_long_fork(t_info *info, t_proc *proc)
{
	int	fork_val;

	ft_putstr("Je commence LONG FORK\n");
	fork_val = 0;
	fork_val = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	ft_putstr("fork_val :\t");
	ft_putnbr(fork_val);
	ft_putstr("\n");
	ft_add_new_proc(info, proc, fork_val);
	ft_putstr("J'ai LONG FORKED\n");
	return (0);
}

int	ft_zjump(t_info *info, t_proc *proc)
{
	int jmp_val;

	ft_putstr("Je commence JUMP_AROUND           JUMP JUMP JUMP\n");
	jmp_val = 0;
	if (proc->carry != 1)
		return (0);
	jmp_val = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	proc->pc = ft_mod_memsize(proc->pc + jmp_val);
	ft_putstr("J'ai JUMPED\n");
	return (0);
}

