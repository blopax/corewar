/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:43:36 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/15 17:21:36 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_live(t_info *info, t_proc *proc)
{
	int i;

	i = 0;
	proc->alive = 1;
	while (i < info->players_nb)
	{
		if (info->players_info[i].number == proc->reg[0])
			info->players_info[i].live++;
		i++;
	}
	return (0);
}
