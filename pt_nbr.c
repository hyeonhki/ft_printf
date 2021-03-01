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
	int		len;
	char	*buf;

	ret = ft_itoa(va_arg(ap, int));
	if (info->precise > (len = ft_strlen(ret)))
		ret = ft_strjoin(ft_bufwhat(info->precise - len, '0'), ret);
	len = ft_strlen(ret);
	buf = (char *)malloc(info->width - len);
	if (info->precise == -1 && info->f_zero == '0')
		ft_bewhat(buf, info->width - len, '0');
	else
		ft_bewhat(buf, info->width - len, ' ');
	if (info->f_minus == 1)
	{
		ft_ptstr(ret);
		ft_ptstr(buf);
	}
	else
	{
		ft_ptstr(buf);
		ft_ptstr(ret);
	}
	return (0);
}
