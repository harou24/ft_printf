/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 17:08:21 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/08 15:57:01 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_digitlen(unsigned long nb)
{
	size_t	size;

	if (nb == 0)
		return (nb + 1);
	size = 0;
	while (nb != 0)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

char			*ft_itoa(unsigned long n)
{
	unsigned long		long_n;
	long				len;
	char				*fresh;
	const static char	tab[16] = "0123456789abcdef";

	long_n = n;
	len = ft_digitlen(long_n);
	if (len == 0)
		len = 1;
	fresh = (char *)malloc((len + 1) * sizeof(char));
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	len--;
	while (len >= 0)
	{
		fresh[len] = (tab[long_n % 16]) + 0;
		len--;
		long_n /= 16;
	}
	return (fresh);
}
