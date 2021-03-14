/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:06:10 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/03/14 16:05:30 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	info_init(t_info *info)
{
	info->f_minus = 0;
	info->f_zero = 0;
	info->f_space = ' ';
	info->f_size = 0;
	info->width = 0;
	info->prec = -1; // precise가 음수로 들어와도 처리 X
	info->spec = 0;
	info->i = 0;
	info->int_d = 0;
	info->minus_d = 0;
	info->len = 0;
	info->pre_size = 0;
}

// * 로 가변인자를 받는 경우, 그 자리에서 해당되는 값만 허용된다.
// 예를들어 precise위치에 *로 가변인자를 받을 경우, 음수가 들어오면 아무런 변화가 없음.
// * 에서는 0 flag를 받아내지 못한다.
// info의 확인 순서는 0-*flag 
// - flag는 중첩 X
// *과 .*을 읽어내야한다
// 0 < -가 우선
void	save_info(t_info *info, char *str, va_list ap)
{
	ft_check_flag(&str, info);
	if (info->f_size == 1)
		info->width = va_arg(ap, int); //width가 - 인 경우를 print 부분에서 해결해주어야한다
	if (info->width < 0)
	{
		info->f_minus = 1;
		info->width *= -1;
	}
	else if (str[info->i] >= '0' && str[info->i] <= '9')
		info->width = ft_atoi(str + (info->i));
	while (str[info->i] >= '0' && str[info->i] <= '9')
		(info->i)++;
	if (str[info->i] == '.' && str[info->i + 1] == '*')
	{
		info->pre_size = 1;
		info->prec = va_arg(ap, int);
		info->i += 2;
	}
	else if (str[info->i] == '.')
		info->prec = ft_atoi(&str[++(info->i)]); //빈문자열 atoi는 0나오는디;
	while (str[info->i] >= '0' && str[info->i] <= '9')
		(info->i)++;
	info->spec = str[info->i];
}
