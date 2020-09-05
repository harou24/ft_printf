/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 14:44:25 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/08 19:00:12 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static struct s_var		do_for_me(struct s_var v, va_list ap,
		const char *format)
{
	v.res = make_sub_str(format, v.i);
	v.moove = ft_strlen(v.res);
	while (is_star(v.res) == 1)
		v.res = replace_star(v.res, va_arg(ap, int));
	v.flag = detect_flags(v.res);
	v.type = detect_type(v.res);
	if (v.type == 'c')
		print_char(v, va_arg(ap, int));
	else if (v.type == 's')
		print_string(v, va_arg(ap, char *));
	else if (v.type == 'd' || v.type == 'i')
		print_int(v, va_arg(ap, int));
	else if (v.type == '%')
		print_percent(v);
	else if (v.type == 'u')
		print_u(v, va_arg(ap, unsigned));
	else if (v.type == 'x')
		print_x(v, va_arg(ap, unsigned), 'x');
	else if (v.type == 'X')
		print_x(v, va_arg(ap, unsigned), 'X');
	else if (v.type == 'p')
		print_pointer(v, va_arg(ap, unsigned long));
	return (v);
}

int						ft_printf(const char *format, ...)
{
	struct s_var	v;
	va_list			ap;
	int				ret;

	v = init();
	va_start(ap, format);
	while (format[v.i])
	{
		if (detect_percent(format[v.i]) == 1)
		{
			v = do_for_me(v, ap, format);
			v.i = v.i + v.moove;
			free(v.res);
		}
		else
		{
			write(1, &format[v.i], 1);
			*(v.ret) += 1;
		}
		v.i++;
	}
	va_end(ap);
	ret = *(v.ret);
	free(v.ret);
	return (ret);
}
