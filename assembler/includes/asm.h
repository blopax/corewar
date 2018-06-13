/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:18:55 by atourner          #+#    #+#             */
/*   Updated: 2018/06/12 19:25:07 by atourner         ###   ########.fr       */
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

typedef struct		s_op
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

int					ft_valid_name(char *name);
t_print				*ft_val_asm(int fd);
void				ft_print_file(t_print *to_print, char *name);
t_print				*ft_val_file(char **file);
char				**ft_check_com_nam(char **file, int *act);
char				**ft_split_arg(char *str);
t_label				*ft_get_label(char **name, int line);
int					ft_get_opt(char **file, int *line, t_label *act);
int					ft_val_lab(char *file, char **name);
void				ft_skip_empty(char **file, int *line);
char				*ft_skip_space(char *str);
void				ft_size_ocp(int *ret, int type, int bitwise, int size);
int					ft_check_param(char *str, int test, char **ret);
int					ft_nb_letter(char *line, char c);
int					ft_letter_lab_name(char c);
int					ft_case_1(char *line, char **split, int op, t_label *act);
int					ft_case_2(char *line, char **split, int op, t_label *act);
int					ft_case_3(char *line, char **split, int op, t_label *act);
int					ft_case_4(char *line, char **split, int op, t_label *act);
int					ft_case_5(char *line, char **split, int op, t_label *act);
int					ft_case_6(char *line, char **split, int op, t_label *act);
int					ft_case_7(char *line, char **split,
		int op, t_label *act);
int					ft_case_8(char *line, char **split, int op, t_label *act);
int					ft_is_d2(char *line);
int					ft_is_d4(char *line);
int					ft_is_rg(char *line);
int					ft_is_id(char *line);
void				ft_add_reg(unsigned char *ret, int *i, t_op *op);
int					ft_add_dir(unsigned char *ret, int *i,
		t_op *op, t_label *first);
int					ft_add_id(unsigned char *ret, int *i,
		t_op *op, t_label *first);
int					ft_add_op(char **split, int op, t_label *act, int *ocp);
int					ft_add_all_op_size(t_label *first);
int					ft_free_chain(t_label *first, int ret);
int					ft_ft_add_op_str(unsigned char *ret,
		t_label *first, int *i);
int					ft_free_and_ret(char **ar_str, int *tab, int ret);
int					ft_add_act_op(unsigned char *ret, t_op *op,
		t_label *first, int *i);
void				ft_print_error(int type, int len);
void				ft_get_describe_len(int *name_len, int *cmd_len, int *len);
int					ft_strncmp_s(char **file, int *act, int choice);

#endif
