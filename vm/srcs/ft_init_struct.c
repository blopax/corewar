/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:28:11 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/14 19:34:50 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc	*ft_init_proc(int pc)
{
	t_proc	*new_proc;

	new_proc = (t_proc*)malloc(sizeof(t_proc));
	ft_bzero(new_proc->reg, sizeof(int) * 16);
	new_proc->carry = 0;
	new_proc->pc = pc;
	new_proc->opcode = 0;
	new_proc->ocp = 0;
	new_proc->cycles_to_go = 0;
	new_proc->alive = 0;
	new_proc->next = 0;
	return (new_proc);
}

void	ft_init_players(t_info *new_info)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		new_info->players_info[i].fd = 0;
		new_info->players_info[i].header = 0;
		new_info->players_info[i].magic = 0;
		new_info->players_info[i].name = 0;
		new_info->players_info[i].comment = 0;
		new_info->players_info[i].size = 0;
		new_info->players_info[i].program = 0;
		new_info->players_info[i].live = 0;
		new_info->players_info[i].turn = 0;
		new_info->players_info[i].number = 1;
		i++;
	}
}

t_info	*ft_init_info(void)
{
	t_info	*new_info;

	new_info = (t_info*)malloc((sizeof(t_info)));
	ft_bzero(new_info->board, MEM_SIZE);
	new_info->first_processus = ft_init_proc(0);
	new_info->cycles_to_die = CYCLE_TO_DIE;
	new_info->cycles = 0;
	new_info->check = 0;
	new_info->lives_threshold = NBR_LIVE;
	new_info->total_lives = 0;
	new_info->dump = 0;
	new_info->players_nb = 0;
	ft_init_players(new_info);
	ft_bzero(new_info->argv, 15);
	new_info->player_one = 1;
	return (new_info);
}
