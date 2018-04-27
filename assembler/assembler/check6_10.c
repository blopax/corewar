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
		if ((len = is_id(split[1])) || (len = is_d4(split[1])) || (len = is_d2(split[1])))
		{
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

/*
*	sti OCP : RG, RG/ID/D2, ID/D2
*/

int		eighth_case(char *line, int start)
{
	char 	**split;
	int		len;

	while (ft_iswhitespace(line[start]))
		start++;
	split = ft_strsplit(&line[start], ',');
	if (split && split[0] && split[1] && split[2])
	{
		if ((len = is_rg(split[0])))
		{
			if (split[0][len])
				return (0);
		}
		else
			return (0);
		if ((len = is_id(split[1])) || (len = is_d4(split[1])) || (len = is_d2(split[1])) || (len = is_rg(split[1])))
		{
			if (split[1][len])
				return (0);
		}
		else
			return (0);
		if ((len = is_id(split[2])) || (len = is_d4(split[2])) || (len = is_d2(split[2])))
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
*	aff : RG
*/

int		nineth_case(char *line, int start)
{
		int		len;

	while (ft_iswhitespace(line[start]))
		start++;
	if (!(len = is_rg(&line[start])))
		return (0);
	while (line[start] != 'r')
		line++;
	while (line[start + len] && ft_iswhitespace(line[start + len]))
		start++;
	if (!line[start + len] || line[start + len] == '#')
		return (1);
	return (0);
}