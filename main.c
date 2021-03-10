/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:47:59 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/02/22 17:05:12 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <string.h>

int main()
{ 
	//printf("경우 1: %d"); //서식지정자가 있지만, 인자가 없는 경우
	// warning > 쓰레기값
	//printf("경우 2: %+3 123",1234); //서식지정자가 없고 인자가 들어간 경우
	// %이전까지만 출력
//	printf("경우 3: %difjoi",1234); //서식지정자이후 연속
	// '1234'ifjoi로 출력된다. 끝을 서식지정자로 구분
//	setbuf(stdout, NULL);
//	printf("%d\n",ft_atoi("1234567d"));
//	printf("printf : %*10c\n",5,'a');
	setbuf(stdout, NULL);
//	printf("printf : %0c\n", 10, 'a');
//	int a;
//	a = printf("%*c",-5,'a');
//	printf("ft_printf : [%*c]\n",-5,0);
//	ft_printf("ft_printf : [%*c]\n", 8,'a');
//	printf("%0.d\n", 0);
//	ft_printf("-->|%-4.*d|<--\n", -4, -135);
//	printf("%d\n",printf("%-16s\n", "nark nark"));
//	ft_printf("%d\n",ft_printf("%-16s\n", "nark nark"));
//	printf("%u\n" , 21);
	char *test = "%123";
	printf("[%9.2p]\n",1234);
	unsigned long p = (unsigned long)NULL;
	printf("%lu\n",p);
	printf("%s",*ft_putnbr_base(0,"0123456789abcdef"));
//	ft_printf("[%p]\n",1234);
//	ft_printf("%u\n" ,4294967295);
//	printf("l : %d\n",printf("%s",NULL));
//	printf("len : %d\n",ft_strlen(NULL));
//	ft_printf("[%s]\n",NULL);
//	printf("%s",ft_strdup(NULL));
	
//	printf("[-4.*d]\n",-4,-135);
//	ft_printf("[-4.*d]\n",-4,-135);
//	int b = 0;
//	a = printf("printf : [%6.5d]\n", 135);
//	b = ft_printf("printf : [%6.5d]\n",135);
//	printf("a: %d, b: %d\n",a,b);
//	ft_printf("printf : [%-3d]\n",-135);
//	ft_printf("ft_printf : [%.1d]\n",12);
	// d는 .과 0이 반응 X
//	ft_printf("ft_printf : [%*c]\n", 8,'a');
//	ft_printf("ft_printf : %-*s and %c\n",3, "hi", 'c');
//	ft_strlen("c");
//	ft_printf("예시 : [%c]",'a'); //%연속
//	char *a = "경우 5: 023.6d\n";
//	printf("실제 : %lu, ret : %d\n",strlen(a),ft_printf(a));
	// % 하나 출력, 뒤에 뭐없으면 출력 X



//	printf("test\n");
//	printf(" %d abcdfefe\n",123);
//	ft_printf("test\n");
	//ft_printf("test");
}