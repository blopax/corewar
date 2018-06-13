/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:02:56 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/12 16:09:55 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	free_player(t_player *player)
{
	if (player)
	{
		if (player->header != 0)
		{
			ft_bzero(player->header, PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
			free(player->header);
		}
		if (player->program != 0)
		{
			ft_bzero(player->program, player->size);
			free(player->program);
		}
		ft_bzero(player, sizeof(t_player));
	}
}

void	ft_free_lst_proc(t_proc *proc_lst)
{
	t_proc	*proc_tmp;

	proc_tmp = proc_lst;
	while (proc_lst)
	{
		proc_tmp = proc_lst->next;
		free(proc_lst);
		proc_lst = 0;
		proc_lst = proc_tmp;
	}
}

int		ft_free_all(t_info *info)
{
	int i;

	i = 0;
	ft_free_lst_proc(info->first_processus);
	while (i < MAX_PLAYERS)
	{
		free_player(&(info->players_info[i]));
		i++;
	}
	free(info);
	info = 0;
	return (0);
}
/*
** Ne pas free name et comment car sont deja free quand on free header
*/
