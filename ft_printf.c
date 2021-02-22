/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:30:03 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		pt_normal(char **input)
{
	while (**input && ((**input) != '%'))
	{
		pt_char(**input);
		(*input)++;
	}
}

int		pt_doublepercent(char **input)
{
	(*input)++;
	if (**input == '%')
	{
		pt_char('%');
		(*input)++;
		return (1);
	}
	return (0);
}

int		t_specifier(int c)
{
	if (c == 'd')
		return (c);
	if (c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	return (0);
}

void		t_parsing(char **input, int *specifier, char **buf)
{
	int				index;
	char			*temp;

	temp = *input;
	index = 0;
	while (**input)
	{
		if (**input == '%')
			return ;
		if ((*specifier = t_specifier(**input)) != 0)
		{
			temp[index] = '\0';
			*buf = ft_strdup(temp);
			(*input)++;
			return ;
		}
		(*input)++;
		index++;
	}
}

int		t_operator(char *str, va_list ap)
{
	int				specifier;
	char			*buf;

	while (*str)
	{
		pt_normal(&str); // 널 또는 %일 경우 멈춤
		if (pt_doublepercent(&str)) // %일때 또 %가 오면 continue, 아니면 그냥 다음문자열
			continue ;
		//box에 parsing, specifier도 지정, 포인터는 넘겨주고 따로 문자열 처리 ㄲ
	//	t_parsing(&str, &specifier, &buf);
	}
	return (1);
}

int		ft_printf(const char *input, ...)
{
	va_list				ap; //가변인자 목록 포인터
	int					ret;

	printf("%s",ft_strdup("abcedf"));
	va_start(ap, input); //가변 인자 목록 포인터 설정
	ret = t_operator((char *)input, ap);
	va_end(ap);
	return (ret);
}