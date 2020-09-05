/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 17:51:23 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/05 22:15:49 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hex(unsigned long nb, char c, struct s_var v)
{
	const static char	hex[16] = "0123456789abcdef";
	const static char	hex2[16] = "0123456789ABCDEF";

	if (c == 'x')
	{
		if (nb > 15)
			ft_putnbr_hex(nb / 16, 'x', v);
		ft_putchar(hex[nb % 16] + 0);
		*(v.ret) += 1;
	}
	else
	{
		if (nb > 15)
			ft_putnbr_hex(nb / 16, 'X', v);
		ft_putchar(hex2[nb % 16] + 0);
		*(v.ret) += 1;
	}
}
