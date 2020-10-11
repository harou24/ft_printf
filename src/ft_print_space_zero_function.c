/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_space_zero_function.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:30:49 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 13:54:31 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_zero(int nb, struct s_var v)
{
	int		i;

	i = 1;
	while (i < nb)
	{
		write(1, "0", 1);
		*(v.ret) += 1;
		i++;
	}
}

void	print_space(int nb, struct s_var v)
{
	int		i;

	i = 1;
	if (nb < 0)
		nb = nb * (-1);
	while (i < nb)
	{
		write(1, " ", 1);
		*(v.ret) += 1;
		i++;
	}
}
