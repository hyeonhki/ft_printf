/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:06:08 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/27 21:16:46 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strnlen(const char *str, unsigned int size)
{
	unsigned int len;

	len = 0;
	while (len < size)
	{
		if (*str == '\0')
			break ;
		len++;
		str++;
	}
	return (len);
}
