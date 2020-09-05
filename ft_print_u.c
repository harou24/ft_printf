/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_u.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:32:46 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 13:13:18 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			print_u_dot(struct s_var v, unsigned long nb, char *nb2)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		*(v.ret) += 1;
		if (v.flag.dot > 0 && (size_t)v.flag.dot >= ft_strlen(nb2))
			print_zero(v.flag.dot - ft_strlen(nb2) + 2, v);
		if (v.flag.dot != 0)
			ft_putnbr2(-nb, v);
		else if (v.flag.dot == 0 && nb != 0)
			ft_putnbr2(-nb, v);
	}
	else
	{
		if (v.flag.dot > 0 && (size_t)v.flag.dot >= ft_strlen(nb2))
			print_zero(v.flag.dot - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr2(nb, v);
		else if (v.flag.dot == 0 && nb != 0)
			ft_putnbr2(nb, v);
	}
}

void				print_u_zero(struct s_var v, unsigned long nb, char *nb2)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		*(v.ret) += 1;
		if (v.flag.zero > 0)
			print_zero(v.flag.zero - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr2(-nb, v);
		if (v.flag.zero < 0 && (size_t)-v.flag.zero > ft_strlen(nb2) - 1)
			print_space(v.flag.zero + ft_strlen(nb2) - 1, v);
	}
	else
	{
		if (v.flag.zero > 0)
			print_zero(v.flag.zero - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr2(nb, v);
		if (v.flag.zero < 0 && (size_t)-v.flag.zero > ft_strlen(nb2) - 1)
			print_space(v.flag.zero + ft_strlen(nb2) - 1, v);
	}
}

static void			print_u_width2(struct s_var v, unsigned long nb, char *nb2)
{
	if ((size_t)v.flag.width > ft_strlen(nb2))
	{
		print_space(v.flag.width - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr2(nb, v);
		else
		{
			write(1, " ", 1);
			*(v.ret) += 1;
		}
	}
	else if (v.flag.dot != 0)
		ft_putnbr2(nb, v);
}

void				print_u_width(struct s_var v, unsigned long nb, char *nb2)
{
	if (v.flag.width > 0)
		print_u_width2(v, nb, nb2);
	else
	{
		if ((size_t)-v.flag.width > ft_strlen(nb2))
		{
			if (v.flag.dot != 0)
				ft_putnbr2(nb, v);
			else
			{
				if (nb == 0)
				{
					write(1, " ", 1);
					*(v.ret) += 1;
				}
				else
					ft_putnbr2(nb, v);
			}
			print_space(-v.flag.width - ft_strlen(nb2) + 1, v);
		}
		else if (v.flag.dot != 0)
			ft_putnbr2(nb, v);
		else if (v.flag.dot == 0 && nb != 0)
			ft_putnbr2(nb, v);
	}
}

void				print_u(struct s_var v, unsigned long nb)
{
	char	*nb2;

	nb2 = ft_itoa3(nb);
	if (v.flag.is_width && v.flag.is_dot)
		print_u_width_and_dot(v, nb, nb2);
	else if (v.flag.is_zero && v.flag.is_dot)
		print_u_zero_and_dot(v, nb, nb2);
	else if (v.flag.is_dot)
		print_u_dot(v, nb, nb2);
	else if (v.flag.is_zero)
		print_u_zero(v, nb, nb2);
	else if (v.flag.is_width)
		print_u_width(v, nb, nb2);
	else
	{
		if (v.flag.dot != 0)
			ft_putnbr2(nb, v);
	}
	free(nb2);
}
