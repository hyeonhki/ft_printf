/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:20:16 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/03/14 16:16:59 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_info(t_info *info, va_list ap)
{
	if (info->spec == 'c')
		return (pt_c(ap, info));
	if (info->spec == 's')
		return (pt_s(ap, info));
	if (info->spec == 'd' || info->spec == 'i')
	{
		info->int_d = va_arg(ap, int);
		return (info->int_d >= 0 ? pt_plusd(info) : pt_minusd(info));
	}
	if (info->spec == 'u')
	{
		info->int_u = va_arg(ap, unsigned int);
		return (pt_u(info));
	}
	if (info->spec == 'p')
		return (pt_p(ap, info));
	if (info->spec == '%')
		return (pt_buf(info));
	if (info->spec == 'x')
		return (pt_x(ap, info));
	if (info->spec == 'X')
		return (pt_bigx(ap, info));
	return (0);
}

int		case_print(char **str, va_list ap)
{
	char			*temp;
	int				i;
	char			*box;
	int				ret;
	t_info			*info;

	temp = *str;
	i = 0;
	box = ft_dup_options(temp + 1, SPECIFIER, &i);
	*str += i + 2;
	info = malloc(sizeof(t_info) * 1);
	info_init(info);
	save_info(info, box, ap);
	ret = print_info(info, ap);
	free(info);
	return (ret);
}

int		t_operator(char *input, va_list ap)
{
	int				ret;

	ret = 0;
	while (*input)
	{
		if (*input && (*input) != '%')
			pt_normal(&input, &ret);
		if (*input && *(input + 1) == '%')
		{
			pt_double(&input, &ret);
			continue ;
		}
		if (*input)
		{
			ret += case_print(&input, ap);
		}
	}
	return (ret);
}

int		ft_printf(const char *input, ...)
{
	va_list				ap;
	int					ret;

	va_start(ap, input);
	ret = t_operator((char *)input, ap);
	va_end(ap);
	return (ret);
}
