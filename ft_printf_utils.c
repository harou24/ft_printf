/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 13:28:30 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/05 22:15:12 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		detect_percent(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

char	*make_sub_str(const char *format, int i)
{
	char	*str;
	int		max;

	max = i;
	while (format[max] && format[max] != 'c' &&
			format[max] != 's' && format[max]
			!= 'p' && format[max] != 'd' && format[max] != 'i' &&
			format[max] != 'u' && format[max] != 'x' && format[max] != 'X')
	{
		max++;
		if (format[max] == '%')
			break ;
	}
	str = ft_substr(format, i + 1, max - i);
	return (str);
}

int		check_multi_flag(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-' || ft_isdigit(str[0]) == 1)
	{
		while (str[i])
		{
			if (str[i] == '.' && ft_isdigit2(str[i + 1]) == 1)
				return (i);
			i++;
		}
	}
	return (0);
}

int		check_multi_flag2(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-' || ft_isdigit(str[0]) == 1)
	{
		while (str[i])
		{
			if (str[i] == '.' && ((str[i + 1] == 's')
						|| (str[i + 1] == 'd') || (str[i + 1] == 'i')
						|| (str[i + 1] == 'u') || (str[i + 1] == 'x')
						|| (str[i + 1] == 'X') || (str[i + 1] == 'p')))
				return (0);
			i++;
		}
	}
	return (-1);
}
