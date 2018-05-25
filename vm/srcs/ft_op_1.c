/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:43:36 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/25 18:19:37 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_idx_mod(int val)
{
	if (val < 0)
		return (val % -MEM_SIZE);
	return (val % MEM_SIZE);
}

int	ft_live(t_info *info, t_proc *proc)
{
	int i;
	int	live_int;

	i = 0;
	live_int = ft_ptr_to_uint(info->board + ((proc->pc - proc->op_size + 1)
				% MEM_SIZE), proc->loaded_op.param_size[0]);
	while (i < info->players_nb)
	{
		if (info->players_info[i].number == live_int)
		{
			info->total_lives++;
			info->players_info[i].live++;
			proc->alive = 1;
		}
		i++;
	}
	ft_putstr("I'm Alive\n");
	return (0);
}

int	ft_load(t_info *info, t_proc *proc)
{
	int val;
	int reg_idx;

	ft_putstr("Je commence LOAD\n");
	proc->carry = (proc->carry + 1) % 2;
	val = ft_ptr_to_uint(info->board + ((proc->pc - proc->op_size + 2) % MEM_SIZE),
			proc->loaded_op.param_size[0]);
	reg_idx = ft_ptr_to_uint(info->board + ((2 + proc->pc - proc->op_size +
			proc->loaded_op.param_size[0]) % MEM_SIZE),
			proc->loaded_op.param_size[1]);
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
	reg_src_idx = info->board[(2 + proc->pc - proc->op_size) % MEM_SIZE];
	if (reg_src_idx <= 0 || reg_src_idx > 16)
		return (0);
	if (info->board[1 + proc->pc - proc->op_size] == 80)
	{
		reg_dest_idx = info->board[(2 + proc->pc - proc->op_size +
				proc->loaded_op.param_size[0]) % MEM_SIZE];
		if (reg_dest_idx <= 0 || reg_dest_idx > 16)
			return (0);
		proc->reg[reg_dest_idx - 1] = proc->reg[reg_src_idx - 1];
	}
	if (info->board[1 + proc->pc - proc->op_size] == 112)
	{
		val = ft_ptr_to_uint(info->board + ((2 + proc->pc - proc->op_size +
						proc->loaded_op.param_size[0]) % MEM_SIZE),
				proc->loaded_op.param_size[1]);
		ft_uint_to_ptr(info->board + ((proc->pc - proc->op_size + ft_idx_mod(val)) % MEM_SIZE),
				REG_SIZE, proc->reg[reg_src_idx - 1]);
	}
	ft_putstr("val :\t");
	ft_putnbr(val);
	ft_putstr("\n");
	ft_putstr("reg_dest_idx :\t");
	ft_putnbr(reg_dest_idx);
	ft_putstr("\treg_src_idx :\t");
	ft_putnbr(reg_src_idx);
	ft_putstr("\n");
	ft_putstr("I'm Storeded\n");
	return (0);
}

int	ft_add(t_info *info, t_proc *proc)
{
	int	r1_idx;
	int	r2_idx;
	int	r3_idx;

	ft_putstr("Je commence ADD\n");
	r1_idx = 0;
	r2_idx = 0;
	r3_idx = 0;
	r1_idx = info->board[(2 + proc->pc - proc->op_size) % MEM_SIZE];
	r2_idx = info->board[(2 + proc->pc - proc->op_size + proc->loaded_op.param_size[0]) % MEM_SIZE];
	r3_idx = info->board[(2 + proc->pc - proc->op_size + proc->loaded_op.param_size[0]+ proc->loaded_op.param_size[1]) % MEM_SIZE];
	if (r1_idx <= 0 || r1_idx > 16 || r2_idx <= 0 || r2_idx > 16 ||
			r3_idx <= 0 || r3_idx > 16)
		return (0);
	ft_putstr("\tr1 :\t");
	ft_putnbr(proc->reg[r1_idx - 1]);
	ft_putstr("\n");
	ft_putstr("\tr2 :\t");
	ft_putnbr(proc->reg[r2_idx - 1]);
	ft_putstr("\n");
	proc->reg[r3_idx - 1] = proc->reg[r1_idx - 1] + proc->reg[r2_idx - 1];
	ft_putstr("\tr3 :\t");
	ft_putnbr(proc->reg[r3_idx - 1]);
	ft_putstr("\n");
	proc->carry = (proc->carry + 1) % 2;
	ft_putstr("J'ai ADDED\n");
	return (0);
}

int	ft_sub(t_info *info, t_proc *proc)
{
	int	r1_idx;
	int	r2_idx;
	int	r3_idx;

	ft_putstr("Je commence SUB\n");
	r1_idx = 0;
	r2_idx = 0;
	r3_idx = 0;
	r1_idx = info->board[(2 + proc->pc - proc->op_size) % MEM_SIZE];
	r2_idx = info->board[(2 + proc->pc - proc->op_size + proc->loaded_op.param_size[0]) % MEM_SIZE];
	r3_idx = info->board[(2 + proc->pc - proc->op_size + proc->loaded_op.param_size[0]+ proc->loaded_op.param_size[1]) % MEM_SIZE];
	if (r1_idx <= 0 || r1_idx > 16 || r2_idx <= 0 || r2_idx > 16 ||
			r3_idx <= 0 || r3_idx > 16)
		return (0);
	ft_putstr("\tr1 :\t");
	ft_putnbr(proc->reg[r1_idx - 1]);
	ft_putstr("\n");
	ft_putstr("\tr2 :\t");
	ft_putnbr(proc->reg[r2_idx - 1]);
	ft_putstr("\n");
	proc->reg[r3_idx - 1] = proc->reg[r1_idx - 1] - proc->reg[r2_idx - 1];
	ft_putstr("\tr3 :\t");
	ft_putnbr(proc->reg[r3_idx - 1]);
	ft_putstr("\n");
	proc->carry = (proc->carry + 1) % 2;
	ft_putstr("J'ai SUBBED\n");
	return (0);
}

int	ft_zjump(t_info *info, t_proc *proc)
{
	int jmp_val;
	
	jmp_val = 0;
	if (proc->carry != 1)
		return (0);
	jmp_val = ft_ptr_to_uint(info->board + ((proc->pc + proc->op_size + 1) %
				MEM_SIZE), proc->loaded_op.param_size[0]);
	proc->pc = (proc->pc + jmp_val) % MEM_SIZE;
	return (0);
}

int	ft_load_indirect(t_info *info, t_proc *proc)
{
	int val;
	int reg_idx;

	ft_putstr("Je commence LOAD INDEX\n");
	proc->carry = (proc->carry + 1) % 2;
	val = ft_ptr_to_uint(info->board + ((proc->pc - proc->op_size + 2) % MEM_SIZE),
			proc->loaded_op.param_size[0]);
	reg_idx = ft_ptr_to_uint(info->board + ((2 + proc->pc - proc->op_size +
			proc->loaded_op.param_size[0]) % MEM_SIZE),
			proc->loaded_op.param_size[1]);
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
	return (0);
}
