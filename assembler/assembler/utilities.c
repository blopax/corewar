#include "asm.h"
#include "ft_printf.h"
#include "op.h"

void		skip_comment_and_empty_line(char **file, int *line)
{
	int		i;

	i = 0;
	while (file[*line])
	{
		if (!ft_iswhitespace(file[*line][i]) && file[*line][i])
			if (file[*line][i] != '#')
				return ;
		if (!file[*line][i] || file[*line][i] == '#')
		{
			i = -1;
			*line += 1;
		}
		i++;
	}
}

char	*after_white_space(char *str)
{
	while (ft_iswhitespace(*str))
		str++;
	return (str);
}

int			is_letter_in_label_name(char test)
{
	char	*label_chars = LABEL_CHARS;

	while (*label_chars)
		if (*label_chars == test)
			return (1);
		else
			label_chars++;
	return (0);
}

int		nb_letter(char *line, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (line[i] && line[i] != COMMENT_CHAR)
		if (line[i] == c)
		{
			nb++;
			i++;
		}
		else
			i++;
	return (nb);
}

int			label_name_valid(char *line, char **name)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_iswhitespace(line[i]))
		i++;
	while (line[i + j] && is_letter_in_label_name(line[i + j]))
		j++;
	if (line[i + j] == LABEL_CHAR)
	{
		if (name)
		{
			*name = ft_strndup(&line[i], j);
			while (j != -1)
			{
				line[i + j] = ' ';
				j--;
			}
		}
		return (1);
	}
	return (0);
}