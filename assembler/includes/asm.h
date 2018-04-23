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
	char				*command;
	int					relative_pos;
	int					size;
	struct	s_label		*next;
}					t_label;

int		valid_name(char *name);
int		*val_asm(int fd);
void	print_in_file(int *to_print, char *name);
int		*turn_into_hex(char **file);
int		*is_file_valid(char **file);
char	**check_name_and_comment(char **file, int *act);
t_label	*get_label(char **name, int line);
int		get_opt(char **file, int *line, t_label *act);
int		label_name_valid(char *file, char **name);
void	skip_comment_and_empty_line(char **file, int *line);

#endif
