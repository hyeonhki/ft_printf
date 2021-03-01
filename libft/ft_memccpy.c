/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:19:54 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/29 20:43:56 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	char			*temp;
	const char		*fp;

	temp = dest;
	fp = src;
	while (n-- != 0)
	{
		*temp = (char)*fp;
		if ((char)*fp == (char)c)
			return (++temp);
		temp++;
		fp++;
	}
	return (0);
}
