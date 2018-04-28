#include "asm.h"
#include "ft_printf.h"
#include "op.h"

int		*get_first_ocp(int op)
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 2);
	ret[0] = 2 << 6;
	if (op == 1)
		ret[1] = 5;
	else
		ret[1] = 3;
	return (ret);
}

int		*get_second_ocp(char **split, int op)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 2);
	tmp = after_white_space(split[0]);
	ret[1] = 7;
	if (*tmp == DIRECT_CHAR)
	{
		ret[0] += 2 << 6;
		if (op != 2)
			ret[1] = 5;
	}
	else
	{
		ret[0] += 3 << 6;
	}
	ret[0] += 1 << 4;
	return (ret);
}

int		*get_third_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 2);
	ret[0] = 1 << 6;
	ret[1] = 3;
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
	{
		ret[0] += 3 << 4;
		ret[1] += 1;
	}
	else
	{
		ret[0] += 1 << 4;
		ret[1] += 4;
	}
	return (ret);
}

int		*get_fourth_ocp()
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 2);
	ret[0] = ((1 << 6) | (1 << 4) | (1 << 2));
	ret[1] = 4;
	return (ret);
}

int		*get_fifth_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 2);
	tmp = after_white_space(split[0]);
	if (*tmp == 'r')
	{
		ret[0] = 1 << 6;
		ret[1] = 3;
	}
	else if (*tmp == DIRECT_CHAR)
	{
		ret[0] = 2 << 6;
		ret[1] = 6;
	}
	else
	{
		ret[0] = 3 << 6;
		ret[1] = 6;
	}
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
	{
		ret[0] += 1 << 4;
		ret[1] += 1;
	}
	else if (*tmp == DIRECT_CHAR)
	{
		ret[0] += 2 << 4;
		ret[1] += 4;
	}
	else
	{
		ret[0] += 3 << 4;
		ret[1] += 4;
	}
	ret[0] += 1 << 2;
	ret[1] += 1;
	return (ret);
}

int		*get_seventh_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 2);
	tmp = after_white_space(split[0]);
	if (*tmp == 'r')
	{
		ret[0] = 1 << 6;
		ret[1] = 3;
	}
	else if (*tmp == DIRECT_CHAR)
	{
		ret[0] = 2 << 6;
		ret[1] = 4;
	}
	else
	{
		ret[0] = 3 << 6;
		ret[1] = 6;
	}
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
	{
		ret[0] += 1 << 4;
		ret[1] += 1;
	}
	else if (*tmp == DIRECT_CHAR)
	{
		ret[0] += 2 << 4;
		ret[1] += 2;
	}
	else
	{
		ret[0] += 3 << 4;
		ret[1] += 4;
	}
	ret[0] += 1 << 2;
	ret[1] += 1;
	return (ret);
}

int		*get_eighth_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 2);
	ret[0] = 1 << 6;
	ret[1] = 3;
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
	{
		ret[0] += 1 << 4;
		ret[1] += 1;
	}
	else if (*tmp == DIRECT_CHAR)
	{
		ret[0] += 2 << 4;
		ret[1] += 2;
	}
	else
	{
		ret[0] += 3 << 4;
		ret[1] += 4;
	}
	tmp = after_white_space(split[2]);
	if (*tmp == DIRECT_CHAR)
	{
		ret[0] += 2 << 2;
		ret[1] += 2;
	}
	else
	{
		ret[0] += 1 << 2;
		ret[1] += 1;
	}
	return (ret);
}

int		*get_nineth_ocp()
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 2);
	ret[0] = 1 << 2;
	ret[1] = 2;
	return (ret);
}