/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_op.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:04:00 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/05 16:22:51 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAB_OP_H
# define FT_TAB_OP_H
# include "vm.h"

typedef struct		s_tab_op
{
	int		op;
	int		(*f_op)(t_info*, t_proc*);
}					t_tab_op;

struct	s_tab_op	tabop[] =
{
	{1, &ft_live},
	{2, &ft_load},
	{3, &ft_store},
	{4, &ft_add},
	{5, &ft_sub},
	{6, &ft_and},
	{7, &ft_or},
	{8, &ft_xor},
	{9, &ft_zjump},
	{10, &ft_load_indirect},
	{11, &ft_store_indirect},
	{12, &ft_fork},
	{13, &ft_load},
	{14, &ft_load_indirect},
	{15, &ft_long_fork},
	{16, &ft_aff},
};

#endif
