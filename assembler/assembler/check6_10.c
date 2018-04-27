#include "ft_printf.h"
#include "asm.h"
#include "op.h"

/*
*	ldi		OCP : RG/ID/D2, ID/D2, RG
*	lldi	OCP : RG/ID/D2, ID/D2, RG
*/

int		seventh_case(char *line, int start)
{
	char 	**split;
	int		len;
	char	*tmp;

	split = ft_strsplit(after_white_space(&line[start]), ',');
	if (split && split[0] && split[1] && split[2])
	{
		len = check_param(after_white_space(split[0]), 7, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 6, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[2]), 1, &tmp);
		if (!len || (*tmp && *tmp != '#'))
			return (0);
		if (!split[3] && nb_letter(&line[start], SEPARATOR_CHAR) == 2)
			return (1);
	}
	return (0);
}

/*
*	sti OCP : RG, RG/ID/D2, ID/D2
*/

int		eighth_case(char *line, int start)
{
	char 	**split;
	int		len;
	char	*tmp;

	split = ft_strsplit(after_white_space(&line[start]), ',');
	if (split && split[0] && split[1] && split[2])
	{
		len = check_param(after_white_space(split[0]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 7, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[2]), 6, &tmp);
		if (!len || (*tmp && *tmp != '#'))
			return (0);
		if (!split[3] && nb_letter(&line[start], SEPARATOR_CHAR) == 2)
			return (1);
	}
	return (0);
}

/*
*	aff : RG
*/

int		nineth_case(char *line, int start)
{
	int		len;
	char	*tmp;

	tmp = after_white_space(&line[start]);
	if ((len = check_param(tmp, 1, &tmp)))
	{
		tmp = after_white_space(&tmp[len]);
		if (!*tmp || *tmp == '#')
			return (1);
	}
	return (0);
}