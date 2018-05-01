/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:06:03 by atourner          #+#    #+#             */
/*   Updated: 2018/04/18 14:47:17 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

int			add_all_op_size(t_label *first)
{
	int		ret;
	t_label	*act;

	ret = 0;
	act = first;
	while (act)
	{
		ret += act->size;
		act = act->next;
	}
	return (ret);
}

void	add_name_comment(unsigned char *ret, char **name, int size)
{
	int		magic;

	if (ret && name)
		magic = 0;
	magic = COREWAR_EXEC_MAGIC;
	ret[0] = magic >> 24;
	ret[1] = (magic >> 16) & 0xFF;
	ret[2] = (magic >> 8) & 0xFF;
	ret[3] = magic & 0xFF;
	ft_strncpy((char*)&ret[4], name[0], PROG_NAME_LENGTH);
	ret[4 + PROG_NAME_LENGTH + 4] = size >> 24;
	ret[4 + PROG_NAME_LENGTH + 5] = (size >> 16) & 0xFF;
	ret[4 + PROG_NAME_LENGTH + 6] = (size >> 8) & 0xFF;
	ret[4 + PROG_NAME_LENGTH + 7] = (size) & 0xFF;
	ft_strncpy((char*)&ret[4 + PROG_NAME_LENGTH + 8], name[1], COMMENT_LENGTH);
}

void				add_reg(unsigned char *ret, int *i, t_op *op)
{
	char	*tmp;

	tmp = after_white_space(op->par[op->act]);
	tmp++;
	ret[*i += 1] = ft_atoi(tmp);
}

int				search_label(t_label *first, t_op *op, char *tmp, int *num)
{
	t_label		*act;
	int			ret;

	act = first;
	ret = 1;
	while (act && strcmp(act->name, &tmp[1]))
		act = act->next;
	if (!act)
		return (0);
	*num = act->relative_pos - op->relative_pos;
	return (1);
}

void			add_dir_2(unsigned char *ret, int *i, int num)
{
	ret[*i += 1] = ((num >> 8) & 0xFF);
	ret[*i += 1] = ((num) & 0xFF);
}

void			add_dir_4(unsigned char *ret, int *i, int num)
{
	ret[*i += 1] = ((num >> 24) & 0xFF);
	ret[*i += 1] = ((num >> 16) & 0xFF);
	ret[*i += 1] = ((num >> 8) & 0xFF);
	ret[*i += 1] = ((num) & 0xFF);
}

int				add_dir(unsigned char *ret, int *i, t_op *op, t_label *first)
{
	char	*tmp;
	int		num;

	tmp = after_white_space(op->par[op->act]);
	tmp++;
	if (*tmp != ':')
		num = ft_atoi(tmp);
	else
		if (!(search_label(first, op, tmp, &num)))
			return (0);
	if (op->dir_size == 2)
			add_dir_2(ret, i, num);
	if (op->dir_size == 4)
			add_dir_4(ret, i, num);
	return (1);

}

void				add_id(unsigned char *ret, int *i, t_op *op)
{
	char	*tmp;
	int		num;

	tmp = after_white_space(op->par[op->act]);
	num = ft_atoi(tmp);
	ret[*i += 1] = ((num >> 8) & 0xFF);
	ret[*i += 1] = ((num) & 0xFF);
}

int				add_act_op(unsigned char *ret, t_op *op ,t_label *first, int *i)
{
	int		bitwise;
	int		param;

	param = 0;
	bitwise = 6;
	if (first)
	ret[*i += 1] = op->op;
	if (op->op != 1 && op->op != 9 && op->op != 12 && op->op != 15 && op->op != 16)
		ret[*i += 1] = op->ocp;
	while (bitwise)
	{
		op->act = param;
		if (((op->ocp >> bitwise) & 3) == 1)
			add_reg(ret, i, op);
		if (((op->ocp >> bitwise) & 3) == 2)
			if (!(add_dir(ret, i, op, first)))
				return (0);
		if (((op->ocp >> bitwise) & 3) == 3)
			add_id(ret, i, op);
		bitwise -= 2;
		param += 1;
	}
	return (1);
}

int				add_op_str(unsigned char *ret, t_label *first)
{
	int			i;
	t_label		*act;
	t_op		*act_op;

	i = PROG_NAME_LENGTH + COMMENT_LENGTH + 15;
	act = first;
	while (act)
	{
		act_op = act->op;
		while (act_op)
		{
			if (!(add_act_op(ret, act_op,first, &i)))
				return (0);
			act_op = act_op->next;
		}
		act = act->next;
	}
	for (int j = 0; j <= i; j += 1)
	{
		if (!(j % 16))
			ft_printf("\n");
		if (!(j % 2))
			ft_printf("%.2x", ret[j]);
		else
			ft_printf("%.2x ", ret[j]);
	}
	return (1);
}

unsigned char		*create_champion(char **name, t_label *first)
{
	unsigned char	*ret;
	int				size;

	size = add_all_op_size(first);
	if (!first || !name ||
		!(ret = ft_memalloc(size + COMMENT_LENGTH + PROG_NAME_LENGTH)))
		return (NULL);
	add_name_comment(ret, name, size);
	if (!(add_op_str(ret, first)))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

/*
*	validation du fichier si c'est bon, creation du champion
*/

unsigned char		*is_file_valid(char **file)
{
	char				**name;
	unsigned char		*ret;
	t_label				*first;
	int					last_line;

	ret = NULL;
	first = NULL;
	name = check_name_and_comment(file, &last_line);
	if (name)
		first = get_label(file, last_line);
/*for (t_label *act = first; act; act = act->next)
	{
		ft_printf("%s Size [%d] RelativePos [%d]\n", act->name, act->size, act->relative_pos);
		for (t_op *op = act->op; op; op = op->next)
		{
			ft_printf("		Op [%d] Position relative [%d] ocp [%d] dir_size [%d]\n", op->op, op->relative_pos, op->ocp, op->dir_size);
			for (int i = 0; op->par[i]; i++)
				ft_printf("			%s\n", op->par[i]);
		}
	}*/
	ret = create_champion(name, first);
	ft_free_ar((void**)name);
/*	
* FREE ALL CHAINED LIST
	t_label *next;
	for (t_label *act = first; act;)
	{
		t_op *next_op;
		for (t_op *act_op = act->op; act_op;)
		{
			for (int i = 0; act_op->par[i]; i++)
				free(act_op->par[i]);
			next_op = act_op->next;
			free(act_op);
			act_op = next_op;
		}
		next = act->next;
		free(act->name);
		free(act);
		act = next;
}*/
	return (ret);
}