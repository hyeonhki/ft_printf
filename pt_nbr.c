/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 09:33:30 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/03/14 17:10:11 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pt_plusd(t_info *info)
{
	if (info->int_d == 0 && info->prec == 0)
		info->ret = 0;
	else
		info->ret = ft_itoa(info->int_d);
	if (info->prec > (info->len = (int)ft_strlen(info->ret)))
	{
		info->buf = ft_bufwhat(info->prec - info->len, '0');
		info->ret = ft_strjoin(info->buf, info->ret);
		free(info->buf);
	}
	info->len = ft_strlen(info->ret);
	if (info->width > info-> len)
		info->buf = (char *)malloc(info->width - info->len);
	else
		info->buf = ft_strdup("");
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

int		pt_minusd(t_info *info)
{
	info->ret = ft_itoa(-1 * (info->int_d));
	if ((info->prec > (info->len = (int)ft_strlen(info->ret))))
	{
		info->buf = ft_bufwhat(info->prec - info->len, '0');
		info->ret = ft_strjoin(info->buf, info->ret);
		free(info->buf);
	}
	info->len = ft_strlen(info->ret);
	info->buf = ft_minus_malloc(info->width - info->len - 1);
//	if (!(info->buf = (char *)malloc(info->width - info->len - 1)))
//		info->buf = ft_strdup("");
	if (info->prec < 0 && info->f_zero == 1 && info->f_minus == 0)
	{
		ft_bewhat(info->buf, info->width - 1 - info->len, '0');
		info->buf = ft_strjoin("-", info->buf);
		pt_flagswap(info->f_minus, info->buf, info->ret);
	}
	else
	{
		ft_bewhat(info->buf, info->width - 1 - info->len, ' ');
		info->ret = ft_strjoin("-", info->ret);
		pt_flagswap(info->f_minus, info->buf, info->ret);
	}
	info->cnt = ft_strlen(info->buf) + ft_strlen(info->ret);
	ft_multifree(info->buf, info->ret);
	return (info->cnt);
}

int		pt_u(t_info *info)
{
	if (info->int_u == 0 && info->prec == 0)
		info->ret = 0;
	else
		info->ret = ft_itoa(info->int_u);
	if (info->prec > (info->len = (int)ft_strlen(info->ret)))
	{
		info->buf = ft_bufwhat(info->prec - info->len, '0');
		info->ret = ft_strjoin(info->buf, info->ret);
		free(info->buf);
	}
	info->len = ft_strlen(info->ret);
	info->buf = ft_minus_malloc(info->width - info->len);
//	info->buf = (char *)malloc(info->width - info->len);
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

int		pt_p(va_list ap, t_info *info)
{
	unsigned long	p;

	if ((info->void_p = va_arg(ap, void *)) == NULL)
		p = 0;
	else
		p = (unsigned long)info->void_p;
	if (p == 0 && info->prec != -1)
		info->ret = ft_strdup("");
	else
		info->ret = *ft_putnbr_base(p, "0123456789abcdef");
	info->len = ft_strlen(info->ret);
	if (info->prec > info->len)
	{
		info->buf = ft_bufwhat(info->prec - info->len, '0');
		info->ret = ft_strjoin(info->buf, info->ret);
		free(info->buf);
	}
	info->ret = ft_strjoin("0x", info->ret);
	info->buf = (char *)malloc(info->width - ft_strlen(info->ret));
	ft_bewhat(info->buf, info->width - ft_strlen(info->ret), ' ');
	pt_flagswap(info->f_minus, info->buf, info->ret);
	info->cnt = ft_strlen(info->buf) + ft_strlen(info->ret);
	ft_multifree(info->buf, info->ret);
	return (info->cnt);
}
