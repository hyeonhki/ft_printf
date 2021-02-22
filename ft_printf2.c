/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:20:16 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/20 19:20:23 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


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

int		check_spec(int c, char *src)
{
	int			i;

	i = 0;
	while (src[i])
	{
		if (c == src[i])
			return (src[i]);
		i++;
	}
	return (0);
}

void	info_init(char *str, int c, int index)
{
	write(1, &c, 1);
}

void	case_print(char **str)
{
	char			*print;
	int				specifier;
	int				i;

	i = 0;
//	printf("check");
	while (*str[i] && *str[i] != 'd')
	{
		i++;
//		if ((specifier = check_spec(*str[i], SPECIFIER)) > 0)
//		{
//			info_init(*str, specifier, i);
//			break;
//		}
	}
	*str += (i + 1);
}

int		t_operator(char *input, va_list ap)
{
	int				ret;
	char			*parsing;
	t_options		*options;

	ret = 0;
	while (*input)
	{
		if (*input && (*input) != '%')
		{
		//	printf("1");
			pt_normal(&input, &ret);
		}
		if (*input && *(input + 1) == '%')
		{
		//	printf("2");
			pt_double(&input, &ret);
			continue;
		}
		if (*input)
		{	
		//	printf("3");
			case_print(&input);
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
