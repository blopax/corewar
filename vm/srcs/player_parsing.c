/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 12:24:21 by pclement          #+#    #+#             */
/*   Updated: 2018/06/12 16:48:05 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_check_header(t_player *player)
{
	int		i;

	i = 0;
	if (player->magic != COREWAR_EXEC_MAGIC)
		return (1);
	while (i < 4)
	{
		if (player->name[PROG_NAME_LENGTH + i] != 0)
			return (1);
		if (player->comment[COMMENT_LENGTH + i] != 0)
			return (1);
		i++;
	}
	if (player->size > CHAMP_MAX_SIZE)
		return (1);
	return (0);
}

int				get_header(t_player *player)
{
	int		ret;
	int		count;

	ret = 0;
	count = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	if (!(player->header = (void *)malloc(sizeof(void) * count)))
		return (1);
	ft_bzero(player->header, count);
	ret = read(player->fd, player->header, count);
	if (ret != count)
		return (1);
	player->magic = ft_ptr_to_uint_parsing(
			(unsigned char *)(player->header), 4);
	player->name = (char*)(player->header + 4);
	player->size = ft_ptr_to_uint_parsing((unsigned char *)(player->header
				+ 8 + PROG_NAME_LENGTH), 4);
	player->comment = (char*)(player->header + PROG_NAME_LENGTH + 12);
	return (ft_check_header(player));
}

int				get_player(t_player *player)
{
	int		ret;
	char	buf[1];

	ret = 0;
	if (get_header(player) == 1)
		return (1);
	if (!(player->program = (void *)malloc(sizeof(char) * player->size)))
		return (1);
	ft_bzero(player->program, player->size);
	ret = read(player->fd, player->program, player->size);
	if ((unsigned int)ret != player->size)
		return (1);
	ret = read(player->fd, buf, 1);
	if (ret != 0)
		return (1);
	return (0);
}

int				set_vm(t_info *info)
{
	int		address;
	int		i;

	i = 0;
	address = 0;
	while (i < info->players_nb)
	{
		address = i * MEM_SIZE / info->players_nb;
		ft_memcpy((void *)(info->board + address),
				(void *)(info->players_info[i].program),
				(size_t)info->players_info[i].size);
		i++;
	}
	return (i);
}
