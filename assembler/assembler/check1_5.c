#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
*	live : D4
*/

int		first_case(char *line, int start)
{
	int		len;

	len = is_d4(&line[start]);
	if (len > 10 || (len == 10 && ft_strncmp(&line[start], "%2147483647", 11) > 0))
		return (0);
	start++;
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

	split = ft_strsplit(&line[start], ',');
	if (split && split[0] && split[1])
	{
		if (((len = is_id(split[0])) || (len = is_d4(split[0]))))
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
		}
	}
	return (1);
}

/*
*	st OCP : RG, RG/ID
*/

int		third_case(char *line, int start)
{
	if (line && start)
		return (0);
	return (0);
}

/*
*	add et sub OCP : RG, RG, RG
*/

int		fourth_case(char *line, int start)
{
	if (line && start)
		return (0);
	return (0);
}

/*
* and et or et xor OCP : RG/ID/D4, RG/ID/D4, RG
*/

int		fifth_case(char *line, int start)
{
	if (line && start)
		return (0);
	return (0);
}