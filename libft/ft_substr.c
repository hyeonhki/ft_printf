/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 21:49:47 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/30 21:50:02 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;

	if (s == 0)
		return (0);
	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (!(temp = (char *)malloc(len + 1)))
		return (0);
	temp = ft_memcpy(temp, s + start, len);
	temp[len] = '\0';
	return (temp);
}
