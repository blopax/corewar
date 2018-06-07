/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:30:38 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/06 17:33:35 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_check_argv_validity(t_info *info, int i)
{
	int	k;

	k = 1;
	while (k < i)
	{
		if (info->argv[k] == 0)
			ft_error(4, info);
		k++;
	}
}

void	ft_check_player_number(t_info *info)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (i < info->players_nb)
	{
		k = i + 1;
		while (k < info->players_nb)
		{
			if (info->players_info[i].number == info->players_info[k].number)
				ft_error(5, info);
			k++;
		}
		i++;
	}
}

void	ft_set_player_number(char **argv, t_info *info, int i)
{
	if (i > 2 && ft_strcmp(argv[i - 2], "-n") == 0)
		info->players_info[info->players_nb].number =
			ft_atoi_cor(argv[i - 1], info);
	else
	{
		if (info->players_nb > 0)
		{
			info->players_info[info->players_nb].number =
				info->players_info[0].number + info->player_one;
			info->player_one++;
		}
	}
}

void	ft_check_player(char **argv, t_info *info, int i)
{
	if (ft_strcmp(ft_strstr(argv[i], ".cor"), ".cor") == 0)
	{
		info->argv[i] = 1;
		if (i > 2 && ft_strcmp(argv[i - 2], "-n") == 0)
		{
			info->argv[i - 2] = 1;
			if (ft_str_isdigit(argv[i - 1]) == 0)
				info->argv[i - 1] = 1;
			else
				ft_error(1, info);
		}
		if ((info->players_info[info->players_nb].fd =
					open(argv[i], O_RDONLY)) == -1)
			ft_error(2, info);
		ft_set_player_number(argv, info, i);
		info->players_nb++;
		ft_check_argv_validity(info, i);
	}
	ft_check_player_number(info);
}

void	ft_define_players(int argc, char **argv, t_info *info)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_check_player(argv, info, i);
		i++;
	}
	ft_check_argv_validity(info, i);
}
