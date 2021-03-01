/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@stduent.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:59:51 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/21 12:16:55 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *buffer, int c, unsigned int n)
{
	unsigned int	i;
	void			*temp;

	temp = buffer;
	i = 0;
	while (i < n)
	{
		*((char *)buffer + i) = c;
		i++;
	}
	return (buffer);
}
