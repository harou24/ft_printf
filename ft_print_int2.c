/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 17:40:31 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/09 21:10:16 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			print_int_dot(struct s_var v, int nb, char *nb2)
{
	if (nb < 0)
	{
		if (nb != -2147483648)
			write(1, "-", 1);
		*(v.ret) += 1;
		if (v.flag.dot > 0 && (size_t)v.flag.dot >= ft_strlen(nb2))
			print_zero(v.flag.dot - ft_strlen(nb2) + 2, v);
		if (v.flag.dot != 0)
			ft_putnbr(-nb, v);
		else if (v.flag.dot == 0 && nb != 0)
			ft_putnbr(-nb, v);
	}
	else
	{
		if (v.flag.dot > 0 && (size_t)v.flag.dot >= ft_strlen(nb2))
			print_zero(v.flag.dot - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr(nb, v);
		else if (v.flag.dot == 0 && nb != 0)
			ft_putnbr(nb, v);
	}
}

void				print_int_zero(struct s_var v, int nb, char *nb2)
{
	if (nb < 0)
	{
		if (nb != -2147483648)
			write(1, "-", 1);
		*(v.ret) += 1;
		if (v.flag.zero > 0)
			print_zero(v.flag.zero - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr(-nb, v);
		if (v.flag.zero < 0 && (size_t)-v.flag.zero > ft_strlen(nb2) - 1)
			print_space(v.flag.zero + ft_strlen(nb2) - 1, v);
	}
	else
	{
		if (v.flag.zero > 0)
			print_zero(v.flag.zero - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr(nb, v);
		if (v.flag.zero < 0 && (size_t)-v.flag.zero > ft_strlen(nb2) - 1)
			print_space(v.flag.zero + ft_strlen(nb2) - 1, v);
	}
}

static void			print_int_width2(struct s_var v, int nb, char *nb2)
{
	if ((size_t)v.flag.width > ft_strlen(nb2))
	{
		print_space(v.flag.width - ft_strlen(nb2) + 1, v);
		if (v.flag.dot != 0)
			ft_putnbr(nb, v);
		else
		{
			write(1, " ", 1);
			*(v.ret) += 1;
		}
	}
	else if (v.flag.dot != 0)
		ft_putnbr(nb, v);
}

void				print_int_width(struct s_var v, int nb, char *nb2)
{
	if (v.flag.width > 0)
		print_int_width2(v, nb, nb2);
	else
	{
		if ((size_t)-v.flag.width > ft_strlen(nb2))
		{
			if (v.flag.dot != 0)
				ft_putnbr(nb, v);
			else
			{
				if (nb == 0)
				{
					write(1, " ", 1);
					*(v.ret) += 1;
				}
				else
					ft_putnbr(nb, v);
			}
			print_space(-v.flag.width - ft_strlen(nb2) + 1, v);
		}
		else if (v.flag.dot != 0)
			ft_putnbr(nb, v);
		else if (v.flag.dot == 0 && nb != 0)
			ft_putnbr(nb, v);
	}
}

void				print_int(struct s_var v, int nb)
{
	char	*nb2;

	nb2 = ft_itoa2(nb);
	if (v.flag.is_width && v.flag.is_dot)
		print_int_width_and_dot(v, nb, nb2);
	else if (v.flag.is_zero && v.flag.is_dot)
		print_int_zero_and_dot(v, nb, nb2);
	else if (v.flag.is_dot)
		print_int_dot(v, nb, nb2);
	else if (v.flag.is_zero)
		print_int_zero(v, nb, nb2);
	else if (v.flag.is_width)
		print_int_width(v, nb, nb2);
	else
	{
		if (v.flag.dot != 0)
			ft_putnbr(nb, v);
	}
	free(nb2);
}
