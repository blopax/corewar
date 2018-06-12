/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:08:34 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/12 17:55:44 by atourner         ###   ########.fr       */
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

void	ft_create_proc(t_info *info)
{
	int		i;
	int		k;
	t_proc	*proc_tmp;

	i = 1;
	k = 1;
	proc_tmp = info->first_processus;
	proc_tmp->reg[0] = info->players_info[0].number;
	while (i < info->players_nb)
	{
		proc_tmp->next = ft_init_proc((MEM_SIZE / info->players_nb) * k);
		proc_tmp->next->prev = proc_tmp;
		proc_tmp = proc_tmp->next;
		proc_tmp->reg[0] = info->players_info[i].number;
		i++;
		k++;
	}
}

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

short	ft_get_op_size(t_proc *proc, unsigned char ocp)
{
	unsigned char	p[3];
	int				i;

	i = 0;
	p[0] = ocp / 64;
	p[1] = (ocp % 64) / 16;
	p[2] = (ocp % 16) / 4;
	while (i < 3)
	{
		if (p[i] == 0)
			P_SIZE[i] = 0;
		else if (p[i] == REG_CODE)
			P_SIZE[i] = 1;
		else if (p[i] == DIR_CODE && proc->loaded_op.dir_size == 4)
			P_SIZE[i] = 4;
		else if (p[i] == DIR_CODE && proc->loaded_op.dir_size == 2)
			P_SIZE[i] = 2;
		else if (p[i] == IND_CODE)
			P_SIZE[i] = 2;
		i++;
	}
	return (P_SIZE[0] + P_SIZE[1] + P_SIZE[2]);
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

t_proc	*ft_last(t_proc *proc)
{
	t_proc	*proc_tmp;

	proc_tmp = proc;
	while (proc_tmp->next)
		proc_tmp = proc_tmp->next;
	return (proc_tmp);
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
		if (proc_tmp->alive != -1)
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

void	ft_reinit_lives(t_info *info)
{
	info->total_lives = 0;
	info->countdown_to_die = 0;
}

int		ft_flag(t_info *info)
{
	if (info->dump >= 0 && info->dump == info->cycles)
	{
		ft_show_board(info);
		return (0);
	}
	if (info->countdown_to_die == info->cycles_to_die)
	{
		if (info->total_lives > NBR_LIVE || info->check == MAX_CHECKS - 1)
		{
			ft_kill_proc(info);
			info->cycles_to_die -= CYCLE_DELTA;
			info->check = 0;
		}
		else
			info->check++;
		info->total_lives = 0;
		info->countdown_to_die = 0;
	}
	if (info->cycles_to_die <= 0 || ft_check_proc_alive(info) == 0)
		return (0);
	return (1);
}

void	ft_run_vm(t_info *info)
{
	while (ft_flag(info) == 1)
	{
		ft_visu(info);
		ft_run_proc(info);
		info->cycles++;
		info->countdown_to_die++;
	}
	if (info->dump == -1)
	{
		ft_putstr("LE GRAND GAGNANT EST LE JOUEUR :\t");
		ft_putnbr(info->last_player_alive + 1);
		ft_putstr("\tNOMME :\t");
		ft_putstr(info->players_info[info->last_player_alive].name);
		ft_putstr("\n");
	}
}
