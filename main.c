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
	printf("printf : [%.5c]\n",'a');
	// d는 .과 0이 반응 X
	ft_printf("ft_printf : [%*c]\n", 8,'a');
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