/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:45:52 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/01/05 23:48:11 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char *temp;

	temp = s1;
	while (*temp)
		++temp;
	while (*s2)
		*temp++ = *s2++;
	*temp = 0;
	return (s1);
}
