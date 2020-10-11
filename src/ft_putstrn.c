/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrn.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:04:58 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/05 22:12:18 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstrn(char *str, int max, struct s_var v)
{
	int		i;

	i = 0;
	while (str[i] && i < max)
	{
		write(1, &str[i], 1);
		*v.ret += 1;
		i++;
	}
}
