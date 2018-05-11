/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:08:34 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/11 16:03:03 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

