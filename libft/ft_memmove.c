/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@studet.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:49:01 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/29 20:49:12 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char		*temp;
	const char	*s;

	if (n == 0 || dest == src)
		return (dest);
	if (dest <= src)
	{
		temp = dest;
		s = src;
		while (n--)
			*temp++ = *s++;
	}
	else
	{
		temp = dest;
		temp += n;
		s = src;
		s += n;
		while (n--)
			*--temp = *--s;
	}
	return (dest);
}
