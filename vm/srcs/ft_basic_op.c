/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:13:38 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/05 19:47:33 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_live(t_info *info, t_proc *proc)
{
	int i;
	int	live_int;

	i = 0;
	live_int = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	while (i < info->players_nb)
	{
		if (info->players_info[i].number == live_int)
		{
			info->total_lives++;
			ft_putstr("Player ");
			ft_putnbr(info->players_info[i].number);
			ft_putstr(" is alive \n");
			info->players_info[i].live++;
			proc->alive = 1;
		}
		i++;
	}
	return (0);
}

int	ft_load(t_info *info, t_proc *proc)
{
	int val;
	int reg_idx;

	ft_putstr("Je commence LOAD\n");
	reg_idx = ft_ptr_to_uint(info, proc->pc + P_SIZE[0], P_SIZE[1]);
	if (info->board[ft_mod_memsize(proc->pc - 1)] == 144)
		val = ft_ptr_to_uint(info, proc->pc, P_SIZE[0]);
	if (info->board[ft_mod_memsize(proc->pc - 1)] == 208)
	{
		ft_putstr("TEST :\t");
		ft_putnbr(ft_idx_mod(proc, ft_ptr_to_uint(info, proc->pc, P_SIZE[0])));
		ft_putstr("\n");
		val = ft_ptr_to_uint(info, proc->pc - 2 + ft_idx_mod(proc,
				ft_ptr_to_uint(info, proc->pc, P_SIZE[0])),
				proc->loaded_op.dir_size);
	}
	ft_putstr("val :\t");
	ft_putnbr(val);
	ft_putstr("\n");
	ft_putstr("reg_idx :\t");
	ft_putnbr(reg_idx);
	ft_putstr("\n");
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	proc->reg[reg_idx - 1] = val;
	ft_putstr("\n");
	ft_putstr("I'm Loaded\n");
	(val == 0) ? ft_modif_carry(proc, 1) : ft_modif_carry(proc, 0);
	return (0);
}

int	ft_store(t_info *info, t_proc *proc)
{
	int val;
	int reg_src_idx;
	int reg_dest_idx;
	
	ft_putstr("Je commence STORE\n");
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
		ft_putstr("reg_dest_idx :\t");
		ft_putnbr(reg_dest_idx);
		proc->reg[reg_dest_idx - 1] = proc->reg[reg_src_idx - 1];
	}
	if (info->board[ft_mod_memsize(proc->pc - 1)] == 112)
	{
		val = ft_ptr_to_uint(info, proc->pc + P_SIZE[0], P_SIZE[1]);
		ft_putstr("val :\t");
		ft_putnbr(val);
		ft_putstr("\n");
		ft_uint_to_ptr(info, proc->pc - 2 + ft_idx_mod(proc, val),
				REG_SIZE, proc->reg[reg_src_idx - 1]);
	}
	ft_putstr("reg_src_idx :\t");
	ft_putnbr(reg_src_idx);
	ft_putstr("\t reg_src_idx_value :\t");
	ft_putnbr(proc->reg[reg_src_idx - 1]);
	ft_putstr("\nI'm Storeded\n");
	return (0);
}

int		ft_aff(t_info *info, t_proc *proc)
{
	int		reg_idx;

	reg_idx = info->board[proc->pc];
	if (reg_idx < 1 || reg_idx > 16)
		return (0);
	ft_putstr("\n________________________________JE COMMENCE AFF\n");
	ft_putchar(proc->reg[reg_idx - 1]);
	ft_putstr("\n________________________________Jai AFF\n");
	return (0);
}
