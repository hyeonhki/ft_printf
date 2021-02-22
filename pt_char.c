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