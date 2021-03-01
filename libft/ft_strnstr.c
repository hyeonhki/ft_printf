/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:03:47 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/23 17:42:48 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_same(const char *b, const char *l, int start)
{
	b += start;
	while (*l)
	{
		if (*b != *l)
			return (0);
		b++;
		l++;
	}
	return (1);
}

char	*ft_strnstr(const char *b, const char *l, unsigned int n)
{
	unsigned int	i;

	if (*l == 0)
		return ((char *)b);
	i = 0;
	if (b != 0 && n < (unsigned int)ft_strlen((char *)l))
		return (0);
	while (i <= (n - ft_strlen((char *)l)) && b[i] != '\0')
	{
		if (is_same(b, l, i) == 1)
			return ((char *)b + i);
		i++;
	}
	return (0);
}
