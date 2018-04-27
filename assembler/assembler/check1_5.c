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

/*
*	live : D4
*/

int		first_case(char *line, int start)
{
	int		len;

	while (ft_iswhitespace(line[start]))
		start++;
	len = is_d4(&line[start]);
	if (!len)
		return (0);
	while (line[start] != DIRECT_CHAR)
		line++;
	while (line[start + len] && ft_iswhitespace(line[start + len]))
		start++;
	if (!line[start + len] || line[start + len] == '#')
		return (1);
	return (0);
}

/*
*	load OCP : ID/D4, RG
*/

int		second_case(char *line, int start)
{
	char	**split;
	int		len;

	while (ft_iswhitespace(line[start]))
		start++;
	split = ft_strsplit(&line[start], SEPARATOR_CHAR);
	if (split && split[0] && split[1])
	{
		if (((len = is_id(split[0])) || (len = is_d4(split[0])) || (len = is_d2(split[0]))))
		{
			if (split[0][len])
				return (0);
		}
		else
			return (0);
		if ((len = is_rg(split[1])))
		{
			while (split[1][len])
				if (split[1][len] == '#')
					return (1);
				else if (!ft_iswhitespace(split[1][len]))
					return (0);
				else
					len++;
			if (!split[2] && nb_letter(&line[start], SEPARATOR_CHAR) == 1)
				return (1);
		}
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

	while (ft_iswhitespace(line[start]))
		start++;
	split = ft_strsplit(&line[start], ',');
	if (split && split[0] && split[1])
	{
		if ((len = is_rg(split[0])))
		{
			if (split[0][len])
				return (0);
		}
		else
			return (0);
		if ((len = is_rg(split[1])) || (len = (is_id(split[1]))))
		{
			while (split[1][len])
				if (split[1][len] == '#')
					return (1);
				else if (!ft_iswhitespace(split[1][len]))
					return (0);
				else
					len++;
			if (!split[2] && nb_letter(&line[start], SEPARATOR_CHAR) == 1)
				return (1);
		}
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
	int		len2;

	while (ft_iswhitespace(line[start]))
		start++;
	split = ft_strsplit(&line[start], ',');
	if (split && split[0] && split[1] && split[2])
	{
		if ((len = is_rg(split[0])) && (len2 = is_rg(split[1])))
		{
			if (split[0][len] || split[1][len2])
				return (0);
		}
		else
			return (0);
		if ((len = is_rg(split[2])))
		{
			while (split[2][len])
				if (split[2][len] == '#')
					return (1);
				else if (!ft_iswhitespace(split[2][len]))
					return (0);
				else
					len++;
			if (!split[3] && nb_letter(&line[start], SEPARATOR_CHAR) == 2)
				return (1);
		}
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

	while (ft_iswhitespace(line[start]))
		start++;
	split = ft_strsplit(&line[start], ',');
	if (split && split[0] && split[1] && split[2])
	{
		if ((len = is_rg(split[0])) || (len = is_id(split[0])) || (len = is_d4(split[0])) || (len = is_d2(split[0])))
		{
			if (split[0][len])
				return (0);
		}
		else
			return (0);
		if ((len = is_rg(split[1])) || (len = is_id(split[1])) || (len = is_d4(split[1])) || (len = is_d2(split[1])))
		{
			if (split[1][len])
				ft_printf("ERROR %d %c %zu\n", len,split[1][len], ft_strlen(split[1]));
			if (split[1][len])
				return (0);
		}
		else
			return (0);
		if ((len = is_rg(split[2])))
		{
			while (split[2][len])
				if (split[2][len] == '#')
					return (1);
				else if (!ft_iswhitespace(split[2][len]))
					return (0);
				else
					len++;
			if (!split[3] && nb_letter(&line[start], SEPARATOR_CHAR) == 2)
				return (1);
		}
	}
	return (0);
}