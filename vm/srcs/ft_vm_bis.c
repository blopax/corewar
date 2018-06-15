/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:56:49 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/15 15:39:17 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_create_proc(t_info *info)
{
	int		i;
	int		k;
	t_proc	*proc_tmp;

	i = 1;
	k = 1;
	proc_tmp = info->first_processus;
	proc_tmp->reg[0] = info->players_info[0].number;
	while (i < info->players_nb)
	{
		proc_tmp->next = ft_init_proc((MEM_SIZE / info->players_nb) * k);
		proc_tmp->next->prev = proc_tmp;
		proc_tmp = proc_tmp->next;
		proc_tmp->reg[0] = info->players_info[i].number;
		i++;
		k++;
	}
}

short	ft_get_op_size(t_proc *proc, unsigned char ocp)
{
	unsigned char	p[3];
	int				i;

	i = 0;
	p[0] = ocp / 64;
	p[1] = (ocp % 64) / 16;
	p[2] = (ocp % 16) / 4;
	while (i < 3)
	{
		if (p[i] == 0)
			P_SIZE[i] = 0;
		else if (p[i] == REG_CODE)
			P_SIZE[i] = 1;
		else if (p[i] == DIR_CODE && proc->loaded_op.dir_size == 4)
			P_SIZE[i] = 4;
		else if (p[i] == DIR_CODE && proc->loaded_op.dir_size == 2)
			P_SIZE[i] = 2;
		else if (p[i] == IND_CODE)
			P_SIZE[i] = 2;
		i++;
	}
	return (P_SIZE[0] + P_SIZE[1] + P_SIZE[2]);
}

t_proc	*ft_last(t_proc *proc)
{
	t_proc	*proc_tmp;

	proc_tmp = proc;
	while (proc_tmp->next)
		proc_tmp = proc_tmp->next;
	return (proc_tmp);
}

int		ft_flag(t_info *info)
{
	if (info->dump >= 0 && info->dump == info->cycles)
	{
		ft_show_board(info);
		return (0);
	}
	if (info->countdown_to_die == info->cycles_to_die)
	{
		ft_kill_proc(info);
		if (info->total_lives > NBR_LIVE || info->check == MAX_CHECKS - 1)
		{
			info->cycles_to_die -= CYCLE_DELTA;
			info->check = 0;
		}
		else
			info->check++;
		info->total_lives = 0;
		info->countdown_to_die = 0;
		ft_init_live_board(info->live_board);
	}
	if (info->cycles_to_die <= 0 || ft_check_proc_alive(info) == 0)
		return (0);
	return (1);
}
