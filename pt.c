/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:09:58 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/03/15 20:09:59 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pt_normal(char **str, int *ret)
{
	while (**str && **str != '%')
	{
		ft_putchar(**str);
		(*ret)++;
		(*str)++;
	}
}

void	pt_double(char **str, int *ret)
{
	ft_putchar('%');
	(*str) += 2;
	(*ret)++;
}

void	pt_flagswap(int flag, char *s1, char *s2)
{
	if (flag == 0)
	{
		ft_putstr(s1);
		ft_putstr(s2);
	}
	else if (flag == 1)
	{
		ft_putstr(s2);
		ft_putstr(s1);
	}
}

int		pt_buf(t_info *info)
{
	info->ret = ft_strdup("%");
	info->buf = ft_minus_malloc(info->width - 1);
	if (info->f_minus == 0 && info->f_zero == 1)
		ft_bewhat(info->buf, info->width - 1, '0');
	else
		ft_bewhat(info->buf, info->width - 1, ' ');
	pt_flagswap(info->f_minus, info->buf, info->ret);
	info->cnt = ft_strlen(info->buf) + 1;
	free(info->buf);
	free(info->ret);
	return (info->cnt);
}
