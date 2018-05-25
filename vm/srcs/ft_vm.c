/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:08:34 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/25 16:04:23 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_tab_op.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR, 0, 0}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, "aff", 1, 0},
	{0, 0, {0, 0, 0}, 0, 0, 0, 0, 0}
};

void	ft_create_proc(t_info *info)
{
	int	i;
	int	k;
	t_proc *proc_tmp;

	i = 1;
	k = 1;
	proc_tmp = info->first_processus;
	while (i < info->players_nb)
	{
		proc_tmp->next = ft_init_proc((MEM_SIZE / info->players_nb) * k);
		proc_tmp->next->prev = proc_tmp;
		proc_tmp = proc_tmp->next;
		ft_putnbr(proc_tmp->pc);
		ft_putstr("\n");
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
		proc->loaded_op.cycle_nb = g_op_tab[i - 1].cycle_nb;
		proc->loaded_op.full_name = g_op_tab[i - 1].full_name;
		proc->loaded_op.codage_octal = g_op_tab[i - 1].codage_octal;
		proc->loaded_op.dir_size = g_op_tab[i - 1].dir_size;
	}
	return (1);
}

short	ft_get_op_size(t_op *loaded_op, unsigned char ocp)
{
	unsigned char	p[3];
	int				i;

	ft_putstr("OCP_VAL :\t");
	ft_putnbr(ocp);
	ft_putstr("\n");
	i = 0;
	p[0] = ocp / 64;
	p[1] = (ocp % 64) / 16;
	p[2] = (ocp % 16) / 4;
	ft_putstr("p0 :\t");
	ft_putnbr(p[0]);
	ft_putstr("\n");
	ft_putstr("p1 :\t");
	ft_putnbr(p[1]);
	ft_putstr("\n");
	ft_putstr("p2 :\t");
	ft_putnbr(p[2]);
	ft_putstr("\n");
	while (i < 3)
	{
		if (p[i] == 0)
			loaded_op->param_size[i] = 0;
		else if (p[i] == REG_CODE)
			loaded_op->param_size[i] = T_REG;
		else if (p[i] == DIR_CODE && loaded_op->dir_size == 0)
			loaded_op->param_size[i] = T_DIR * 2;
		else if (p[i] == DIR_CODE && loaded_op->dir_size == 1)
			loaded_op->param_size[i] = T_DIR;
		else if (p[i] == IND_CODE)
			loaded_op->param_size[i] = T_IND;
//		if ((i == 0 && p[i] == 2) || (p[1] == 0 && p[2] != 2))
//			return (0);
//		ft_putnbr(i);
//		ft_putstr("\n");
		i++;
	}
	return (2 + loaded_op->param_size[0] + loaded_op->param_size[1] +
			loaded_op->param_size[2]);
}

int		ft_load_instruction(t_info *info, t_proc *proc)
{

	ft_putstr("codage octal :\t");
	ft_putnbr(proc->loaded_op.codage_octal == 1);
	ft_putstr("\n");
	if (proc->loaded_op.codage_octal == 1)
	{
		ft_putstr("octal oui\n");
		proc->op_size = ft_get_op_size(&(proc->loaded_op),
				*(info->board + proc->pc + 1));
	}
	else
	{
		proc->op_size = 1 + proc->loaded_op.param_size[0] +
			proc->loaded_op.param_size[1] + proc->loaded_op.param_size[2];
	}
	ft_putstr("ADV :\t");
	ft_putnbr(proc->op_size);
	ft_putstr("\n");
	proc->pc = (proc->pc + proc->op_size) % MEM_SIZE;
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
	ft_bzero((void*)&(proc->loaded_op), sizeof(t_op));
}

void	ft_run_proc(t_info *info)
{
	t_proc	*proc_tmp;

	proc_tmp = ft_last(info->first_processus);
	while (proc_tmp)
	{
		if (proc_tmp->loaded_op.cycle_nb == 0)
		{
			if (proc_tmp->loaded_op.opcode != 0)
				ft_execute_instruction(info, proc_tmp);
			ft_preload_instruction(info, proc_tmp);
			ft_putstr("preoload opcode :\t");
			ft_putnbr(proc_tmp->loaded_op.opcode);
			ft_putstr("\n");
		}
		if (proc_tmp->loaded_op.cycle_nb > 0)
			proc_tmp->loaded_op.cycle_nb--;
		proc_tmp = proc_tmp->prev;
	}
}

void	ft_reinit_lives(t_info *info)
{
	t_proc *proc_tmp;

	proc_tmp = info->first_processus;
	while (proc_tmp)
	{
		proc_tmp->alive = 0;
		proc_tmp = proc_tmp->next;
	}
	info->total_lives = 0;
	info->countdown_to_die = 0;
}

int		ft_flag(t_info *info)
{
	if (info->countdown_to_die == info->cycles_to_die)
	{
		if (info->total_lives > NBR_LIVE || info->check == MAX_CHECKS - 1)
		{
			info->cycles_to_die -= CYCLE_DELTA;
			info->check = 0;
		}
		else
			info->check++;
		ft_reinit_lives(info);
	}
	if (info->cycles_to_die <= 0)
		return (0);
	return (1);
}

void	ft_run_vm(t_info *info)
{
	while (ft_flag(info) == 1)
	{
		ft_run_proc(info);
		info->cycles++;
		info->countdown_to_die++;
		ft_putstr("Cycles :\t");
		ft_putnbr(info->cycles);
		ft_putstr("\t");
		ft_putstr("Cycles_to_die :\t");
		ft_putnbr(info->cycles_to_die);
		ft_putstr("\t");
		ft_putstr("Countdown_to_die :\t");
		ft_putnbr(info->countdown_to_die);
		ft_putstr("\t");
		ft_putstr("Checks :\t");
		ft_putnbr(info->check);
		ft_putstr("\n");
	}
}
