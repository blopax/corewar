#include "op.h"
#include "asm.h"
#include "ft_printf.h"


int		is_d2(char *line)
{
	int		i;

	i = 0;
	while (*line || ft_iswhitespace(*line))
		if (!*line)
			return (0);
		else
			line++;
	if (line[i] == DIRECT_CHAR && line[i + 1] == LABEL_CHAR)
	{
		i += 2;
		while (ft_isascii(line[i]))
			i++;
	}
	else
		return (0);
	return (i - 2);
}

int		is_d4(char *line)
{
	int		i;

	i = 0;
	while (ft_iswhitespace(*line) && *line)
			line++;
	if (!*line)
		return (0);
	if (line[i] == DIRECT_CHAR && ++i)
		while (ft_isdigit(line[i]))
			i++;
	else
		return (0);
	if (i > 11 || (i == 11 && ft_strncmp(line, "%2147483647", 11) > 0))
		return (0);
	return (i);
}

int		is_rg(char *line)
{
	int		i;

	i = 0;
	while (*line && ft_iswhitespace(*line))
			line++;
	if (!*line)
		return (0);
	if (line[i] == 'r' && ++i)
		while (ft_isdigit(line[i]))
			i++;
	else
		return (0);
	if (i > 3 || (i == 3 && ft_strncmp(line, "r16", 3) > 0))
		return (0);
	return (i);
}

int		is_id(char *line)
{
	int		i;

	i = 0;
	while (!line || ft_iswhitespace(*line))
		if (!*line)
			return (0);
		else
			line++;
	if (ft_isdigit(line[i]))
		while (ft_isdigit(line[i]))
			i++;
	else
		return (0);
	if (i > 10 || (i == 10 && ft_strncmp(line, "2147483647", 10) > 0))
		return (0);
	return (i);
}