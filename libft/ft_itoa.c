/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 19:22:16 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/01/02 19:26:24 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	nbrtostr(char *str, int n, int len)
{
	int				p;
	long long		n1;

	n1 = n;
	p = 0;
	if (n < 0)
	{
		str[0] = '-';
		n1 = n1 * -1;
		p += 1;
	}
	str[len] = '\0';
	while (--len >= p)
	{
		str[len] = n1 % 10 + '0';
		n1 = n1 / 10;
	}
}

void	u_nbrtostr(char *str, unsigned int n, int len)
{
	int				p;
	unsigned int	n1;

	n1 = n;
	p = 0;
	str[len] = '\0';
	while (--len >= p)
	{
		str[len] = n1 % 10 + '0';
		n1 = n1 / 10;
	}
}

char	*ft_itoa(int n)
{
	char			*temp;
	int				len;

	len = ft_numlen(n);
	if (!(temp = (char *)malloc(len + 1)))
		return (0);
	nbrtostr(temp, n, len);
	return (temp);
}

char	*ft_u_itoa(unsigned int n)
{
	char			*temp;
	int				len;

	if (n > 2147483647)
		len = 10;
	else
		len = ft_numlen((int)n);
	if (!(temp = (char *)malloc(len + 1)))
		return (0);
	u_nbrtostr(temp, n, len);
	return (temp);
}