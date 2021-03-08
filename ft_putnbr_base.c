/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:33:20 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/03/08 08:32:38 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		recursive_base(unsigned long nbr, char *base, char **ret)
{
	int		base_num;
	int		prt;

	base_num = ft_strlen(base);
	if (nbr == 0)
		return ;
	recursive_base(nbr / base_num, base, ret);
	prt = nbr % base_num;
	**ret = base[prt];
	(*ret)++;
	write(1, &base[prt], 1);
}

int		nbrlen(unsigned long nbr, char *base)
{
	int			base_num;
	int			cnt;

	cnt = 0;
	if (nbr == 0)
		return (1);
	base_num = ft_strlen(base);
	while (nbr != 0)
	{
		nbr = nbr / base_num;
		cnt++;
	}
	return (cnt);
}

char	*ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	temp_nbr;
	int				cnt;
	char			*ret;

	cnt = 0;
	temp_nbr = nbr;
	ret = (char *)malloc(nbrlen(nbr, base) + 1);
	if (temp_nbr == 0)
	{
		ret[0] = *base;
		ret[1] = '\0';
	}
	recursive_base(temp_nbr, base, &ret);
	return (ret);
}
