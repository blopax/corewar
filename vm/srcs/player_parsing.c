/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:56:03 by pclement          #+#    #+#             */
/*   Updated: 2018/05/11 18:26:12 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 12:24:21 by pclement          #+#    #+#             */
/*   Updated: 2018/05/11 17:54:36 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		ft_check_header(t_player *player)
{
	int		i;

	if (player->magic != COREWAR_EXEC_MAGIC)
		return (1);
	i = 0;
	while (i < 4)
	{
		if (player->name[PROG_NAME_LENGTH + i] != 0)
			return (1);
		if (player->comment[COMMENT_LENGTH + i] != 0)
			return (1);
	}
	return (0);
}

int		get_header(t_player *player)
{
	int		ret;
	int		count;
	int		*tmp;


	ret = 0;
	count = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	if (!(player->header = (void *)malloc(sizeof(char) * count)))
		return (1);
	ft_bzero(player->header, count);
	ret = read(player->fd, player->header, count);
	if (ret != count)
		return (1);
	if (!(tmp = (void *)malloc(sizeof(int))))
		return (1);
	ft_memcpy(tmp, player->header, sizeof(int));
	player->magic = *((unsigned char *)(player->header + 3));
	ft_putnbr(player->magic);
	player->name = (char*)(player->header + 4);
	ft_memcpy(tmp, player->header + 8 + PROG_NAME_LENGTH, sizeof(int));
	player->size = *tmp;
	player->comment = (char*)(player->header + PROG_NAME_LENGTH + 12);
	return (ft_check_header(player));
}

int		get_player(t_player *player)
{
	int		ret;
	char	buf[1];

	ret = 0;
	ft_putstr("HIHIHI");
	if (get_header(player) == 1)
		return (1);
	if (!(player->program = (void *)malloc(sizeof(char) * player->size)))
		return (1);
	ft_putstr("HUHUHU");
	ft_bzero(player->program, player->size);
	ret = read(player->fd, player->program, player->size);
	ft_putstr("HIHIHI");
	if (ret != player->size)
		return (1);
	ret = read(player->fd, buf, 1);
	if (ret != 0)
		return (1);
	return (0);
}

int		set_vm(t_info *info)
{
	int		address;
	int		i;

	i = 0;
	while (i < info->players_nb)
	{
		address = i * MEM_SIZE / info->players_nb;
		
		ft_memcpy(info->board + address, info->players_info[i].program,
				(size_t)info->players_info[i].size);
		i++;
	}
	return (i);
}
