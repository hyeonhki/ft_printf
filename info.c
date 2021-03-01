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
	info->f_minus = 0;
	info->f_zero = 0;
	info->f_space = ' ';
	info->f_size = 0;
	info->width = 0;
	info->precise = -1;
	info->spec = 0;
}

void	save_info(t_info *info, char *str, va_list ap)
{
	int			i;

	i = 0;
	ft_check_flag(&str, info);
	if (info->f_size == 1)
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->f_minus = 1;
		}
	}
	else if (str[i] >= '0' && str[i] <= '9')
		info->width = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		info->precise = ft_atoi(&str[++i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (ft_check_init(str[i], SPECIFIER))
		info->spec = str[i];
}