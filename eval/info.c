/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:06:10 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/03/14 16:05:30 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	info_check_flag(char **str, t_info *info)
{
	while (1)
	{
		if (**str == '0')
		{
			info->f_zero = 1;
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

int		info_check_init(char c, const char *src)
{
	while (*src)
	{
		if (c == *src)
			return (1);
		src++;
	}
	return (0);
}

void	info_init(t_info *info)
{
	info->f_minus = 0;
	info->f_zero = 0;
	info->f_size = 0;
	info->f_presize = 0;
	info->width = 0;
	info->prec = -1;
	info->spec = 0;
	info->i = 0;
	info->int_d = 0;
	info->int_u = 0;
	info->len = 0;
	info->cnt = 0;
	info->ret = 0;
	info->str = 0;
	info->buf = 0;
	info->void_p = 0;
}

void	save_info(t_info *info, char *str, va_list ap)
{
	info_check_flag(&str, info);
	if (info->f_size == 1)
		info->width = va_arg(ap, int);
	if (info->width < 0)
	{
		info->f_minus = 1;
		info->width *= -1;
	}
	else if (str[info->i] >= '0' && str[info->i] <= '9')
		info->width = ft_atoi(str + (info->i));
	while (str[info->i] >= '0' && str[info->i] <= '9')
		(info->i)++;
	if (str[info->i] == '.' && str[info->i + 1] == '*')
	{
		info->f_presize = 1;
		info->prec = va_arg(ap, int);
		info->i += 2;
	}
	else if (str[info->i] == '.')
		info->prec = ft_atoi(&str[++(info->i)]);
	while (str[info->i] >= '0' && str[info->i] <= '9')
		(info->i)++;
	info->spec = str[info->i];
}
