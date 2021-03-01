/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@studet.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:41:15 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/27 20:19:45 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	void			*temp;
	const void		*s;
	unsigned int	i;

	temp = dest;
	s = src;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		*((char *)temp + i) = *((char *)s + i);
		i++;
	}
	return (dest);
}
