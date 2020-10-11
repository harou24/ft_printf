/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_u3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:44:35 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 13:16:47 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		print_u_zero_and_dot2(struct s_var v,
					unsigned long nb, char *nb2)
{
	if (nb >= 0)
	{
		if (v.flag.zero > v.flag.dot && (size_t)v.flag.dot >= ft_strlen(nb2))
			print_space(v.flag.zero - v.flag.dot + 1, v);
		else if (v.flag.zero > v.flag.dot &&
				(size_t)v.flag.dot <= ft_strlen(nb2)
				&& (size_t)v.flag.zero >= ft_strlen(nb2))
			print_space(v.flag.zero - ft_strlen(nb2) + 1, v);
		if ((size_t)v.flag.dot >= ft_strlen(nb2))
			print_zero(v.flag.dot - ft_strlen(nb2) + 1, v);
		ft_putnbr2(nb, v);
	}
	else if (nb < 0)
	{
		if (v.flag.zero > v.flag.dot && (size_t)v.flag.dot >= ft_strlen(nb2))
			print_space(v.flag.zero - v.flag.dot, v);
		else if (v.flag.zero > v.flag.dot && (size_t)v.flag.dot <=
				ft_strlen(nb2) && (size_t)v.flag.zero >= ft_strlen(nb2))
			print_space(v.flag.zero - ft_strlen(nb2) + 1, v);
		write(1, "-", 1);
		*(v.ret) += 1;
		if ((size_t)v.flag.dot >= ft_strlen(nb2))
			print_zero(v.flag.dot - ft_strlen(nb2) + 2, v);
		ft_putnbr2(-nb, v);
	}
}

static void		print_u_zero_and_dot3(struct s_var v,
					unsigned long nb, char *nb2)
{
	int		tmp;

	if ((size_t)v.flag.dot >= ft_strlen(nb2))
	{
		tmp = -v.flag.zero;
		if (nb >= 0)
			v.flag.zero = v.flag.dot;
		else
			v.flag.zero = v.flag.dot + 1;
		print_u_zero(v, nb, nb2);
		if (tmp > v.flag.dot && (size_t)v.flag.dot >= ft_strlen(nb2))
		{
			if (nb >= 0)
				print_space(tmp - v.flag.dot + 1, v);
			else
				print_space(tmp - v.flag.dot, v);
		}
	}
	if ((size_t)v.flag.dot < ft_strlen(nb2))
	{
		v.flag.width = v.flag.zero;
		print_u_width(v, nb, nb2);
	}
}

void			print_u_zero_and_dot(struct s_var v,
					unsigned long nb, char *nb2)
{
	if (v.flag.dot >= 0 && v.flag.zero >= 0)
		print_u_zero_and_dot2(v, nb, nb2);
	else if (v.flag.dot < 0 && v.flag.zero < 0)
	{
		v.flag.width = v.flag.zero;
		print_u_width(v, nb, nb2);
	}
	else if (v.flag.dot < 0 && v.flag.zero >= 0)
	{
		if ((size_t)v.flag.zero < ft_strlen(nb2))
		{
			v.flag.width = v.flag.zero;
			print_u_width(v, nb, nb2);
		}
		else
			print_u_zero(v, nb, nb2);
	}
	else if (v.flag.dot >= 0 && v.flag.zero < 0)
		print_u_zero_and_dot3(v, nb, nb2);
}
