/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:58:03 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/29 22:16:21 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int n)
{
	unsigned int i;
	unsigned int dst_len;
	unsigned int src_len;

	dst_len = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (n == 0)
		return (src_len);
	while (dest[dst_len] != '\0')
		dst_len++;
	if (dst_len > n)
		return (n + src_len);
	i = 0;
	while (i + dst_len + 1 < n && src[i])
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = '\0';
	return (src_len + dst_len);
}
