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

int		pt_d(va_list ap, t_info *info)
{
	char	*ret;
	char	*buf;

	info->int_d = va_arg(ap, int);
	if (info->int_d < 0)
		ret = ft_itoa(-(info->int_d));
	else
		ret = ft_itoa(info->int_d);
	//ret에 부호가 '-'일 경우 그 사이에 Precise 공백을 붙여줘야한다..
	//-는 width에서 취급을 안하네..
	if (info->precise > (info->len = ft_strlen(ret)))
		ret = ft_strjoin(ft_bufwhat(info->precise - info->len, '0'), ret);
	info->len = ft_strlen(ret);
	buf = (char *)malloc(info->width - info->len);
	if (info->precise == -1 && info->f_zero == '0')
		ft_bewhat(buf, info->width - info->len, '0');
	else
		ft_bewhat(buf, info->width - info->len, ' ');
	if (info->int_d < 0)
		pt_char('-');
	if (info->f_minus == 1)
		ft_pt2str(ret, buf);
	else
		ft_pt2str(ret, buf);
	return (0);
}
