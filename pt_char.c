/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:03:01 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/22 16:05:12 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pt_char(int a)
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
	char	*buf;
	int		i;
	int		c;

	c = va_arg(ap, int);
	i = 0;
	if (info->width == 0)
		info->width = 1;
	if (!(buf = (char *)malloc(info->width + 1 - 1)))
		return (0);
	ft_bewhat(buf, info->width - 1, ' ');
	if (info->f_minus == 1)
	{
		pt_char(c);
		ft_ptstr(buf);
	}
	else
	{
		ft_ptstr(buf);
		pt_char(c);
	}
	return (ft_strlen(buf) + 1);
}

int		pt_string(va_list ap, t_info *info)
{
	char	*ret;
	char	*buf;
	int		len;

	//precise 적용 후 위드 수정
	if ((ret = ft_strdup(va_arg(ap, char *))) == NULL)
		ret = ft_strdup("(null)");
	//precise가 없는 경우 위드 길이 해결
//	printf("\nwidth : %d, %d\n",info->width,info->precise);
	if (info->precise >= 0 && info->precise < (int)ft_strlen(ret))
		ret[info->precise] = 0;
	len = ft_strlen(ret);
	if (info->width <= len)
		info->width = len;
	// 길이를 다시 재서 precise시 반영
	buf = (char *)malloc(info->width - ft_strlen(ret));
	ft_bewhat(buf, info->width - ft_strlen(ret), info->f_space);
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
	return (ft_strlen(ret) + ft_strlen(buf));
}