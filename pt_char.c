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
		write(1, &c, 1);
		ft_putstr(info->buf);
	}
	else
	{
		ft_putstr(info->buf);
		write(1, &c, 1);
	}
	info->cnt = ft_strlen(info->buf) + 1;
	free(info->buf);
	return (info->cnt);
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
	info->buf = (char *)malloc(info->width - ft_strlen(info->ret) + 1);
	ft_bewhat(info->buf, info->width - ft_strlen(info->ret), ' ');
	pt_flagswap(info->f_minus, info->buf, info->ret);
	info->cnt = ft_strlen(info->ret) + ft_strlen(info->buf);
	free(info->ret);
	free(info->buf);
	return (info->cnt);
}

int		pt_x(va_list ap, t_info *info)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	if (x == 0 && info->prec == 0)
		info->ret = ft_strdup("");
	else
		info->ret = *ft_putnbr_base(x, "0123456789abcdef");
	info->len = ft_strlen(info->ret);
	if (info->prec > info->len)
	{
		info->buf = ft_bufwhat(info->prec - info->len, '0');
		info->ret = ft_strjoin(info->buf, info->ret);
		free(info->buf);
	}
	info->buf = ft_minus_malloc(info->width - ft_strlen(info->ret) + 1);
//	info->buf = (char *)malloc(info->width - ft_strlen(info->ret));
	info->len = ft_strlen(info->ret);
	if (info->prec < 0 && info->f_zero == 1 && info->f_minus == 0)
		ft_bewhat(info->buf, info->width - info->len, '0');
	else
		ft_bewhat(info->buf, info->width - info->len, ' ');
	pt_flagswap(info->f_minus, info->buf, info->ret);
	info->cnt = ft_strlen(info->buf) + ft_strlen(info->ret);
	free(info->buf);
	free(info->ret);
	return (info->cnt);
}

int		pt_bigx(va_list ap, t_info *info)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	if (x == 0 && info->prec == 0)
		info->ret = ft_strdup("");
	else
		info->ret = *ft_putnbr_base(x, "0123456789ABCDEF");
	info->len = ft_strlen(info->ret);
	if (info->prec > info->len)
	{
		info->buf = ft_bufwhat(info->prec - info->len, '0');
		info->ret = ft_strjoin(info->buf, info->ret);
		free(info->buf);
	}
	info->buf = ft_minus_malloc(info->width - ft_strlen(info->ret) + 1);
//	info->buf = (char *)malloc(info->width - ft_strlen(info->ret));
	info->len = ft_strlen(info->ret);
	if (info->prec < 0 && info->f_zero == 1 && info->f_minus == 0)
		ft_bewhat(info->buf, info->width - info->len, '0');
	else
		ft_bewhat(info->buf, info->width - info->len, ' ');
	pt_flagswap(info->f_minus, info->buf, info->ret);
	info->cnt = ft_strlen(info->buf) + ft_strlen(info->ret);
	free(info->buf);
	free(info->ret);
	return (info->cnt);
}
