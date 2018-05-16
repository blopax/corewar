/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:08:34 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/16 17:57:38 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_tab_op.h"

void	ft_create_proc(t_info *info)
{
	int	i;
	int	k;
	t_proc *proc_tmp;

	i = 1;
	k = 1;
	proc_tmp = info->first_processus;
	while (i < info->players_nb)
	{
		proc_tmp->next = ft_init_proc((MEM_SIZE / info->players_nb) * k);
		proc_tmp = proc_tmp->next;
		ft_putnbr(proc_tmp->pc);
		ft_putstr("\n");
		i++;
		k++;
	}
}

void	ft_reinit_lives(t_info *info)
{
	t_proc *proc_tmp;

	proc_tmp = info->first_processus;
	while (proc_tmp)
	{
		proc_tmp->alive = 0;
		proc_tmp = proc_tmp->next;
	}
	info->total_lives = 0;
	info->check = 0;
	info->countdown_to_die = 0;
}

int		ft_flag(t_info *info)
{
	if (info->countdown_to_die == info->cycles_to_die)
	{
		if (info->total_lives > NBR_LIVE || info->check == MAX_CHECKS - 1)
			info->cycles_to_die -= CYCLE_DELTA;
		else
			info->check++;
		ft_reinit_lives(info);
	}
	if (info->cycles_to_die <= 0)
		return (0);
	return (1);
}

void	ft_execute_instruction(t_info *info, t_proc *proc)
{
	tabop[proc->loaded_op.opcode - 1].f_op(info, proc);
}

void	ft_load_instruction(t_info *info, t_proc *proc)
{
}

void	ft_run_proc(t_info *info)
{
	t_proc	*proc_tmp;

	proc_tmp = info->first_processus;
	while (proc_tmp)
	{
		if (proc_tmp->loaded_op.cycle_nb == 0)
		{
			if (proc_tmp->loaded_op.opcode != 0)
				ft_execute_instruction(info, proc_tmp);
			ft_load_instruction(info, proc_tmp);
		}
		else if (proc_tmp->loaded_op.cycle_nb > 0)
			proc_tmp->loaded_op.cycle_nb--;
	}
}

void	ft_run_vm(t_info *info)
{
	while (ft_flag(info))
	{
		ft_run_proc(info);
		info->cycles++;
		info->countdown_to_die++;
	}
}
