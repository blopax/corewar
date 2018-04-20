/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:11:17 by pclement          #+#    #+#             */
/*   Updated: 2018/04/20 16:29:15 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

typedef	struct	s_board
{
	char	mem_val;
	char	player;
}				t_board;

typedef struct	s_proc
{
	char	*reg;
	char	carry;
	int		pc;
}				t_proc;

typedef struct	s_info
{
	t_board	*board;
	t_proc	*first_processus;
	int		cycles_to_die;
	int		cycles;
	int		check;
}			t_info;


#endif
