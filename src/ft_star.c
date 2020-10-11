/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_star.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch </var/mail/haachtch>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 12:49:53 by haachtch      #+#    #+#                 */
/*   Updated: 2020/01/07 14:55:14 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				is_star(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

static char		*copy_without_star(char *str, char *res, char *nb)
{
	int		i;
	int		j;

	if (!str || !res || !nb)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '*')
	{
		if (str[i] != '*')
			res[i] = str[i];
		i++;
	}
	while (nb[j])
	{
		res[i + j] = nb[j];
		j++;
	}
	while (str[i])
	{
		res[i + j] = str[i + 1];
		i++;
	}
	res[i + j] = '\0';
	return (res);
}

char			*replace_star(char *str, int value)
{
	char	*nb;
	char	*res;

	if (!str)
		return (NULL);
	nb = ft_itoa2(value);
	res = malloc(ft_strlen(str) + ft_strlen(nb) + 1);
	if (res == NULL)
		return (NULL);
	if (value < 0 && str[0] == '-')
	{
		free(nb);
		nb = ft_itoa2(value);
		free(res);
		res = ft_substr(str, 2, ft_strlen(res));
	}
	res = copy_without_star(str, res, nb);
	free(str);
	free(nb);
	return (res);
}
