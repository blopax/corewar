/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:11:17 by pclement          #+#    #+#             */
/*   Updated: 2018/05/02 19:30:11 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# include "libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
typedef struct		s_op
{
	char			*mnemonic;
	int				param_nb;
	int				param_size[3];
	int				opc;
	int				cycle_nb;
	char			*full_name;
	short			codage_octal;
	short			dir_size;
}					t_op;

typedef struct		s_proc
{
	int				reg[16];
	char			carry;
	int				pc;
	int				opcode;
	int				ocp;
	int				cycles_to_go;
	int				alive;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_player
{
	int				fd;
	void			*header;
	int				magic;
	char			*name;
	char			*comment;
	int				size;
	void			*program;
	int				live;
	int				turn;
	int				number;
}					t_player;

typedef struct		s_info
{
	char			board[MEM_SIZE];
	t_proc			*first_processus;
	int				cycles_to_die;
	int				cycles;
	int				check;
	int				lives_threshold;
	int				total_lives;
	int				dump;
	int				players_nb;
	t_player		players_info[MAX_PLAYERS];
	char			argv[15];
}					t_info;

int					ft_atoi_cor(const char *str);
#endif
