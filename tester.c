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

int main()
{
	printTEST("abc", "abcdef");
//	printTEST("abcde\n", 123, 456);
//	char *a;
//	a = "abcdefgh";
//	printf("%0100s\n",a);
//	tester(&a);
//	printf("%s\n",a);
//	printf("");
//	printf("test :%1.6d",14);
}