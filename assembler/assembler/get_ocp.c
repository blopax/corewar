#include "asm.h"
#include "ft_printf.h"
#include "op.h"

void	size_and_ocp(int *ret, int type, int bitwise, int size)
{
	ret[0] += type << bitwise;
	ret[1] += size;
}

int		*get_first_ocp(int op)
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	if (op == 1)
		size_and_ocp(ret, 2, 6, 5);
	else
	{
		size_and_ocp(ret, 2, 6, 3);
		ret[2] = 2;
	}
	return (ret);
}

int		*get_second_ocp(char **split, int op)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	tmp = after_white_space(split[0]);
	if (op == 2)
		ret[2] = 4;
	else
		ret[2] = 2;
	if (*tmp == DIRECT_CHAR)
	{
		if (op != 2)
			size_and_ocp(ret, 2, 6, 4);
		else
			size_and_ocp(ret, 2, 6, 6);
	}
	else
		size_and_ocp(ret, 3, 6, 6);
	size_and_ocp(ret, 1, 4, 1);
	return (ret);
}

int		*get_third_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	size_and_ocp(ret, 1, 6, 3);
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
		size_and_ocp(ret, 3, 4, 1);
	else
		size_and_ocp(ret, 1, 4, 4);
	return (ret);
}

int		*get_fourth_ocp()
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	size_and_ocp(ret, 1, 6, 2);
	size_and_ocp(ret, 1, 4, 1);
	size_and_ocp(ret, 1, 2, 1);
	return (ret);
}

int		*get_fifth_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	tmp = after_white_space(split[0]);
	ret[2] = 4;
	if (*tmp == 'r')
		size_and_ocp(ret, 1, 6, 3);
	else if (*tmp == DIRECT_CHAR)
		size_and_ocp(ret, 2, 6, 6);
	else
		size_and_ocp(ret, 2, 6, 6);
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
		size_and_ocp(ret, 1, 4, 1);
	else if (*tmp == DIRECT_CHAR)
		size_and_ocp(ret, 2, 4, 4);
	else
		size_and_ocp(ret, 3, 4, 4);
	size_and_ocp(ret, 1, 2, 1);
	return (ret);
}

int		*get_seventh_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 2;
	tmp = after_white_space(split[0]);
	if (*tmp == 'r')
		size_and_ocp(ret, 1, 6, 3);
	else if (*tmp == DIRECT_CHAR)
		size_and_ocp(ret, 2, 6, 4);
	else
		size_and_ocp(ret, 3, 6, 6);
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
		size_and_ocp(ret, 1, 4, 1);
	else if (*tmp == DIRECT_CHAR)
		size_and_ocp(ret, 2, 4, 2);
	else
		size_and_ocp(ret, 3, 4, 4);
	size_and_ocp(ret, 1, 2, 1);
	return (ret);
}

int		*get_eighth_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 2;
	size_and_ocp(ret, 1, 6, 3);
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
		size_and_ocp(ret, 1, 4, 1);
	else if (*tmp == DIRECT_CHAR)
		size_and_ocp(ret, 2, 4 ,2);
	else
		size_and_ocp(ret, 3, 4, 4);
	tmp = after_white_space(split[2]);
	if (*tmp == DIRECT_CHAR)
		size_and_ocp(ret, 2, 2, 2);
	else
		size_and_ocp(ret, 1, 2, 1);
	return (ret);
}

int		*get_nineth_ocp()
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	size_and_ocp(ret, 1, 6, 2);
	return (ret);
}