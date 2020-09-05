/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_struct.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 23:16:20 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/05 22:19:11 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

struct s_flag	initialise(void)
{
	struct s_flag	flag;

	flag.width = 0;
	flag.zero = 0;
	flag.dot = -1;
	flag.star = 0;
	flag.is_width = 0;
	flag.is_zero = 0;
	flag.is_dot = 0;
	return (flag);
}

struct s_var	init(void)
{
	struct s_var	v;

	v.flag = initialise();
	v.i = 0;
	v.type = 'Z';
	v.res = NULL;
	v.moove = 0;
	v.ret = malloc(sizeof(int));
	if (v.ret != NULL)
		*v.ret = 0;
	return (v);
}
