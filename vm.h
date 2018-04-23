/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:11:17 by pclement          #+#    #+#             */
/*   Updated: 2018/04/23 16:44:27 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

typedef struct	s_proc
{
	char	*reg;
	char	carry;
	int		pc;
	struct	s_proc *next;
}				t_proc;

typedef struct	s_player
{
	int		live;
	char	*name;
	int		size;
}

typedef struct	s_info
{
	char	board[MEM_SIZE];
	t_proc	*first_processus;
	int		cycles_to_die;
	int		cycles;
	int		check;
	int		
}			t_info;


#endif
