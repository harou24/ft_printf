/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 13:32:50 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 13:48:13 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_char2(struct s_var v, int value)
{
	if (v.flag.width > 0)
	{
		print_space(v.flag.width, v);
		write(1, &value, 1);
		*(v.ret) += 1;
	}
	else if (v.flag.width < 0)
	{
		write(1, &value, 1);
		*(v.ret) += 1;
		print_space(v.flag.width, v);
	}
}

void	print_char(struct s_var v, int value)
{
	if (v.flag.width != 0)
		print_char2(v, value);
	else if (v.flag.zero != 0)
	{
		print_zero(v.flag.zero, v);
		write(1, &value, 1);
		*(v.ret) += 1;
	}
	else
	{
		write(1, &value, 1);
		*(v.ret) += 1;
	}
}
