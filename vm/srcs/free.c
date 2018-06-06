/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:44:45 by pclement          #+#    #+#             */
/*   Updated: 2018/05/14 18:28:30 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

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
/*
** Ne pas free name et comment car sont deja free quand on free header
*/
