/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 13:57:42 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 13:21:17 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		print_x_width_and_dot2(struct s_var v,
					unsigned long nb, char c, char *nb2)
{
	if (nb >= 0)
	{
		if (v.flag.width > v.flag.dot && (size_t)v.flag.dot >= ft_strlen(nb2))
			print_space(v.flag.width - v.flag.dot + 1, v);
		else if (v.flag.width > v.flag.dot &&
				(size_t)v.flag.dot <= ft_strlen(nb2)
				&& (size_t)v.flag.width >= ft_strlen(nb2))
			print_space(v.flag.width - ft_strlen(nb2) + 1, v);
		v.flag.zero = v.flag.dot;
		print_x_zero(v, nb, c, nb2);
		if (v.flag.dot == 0 && nb != 0)
			ft_putnbr_hex(nb, c, v);
		else if (v.flag.dot == 0 && nb == 0)
		{
			write(1, " ", 1);
			*(v.ret) += 1;
		}
	}
}

static void		print_x_width_and_dot3(struct s_var v,
					unsigned long nb, char c, char *nb2)
{
	if (v.flag.width > v.flag.dot && (size_t)v.flag.dot >= ft_strlen(nb2))
		print_space(v.flag.width - v.flag.dot, v);
	else if (v.flag.width > v.flag.dot && (size_t)v.flag.dot <= ft_strlen(nb2)
			&& (size_t)v.flag.width >= ft_strlen(nb2))
		print_space(v.flag.width - ft_strlen(nb2) + 1, v);
	v.flag.zero = v.flag.dot + 1;
	print_x_zero(v, nb, c, nb2);
	if (v.flag.dot == 0 && nb != 0)
		ft_putnbr_hex(-nb, c, v);
	else if (v.flag.dot == 0 && nb == 0)
	{
		write(1, " ", 1);
		*(v.ret) += 1;
	}
}

static void		print_x_width_and_dot4(struct s_var v,
					unsigned long nb, char c, char *nb2)
{
	if (nb >= 0)
		v.flag.zero = v.flag.dot;
	else
		v.flag.zero = v.flag.dot + 1;
	print_x_zero(v, nb, c, nb2);
	if (-v.flag.width > v.flag.dot && (size_t)v.flag.dot >= ft_strlen(nb2))
	{
		if (nb >= 0)
			print_space(-v.flag.width - v.flag.dot + 1, v);
		else
			print_space(-v.flag.width - v.flag.dot, v);
	}
}

void			print_x_width_and_dot(struct s_var v,
					unsigned long nb, char c, char *nb2)
{
	if (v.flag.width >= 0 && v.flag.dot >= 0)
	{
		if (nb >= 0)
			print_x_width_and_dot2(v, nb, c, nb2);
		else if (nb < 0)
			print_x_width_and_dot3(v, nb, c, nb2);
	}
	else if (v.flag.dot < 0 && v.flag.width < 0)
		print_x_width(v, nb, c, nb2);
	else if (v.flag.dot < 0 && v.flag.width >= 0)
		print_x_width(v, nb, c, nb2);
	else if (v.flag.dot >= 0 && v.flag.width < 0)
	{
		if ((size_t)v.flag.dot < ft_strlen(nb2))
			print_x_width(v, nb, c, nb2);
		else if ((size_t)v.flag.dot >= ft_strlen(nb2))
			print_x_width_and_dot4(v, nb, c, nb2);
	}
}
