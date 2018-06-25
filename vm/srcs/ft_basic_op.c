/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:13:38 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/19 19:11:25 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_live_write(t_info *info, t_proc *proc, int live_int)
{
	int		i;

	i = 0;
	while (i < P_SIZE[0])
	{
		info->live_board[(proc->pc + i) % MEM_SIZE] = live_int;
		i++;
	}
	return (0);
}

int		ft_live(t_info *info, t_proc *proc)
{
	int i;
	int	live_int;

	i = 0;
	live_int = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	proc->alive = 1;
	while (i < info->players_nb)
	{
		if (info->players_info[i].number == live_int)
		{
			ft_live_write(info, proc, live_int);
			info->total_lives++;
			info->players_info[i].live++;
			info->last_player_alive = info->players_info[i].number;
			info->last_player_alive_idx = i;
		}
		i++;
	}
	return (0);
}

int		ft_load(t_info *info, t_proc *proc)
{
	int val;
	int reg_idx;

	val = 0;
	reg_idx = ft_ptr_to_uint(info, proc->pc + P_SIZE[0], P_SIZE[1]);
	if (info->board[ft_mod_memsize(proc->pc - 1)] == 144)
		val = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	if (info->board[ft_mod_memsize(proc->pc - 1)] == 208)
	{
		val = ft_ptr_to_uint(info, proc->pc - 2 + ft_idx_mod(proc,
				ft_ptr_to_uint(info, proc->pc, P_SIZE[0])),
				proc->loaded_op.dir_size);
	}
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	proc->reg[reg_idx - 1] = val;
	(val == 0) ? ft_modif_carry(proc, 1) : ft_modif_carry(proc, 0);
	return (0);
}

int		ft_store(t_info *info, t_proc *proc)
{
	int val;
	int reg_src_idx;
	int reg_dest_idx;

	val = 0;
	reg_dest_idx = 0;
	reg_src_idx = info->board[proc->pc];
	if (reg_src_idx <= 0 || reg_src_idx > 16)
		return (0);
	if (info->board[ft_mod_memsize(proc->pc - 1)] == 80)
	{
		reg_dest_idx = info->board[ft_mod_memsize(proc->pc + P_SIZE[0])];
		if (reg_dest_idx <= 0 || reg_dest_idx > 16)
			return (0);
		proc->reg[reg_dest_idx - 1] = proc->reg[reg_src_idx - 1];
	}
	if (info->board[ft_mod_memsize(proc->pc - 1)] == 112)
	{
		val = ft_ptr_to_uint(info, proc->pc + P_SIZE[0], P_SIZE[1]);
		ft_uint_to_ptr(info, proc->pc - 2 + ft_idx_mod(proc, val),
				REG_SIZE, proc->reg[reg_src_idx - 1]);
	}
	return (0);
}

int		ft_aff(t_info *info, t_proc *proc)
{
	int		reg_idx;

	reg_idx = info->board[proc->pc];
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	if (info->visual == 0)
		ft_putchar((char)(proc->reg[reg_idx - 1]));
	return (0);
}
