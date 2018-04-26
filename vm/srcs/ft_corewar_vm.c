/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:56:29 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/26 18:44:20 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_info	*ft_init_info(void)
{
	t_info	*new_info;

	new_info = (t_info*)malloc((sizeof(t_info)));
	ft_bzero(new_info->board, MEM_SIZE);
	return (new_info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = ft_init_info();
	if (argc == 0)
		ft_usage();
	if (ft_strcmp("-dump", argv[1]))
}
