/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:18:55 by atourner          #+#    #+#             */
/*   Updated: 2018/04/20 13:52:44 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <fcntl.h>

# define OP1 "live"
# define OP2 "ld"
# define OP3 "st"
# define OP4 "add"
# define OP5 "sub"
# define OP6 "and"
# define OP7 "or"
# define OP8 "xor"
# define OP9 "zjmp"
# define OP10 "ldi"
# define OP11 "sti"
# define OP12 "fork"
# define OP13 "lld"
# define OP14 "lldi"
# define OP15 "lfork"
# define OP16 "aff"

typedef struct		s_label
{
	char				*name;
	int					relative_pos;
	int					size;
	struct s_op			*op;
	struct s_label		*next;
}					t_label;

typedef struct 		s_op
{
	int					op;
	int					ocp;
	int					dir_size;
	int					act;
	char				*par[4];
	int					size;
	int					relative_pos;
	struct s_op			*next;
}					t_op;

typedef struct		s_print
{
	unsigned char		*str;
	int					size;
}					t_print;

int				valid_name(char *name);
t_print			*val_asm(int fd);
void			print_in_file(t_print *to_print, char *name);
t_print			*is_file_valid(char **file);
char			**check_name_and_comment(char **file, int *act);
char			**split_arg(char *str);
t_label			*get_label(char **name, int line);
int				get_opt(char **file, int *line, t_label *act);
int				label_name_valid(char *file, char **name);
void			skip_comment_and_empty_line(char **file, int *line);
char			*after_white_space(char *str);
void			size_and_ocp(int *ret, int type, int bitwise, int size);
int				check_param(char *str, int test, char **ret);
int				nb_letter(char *line, char c);
int				is_letter_in_label_name(char c);
int				first_case(char *line, char **split, int op, t_label *act);
int				second_case(char *line, char **split, int op, t_label *act);
int				third_case(char *line, char **split, int op, t_label *act);
int				fourth_case(char *line, char **split, int op, t_label *act);
int				fifth_case(char *line, char **split, int op, t_label *act);
int				sixth_case(char *line, char **split, int op, t_label *act);
int				seventh_case(char *line, char **split, int op, t_label *act);
int				eighth_case(char *line, char **split, int op, t_label *act);
int				is_d2(char *line);
int				is_d4(char *line);
int				is_rg(char *line);
int				is_id(char *line);
void			add_reg(unsigned char *ret, int *i, t_op *op);
int				add_dir(unsigned char *ret, int *i, t_op *op, t_label *first);
int				add_id(unsigned char *ret, int *i, t_op *op, t_label *first);
int				add_op(char **split, int op, t_label *act, int *ocp);
int				add_all_op_size(t_label *first);
int				free_chain(t_label *first, int ret);
int				add_op_str(unsigned char *ret, t_label *first, int *i);
int				free_and_ret(char **ar_str, int *tab, int ret);
int				add_act_op(unsigned char *ret, t_op *op ,t_label *first, int *i);

#endif