#include "asm.h"
#include "ft_printf.h"
#include "op.h"

void	size_and_ocp(int *ret, int type, int bitwise, int size)
{
	ret[0] += type << bitwise;
	ret[1] += size;
}

int		check_param(char *str, int test, char **ret)
{
	int		len;
	char	*tmp;

	if ((test & 1) && (len = is_rg(str)))
	{
		tmp = after_white_space(&str[len]);
			if (len && (!*tmp || *tmp == COMMENT_CHAR) && (*ret = tmp))
				return (len);
	}
	if ((test & 2))
	{
		len = is_d2(str);
		if (!len)
			len = is_d4(str);
		tmp = after_white_space(&str[len]);
		if (len && (!*tmp || *tmp == COMMENT_CHAR) && (*ret = tmp))
			return (len);
	}
	if ((test & 4) && (len = is_id(str)))
	{
		tmp = after_white_space(&str[len]);
		if (len && (!*tmp || *tmp == COMMENT_CHAR) && (*ret = tmp))
			return (len);
	}
	return (0);
}