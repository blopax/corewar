/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:56:29 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/26 19:04:37 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc	*ft_init_proc(void)
{
	t_proc	*new_proc;

	new_proc = (t_proc*)malloc(sizeof(t_proc));
	ft_bzero(new_proc->reg, sizeof(int) * 16);
	new_proc->carry = 0;

t_info	*ft_init_info(void)
{
	t_info	*new_info;

	new_info = (t_info*)malloc((sizeof(t_info)));
	ft_bzero(new_info->board, MEM_SIZE);
	new_info->first_processus = ft_init_proc();
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
