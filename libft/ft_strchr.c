/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:22:42 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/27 20:33:13 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (1)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
