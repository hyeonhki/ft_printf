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

void	ft_mvminus(char **str, int d)
{
	int	i;

	if (d >= 0)
		return ;
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '-')
			(*str)[i] = '0';
		i++;
	}
	**str = '-';
}

void	ft_bewhat(void *ptr, int size, int what)
{
	int i;

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
	char	*temp;
	int		i;

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

void	ft_check_flag(char **str, t_info *info)
{
	while (1)
	{
		if (**str == '0')
		{
			info->f_zero = 1;
			info->f_space = 0;
			(*str)++;
			continue;
		}
		if (**str == '-')
		{
			info->f_minus = 1;
			(*str)++;
			continue;
		}
		if (**str == '*')
		{
			info->f_size = 1;
			(*str)++;
			continue;
		}
		break ;
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

	if (str == 0)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

void	ft_pt2str(char *s1, char *s2)
{
	if (s1 != 0)
	{
		while (*s1)
		{
			pt_char(*s1);
			s1++;
		}
	}
	if (s2 != 0)
	{
		while (*s2)
		{
			pt_char(*s2);
			s2++;
		}
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
	while (str[i]) //%이후가 들어왔음
	{
		j = 0;
		while (type[j])
		{
			if (str[i] == type[j])
			{
				*index += i;
				if (!(ret = ft_strndup(str, i)))
					return (0);
				return (ret);
			}
			j++;
		}
		i++;
	}
	return (0);
}
