/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 13:42:21 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 14:38:44 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			print_string4(struct s_var v, char *value)
{
	if ((size_t)v.flag.dot >= ft_strlen(value) &&
			(size_t)v.flag.width > ft_strlen(value))
		print_space(v.flag.width - ft_strlen(value) + 1, v);
	else if ((size_t)v.flag.dot < ft_strlen(value) &&
			v.flag.dot < v.flag.width)
		print_space(v.flag.width - v.flag.dot + 1, v);
	if ((size_t)v.flag.dot > ft_strlen(value))
		ft_putstr(value, v);
	else
		ft_putstrn(value, v.flag.dot, v);
}

static void			print_string3(struct s_var v, char *value)
{
	if (v.flag.width < 0 && v.flag.dot > 0)
	{
		if ((size_t)v.flag.dot > ft_strlen(value))
			ft_putstr(value, v);
		else
			ft_putstrn(value, v.flag.dot, v);
		if ((size_t)v.flag.dot >= ft_strlen(value) &&
				(size_t)-v.flag.width > ft_strlen(value))
			print_space(-v.flag.width - ft_strlen(value) + 1, v);
		else if ((size_t)v.flag.dot < ft_strlen(value) &&
				v.flag.dot < -v.flag.width)
			print_space(-v.flag.width - v.flag.dot + 1, v);
	}
	else if (v.flag.dot == 0)
	{
		if (v.flag.width >= 0)
			print_space(v.flag.width + 1, v);
		else
			print_space(-v.flag.width + 1, v);
	}
}

static void			print_string2(struct s_var v, char *value)
{
	if (v.flag.width < 0 && v.flag.dot < 0)
	{
		ft_putstr(value, v);
		if (v.flag.width < 0 && (size_t)-v.flag.width > ft_strlen(value))
			print_space(-v.flag.width - ft_strlen(value) + 1, v);
	}
	else if (v.flag.width >= 0 && v.flag.dot > 0)
		print_string4(v, value);
	else if (v.flag.width >= 0 && v.flag.dot < 0)
	{
		if ((size_t)v.flag.width > ft_strlen(value))
			print_space(v.flag.width - ft_strlen(value) + 1, v);
		ft_putstr(value, v);
	}
	else if ((v.flag.width < 0 && v.flag.dot > 0) || (v.flag.dot == 0))
		print_string3(v, value);
}

void				print_string(struct s_var v, char *value)
{
	if (value == NULL)
		value = ft_strdup("(null)");
	if (v.flag.is_width && v.flag.is_dot)
		print_string2(v, value);
	else if (v.flag.is_width)
	{
		if (v.flag.width > 0 && (size_t)v.flag.width > ft_strlen(value))
			print_space(v.flag.width - ft_strlen(value) + 1, v);
		ft_putstr(value, v);
		if (v.flag.width < 0 && (size_t)-v.flag.width > ft_strlen(value))
			print_space(-v.flag.width - ft_strlen(value) + 1, v);
	}
	else if (v.flag.is_dot)
	{
		if (v.flag.dot < 0)
			ft_putstr(value, v);
		else if ((size_t)v.flag.dot < ft_strlen(value))
			ft_putstrn(value, v.flag.dot, v);
		else
			ft_putstr(value, v);
	}
	else
		ft_putstr(value, v);
}
