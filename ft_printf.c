/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:20:16 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/22 16:15:47 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		print_info(t_list *info, va_list ap);

void	case_print(char **str, va_list ap) //문자열 저장 후 주소 이동
{
	char			*temp;
	int				i;
	char			*box;
	t_info			*info;

	temp = *str;
	i = 0;
	box = ft_dup_options(temp, SPECIFIER, &i); //case에는 % 이후부터 서식지정자까지 담긴다. i는 인덱스값
	*str += i;
	if (!(info = malloc(sizeof(t_info) * 1)))
		return (0);
	info_init(info); //구조체 초기화
	save_info(info, box); //구조체 기록
	print_info(info, ap); //구조체 확인 및 출력
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
			pt_normal(&input, &ret);
		if (*input && *(input + 1) == '%')
		{
			pt_double(&input, &ret);
			continue ;
		}
		if (*input)
			case_print(&input, ap);
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
