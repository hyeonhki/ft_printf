/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:19:03 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/18 16:19:04 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>



void tester2(va_list ap)
{
	char *ret;
	ret = va_arg(ap, char *);
	printf("test : %s", ret);
}

void printTEST(char *input, ...)
{
	va_list ap;
	int i = 0;
	va_start(ap, input);
	tester2(ap);
	va_end(ap);
}

void	test(char **buf)
{
	(*buf)[3] = '\0';
}

#include <stdlib.h>

int main()
{
	int a;
	int *b;
	b = &a;
	unsigned long long z = (void *)1234;
	printf("%d\n",z);
	printf("%2.9p\n", 1234);
	printf("%p\n",1234);
/*	char *buf;
	int i;
	i = 0;

	buf = (char *)malloc(5);
	while (i <= 4)
	{
		buf[i] = i + '0';
		i++;
	}
	buf[3] = '\0';
	printf("%s\n",buf);
*/
//	printTEST("abcde\n", 123, 456);
//	char *a;
//	a = "abcdefgh";
//	printf("%0100s\n",a);
//	tester(&a);
//	printf("%s\n",a);
//	printf("");
//	printf("test :%1.6d",14);
}