/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 20:57:37 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/01/02 19:33:06 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*temp;
	unsigned int		sum;

	if (s1 == 0 || s2 == 0)
		return (0);
	sum = 0;
	sum = sum + ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(temp = (char *)malloc(sum + 1)))
		return (0);
	ft_memcpy(temp, s1, ft_strlen((char *)s1) + 1);
	ft_memcpy(temp + ft_strlen((char *)s1), s2, ft_strlen((char *)s2) + 1);
	temp[sum] = '\0';
	return (temp);
}
