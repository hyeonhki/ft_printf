/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@studet.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:02:53 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/01/10 12:37:18 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *ptr, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*temp;

	temp = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return ((unsigned char *)&temp[i]);
		i++;
	}
	return (0);
}
