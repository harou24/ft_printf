/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 14:40:28 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/05 22:12:38 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *str, struct s_var v)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		*v.ret += 1;
		i++;
	}
}
