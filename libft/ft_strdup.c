/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:36:04 by hyeonhki          #+#    #+#             */
/*   Updated: 2020/12/27 16:44:44 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		i;

	if (src == NULL)
		return (NULL);
	i = 0;
	if (!(temp = (char *)malloc((int)(ft_strlen((char *)src) + 1))))
		return (0);
	while (src[i] != '\0')
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strndup(const char *src, int n)
{
	char			*temp;
	int				i;

	i = 0;
	temp = (char *)malloc((unsigned int)n + 1);
	if (temp == 0)
		return (0);
	while (src[i] != '\0' && n > 0)
	{
		temp[i] = src[i];
		i++;
		n--;
	}
	temp[i] = '\0';
	return (temp);
}
