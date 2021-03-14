/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:03:01 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/03/14 16:05:47 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pt_char(int a)
{
	write(1, &a, 1);
}

void	pt_normal(char **str, int *ret)
{
	while (**str && **str != '%')
	{
		pt_char(**str);
		(*ret)++;
		(*str)++;
	}
}

void	pt_double(char **str, int *ret)
{
	pt_char('%');
	(*str) += 2;
	(*ret)++;
}

int		pt_c(va_list ap, t_info *info)
{
	int		c;

	c = va_arg(ap, int);
	if (info->width == 0)
		info->width = 1;
	if (!(info->buf = (char *)malloc(info->width + 1 - 1)))
		return (0);
	ft_bewhat(info->buf, info->width - 1, ' ');
	if (info->f_minus == 1)
	{
		pt_char(c);
		ft_ptstr(info->buf);
	}
	else
	{
		ft_ptstr(info->buf);
		pt_char(c);
	}
	info->cnt = ft_strlen(info->buf) + 1;
	free(info->buf);
	return (info->cnt);
}

void	pt_mswap(int flag, char *s1, char *s2)
{
	if (flag == 0)
	{
		ft_ptstr(s1);
		ft_ptstr(s2);
	}
	else if (flag == 1)
	{
		ft_ptstr(s2);
		ft_ptstr(s1);
	}
}

int		pt_s(va_list ap, t_info *info)
{
	if ((info->ret = ft_strdup(va_arg(ap, char *))) == NULL)
		info->ret = ft_strdup("(null)");
	if (info->prec >= 0 && info->prec < (int)ft_strlen(info->ret))
		info->ret[info->prec] = 0;
	info->len = ft_strlen(info->ret);
	if (info->width <= info->len)
		info->width = info->len;
	info->buf = (char *)malloc(info->width - ft_strlen(info->ret));
	ft_bewhat(info->buf, info->width - ft_strlen(info->ret), info->f_space);
	pt_mswap(info->f_minus, info->buf, info->ret);
	info->cnt = ft_strlen(info->ret) + ft_strlen(info->buf);
	free(info->ret);
	free(info->buf);
	return (info->cnt);
}