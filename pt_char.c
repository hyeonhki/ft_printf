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

	i = 0;
	if (info->width == 0)
		info->width = 1;
	if (!(buf = (char *)malloc(info->width)))
		return (0);
	ft_bewhat(buf, info->width, ' ');
	if (info->f_minus == 1)
		*buf = (char)va_arg(ap, int);
	else
	{
		while (buf[i])
			i++;
		i -= 1;
		buf[i] = (char)va_arg(ap, int);
	}
	ft_ptstr(buf);
	return (0);
}

int		pt_string(va_list ap, t_info *info)
{
	char	*ret;
	char	*buf;
	int		len;
	int		a;

	//precise 적용 후 위드 수정
	ret = va_arg(ap, char *);
	len = ft_strlen(ret);
	//precise가 없는 경우 위드 길이 해결
//	printf("\nwidth : %d, %d\n",info->width,info->precise);
	if (info->precise == -1 && info->width <= len)
		info->width = len; //buf는 0길이가 되고 문자열만 출력되는 경우
	//precise 의 경우
	if (info->precise >= 0 && info->precise <= len)
		*(ret + (info->precise)) = 0;
	// 길이를 다시 재서 precise시 반영
	buf = (char *)malloc(info->width - ft_strlen(ret));
	ft_bewhat(buf, info->width - len, info->f_space);
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