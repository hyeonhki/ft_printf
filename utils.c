/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:30:49 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/03/14 14:48:09 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_multifree(char *p1, char *p2)
{
	free(p1);
	free(p2);
}

void	ft_bewhat(void *ptr, int size, int what)
{
	int				i;

	i = 0;
	if (size < 0)
		return ;
	else
	{
		while (i < size)
		{
			*((char *)ptr + i) = what;
			i++;
		}
		*((char *)ptr + i) = '\0';
	}
}

char	*ft_bufwhat(int size, int what)
{
	char			*temp;
	int				i;

	i = 0;
	temp = (char *)malloc(size);
	while (i < size)
	{
		*(temp + i) = what;
		i++;
	}
	*(temp + i) = '\0';
	return (temp);
}

char	*ft_dup_options(char *str, char *type, int *index)
{
	int				i;
	int				j;
	char			*temp;
	char			*ret;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (type[j])
		{
			if (str[i] == type[j++])
			{
				*index += i;
				if (!(temp = ft_strndup(str, i)))
					return (0);
				ret = temp;
				free(temp);
				return (ret);
			}
		}
		i++;
	}
	return (0);
}
