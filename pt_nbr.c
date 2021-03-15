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
	info->buf = (char *)malloc(info->width - info->len);
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
	if (!(info->buf = (char *)malloc(info->width - info->len - 1)))
		 info->buf = ft_strdup("");
	if (info->prec < 0 && info->f_zero == 1 && info->f_minus == 0)
	{
		ft_bewhat(info->buf, info->width - 1 - info->len, '0');
		pt_flagswap(info->f_minus, ft_strjoin("-", info->buf), info->ret);
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
	info->buf = (char *)malloc(info->width - info->len);
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
		info->ret = ft_strjoin(ft_bufwhat(info->prec - info->len, '0'), info->ret);
	info->ret = ft_strjoin("0x", info->ret);
	info->buf = (char *)malloc(info->width - ft_strlen(info->ret));
	ft_bewhat(info->buf, info->width - ft_strlen(info->ret), ' ');
	pt_flagswap(info->f_minus, info->buf, info->ret);
	info->cnt = ft_strlen(info->buf) + ft_strlen(info->ret);
	free(info->buf);
	free(info->ret);
	return (info->cnt);
}

int		pt_x(va_list ap, t_info *info)
{
	unsigned int	x;

	x = va_arg(ap, int);
	if (x == 0 && info->prec == 0)
		info->ret = "";
	else
		info->ret = *ft_putnbr_base(x, "0123456789abcdef");
	info->len = ft_strlen(info->ret);
	if (info->prec > info->len)
		info->ret = ft_strjoin(ft_bufwhat(info->prec - info->len, '0'), info->ret);
	info->buf = (char *)malloc(info->width - ft_strlen(info->ret));
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

	x = va_arg(ap, int);
	if (x == 0 && info->prec == 0)
		info->ret = "";
	else
		info->ret = *ft_putnbr_base(x, "0123456789ABCDEF");
	info->len = ft_strlen(info->ret);
	if (info->prec > info->len)
		info->ret = ft_strjoin(ft_bufwhat(info->prec - info->len, '0'), info->ret);
	info->buf = (char *)malloc(info->width - ft_strlen(info->ret));
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

int		pt_buf(t_info *info)
{
	info->ret = "%";
	info->buf = (char *)malloc(info->width - 1);
	if (info->f_minus == 0 && info->f_zero == 1)
		ft_bewhat(info->buf, info->width - 1, '0');
	else
		ft_bewhat(info->buf, info->width - 1, ' ');
	pt_flagswap(info->f_minus, info->buf, info->ret);
	info->cnt = ft_strlen(info->buf) + 1;
//	if (info->f_minus == 1)
//		ft_pt2str(info->ret, info->buf);
//	else
//		ft_pt2str(info->buf, info->ret);
	return (ft_strlen(info->buf) + 1);
}
 