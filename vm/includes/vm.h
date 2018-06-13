/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:11:17 by pclement          #+#    #+#             */
/*   Updated: 2018/06/12 18:37:21 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# include "../libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"
# include <ncurses.h>
# define P_SIZE proc->loaded_op.param_size


typedef struct		s_op
{
	char			*mnemonic;
	int				param_nb;
	int				param_size[9];
	int				opcode;
	int				cycle_nb;
	char			*full_name;
	short			codage_octal;
	short			dir_size;
}					t_op;

typedef struct		s_proc
{
	unsigned int	reg[16];
	char			carry;
	int				pc;
	int				alive;
	t_op			loaded_op;
	short			op_size;
	short			error;
	struct s_proc	*next;
	struct s_proc	*prev;
}					t_proc;

typedef struct		s_player
{
	int				fd;
	void			*header;
	unsigned int	magic;
	char			*name;
	char			*comment;
	unsigned int	size;
	unsigned char	*program;
	int				live;
	int				turn;
	int				number;
}					t_player;

typedef struct		s_info
{
	unsigned char	board[MEM_SIZE];
	long int		live_board[MEM_SIZE];
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
	int				player_one;
	int				last_player_alive;
	int				countdown_to_die;
}					t_info;

int					ft_atoi_cor(const char *str, t_info *info);
void				ft_error(int error_code, t_info *info);
t_info				*ft_init_info(void);
void				ft_check_argc(int argc, char **argv, t_info *info);
void				ft_define_players(int argc, char **argv, t_info *info);
t_proc				*ft_init_proc(int pc);
void				ft_create_proc(t_info *info);
int					get_player(t_player *player);
int					set_vm(t_info *info);
void				ft_run_vm(t_info *info);
t_proc				*ft_last(t_proc *proc);
void				ft_kill_proc(t_info *info);
int					ft_check_proc_alive(t_info *info);
void				ft_show_board(t_info *info);
unsigned int		ft_ptr_to_uint_parsing(unsigned char *ptr, int size);
unsigned int		ft_ptr_to_uint(t_info *info, unsigned int ptr, int size);
void				ft_uint_to_ptr(t_info *info, unsigned int ptr, int size,
		unsigned int value);
void				ft_modif_carry(t_proc *proc, int carry_value);
int					ft_idx_mod(t_proc *proc, unsigned int val);
unsigned int		ft_mod_memsize(int val);
void				free_player(t_player *player);
int					ft_free_all(t_info *info);
int					ft_live(t_info *info, t_proc *proc);
int					ft_load(t_info *info, t_proc *proc);
int					ft_store(t_info *info, t_proc *proc);
int					ft_add(t_info *info, t_proc *proc);
int					ft_sub(t_info *info, t_proc *proc);
int					ft_and(t_info *info, t_proc *proc);
int					ft_or(t_info *info, t_proc *proc);
int					ft_xor(t_info *info, t_proc *proc);
int					ft_zjump(t_info *info, t_proc *proc);
int					ft_load_indirect(t_info *info, t_proc *proc);
int					ft_store_indirect(t_info *info, t_proc *proc);
int					ft_fork(t_info *info, t_proc *proc);
int					ft_long_load(t_info *info, t_proc *proc);
int					ft_long_load_indirect(t_info *info, t_proc *proc);
int					ft_long_fork(t_info *info, t_proc *proc);
int					ft_aff(t_info *info, t_proc *proc);
int					ft_get_param(t_info *info, t_proc *proc, int param,
					int ocp);
int					ft_param_84(t_info *info, t_proc *proc, int param);
int					ft_param_88(t_info *info, t_proc *proc, int param);
int					ft_param_100(t_info *info, t_proc *proc, int param);
int					ft_param_104(t_info *info, t_proc *proc, int param);
int					ft_param_116(t_info *info, t_proc *proc, int param);
int					ft_param_120(t_info *info, t_proc *proc, int param);
int					ft_param_148(t_info *info, t_proc *proc, int param);
int					ft_param_164(t_info *info, t_proc *proc, int param);
int					ft_param_180(t_info *info, t_proc *proc, int param);
int					ft_param_212(t_info *info, t_proc *proc, int param);
int					ft_param_228(t_info *info, t_proc *proc, int param);
int					ft_param_244(t_info *info, t_proc *proc, int param);
void				ft_init_live_board(long int *live_board);
void				ft_visu(t_info *info, int end);
int					ft_init_ncurse(WINDOW **board, WINDOW **player);
void				print_pikachu(t_info *info, WINDOW *player);
void				print_bulbasaur(t_info *info, WINDOW *player);
void				wait_plz(int ms);
void				get_ev(WINDOW *board, char c);
void				is_proc(int i, t_proc *act, WINDOW *board);
void				ft_pause(WINDOW *board);
void				change_music();
void				launch_end(t_info *info, WINDOW *player);
void				wprint_player(WINDOW *player, t_info *info, int g_wait_time);

#endif
