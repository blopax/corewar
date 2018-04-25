/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:11:17 by pclement          #+#    #+#             */
/*   Updated: 2018/04/25 17:29:19 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

typedef struct	s_proc
{
	char	*reg;
	char	carry;
	int		pc;
	int		opcode;
	int		ocp;

	int		cycles_to_go;
	t_proc	*next;

}				t_proc;

typedef struct	s_info
{
	char	*board[MEM_SIZE];
	t_proc	*first_processus;
	int		cycles_to_die;
	int		cycles;
	int		check;
}			t_info;


#endif
