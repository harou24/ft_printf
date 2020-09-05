/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 13:49:28 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 13:20:18 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			print_x_dot(struct s_var v,
						unsigned long nb, char c, char *nb2)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		*(v.ret) += 1;
		if (v.flag.dot > 0 && (size_t)v.flag.dot >= ft_strlen(nb2))
			print_zero(v.flag.dot - ft_strlen(nb2) + 2, v);
		if (v.flag.dot != 0)
			ft_putnbr_hex(-nb, c, v);
		else if (v.flag.dot == 0 && nb != 0)
			ft_putnbr_hex(-nb, c, v);
	}
	else
	{
		if (v.flag.dot > 0 && (size_t)v.flag.dot >= ft_strlen(nb2))
			print_zero(v.flag.dot - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr_hex(nb, c, v);
		else if (v.flag.dot == 0 && nb != 0)
			ft_putnbr_hex(nb, c, v);
	}
}

void				print_x_zero(struct s_var v,
						unsigned long nb, char c, char *nb2)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		*(v.ret) += 1;
		if (v.flag.zero > 0)
			print_zero(v.flag.zero - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr_hex(-nb, c, v);
		if (v.flag.zero < 0 && (size_t)-v.flag.zero > ft_strlen(nb2) - 1)
			print_space(v.flag.zero + ft_strlen(nb2) - 1, v);
	}
	else
	{
		if (v.flag.zero > 0)
			print_zero(v.flag.zero - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr_hex(nb, c, v);
		if (v.flag.zero < 0 && (size_t)-v.flag.zero > ft_strlen(nb2) - 1)
			print_space(v.flag.zero + ft_strlen(nb2) - 1, v);
	}
}

static void			print_x_width2(struct s_var v,
						unsigned long nb, char c, char *nb2)
{
	if ((size_t)v.flag.width > ft_strlen(nb2))
	{
		print_space(v.flag.width - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr_hex(nb, c, v);
		else
		{
			write(1, " ", 1);
			*(v.ret) += 1;
		}
	}
	else if (v.flag.dot != 0)
		ft_putnbr_hex(nb, c, v);
}

void				print_x_width(struct s_var v,
						unsigned long nb, char c, char *nb2)
{
	if (v.flag.width > 0)
		print_x_width2(v, nb, c, nb2);
	else
	{
		if ((size_t)-v.flag.width > ft_strlen(nb2))
		{
			if (v.flag.dot != 0)
				ft_putnbr_hex(nb, c, v);
			else
			{
				if (nb == 0)
				{
					write(1, " ", 1);
					*(v.ret) += 1;
				}
				else
					ft_putnbr_hex(nb, c, v);
			}
			print_space(-v.flag.width - ft_strlen(nb2) + 1, v);
		}
		else if (v.flag.dot != 0)
			ft_putnbr_hex(nb, c, v);
		else if (v.flag.dot == 0 && nb != 0)
			ft_putnbr_hex(nb, c, v);
	}
}

void				print_x(struct s_var v, unsigned long nb, char c)
{
	char	*nb2;

	nb2 = ft_itoa(nb);
	if (v.flag.is_width && v.flag.is_dot)
		print_x_width_and_dot(v, nb, c, nb2);
	else if (v.flag.is_zero && v.flag.is_dot)
		print_x_zero_and_dot(v, nb, c, nb2);
	else if (v.flag.is_dot)
		print_x_dot(v, nb, c, nb2);
	else if (v.flag.is_zero)
		print_x_zero(v, nb, c, nb2);
	else if (v.flag.is_width)
		print_x_width(v, nb, c, nb2);
	else
	{
		if (v.flag.dot != 0)
			ft_putnbr_hex(nb, c, v);
	}
	free(nb2);
}
