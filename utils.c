/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:30:49 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/22 17:03:33 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bewhat(void *ptr, int size, int what)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		*((char *)ptr + i) = what;
		i++;
	}
}

int		ft_check_init(char c, const char *src)
{
	while (*src)
	{
		if (c == *src)
			return (1);
		src++;
	}
	return (0);
}

void	ft_ptstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

char	*ft_strndup(const char *src, int n)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc((unsigned int)n + 1);
	if (temp == 0)
		return (0);
	while (src[i] != '\0' && n >= 0)
	{
		temp[i] = src[i];
		i++;
		n--;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_dup_options(char *str, char *type, int *index)
{
	int				i;
	int				j;
	char			*ret;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (type[j])
		{
			if (str[i] == type[j])
			{
				*index += i + 1;
				if (!(ret = ft_strndup((str + 1), i - 1)))
					return (0);
				return (ret);
			}
			j++;
		}
		i++;
	}
	return (0);
}