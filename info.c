/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:06:10 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/22 16:38:01 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	info_init(t_info *info)
{
	info.buf_size = 0;
	info.width = 0;
	info.precise = 0;
	info.specifier = 0;
	info.flag = 0;
}

void	save_info(t_info *info, char *str)
{
	ft_strch
}