/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_percent.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 13:40:20 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 13:46:19 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_percent2(struct s_var v)
{
	if (v.flag.width > 0)
	{
		print_space(v.flag.width, v);
		write(1, "%", 1);
		*(v.ret) += 1;
	}
	else
	{
		write(1, "%", 1);
		*(v.ret) += 1;
		print_space(v.flag.width, v);
	}
}

void	print_percent(struct s_var v)
{
	if (v.flag.width != 0)
	{
		print_percent2(v);
	}
	else if (v.flag.zero != 0)
	{
		print_zero(v.flag.zero, v);
		write(1, "%", 1);
		*(v.ret) += 1;
	}
	else
	{
		write(1, "%", 1);
		*(v.ret) += 1;
	}
}
