/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:02:56 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/06 16:03:02 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	free_player(t_player *player)
{
	size_t	bytes_nb;

	bytes_nb = 0;
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
		bytes_nb = sizeof(int) * 6 + (sizeof(char *) + sizeof(void *)) * 2;
		ft_bzero(player, bytes_nb);
		free(player);
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
	ft_free_lst_proc(info->first_processus);
	free(info);
	info = 0;
	return (0);
}
/*
** Ne pas free name et comment car sont deja free quand on free header
*/
