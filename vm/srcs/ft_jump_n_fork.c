/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_n_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:08:45 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/29 20:10:15 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_zjump(t_info *info, t_proc *proc)
{
	int jmp_val;
	
	jmp_val = 0;
	if (proc->carry != 1)
		return (0);
	jmp_val = ft_ptr_to_uint(info, ((proc->pc + proc->op_size + 1) %
				MEM_SIZE), proc->loaded_op.param_size[0]);
	proc->pc = (proc->pc + jmp_val) % MEM_SIZE;
	return (0);
}
