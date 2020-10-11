/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_detect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 23:18:45 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/08 17:16:57 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char					detect_type(char *str)
{
	if (str[ft_strlen(str) - 1] == 'c')
		return ('c');
	else if (str[ft_strlen(str) - 1] == 's')
		return ('s');
	else if (str[ft_strlen(str) - 1] == 'p')
		return ('p');
	else if (str[ft_strlen(str) - 1] == 'd')
		return ('d');
	else if (str[ft_strlen(str) - 1] == 'i')
		return ('i');
	else if (str[ft_strlen(str) - 1] == 'u')
		return ('u');
	else if (str[ft_strlen(str) - 1] == 'x')
		return ('x');
	else if (str[ft_strlen(str) - 1] == 'X')
		return ('X');
	else if (str[ft_strlen(str) - 1] == '%')
		return ('%');
	return ('Z');
}

static int				is_flag_dot(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if ((str[i] == '.' && ft_isdigit2(str[i + 1]))
			|| (str[i] == '.' && str[i + 1] == '-') || (str[i] == '.'))
		return (i);
	return (0);
}

static struct s_flag	check_for_flags(char *str, struct s_flag flag)
{
	if ((str[0] == '-' && ft_isdigit2(str[1])) || ft_isdigit(str[0]) == 1)
	{
		flag.is_width = 1;
		flag.width = ft_atoi(str);
	}
	else if ((str[0] == '0' && ft_isdigit2(str[1]))
			|| (str[0] == '0' && str[1] == '-' && ft_isdigit2(str[2])))
	{
		flag.is_zero = 1;
		flag.zero = ft_atoi(str + 1);
	}
	else if ((str[0] == '.' && ft_isdigit2(str[1])) || (str[0] == '.'))
	{
		flag.is_dot = 1;
		flag.dot = ft_atoi(str + 1);
	}
	else if (str[0] == '0')
		flag.is_zero = 1;
	if (is_flag_dot(str) > 0 && !flag.is_dot)
	{
		flag.is_dot = 1;
		flag.dot = ft_atoi(str + is_flag_dot(str) + 1);
	}
	return (flag);
}

static int				check_duplicate_flag(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == '-')
		i++;
	return (i);
}

struct s_flag			detect_flags(char *str)
{
	struct s_flag	flag;

	if (check_duplicate_flag(str) > 1)
		str = str + check_duplicate_flag(str) - 1;
	flag = initialise();
	return (check_for_flags(str, flag));
}
