/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:10:56 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:51:41 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

static char		**realloc_ar(char **tmp, char **act, int nb)
{
	char		**new;
	int			to_cpy;

	if (!(new = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	to_cpy = -1;
	while (++to_cpy < nb - 1)
		new[to_cpy] = ft_strdup(act[to_cpy]);
	new[to_cpy] = ft_strdup(*tmp);
	new[to_cpy + 1] = NULL;
	if (act)
		ft_free_ar((void**)act);
	ft_strdel(tmp);
	return (new);
}

static int		ft_test_line(char *line)
{
	char	*tmp;

	tmp = ft_skip_space(line);
	if (*tmp == '.' || *tmp == '#' || !*tmp || ft_isascii(*tmp))
		return (1);
	ft_strdel(&line);
	return (0);
}

static char		**read_file(int fd)
{
	char	*tmp;
	int		nb;
	char	**act;

	nb = 0;
	act = NULL;
	while (get_next_line(fd, &tmp) > 0 && ft_test_line(tmp))
		act = realloc_ar(&tmp, act, ++nb);
	return (act);
}

int				ft_valid_name(char *name)
{
	unsigned int		i;

	i = 0;
	while (name[i])
		i++;
	if (i > 2 && name[i - 1] == 's' && name[i - 2] == '.')
		return (1);
	return (0);
}

t_print			*ft_val_asm(int fd)
{
	char			**file;
	t_print			*ret;

	ret = NULL;
	if (fd >= 2)
	{
		file = read_file(fd);
		if (file)
		{
			ret = ft_val_file(file);
			ft_free_ar((void**)file);
		}
	}
	return (ret);
}
