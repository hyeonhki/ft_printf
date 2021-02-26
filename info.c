/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:06:10 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/22 17:04:03 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	info_init(t_info *info)
{
	info->buf_size = 0;
	info->width = 0;
	info->precise = 0;
	info->spec = 0;
	info->flag = 0;
	info->minus = 0;
	info->zero = 0;
	info->ch = ' ';
}

void	save_info(t_info *info, char *str, va_list ap)
{
	int			i;

	//width와 *의 중복 경우 *만! 같이쓰면 warning
	//flag의 중복 처리
	i = 0;
	if (ft_check_init(str[i], FLAG))
		info->flag = str[i++];
	if (info->flag == '*')
		info->width = va_arg(ap, int);
	else if (str[i] >= '0' && str[i] <= '9')
		info->width = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		info->precise = ft_atoi(&str[++i]);
		while (str[i] <= '0' && str[i] <= '9')
			i++;
	}
	if (ft_check_init(str[i], SPECIFIER))
		info->spec = str[i];
}