/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_pointer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 13:47:28 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 13:42:59 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_pointer(struct s_var v, unsigned long nb)
{
	char	*nb2;

	nb2 = ft_itoa(nb);
	if (v.flag.width > 0 && (size_t)v.flag.width > ft_strlen(nb2))
		print_space(v.flag.width - ft_strlen(nb2) - 1, v);
	if (v.flag.width > 0 && (size_t)v.flag.width > 4
			&& v.flag.is_dot && nb == 0)
	{
		write(1, " ", 1);
		*(v.ret) += 1;
	}
	write(1, "0x", 2);
	*(v.ret) += 2;
	if (!v.flag.is_dot)
		ft_putstr(nb2, v);
	if (v.flag.width < 0 && (size_t)-v.flag.width > ft_strlen(nb2))
		print_space(-v.flag.width - ft_strlen(nb2) - 1, v);
	free(nb2);
}
