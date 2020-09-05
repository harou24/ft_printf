/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 18:57:00 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/06 17:54:48 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int nb, struct s_var v)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		*(v.ret) += 2;
		ft_putnbr(147483648, v);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		*(v.ret) += 1;
		ft_putnbr(nb * (-1), v);
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10, v);
		ft_putchar((nb % 10) + '0');
		*(v.ret) += 1;
	}
}

void	ft_putnbr2(unsigned long nb, struct s_var v)
{
	if (nb >= 10)
		ft_putnbr(nb / 10, v);
	ft_putchar((nb % 10) + '0');
	*(v.ret) += 1;
}
