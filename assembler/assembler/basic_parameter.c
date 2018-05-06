/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_parameter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:02:59 by atourner          #+#    #+#             */
/*   Updated: 2018/05/06 13:53:10 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "ft_printf.h"

int		is_d2(char *line)
{
	int		i;

	i = 0;
	if (line[i] == DIRECT_CHAR && line[i + 1] == LABEL_CHAR &&
		is_letter_in_label_name(line[i + 2]))
	{
		i += 2;
		while (is_letter_in_label_name(line[i]))
			i++;
		if (line[i] && !ft_iswhitespace(line[i]) && line[i] != '#')
			return (0);
	}
	else
		return (0);
	return (i);
}

int		is_d4(char *line)
{
	int		i;

	i = 0;
	if (line[i] == DIRECT_CHAR && ++i && (ft_isdigit(line[i])
		|| ((line[i] == '-' || line[i] == '+') && ft_isdigit(line[i + 1]))))
	{
		if (line[i] == '-' || line[i] == '+')
			i++;
		while (ft_isdigit(line[i]))
			i++;
	}
	else
		return (0);
	return (i);
}

int		is_rg(char *line)
{
	int		i;

	i = 0;
	if (line[i] == 'r' && ft_isdigit(line[i + 1]) && ++i)
		while (ft_isdigit(line[i]))
			i++;
	else
		return (0);
	return (i);
}

int		is_id(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '-' || line[i] == '+')
		i++;
	if (ft_isdigit(line[i]))
		while (ft_isdigit(line[i]))
			i++;
	else if (line[i] == ':')
	{
		while (is_letter_in_label_name(line[++i]))
			i++;
		if (line[i] && !ft_iswhitespace(line[i]) && line[i] != '#')
			return (0);
	}
	else
		return (0);
	return (i);
}
