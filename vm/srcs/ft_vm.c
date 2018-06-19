/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:08:34 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/19 19:11:41 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_tab_op.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR, 0, 0, 0, 0, 0, 0, 0, 0}, 1, 10, "alive", 0, 0},
	{"ld", 2, {144, 208, 0, 0, 0, 0, 0, 0, 0}, 2, 5, "load", 1, 0},
	{"st", 2, {112, 80, 0, 0, 0, 0, 0, 0, 0}, 3, 5, "store", 1, 0},
	{"add", 3, {84, 0, 0, 0, 0, 0, 0, 0, 0}, 4, 10, "addition", 1, 0},
	{"sub", 3, {84, 0, 0, 0, 0, 0, 0, 0, 0}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {84, 100, 116, 148, 164, 180, 212, 228, 244}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {84, 100, 116, 148, 164, 180, 212, 228, 244}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {84, 100, 116, 148, 164, 180, 212, 228, 244}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR, 0, 0, 0, 0, 0, 0, 0, 0}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {80, 100, 148, 164, 212, 228, 0, 0, 0}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {84, 88, 100, 104, 116, 120, 0, 0, 0}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR, 0, 0, 0, 0, 0, 0, 0, 0}, 12, 800, "fork", 0, 1},
	{"lld", 2, {144, 208, 0, 0, 0, 0, 0, 0, 0}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {80, 100, 148, 164, 212, 228, 0, 0, 0}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR, 0, 0, 0, 0, 0, 0, 0, 0}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG, 0, 0, 0, 0, 0, 0, 0, 0}, 16, 2, "aff", 1, 0},
	{0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0, 0}
};

int		ft_preload_instruction(t_info *info, t_proc *proc)
{
	unsigned char i;

	i = *(info->board + proc->pc);
	if (i == 0 || i > 16)
		proc->pc = (proc->pc + 1) % MEM_SIZE;
	else
	{
		proc->loaded_op.mnemonic = g_op_tab[i - 1].mnemonic;
		proc->loaded_op.param_nb = g_op_tab[i - 1].param_nb;
		if ((proc->loaded_op.opcode = g_op_tab[i - 1].opcode) == 1)
			proc->loaded_op.param_size[0] = T_DIR * 2;
		else
			proc->loaded_op.param_size[0] = g_op_tab[i - 1].param_size[0];
		proc->loaded_op.param_size[1] = g_op_tab[i - 1].param_size[1];
		proc->loaded_op.param_size[2] = g_op_tab[i - 1].param_size[2];
		proc->loaded_op.codage_octal = g_op_tab[i - 1].codage_octal;
		proc->loaded_op.cycle_nb = g_op_tab[i - 1].cycle_nb;
		proc->loaded_op.full_name = g_op_tab[i - 1].full_name;
		proc->loaded_op.dir_size = 4 - (2 * g_op_tab[i - 1].dir_size);
	}
	return (1);
}

int		ft_load_instruction(t_info *info, t_proc *proc)
{
	if (proc->loaded_op.codage_octal == 1)
	{
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		proc->op_size = ft_get_op_size(proc, *(info->board + proc->pc));
	}
	else
	{
		proc->op_size = proc->loaded_op.param_size[0] +
			proc->loaded_op.param_size[1] + proc->loaded_op.param_size[2];
	}
	proc->pc = (proc->pc + 1) % MEM_SIZE;
	return (1);
}

void	ft_execute_instruction(t_info *info, t_proc *proc)
{
	ft_load_instruction(info, proc);
	tabop[proc->loaded_op.opcode - 1].f_op(info, proc);
	proc->error = 0;
	proc->pc = (proc->pc + proc->op_size) % MEM_SIZE;
	ft_bzero((void*)&(proc->loaded_op), sizeof(t_op));
}

void	ft_run_proc(t_info *info)
{
	t_proc	*proc_tmp;

	proc_tmp = ft_last(info->first_processus);
	while (proc_tmp)
	{
		if (proc_tmp->alive >= 0)
		{
			if (proc_tmp->loaded_op.cycle_nb == 0)
			{
				if (proc_tmp->loaded_op.opcode != 0)
					ft_execute_instruction(info, proc_tmp);
				ft_preload_instruction(info, proc_tmp);
			}
			if (proc_tmp->loaded_op.cycle_nb > 0)
				proc_tmp->loaded_op.cycle_nb--;
		}
		proc_tmp = proc_tmp->prev;
	}
}

void	ft_run_vm(t_info *info)
{
	while (ft_flag(info) == 1)
	{
		if (info->visual == 1)
			ft_visu(info, 0);
		ft_run_proc(info);
		info->cycles++;
		info->countdown_to_die++;
	}
	if (info->dump == -1 || info->dump > info->cycles)
	{
		if (info->visual == 1)
			ft_visu(info, 1);
		ft_putstr("\nContestant ");
		ft_putnbr(info->players_info[info->last_player_alive_idx].number);
		ft_putstr(", \"");
		ft_putstr(info->players_info[info->last_player_alive_idx].name);
		ft_putstr("\", has won !\n");
	}
}
