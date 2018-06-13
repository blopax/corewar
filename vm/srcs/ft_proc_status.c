/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:49:48 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/13 16:52:12 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_modif_carry(t_proc *proc, int carry_value)
{
	proc->carry = carry_value;
}

int		ft_check_proc_alive(t_info *info)
{
	t_proc	*proc_tmp;
	int		proc_alive;

	proc_alive = 0;
	proc_tmp = info->first_processus;
	while (proc_tmp)
	{
		if (proc_tmp->alive >= 0)
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
		if (proc_tmp->alive > 0)
			proc_tmp->alive = 0;
		else if (proc_tmp->alive == 0)
			proc_tmp->alive = -1;
		proc_tmp = proc_tmp->next;
	}
}
