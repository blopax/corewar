#include "asm.h"
#include "ft_printf.h"
#include "op.h"


int		nb_letter(char *line, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (line[i])
		if (line[i] == c)
		{
			nb++;
			i++;
		}
		else
			i++;
	return (nb);
}

char	*after_white_space(char *str)
{
	while (ft_iswhitespace(*str))
		str++;
	return (str);
}

int		check_param(char *str, int test, char **ret)
{
	int		len;
	char	*tmp;

	if ((test & 1) && (len = is_rg(str)) && (tmp = after_white_space(&str[len])))
	{
			if (len && (!*tmp || *tmp == '#') && (*ret = tmp))
				return (len);
			return (0);
	}
	if ((test & 2) && ((len = is_d2(str)) || (len = is_d4(str))) && (tmp = after_white_space(&str[len])))
	{
		if (len && (!*tmp || *tmp == '#') && (*ret = tmp))
			return (len);
		return (0);
	}
	if ((test & 4) && (len = is_id(str)) && (tmp = after_white_space(&str[len])))
	{
		if (len && (!*tmp || *tmp == '#') && (*ret = tmp))
			return (len);
		return (0);
	}
	return (0);
}

/*
*	live : D4
*	zjmp : D2
*	fork : D2
*/

int		first_case(char *line, int start)
{
	int		len;
	char	*tmp;

	tmp = after_white_space(&line[start]);
	if ((len = check_param(tmp, 2, &tmp)))
	if (!*tmp || *tmp== '#')
		return (1);
	return (0);
}

/*
*	ld		OCP : ID/D4, RG
*	lld		OCP : ID/D2, RG
*/

int		second_case(char *line, int start)
{
	char	**split;
	int		len;
	char	*tmp;

	split = ft_strsplit(after_white_space(&line[start]), SEPARATOR_CHAR);
	if (split && split[0] && split[1])
	{
		len = check_param(after_white_space(split[0]), 6, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 1, &tmp);
		if (!len || (*tmp && *tmp != '#'))
			return (0);
		if (!split[2] && nb_letter(&line[start], SEPARATOR_CHAR) == 1)
			return (1);
	}
	return (0);
}

/*
*	st OCP : RG, RG/ID
*/

int		third_case(char *line, int start)
{
	char	**split;
	int		len;
	char	*tmp;

	split = ft_strsplit(after_white_space(&line[start]), ',');
	if (split && split[0] && split[1])
	{
		len = check_param(after_white_space(split[0]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 5, &tmp);
		if (!len || (*tmp && *tmp != '#'))
			return (0);
		if (!split[2] && nb_letter(&line[start], SEPARATOR_CHAR) == 1)
			return (1);
	}
	return (0);
}

/*
*	add et sub OCP : RG, RG, RG
*/

int		fourth_case(char *line, int start)
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
		len = check_param(after_white_space(split[1]), 1, &tmp);
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
* and et or et xor OCP : RG/ID/D4, RG/ID/D4, RG
*/

int		fifth_case(char *line, int start)
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
		len = check_param(after_white_space(split[1]), 7, &tmp);
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