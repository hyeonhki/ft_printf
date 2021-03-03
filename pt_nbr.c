/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 09:33:30 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/27 09:33:32 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ret이 음수일 경우
// precise 처리 어떠헤?

int		pt_d(va_list ap, t_info *info)
{
	char	*buf;

	info->int_d = va_arg(ap, int);
	if (info->int_d < 0)
		info->precise += 1;
	info->ret = ft_itoa(info->int_d);
	if (info->precise > (int)ft_strlen(info->ret))
		info->ret = ft_strjoin(ft_bufwhat(info->precise - info->len, '0'), info->ret);
	ft_mvminus(&info->ret, info->int_d);		
	info->len = ft_strlen(info->ret);
	buf = (char *)malloc(info->width - info->len);
	if (info->precise == -1 && info->f_zero == 1)
		ft_bewhat(buf, info->width - info->len, '0');
	else
		ft_bewhat(buf, info->width - info->len, ' ');
	if (info->f_minus == 1)
		ft_pt2str(info->ret, buf);
	else
		ft_pt2str(buf, info->ret);
	return (ft_strlen(buf) + ft_strlen(info->ret));
}

int		pt_plusd(t_info *info)
{
	char	*buf;
	if (info->int_d == 0 && info->precise == 0)
		info->ret = 0;
	else
		info->ret = ft_itoa(info->int_d);
	if (info->precise > (info->len = (int)ft_strlen(info->ret)))
		info->ret = ft_strjoin(ft_bufwhat(info->precise - info->len, '0'), info->ret);
	info->len = ft_strlen(info->ret);
	buf = (char *)malloc(info->width - info->len);
	if (info->precise == -1 && info->f_zero == 1)
		ft_bewhat(buf, info->width - info->len, '0');
	else
		ft_bewhat(buf, info->width - info->len, ' ');
	if (info->f_minus == 1)
		ft_pt2str(info->ret, buf);
	else
		ft_pt2str(buf, info->ret);
	return (ft_strlen(buf) + ft_strlen(info->ret));
}

int		pt_minusd(t_info *info)
{
	char	*buf;

	//itoa는 양수만로 변환해서 넣어준다
	info->ret = ft_itoa(-(info->int_d));
	if ((info->precise > (info->len = (int)ft_strlen(info->ret))))
		info->ret = ft_strjoin(ft_bufwhat(info->precise - info->len, '0'), info->ret);
	info->len = ft_strlen(info->ret);
	buf = (char *)malloc(info->width - info->len);
	if (info->precise == -1 && info->f_zero == 1)
	{
		ft_bewhat(buf, info->width - 1 - info->len, '0');
		buf = ft_strjoin("-", buf);
		ft_pt2str(buf, info->ret);
	}
	else if (info-> f_minus == 1)
	{
		ft_bewhat(buf, info->width - 1 - info->len, ' ');
		info->ret = ft_strjoin("-", info->ret);
		ft_pt2str(info->ret, buf);
	}
	else
	{
		ft_bewhat(buf, info->width - 1 - info->len, ' ');
		info->ret = ft_strjoin("-", info->ret);
		ft_pt2str(buf, info->ret);
	}
	return (ft_strlen(buf) + ft_strlen(info->ret));
}
 